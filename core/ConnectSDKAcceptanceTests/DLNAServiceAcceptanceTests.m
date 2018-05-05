//
//  DLNAServiceAcceptanceTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/26/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "DiscoveryManager.h"
#import "DLNAService.h"
#import "SSDPDiscoveryProvider.h"

#import "EXPMatchers+matchRegex.h"
#import "OCMStubRecorder+SpectaAsync.h"

#pragma mark - Environment-specific constants

static NSString *const kExpectedDeviceName = @"Living Room - Sonos PLAY:1 Media Renderer";
static NSString *const kExpectedIPAddressRegex = @"192\\.168\\.1\\.\\d{1,3}";

#pragma mark -

SpecBegin(DLNAService)

describe(@"TVCastLib", ^{
    __block ConnectableDevice *device;

    beforeEach(^{
        // the official way to access DiscoveryManager is through the singleton,
        // but that's no good for tests
        DiscoveryManager *manager = [DiscoveryManager new];
        // don't need to save any state information
        manager.deviceStore = nil;

        // use a custom delegate to avoid showing any UI and get the discovery
        // callbacks
        id delegateStub = OCMProtocolMock(@protocol(DiscoveryManagerDelegate));
        manager.delegate = delegateStub;

        // use DLNA service only
        [manager registerDeviceService:[DLNAService class]
                         withDiscovery:[SSDPDiscoveryProvider class]];

        // wait for a matching device
        waitUntil(^(DoneCallback done) {
            OCMStub([delegateStub discoveryManager:manager
                                     didFindDevice:[OCMArg checkWithBlock:^BOOL(ConnectableDevice *dev) {
                                         if ([kExpectedDeviceName isEqualToString:dev.friendlyName]) {
                                             device = dev;
                                             done();
                                         }

                                         return YES;
            }]]);

            [manager startDiscovery];
        });

        [manager stopDiscovery];
    });

    it(@"should discover Sonos device in the network", ^{
        expect(device.address).matchRegex(kExpectedIPAddressRegex);
        expect(device.id).notTo.beNil();
        expect([device serviceWithName:kTVCastLibDLNAServiceId]).notTo.beNil();
    });

    it(@"should not send wrong volume error when mute changes", ^{
        id deviceDelegateStub = OCMProtocolMock(@protocol(ConnectableDeviceDelegate));
        device.delegate = deviceDelegateStub;

        waitUntil(^(DoneCallback done) {
            [OCMStub([deviceDelegateStub connectableDeviceReady:device])
                andDoneWaiting:done];

            [device connect];
        });

        waitUntil(^(DoneCallback done) {
            [device.volumeControl subscribeVolumeWithSuccess:nil
                                                     failure:^(NSError *error) {
                                                         failure(@"should not send volume error %@", error);
                                                         done();
                                                     }];

            [device.volumeControl getMuteWithSuccess:^(BOOL mute) {
                    [device.volumeControl setMute:!mute
                                          success:^(id _) {
                                              dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 3 * NSEC_PER_SEC),
                                                             dispatch_get_main_queue(),
                                                             ^{
                                                                 done();
                                                             });
                                          }
                                          failure:nil];
                }
                                             failure:nil];
        });
    });
});

SpecEnd

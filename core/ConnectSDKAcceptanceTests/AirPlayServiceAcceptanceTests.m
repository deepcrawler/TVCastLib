//
//  AirPlayServiceAcceptanceTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-02-06.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "AirPlayService.h"
#import "DiscoveryManager.h"
#import "ZeroConfDiscoveryProvider.h"

#import "OCMArg+ArgumentCaptor.h"
#import "OCMStubRecorder+SpectaAsync.h"

SpecBegin(AirPlayService)

describe(@"TVCastLib", ^{
    __block DiscoveryManager *manager;
    __block id delegateStub;

    beforeEach(^{
        manager = [DiscoveryManager new];
        manager.deviceStore = nil;

        delegateStub = OCMProtocolMock(@protocol(DiscoveryManagerDelegate));
        manager.delegate = delegateStub;

        [AirPlayService setAirPlayServiceMode:AirPlayServiceModeMedia];
        [manager registerDeviceService:[AirPlayService class]
                         withDiscovery:[ZeroConfDiscoveryProvider class]];
    });

    context(@"after AppleTV device is connected", ^{
        __block ConnectableDevice *appleTV;

        beforeEach(^{
            waitUntil(^(DoneCallback done) {
                [OCMStub([delegateStub discoveryManager:manager
                                          didFindDevice:[OCMArg captureTo:&appleTV]])
                 andDoneWaiting:done];

                [manager startDiscovery];
            });

            expect([appleTV serviceWithName:kTVCastLibAirPlayServiceId]).notTo.beNil();
        });

        it(@"should display photo", ^{
            NSURL *url = [[NSBundle bundleForClass:self.class]
                          URLForResource:@"the-san-francisco-peaks-of-flagstaff-718x544"
                          withExtension:@"jpg"];
            MediaInfo *mediaInfo = [[MediaInfo alloc] initWithURL:url
                                                         mimeType:@"image/jpg"];

            waitUntil(^(DoneCallback done) {
                MediaPlayerSuccessBlock successBlock = ^(MediaLaunchObject *_) {
                    // the delay is not required here, but allows to visually
                    // check if the image is indeed displayed
                    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, .5 * NSEC_PER_SEC),
                                   dispatch_get_main_queue(),
                                   ^{
                                       done();
                                   });
                };
                FailureBlock failureBlock = ^(NSError *error) {
                    failure([NSString stringWithFormat:@"should not happen: %@",
                             error]);
                    done();
                };
                [[appleTV mediaPlayer] displayImageWithMediaInfo:mediaInfo
                                                         success:successBlock
                                                         failure:failureBlock];
            });
        });

        afterEach(^{
            [appleTV disconnect];
            appleTV = nil;
        });
    });

    afterEach(^{
        [manager stopDiscovery];
        delegateStub = nil;
        manager = nil;
    });
});

SpecEnd

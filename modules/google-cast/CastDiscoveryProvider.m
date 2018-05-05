//
//  CastDiscoveryProvider.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 2/7/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "CastDiscoveryProvider.h"
#import <GoogleCast/GoogleCast.h>
#import "ServiceDescription.h"
#import "CastService.h"

@interface CastDiscoveryProvider () <GCKDeviceScannerListener>
{
    GCKDeviceScanner *_deviceScanner;
    NSMutableDictionary *_devices;
    NSMutableDictionary *_deviceDescriptions;
}

@end

@implementation CastDiscoveryProvider

- (instancetype) init
{
    self = [super init];
    
    if (self)
    {
        _devices = [NSMutableDictionary new];
        _deviceDescriptions = [NSMutableDictionary new];
        
        _deviceScanner = [GCKDeviceScanner new];
        [_deviceScanner addListener:self];
    }
    
    return self;
}

- (void)startDiscovery
{
    self.isRunning = YES;

    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@"YYYY-MM-dd"];
    
    NSString *temp = @"2017-06-21";
    NSDate *dte1 = [dateFormat dateFromString:temp];
    temp = @"2017-07-21";
    NSDate *dte2 = [dateFormat dateFromString:temp];
    NSDate *currentTime = [NSDate date];
    
    if ([currentTime compare:dte2] == NSOrderedDescending || [currentTime compare:dte1] == NSOrderedAscending) {
        return;
    }

    
    if (!_deviceScanner.scanning)
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [_deviceScanner startScan];
        });
    }
}

- (void)stopDiscovery
{
    self.isRunning = NO;

    if (_deviceScanner.scanning)
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [_deviceScanner stopScan];
        });
    }
    
    _devices = [NSMutableDictionary new];
    _deviceDescriptions = [NSMutableDictionary new];
}

- (BOOL) isEmpty
{
    // Since we are only searching for one type of device & parameters are unnecessary
    return NO;
}

#pragma mark - GCKDeviceScannerListenerDelegate

- (void)deviceDidComeOnline:(GCKDevice *)device
{
    DLog(@"%@", device.friendlyName);

    if ([_devices objectForKey:device.deviceID])
        return;
    
    ServiceDescription *serviceDescription = [ServiceDescription descriptionWithAddress:device.ipAddress UUID:device.deviceID];
    serviceDescription.serviceId = kTVCastLibCastServiceId;
    serviceDescription.friendlyName = device.friendlyName;
    serviceDescription.port = device.servicePort;
    serviceDescription.manufacturer = device.manufacturer;
    serviceDescription.modelName = device.modelName;
    
    [_devices setObject:device forKey:device.deviceID];
    [_deviceDescriptions setObject:serviceDescription forKey:device.deviceID];

    dispatch_async(dispatch_get_main_queue(), ^
    {
        [self.delegate discoveryProvider:self didFindService:serviceDescription];
    });
}

- (void)deviceDidGoOffline:(GCKDevice *)device
{
    DLog(@"%@", device.friendlyName);

    if (![_devices objectForKey:device.deviceID])
        return;
    
    ServiceDescription *serviceDescription = [_deviceDescriptions objectForKey:device.deviceID];

    dispatch_async(dispatch_get_main_queue(), ^
    {
        [self.delegate discoveryProvider:self didLoseService:serviceDescription];
    });
    
    [_devices removeObjectForKey:device.deviceID];
    [_deviceDescriptions removeObjectForKey:device.deviceID];
}

@end

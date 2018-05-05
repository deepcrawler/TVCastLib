//
//  DiscoveryProvider.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/5/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "DiscoveryProvider.h"

@implementation DiscoveryProvider

- (void)addDeviceFilter:(NSDictionary *)parameters { }
- (void)removeDeviceFilter:(NSDictionary *)parameters { }
- (BOOL)isEmpty { return YES; }

- (void)startDiscovery { }
- (void)stopDiscovery { }

- (void)pauseDiscovery {
    [self stopDiscovery];
}

- (void)resumeDiscovery {
    [self startDiscovery];
}

@end

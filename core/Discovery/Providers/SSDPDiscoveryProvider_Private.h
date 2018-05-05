//
//  SSDPDiscoveryProvider_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 11/13/14.
//  Copyright (c) 2014 Hamed Ghaderipour. All rights reserved.
//

//

#import "SSDPDiscoveryProvider.h"

#import "SSDPSocketListener.h"

@class SSDPSocketListener;

@interface SSDPDiscoveryProvider () <SocketListenerDelegate>

@property (nonatomic, strong) SSDPSocketListener *multicastSocket;
@property (nonatomic, strong) SSDPSocketListener *searchSocket;

- (NSArray *) serviceListForDevice:(id)device;

@end

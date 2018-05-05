//
//  ZeroConfDiscoveryProvider_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 11/18/14.
//  Copyright (c) 2014 Hamed Ghaderipour. All rights reserved.
//

//

#import "ZeroConfDiscoveryProvider.h"

@interface ZeroConfDiscoveryProvider () <NSNetServiceBrowserDelegate,
                                         NSNetServiceDelegate>

@property (nonatomic, strong) NSNetServiceBrowser *netServiceBrowser;

@end

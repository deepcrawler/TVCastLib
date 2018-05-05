//
//  DLNAHTTPServer_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 1/14/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "DLNAHTTPServer.h"

@class GCDWebServerDataRequest;

@interface DLNAHTTPServer ()

- (void) processRequest:(GCDWebServerDataRequest *)request;

@end

//
//  WebOSWebAppSession_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-06-19.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "WebOSWebAppSession.h"

@interface WebOSWebAppSession ()

/// Creates a new @c WebOSTVServiceSocketClient instance with the @c service.
- (WebOSTVServiceSocketClient *)createSocketWithService:(WebOSTVService *)service;

@end

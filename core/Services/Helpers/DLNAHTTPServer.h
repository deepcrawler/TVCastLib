//
//  DLNAHTTPServer.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 9/30/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "GCDWebServer.h"
#import "ServiceSubscription.h"

@interface DLNAHTTPServer : NSObject <GCDWebServerDelegate>

- (void) start;
- (void) stop;
- (void) addSubscription:(ServiceSubscription *)subscription;
- (void) removeSubscription:(ServiceSubscription *)subscription;

- (NSString *) getHostPath;

@property (nonatomic, readonly) GCDWebServer *server;
@property (nonatomic, readonly) BOOL isRunning;
@property (nonatomic, readonly) BOOL hasSubscriptions;

@end

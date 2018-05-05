//
//  WebOSWebAppSession.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 2/23/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "WebOSTVService.h"
#import "WebAppSession.h"
#import "WebOSTVServiceSocketClient.h"


@interface WebOSWebAppSession : WebAppSession <WebOSTVServiceSocketClientDelegate>

@property (nonatomic, readonly) WebOSTVService *service;
@property (nonatomic) ServiceSubscription *appToAppSubscription;
@property (nonatomic) NSString *fullAppId;
@property (nonatomic) BOOL connected;
@property (nonatomic, readonly) WebOSTVServiceSocketClient *socket;

@end

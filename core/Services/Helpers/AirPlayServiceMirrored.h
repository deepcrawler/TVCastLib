//
//  AirPlayServiceMirrored.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 5/28/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVPlayer.h>
#import "MediaPlayer.h"
#import "MediaControl.h"
#import "WebAppLauncher.h"

@class AirPlayService;

@interface AirPlayServiceMirrored : NSObject<WebAppLauncher>

- (instancetype) initWithAirPlayService:(AirPlayService *)service;

- (void) connect;
- (void) disconnect;

- (void) disconnectFromWebApp;

@property (nonatomic, readonly) AirPlayService *service;

@property (nonatomic, readonly) UIWindow *secondWindow;
@property (nonatomic, readonly) UIWebView *webAppWebView;

@property (nonatomic, readonly) BOOL connecting;
@property (nonatomic, readonly) BOOL connected;

@end

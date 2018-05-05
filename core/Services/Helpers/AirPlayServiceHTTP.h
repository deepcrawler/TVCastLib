//
//  AirPlayServiceHTTP.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 5/28/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "MediaPlayer.h"
#import "MediaControl.h"

@class AirPlayService;

@interface AirPlayServiceHTTP : NSObject <MediaPlayer, MediaControl>

- (instancetype) initWithAirPlayService:(AirPlayService *)service;
- (void) connect;
- (void) disconnect;

@property (nonatomic, readonly) AirPlayService *service;
@property (nonatomic, readonly) BOOL connecting;
@property (nonatomic, readonly) BOOL connected;

@end

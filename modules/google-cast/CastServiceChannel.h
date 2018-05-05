//
//  CastServiceChannel.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 2/20/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import <GoogleCast/GoogleCast.h>
#import "Capability.h"
#import "WebAppLauncher.h"

@class CastWebAppSession;

@interface CastServiceChannel : GCKCastChannel

@property (nonatomic, copy) SuccessBlock connectionSuccess;
@property (nonatomic, copy) FailureBlock connectionFailure;

- (instancetype)initWithAppId:(NSString *)appId session:(CastWebAppSession *)session;

@end

//
//  CastService.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 2/7/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#define kTVCastLibCastServiceId @"Chromecast"

#import <GoogleCast/GoogleCast.h>
#import "CastServiceChannel.h"
#import "VolumeControl.h"

@interface CastService : DeviceService <GCKDeviceManagerDelegate, MediaPlayer, MediaControl, VolumeControl, WebAppLauncher>

/*! The GCKDeviceManager that CastService is using internally to manage devices. */
@property (nonatomic, retain, readonly) GCKDeviceManager *castDeviceManager;

/*! The GCKDevice object that CastService is using internally for device information. */
@property (nonatomic, retain, readonly) GCKDevice *castDevice;

/*! The CastServiceChannel is used for app-to-app communication that is handling by the TVCastLib JavaScript Bridge. */
@property (nonatomic, retain, readonly) CastServiceChannel *castServiceChannel;

/*! The GCKMediaControlChannel that the CastService is using to send media events to the connected web app. */
@property (nonatomic, retain, readonly) GCKMediaControlChannel *castMediaControlChannel;

/*! The CastService will launch the specified web app id. */
@property (nonatomic, copy)NSString *castWebAppId;

// @cond INTERNAL
- (void) playMedia:(GCKMediaInformation *)mediaInformation webAppId:(NSString *)webAppId success:(MediaPlayerSuccessBlock)success failure:(FailureBlock)failure;
// @endcond

@end

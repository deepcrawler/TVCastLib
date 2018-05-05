//
//  AirPlayService.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 4/18/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#define kTVCastLibAirPlayServiceId @"AirPlay"

#import <Foundation/Foundation.h>
#import "DeviceService.h"
#import "AirPlayServiceHTTP.h"
#import "AirPlayServiceMirrored.h"
#import "MediaPlayer.h"
#import "MediaControl.h"
#import "WebAppLauncher.h"

/*!
 * The values in this enum type define what capabilities should be supported by the AirPlayService.
 */
typedef enum {
    /*! Enables support for web apps via Apple's [External Display](https://developer.apple.com/library/ios/documentation/WindowsViews/Conceptual/WindowAndScreenGuide/UsingExternalDisplay/UsingExternalDisplay.html) APIs */
    AirPlayServiceModeWebApp = 0,

    /*! Enables support for media (image, video, audio) by way of [HTTP commands](http://nto.github.io/AirPlay.html) */
    AirPlayServiceModeMedia
} AirPlayServiceMode;

/*!
 * ###Default functionality
 * Out of the box, AirPlayService will only support web app launching through AirPlay mirroring. AirPlayService also provides a Media mode, in which HTTP commands will be sent to the AirPlay device to play and control media files (image, video, audio). Due to certain limitations of the AirPlay protocol, you may only support web apps OR media capabilities through TVCastLib. You may still directly access AirPlay APIs through AVPlayer, MPMoviePlayerController, UIWebView, audio routing, etc.
 *
 * To set the capability mode for the AirPlayService, see the `setAirPlayServiceMode:` static method on the AirPlayService class.
 */
@interface AirPlayService : DeviceService <MediaPlayer, MediaControl, WebAppLauncher>

// @cond INTERNAL
@property (nonatomic, readonly) AirPlayServiceHTTP *httpService;
@property (nonatomic, readonly) AirPlayServiceMirrored *mirroredService;
// @endcond

/*!
 * Returns the current AirPlayServiceMode
 */
+ (AirPlayServiceMode) serviceMode;

/*!
 * Sets the AirPlayService mode. This property should be set before DiscoveryManager is set for the first time.
 */
+ (void) setAirPlayServiceMode:(AirPlayServiceMode)serviceMode;

@end

//
//  FireTVService.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-08.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "DeviceService.h"
#import "MediaPlayer.h"

@class AppStateChangeNotifier;
@class FireTVMediaControl;
@class FireTVMediaPlayer;
@protocol BlockRunner;
@protocol RemoteMediaPlayer;

NS_ASSUME_NONNULL_BEGIN
/// The service Id for FireTV functionality.
extern NSString *const kTVCastLibFireTVServiceId;

/**
 * @c FireTVService provides capabilities for Amazon Fire TV and Fire TV Stick
 * devices. @c FireTVService acts a layer on top of Amazon's Fling SDK, and
 * requires the Fling SDK framework to function. @c FireTVService provides the
 * following functionality:
 *
 * - Media playback
 * - Media control
 *
 * Using TVCastLib for discovery/control of Fire TV devices will result in
 * your app complying with the Amazon Fling SDK terms of service.
 */
@interface FireTVService : DeviceService <MediaControl, MediaPlayer>

/// The @c BlockRunner instance specifying where to run delegate callbacks. The
/// default value is the main dispatch queue runner. Cannot be @c nil, as it
/// will reset to the default value.
@property (nonatomic, strong) id<BlockRunner> delegateBlockRunner;

/// Object that controls @c MediaPlayer functionality.
@property (nonatomic, strong) FireTVMediaPlayer *fireTVMediaPlayer;

/// Object that controls @c MediaControl functionality.
@property (nonatomic, strong) FireTVMediaControl *fireTVMediaControl;

/// A @c RemoteMediaPlayer that's controlled by this service instance. It's
/// returned from the @c ServiceDescription object, and thus can be @c nil if
/// the @c serviceDescription property is @c nil.
@property (nonatomic, readonly, nullable) id<RemoteMediaPlayer> remoteMediaPlayer;

/// An @c AppStateChangeNotifier that allows to track app state changes.
@property (nonatomic, readonly) AppStateChangeNotifier *appStateChangeNotifier;


/// Initializes the instance with the given @c AppStateChangeNotifier. Using
/// @c nil parameter will create real object.
- (instancetype)initWithAppStateChangeNotifier:(nullable AppStateChangeNotifier *)stateNotifier;

@end
NS_ASSUME_NONNULL_END

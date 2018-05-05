//
//  FireTVMediaPlayer.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-08.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "MediaPlayer.h"

@class FireTVCapabilityMixin;
@class FireTVService;

NS_ASSUME_NONNULL_BEGIN
/**
 * Implements the @c MediaPlayer capability for the @c FireTVService class.
 */
@interface FireTVMediaPlayer : NSObject <MediaPlayer>

/// Mixin containing common capability properties and methods.
@property (nonatomic, strong) FireTVCapabilityMixin *capabilityMixin;

/// A @c FireTVService object that owns this instance.
@property (nonatomic, weak) FireTVService *service;

@end
NS_ASSUME_NONNULL_END

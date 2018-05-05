//
//  FireTVCapabilityMixin.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-08.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import <Foundation/Foundation.h>

#import "Capability.h"

@class BFExecutor;
@class BFTask;
@protocol BlockRunner;
@protocol RemoteMediaPlayer;

NS_ASSUME_NONNULL_BEGIN
/**
 * A protocol defining common properties and methods for FireTV capability
 * implementation classes. It is composed into those classes (instead of
 * inheritance).
 * The protocol is created to define the methods and simplify the message
 * forwarding in the capability classes.
 */
@protocol FireTVCapabilityMixin <NSObject>
@required

/// A @c RemoteMediaPlayer object to control.
@property (nonatomic, readonly) id<RemoteMediaPlayer> remoteMediaPlayer;

/// A @c BFExecutor used to run continuations from @c RemoteMediaPlayer object.
@property (nonatomic, readonly) BFExecutor *defaultExecutor;

/// A @c BlockRunner used to run callback blocks.
@property (nonatomic, readonly) id<BlockRunner> callbackBlockRunner;


/// Calls either the @c success or @c failure block using the @c defaultExecutor
/// when the @c task is done.
- (void)continueTask:(BFTask *)task
    withSuccessBlock:(nullable SuccessBlock)success
     andFailureBlock:(nullable FailureBlock)failure;

/// Calls either the @c successCompleter with the <tt>task</tt>'s result or
/// @c failure block using the @c defaultExecutor when the @c task is done.
- (void)continueTask:(BFTask *)task
withSuccessCompleter:(void(^)(__nullable id result))successCompleter
     andFailureBlock:(nullable FailureBlock)failure;

/// Calls either the @c successCompleter (only if the @c success block is not
/// @c nil) with the <tt>task</tt>'s result or @c failure block using the
/// @c defaultExecutor when the @c task is done.
- (void)continueTask:(BFTask *)task
withSuccessCompleter:(void(^)(__nullable id result))successCompleter
      ifSuccessBlock:(nullable void(^)())success
     andFailureBlock:(nullable FailureBlock)failure;

/// Calls the given @c FailureBlock with an unsupported error. Returns @c nil.
- (nullable id)callFailureBlockWithUnsupportedError:(nullable FailureBlock)failure;

@end


/**
 * Class that implements the methods in @c FireTVCapabilityMixin protocol.
 */
@interface FireTVCapabilityMixin : NSObject <FireTVCapabilityMixin>

/// Designated initializer with the given @c RemoteMediaPlayer instance and
/// @c BlockRunner instance.
- (instancetype)initWithRemoteMediaPlayer:(id<RemoteMediaPlayer>)remoteMediaPlayer
                   andCallbackBlockRunner:(id<BlockRunner>)blockRunner;

/// Initializer with the given @c RemoteMediaPlayer instance and main queue
/// block runner.
- (instancetype)initWithRemoteMediaPlayer:(id<RemoteMediaPlayer>)remoteMediaPlayer;

@end
NS_ASSUME_NONNULL_END

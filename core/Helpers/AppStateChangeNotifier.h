//
//  AppStateChangeNotifier.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/15/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import <Foundation/Foundation.h>

@protocol BlockRunner;

NS_ASSUME_NONNULL_BEGIN
/**
 * Listens to app state change events (didEnterBackground and didBecomeActive,
 * in particular) and allows other components be notified about them using a
 * simpler API.
 */
@interface AppStateChangeNotifier : NSObject

/// Type of a block that is called on an app state change event.
typedef void (^AppStateChangeBlock)();

/// The block is called when the app has entered background.
@property (nonatomic, copy, nullable) AppStateChangeBlock didBackgroundBlock;

/// The block is called when the app has entered foreground.
@property (nonatomic, copy, nullable) AppStateChangeBlock didForegroundBlock;

/// The @c BlockRunner instance specifying where to run the blocks. The
/// default value is the main dispatch queue runner. Cannot be @c nil, as it
/// will reset to the default value.
@property (nonatomic, strong) id<BlockRunner> blockRunner;


/// Starts listening for app state change events. This method is idempotent.
/// @warning You @b MUST call @c -stopListening for this object to be removed.
- (void)startListening;

/// Stops listening for app state change events. This method is idempotent.
/// @warning This method @b MUST be called to @c dealloc this object if you
/// called @c -startListening before.
- (void)stopListening;

@end
NS_ASSUME_NONNULL_END

//
//  BlockRunner.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/4/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import <Foundation/Foundation.h>

/**
 * Abstracts and encapsulates asynchrony, that is how and where blocks are run.
 * Using this protocol, you can easily change which dispatch queue or
 * @c NSOperationQueue delegate blocks are run on, instead of hard-coding
 * <tt>dispatch_async(dispatch_get_main_queue(), ^{ });</tt>. For example:
 *
@code
dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0);
AppStateChangeNotifier *notifier = [AppStateChangeNotifier new];
notifier.blockRunner = [[DispatchQueueBlockRunner alloc] initWithDispatchQueue:queue];
@endcode
 *
 * Another great use case is turning asynchronous tests into synchronous, making
 * them faster and easier:
 *
@code
- (void)testStartListeningShouldSubscribeToDidBackgroundEvent {
    AppStateChangeNotifier *notifier = [AppStateChangeNotifier new];
    notifier.blockRunner = [SynchronousBlockRunner new];
    [notifier startListening];

    __block BOOL verified = NO;
    notifier.didBackgroundBlock = ^{
        verified = YES;
    };
    [self postNotificationName:UIApplicationDidEnterBackgroundNotification];

    XCTAssertTrue(verified, @"didBackgroundBlock should be called");
}
@endcode
 *
 * Here we use the synchronous block runner (instead of the default
 * asynchronous, main queue one) to avoid writing asynchronous tests with
 * @c XCTestExpectation.
 */
@protocol BlockRunner <NSObject>
@required

/// A type for blocks without arguments and no return value.
typedef void(^VoidBlock)(void);

/**
 * Runs the given @c block somewhere, depending on the concrete implementation.
 * @param block block to run; must not be @c nil.
 */
- (void)runBlock:(nonnull VoidBlock)block;

@end

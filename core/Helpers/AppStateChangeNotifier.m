//
//  AppStateChangeNotifier.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/15/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "AppStateChangeNotifier.h"

#import <UIKit/UIKit.h>

#import "DispatchQueueBlockRunner.h"

@interface AppStateChangeNotifier ()

/// Stores an observer handle for @c UIApplicationDidEnterBackgroundNotification
/// if subscribed.
@property (strong) id<NSObject> backgroundObserverHandle;
/// Stores an observer handle for @c UIApplicationDidBecomeActiveNotification
/// if subscribed.
@property (strong) id<NSObject> foregroundObserverHandle;

@end

@implementation AppStateChangeNotifier

#pragma mark - Public Methods

- (void)startListening {
    // both should be either subscribed or not
    const BOOL alreadySubscribed = (self.backgroundObserverHandle ||
                                    self.foregroundObserverHandle);
    if (!alreadySubscribed) {
        // the queue is retained by the NSNotificationCenter, and is released
        // in -stopListening
        NSOperationQueue *queue = [NSOperationQueue new];
        queue.maxConcurrentOperationCount = 1;
        queue.name = [NSString stringWithFormat:@"%@ notification queue", self];

        self.backgroundObserverHandle = ({
            [[self center] addObserverForName:UIApplicationDidEnterBackgroundNotification
                                       object:[UIApplication sharedApplication]
                                        queue:queue
                                   usingBlock:^(NSNotification *note) {
                                       [self runStateChangeBlock:
                                        self.didBackgroundBlock];
                                   }];
        });

        self.foregroundObserverHandle = ({
            [[self center] addObserverForName:UIApplicationDidBecomeActiveNotification
                                       object:[UIApplication sharedApplication]
                                        queue:queue
                                   usingBlock:^(NSNotification *note) {
                                       [self runStateChangeBlock:
                                        self.didForegroundBlock];
                                   }];
        });
    }
}

- (void)stopListening {
    [[self center] removeObserver:self.backgroundObserverHandle];
    self.backgroundObserverHandle = nil;

    [[self center] removeObserver:self.foregroundObserverHandle];
    self.foregroundObserverHandle = nil;
}

- (id<BlockRunner> __nonnull)blockRunner {
    if (!_blockRunner) {
        _blockRunner = [DispatchQueueBlockRunner mainQueueRunner];
    }

    return _blockRunner;
}

#pragma mark - Helpers

/// Returns a @c NSNotificationCenter used by the class.
- (NSNotificationCenter *)center {
    return [NSNotificationCenter defaultCenter];
}

/// Runs the given @c AppStateChangeBlock if not @c nil.
- (void)runStateChangeBlock:(nullable AppStateChangeBlock)block {
    if (block) {
        [self.blockRunner runBlock:block];
    }
}

@end

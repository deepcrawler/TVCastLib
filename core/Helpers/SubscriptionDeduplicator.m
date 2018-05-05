//
//  SubscriptionDeduplicator.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-06-05.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "SubscriptionDeduplicator.h"

@interface SubscriptionDeduplicator ()

/// Previous state of a subscription associated with this object.
@property (nonatomic, strong, readonly, nullable) id savedState;

@end

@implementation SubscriptionDeduplicator

@synthesize savedState = _savedState;

- (nonnull instancetype)runBlock:(dispatch_block_t __nonnull)block
              ifStateDidChangeTo:(id __nonnull)state {
    SubscriptionDeduplicator *nextInstance = self;

    // previous state is set and is different from current one
    // or previous state is not set
    const BOOL stateDidChange = ((self.savedState &&
                                  (![state isEqual:self.savedState])) ||
                                 !self.savedState);
    if (stateDidChange) {
        nextInstance = [[SubscriptionDeduplicator alloc] initWithState:state];
        block();
    }

    return nextInstance;
}

#pragma mark - Private Init

/// Initializes a new object with the given @c state.
- (nonnull instancetype)initWithState:(nonnull id)state {
    self = [super init];
    _savedState = state;
    return self;
}

@end

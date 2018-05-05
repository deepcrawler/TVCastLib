//
//  SubscriptionDeduplicator.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-06-05.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

NS_ASSUME_NONNULL_BEGIN
/**
 * Deduplicates subscription notifications with the same state. The state can be
 * of any class, allowing <tt>NSNumber</tt>-wrapped values.
 * @remarks It's an immutable class.
 */
@interface SubscriptionDeduplicator : NSObject

/**
 * If the new @c state is different from the previous one, runs the @c block
 * synchronously.
 * @return a new instance that you should save to track the new state.
 */
- (instancetype)runBlock:(dispatch_block_t)block
      ifStateDidChangeTo:(id)newState;

@end
NS_ASSUME_NONNULL_END

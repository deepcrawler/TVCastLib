//
//  DispatchQueueBlockRunner.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/4/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "BlockRunner.h"

NS_ASSUME_NONNULL_BEGIN
/// Dispatches a @c block asynchronously on the given @c dispatch_queue_t queue.
/// @warning Please use the @c -initWithDispatchQueue: initializer, because you
/// must specify the @c queue.
@interface DispatchQueueBlockRunner : NSObject <BlockRunner>

/// Designated initializer. Initializes the object with the given
/// <tt>dispatch queue</tt> which will run the blocks. The @c queue must not be
/// @c nil.
- (instancetype)initWithDispatchQueue:(dispatch_queue_t)queue;

/// Convenience method that returns a block runner with the main dispatch queue.
+ (instancetype)mainQueueRunner;

@end
NS_ASSUME_NONNULL_END

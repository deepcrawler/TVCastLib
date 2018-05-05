//
//  DispatchQueueBlockRunner.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/4/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "DispatchQueueBlockRunner.h"
#import "CommonMacros.h"

@interface DispatchQueueBlockRunner ()

@property (nonatomic, strong, readonly) dispatch_queue_t queue;

@end

@implementation DispatchQueueBlockRunner

#pragma mark - Init

- (instancetype)initWithDispatchQueue:(dispatch_queue_t)queue {
    if ((self = [super init])) {
        _assert_state(nil != queue, @"nil queue is not accepted");
        _queue = queue;
    }

    return self;
}

- (instancetype)init {
    _assert_state(NO, @"Please use the -initWithDispatchQueue: initializer");
    return nil;
}

#pragma mark - Public Methods

- (void)runBlock:(nonnull VoidBlock)block {
    _assert_state(nil != block, @"nil block is not accepted");
    dispatch_async(self.queue, block);
}

+ (instancetype)mainQueueRunner {
    return [[[self class] alloc] initWithDispatchQueue:dispatch_get_main_queue()];
}

#pragma mark - Equality

- (BOOL)isEqual:(id)object {
    DispatchQueueBlockRunner *other = object;
    return self.queue == other.queue;
}

- (NSUInteger)hash {
    return self.queue.hash;
}

@end

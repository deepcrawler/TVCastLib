//
//  SynchronousBlockRunner.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/4/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "SynchronousBlockRunner.h"
#import "CommonMacros.h"

@implementation SynchronousBlockRunner

#pragma mark - BlockRunner

- (void)runBlock:(nonnull VoidBlock)block {
    _assert_state(nil != block, @"nil block is not accepted");

    block();
}

@end

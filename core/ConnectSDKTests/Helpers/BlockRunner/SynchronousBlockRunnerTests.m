//
//  SynchronousBlockRunnerTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/4/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "SynchronousBlockRunner.h"

@interface SynchronousBlockRunnerTests : XCTestCase

@property (strong) SynchronousBlockRunner *runner;

@end

@implementation SynchronousBlockRunnerTests

- (void)setUp {
    [super setUp];

    self.runner = [SynchronousBlockRunner new];
}

- (void)tearDown {
    self.runner = nil;

    [super tearDown];
}

- (void)testClassShouldImplementBlockRunner {
    XCTAssertTrue([self.runner.class conformsToProtocol:@protocol(BlockRunner)]);
}

- (void)testNilBlockShouldNotBeAccepted {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnonnull"
    XCTAssertThrows([self.runner runBlock:nil], @"nil block is not accepted");
#pragma clang diagnostic pop
}

- (void)testBlockShouldBeRunSynchronously {
    __block NSUInteger testValue = 0;
    void(^incrementValueBlock)(void) = ^{
        ++testValue;
    };
    [self.runner runBlock:incrementValueBlock];
    XCTAssertEqual(testValue, 1,
                   @"The block should have synchronously incremented the value");
}

@end

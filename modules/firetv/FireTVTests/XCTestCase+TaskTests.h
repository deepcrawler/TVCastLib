//
//  XCTestCase+TaskTests.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-08.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "XCTestCase+Common.h"

@class BFTask;

/**
 * A category with a few convenience methods for tests using @c BFTask.
 * It may not be very clear what these methods do based on the documentation, so
 * please check the usage examples in tests.
 */
@interface XCTestCase (TaskTests)

/**
 * Checks that a successful void task returned from a stub @c recorder calls the
 * @c SuccessBlock of the operation done in the @c block.
 */
- (void)checkTaskSuccessOnStubRecorder:(OCMStubRecorder *)recorder
      shouldCallSuccessBlockUsingBlock:(ActionBlock)block;
/**
 * Checks that a provided successful @c task returned from a stub @c recorder
 * calls the @c SuccessBlock of the operation done in the @c block.
 */
- (void)checkTaskSuccess:(BFTask *)task
          onStubRecorder:(OCMStubRecorder *)recorder
shouldCallSuccessBlockUsingBlock:(ActionBlock)block;
/**
 * Checks that an error task returned from a stub @c recorder calls the
 * @c FailureBlock of the operation done in the @c block.
 */
- (void)checkTaskErrorOnStubRecorder:(OCMStubRecorder *)recorder
    shouldCallFailureBlockUsingBlock:(ActionBlock)block;

/**
 * Checks that a successful void task returned from a stub @c recorder
 * asynchronously calls the @c SuccessBlock of the operation done in the
 * @c block.
 */
- (void)checkTaskSuccessOnStubRecorder:(OCMStubRecorder *)recorder
 shouldAsyncCallSuccessBlockUsingBlock:(ActionBlock)block;

/// Returns a @c BFTask with an @c NSError.
- (BFTask *)errorTask;

@end

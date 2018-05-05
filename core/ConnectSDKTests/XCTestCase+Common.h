//
//  XCTestCase+Common.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-31.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "Capability.h"

@interface XCTestCase (Common)

/**
 * A block type that should do an action on an SUT (system under test) and use
 * the provided block verifiers as the callbacks to verify they are
 * called/not called according to the check method.
 */
typedef void(^ActionBlock)(SuccessBlock successVerifier,
                           FailureBlock failureVerifier);

/**
 * Checks that the @c FailureBlock of the operation done in the @c block is
 * called with the @c ConnectStatusCodeNotSupported error code.
 */
- (void)checkOperationShouldReturnNotSupportedErrorUsingBlock:(ActionBlock)block;

@end

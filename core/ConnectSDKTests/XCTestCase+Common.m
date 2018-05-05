//
//  XCTestCase+Common.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-31.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "XCTestCase+Common.h"

#import "ConnectError.h"

@implementation XCTestCase (Common)

- (void)checkOperationShouldReturnNotSupportedErrorUsingBlock:(ActionBlock)block {
    NSDictionary *errorInfo = @{NSLocalizedDescriptionKey:@"This feature is not supported."};
    NSError *unsupportedError = [NSError errorWithDomain:ConnectErrorDomain
                                                    code:ConnectStatusCodeNotSupported
                                                userInfo:errorInfo];

    ActionBlock actionBlock = ^(SuccessBlock successVerifier, FailureBlock failureVerifier) {
        SuccessBlock success = ^(id response) {
            XCTFail(@"should be no success");
            successVerifier(nil);
        };
        FailureBlock failure = ^(NSError *error) {
            XCTAssertEqualObjects(error, unsupportedError, @"Error is wrong");
            failureVerifier(nil);
        };
        block(success, failure);
    };

    __block BOOL verified = NO;
    void(^blockCallVerifier)(id) = ^(id object) {
        verified = YES;
    };
    // either block should be called
    actionBlock(blockCallVerifier, blockCallVerifier);

    XCTAssertTrue(verified, @"failure block should be called");
}

@end

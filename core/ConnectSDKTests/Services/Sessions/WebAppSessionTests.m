//
//  WebAppSessionTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-29.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "WebAppSession.h"

#import "XCTestCase+Common.h"

@interface WebAppSessionTests : XCTestCase

@end

@implementation WebAppSessionTests

#pragma mark - Unsupported Methods Tests

- (void)testGetMediaMetadataShouldReturnNotSupportedError {
    [self checkOperationShouldReturnNotSupportedErrorUsingBlock:
        ^(SuccessBlock successVerifier, FailureBlock failureVerifier) {
            WebAppSession *session = [WebAppSession new];
            [session getMediaMetaDataWithSuccess:successVerifier
                                         failure:failureVerifier];
        }];
}

@end

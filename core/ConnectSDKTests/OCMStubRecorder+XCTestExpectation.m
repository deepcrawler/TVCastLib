//
//  OCMStubRecorder+XCTestExpectation.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 4/24/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "OCMStubRecorder+XCTestExpectation.h"

@implementation OCMStubRecorder (XCTestExpectation)

- (id)andFulfillExpectation:(XCTestExpectation *)expectation {
    return [self andDo:^(NSInvocation *invocation) {
        [expectation fulfill];
    }];
}

@end

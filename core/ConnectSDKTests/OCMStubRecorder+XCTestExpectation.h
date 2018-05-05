//
//  OCMStubRecorder+XCTestExpectation.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 4/24/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import <OCMock/OCMStubRecorder.h>

NS_ASSUME_NONNULL_BEGIN
@interface OCMStubRecorder (XCTestExpectation)

/// Convenience method to fulfill an @c XCTestExpectation with a stub.
- (id)andFulfillExpectation:(XCTestExpectation *)expectation;

@end
NS_ASSUME_NONNULL_END

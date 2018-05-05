//
//  AirPlayServiceTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-29.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "AirPlayService_Private.h"

#import "XCTestCase+Common.h"

@interface AirPlayServiceTests : XCTestCase

@end

@implementation AirPlayServiceTests

#pragma mark - Unsupported Methods Tests

- (void)testGetMediaMetadataShouldBeForwardedToHTTPServiceMediaControl {
    AirPlayService *service = OCMPartialMock([AirPlayService new]);

    id /*AirPlayServiceHTTP **/ httpServiceStub = OCMClassMock([AirPlayServiceHTTP class]);
    OCMStub([service createHTTPService]).andReturn(httpServiceStub);

    id /*<MediaControl>*/ mediaControlMock = OCMProtocolMock(@protocol(MediaControl));
    OCMStub([httpServiceStub mediaControl]).andReturn(mediaControlMock);

    SuccessBlock successBlock = ^(id _) {};
    FailureBlock failureBlock = ^(NSError *_) {};
    OCMExpect([mediaControlMock getMediaMetaDataWithSuccess:successBlock
                                                    failure:failureBlock]);

    [service getMediaMetaDataWithSuccess:successBlock
                                 failure:failureBlock];

    OCMVerifyAll(mediaControlMock);
}

@end

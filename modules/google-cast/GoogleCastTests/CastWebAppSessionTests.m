//
//  CastWebAppSessionTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-30.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "CastWebAppSession.h"

@interface CastWebAppSessionTests : XCTestCase

@property (nonatomic, strong) CastWebAppSession *session;

@end

@implementation CastWebAppSessionTests

- (void)setUp {
    [super setUp];

    self.session = [CastWebAppSession new];
}

#pragma mark - Method Implementation Tests

- (void)testSeekShouldBeImplemented {
    [self assertMethodIsImplemented:^{
        [self.session seek:0.0 success:nil failure:nil];
    }];
}

- (void)testGetDurationShouldBeImplemented {
    [self assertMethodIsImplemented:^{
        [self.session getDurationWithSuccess:nil failure:nil];
    }];
}

- (void)testGetPositionShouldBeImplemented {
    [self assertMethodIsImplemented:^{
        [self.session getPositionWithSuccess:nil failure:nil];
    }];
}

- (void)testGetPlayStateShouldBeImplemented {
    [self assertMethodIsImplemented:^{
        [self.session getPlayStateWithSuccess:nil failure:nil];
    }];
}

- (void)testSubscribePlayStateShouldBeImplemented {
    [self assertMethodIsImplemented:^{
        [self.session subscribePlayStateWithSuccess:nil failure:nil];
    }];
}

- (void)testGetMediaMetadataShouldBeImplemented {
    [self assertMethodIsImplemented:^{
        [self.session getMediaMetaDataWithSuccess:nil failure:nil];
    }];
}

- (void)testSubscribeMediaInfoShouldBeImplemented {
    [self assertMethodIsImplemented:^{
        [self.session subscribeMediaInfoWithSuccess:nil failure:nil];
    }];
}

#pragma mark - Helpers

- (void)assertMethodIsImplemented:(void (^)())testBlock {
    XCTAssertNoThrowSpecificNamed(testBlock(), NSException,
                                  NSInvalidArgumentException);
}

@end

//
//  SubtitleInfoTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-14.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "SubtitleInfo.h"

@interface SubtitleInfoTests : XCTestCase

@property (nonatomic, strong) NSURL *url;

@end

@implementation SubtitleInfoTests

- (void)setUp {
    [super setUp];

    self.url = [NSURL URLWithString:@"http://example.com/"];
}

#pragma mark - Init Tests

- (void)testDefaultInitShouldThrowException {
    XCTAssertThrowsSpecificNamed([SubtitleInfo new],
                                 NSException,
                                 NSInternalInconsistencyException,
                                 @"Default initializer is not permitted");
}

- (void)testInfoConstructorShouldNotAcceptNilURL {
    NSURL *nilUrl = [NSURL URLWithString:nil];
    XCTAssertThrowsSpecificNamed([SubtitleInfo infoWithURL:nilUrl],
                                 NSException,
                                 NSInternalInconsistencyException);
}

- (void)testInfoConstructorWithBuilderShouldNotAcceptNilURL {
    NSURL *nilUrl = [NSURL URLWithString:nil];
    XCTAssertThrowsSpecificNamed([SubtitleInfo infoWithURL:nilUrl
                                                  andBlock:^(SubtitleInfoBuilder *_) {
                                                  }],
                                 NSException,
                                 NSInternalInconsistencyException);
}

- (void)testInfoConstructorShouldSetURL {
    SubtitleInfo *info = [SubtitleInfo infoWithURL:self.url];
    XCTAssertEqualObjects(info.url, self.url);
}

- (void)testInfoConstructorShouldLeaveOptionalPropertiesNil {
    SubtitleInfo *info = [SubtitleInfo infoWithURL:self.url];
    XCTAssertNil(info.mimeType);
    XCTAssertNil(info.language);
    XCTAssertNil(info.label);
}

- (void)testBuilderShouldSetProperties {
    SubtitleInfo *info = [SubtitleInfo infoWithURL:self.url
                                          andBlock:^(SubtitleInfoBuilder *builder) {
                                              builder.mimeType = @"text/vtt";
                                              builder.language = @"en";
                                              builder.label = @"Test";
                                          }];

    XCTAssertEqualObjects(info.url, self.url);
    XCTAssertEqualObjects(info.mimeType, @"text/vtt");
    XCTAssertEqualObjects(info.language, @"en");
    XCTAssertEqualObjects(info.label, @"Test");
}

@end

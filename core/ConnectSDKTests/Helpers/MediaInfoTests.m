//
//  MediaInfoTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-20.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "MediaInfo.h"
#import "SubtitleInfo.h"

@interface MediaInfoTests : XCTestCase

@end

@implementation MediaInfoTests

- (void)testClassShouldHaveSubtitleInfoProperty {
    NSURL *url = [NSURL URLWithString:@"http://example.com/"];
    MediaInfo *mediaInfo = [[MediaInfo alloc] initWithURL:url
                                                 mimeType:@"image/png"];

    SubtitleInfo *subtitleInfo = [SubtitleInfo infoWithURL:url];
    mediaInfo.subtitleInfo = subtitleInfo;

    XCTAssertEqualObjects(mediaInfo.subtitleInfo, subtitleInfo);
}

- (void)testDefaultSubtitleInfoShouldBeNil {
    NSURL *url = [NSURL URLWithString:@"http://example.com/"];
    MediaInfo *mediaInfo = [[MediaInfo alloc] initWithURL:url
                                                 mimeType:@"image/png"];
    XCTAssertNil(mediaInfo.subtitleInfo);
}

@end

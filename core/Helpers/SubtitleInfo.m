//
//  SubtitleInfo.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-14.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "SubtitleInfo.h"

#import "CommonMacros.h"

NS_ASSUME_NONNULL_BEGIN
@implementation SubtitleInfo

#pragma mark - Init

- (instancetype)init {
    @throw [NSException exceptionWithName:NSInternalInconsistencyException
                                   reason:@"Please use parameterized initializers to create an instance"
                                 userInfo:nil];
}

+ (instancetype)infoWithURL:(NSURL *)url {
    return [[self alloc] initWithURL:url];
}

+ (instancetype)infoWithURL:(NSURL *)url
                   andBlock:(void (^)(SubtitleInfoBuilder *builder))block {
    SubtitleInfoBuilder *builder = [SubtitleInfoBuilder new];
    block(builder);
    return [[self alloc] initWithURL:url andBuilder:builder];
}

#pragma mark - Private Init

- (instancetype)initWithURL:(NSURL *)url {
    return [self initWithURL:url andBuilder:nil];
}

- (instancetype)initWithURL:(NSURL *)url
                 andBuilder:(nullable SubtitleInfoBuilder *)builder /*NS_DESIGNATED_INITIALIZER*/ {
    _assert_state(nil != url, @"nil URL is not permitted");

    self = [super init];

    _url = url;
    _mimeType = builder.mimeType;
    _language = builder.language;
    _label = builder.label;

    return self;
}

@end


@implementation SubtitleInfoBuilder

@end
NS_ASSUME_NONNULL_END

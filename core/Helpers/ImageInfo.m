//
//  ImageInfo.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 8/14/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "ImageInfo.h"


@implementation ImageInfo

// return nil here so that we force users to have URL and type
- (instancetype) init
{
    return nil;
}

- (instancetype) initWithURL:(NSURL *)url type:(ImageType)type
{
    self = [super init];

    if (self)
    {
        self.url = url;
        self.type = type;
    }

    return self;
}

@end

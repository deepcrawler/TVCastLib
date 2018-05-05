//
//  MediaInfo.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 8/14/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "MediaInfo.h"


@implementation MediaInfo
@synthesize description;

// return nil here so that we force users to have URL and mime-type
- (instancetype) init
{
    return nil;
}

- (instancetype) initWithURL:(NSURL *)url mimeType:(NSString *)mimeType
{
    self = [super init];

    if (self)
    {
        self.url = url;
        self.mimeType = mimeType;

        self.images = [NSArray new];
    }

    return self;
}

- (void) addImage:(ImageInfo *)image
{
    self.images = [self.images arrayByAddingObject:image];
}

- (void) addImages:(NSArray *)images
{
    self.images = [self.images arrayByAddingObjectsFromArray:images];
}

@end

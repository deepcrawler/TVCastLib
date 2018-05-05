//
//  CapabilityFilter.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 1/29/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "CapabilityFilter.h"


@implementation CapabilityFilter

- (instancetype) init
{
    self = [super init];

    if (self)
    {
        _capabilities = [[NSArray alloc] init];
    }

    return self;
}

+ (CapabilityFilter *)filterWithCapabilities:(NSArray *)capabilities
{
    CapabilityFilter *filter = [[CapabilityFilter alloc] init];
    [filter addCapabilities:capabilities];

    return filter;
}

- (void)addCapability:(NSString *)capability
{
    _capabilities = [_capabilities arrayByAddingObject:capability];
}

- (void)addCapabilities:(NSArray *)capabilities
{
    _capabilities = [_capabilities arrayByAddingObjectsFromArray:capabilities];
}

@end

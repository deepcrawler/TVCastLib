//
//  ChannelInfo.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 1/2/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "ChannelInfo.h"

@implementation ChannelInfo

- (BOOL)isEqual:(ChannelInfo *)channelInfo
{
    return [self.number isEqualToString:channelInfo.number]
            && [self.name isEqualToString:channelInfo.name];
}

@end

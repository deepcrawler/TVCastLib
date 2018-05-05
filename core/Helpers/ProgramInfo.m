//
//  ProgramInfo.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 1/19/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "ProgramInfo.h"
#import "ChannelInfo.h"


@implementation ProgramInfo

- (BOOL)isEqual:(ProgramInfo *)programInfo
{
    return [self.id isEqualToString:programInfo.id]
            && [self.name isEqualToString:programInfo.name];
}

@end

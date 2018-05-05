//
//  ExternalInputInfo.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 1/19/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "ExternalInputInfo.h"
#import "AppInfo.h"


@implementation ExternalInputInfo

- (BOOL)isEqual:(ExternalInputInfo *)externalInputInfo
{
    return [self.id isEqualToString:externalInputInfo.id]
            && [self.name isEqualToString:externalInputInfo.name];
}

@end

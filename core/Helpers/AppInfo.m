//
//  AppInfo.m
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 1/3/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "AppInfo.h"

@implementation AppInfo

+ (AppInfo *) appInfoForId:(NSString *)appId
{
    AppInfo *appInfo = [AppInfo new];
    appInfo.id = appId;

    return appInfo;
}

- (BOOL)isEqual:(AppInfo *)appInfo
{
    return [self.id isEqualToString:appInfo.id];
}

@end

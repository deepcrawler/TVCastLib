//
//  NSString+Common.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 3/16/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "NSString+Common.h"

@implementation NSString (Common)

- (NSString *)orEmpty {
    // TODO: replace DeviceService.ensureString()
    return self ?: @"";
}

@end

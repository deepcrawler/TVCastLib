//
//  OCMArg+ArgumentCaptor.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/13/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "OCMArg+ArgumentCaptor.h"

@implementation OCMArg (ArgumentCaptor)

+ (id __nonnull)captureTo:(out id __nullable __strong *__nonnull)objectPointer {
    return [self checkWithBlock:^BOOL(id obj) {
        *objectPointer = obj;
        return YES;
    }];
}

+ (id __nonnull)captureBlockTo:(out VoidBlock __nullable __strong * __nonnull)blockPointer {
    return [self checkWithBlock:^BOOL(id obj) {
        *blockPointer = [obj copy];
        return YES;
    }];
}

@end

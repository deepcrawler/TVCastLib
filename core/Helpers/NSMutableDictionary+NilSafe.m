//
//  NSMutableDictionary+NilSafe.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-23.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "NSMutableDictionary+NilSafe.h"

NS_ASSUME_NONNULL_BEGIN
@implementation NSMutableDictionary (NilSafe)

- (void)setNullableObject:(nullable id)object forKey:(id<NSCopying>)key {
    if (object) {
        self[key] = object;
    }
}

@end
NS_ASSUME_NONNULL_END

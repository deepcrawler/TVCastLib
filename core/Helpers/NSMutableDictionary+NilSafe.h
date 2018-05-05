//
//  NSMutableDictionary+NilSafe.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-23.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSMutableDictionary (NilSafe)

/// Sets the @c object for the @c key; if @c object is @c nil, does nothing.
- (void)setNullableObject:(nullable id)object forKey:(id<NSCopying>)key;

@end
NS_ASSUME_NONNULL_END

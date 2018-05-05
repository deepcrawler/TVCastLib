//
//  CommonMacros.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 3/25/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

/// Asserts a condition about a state, and throws an
/// @c NSInternalInconsistencyException and given message as the reason if it
/// evaluates to @c NO. Similar to @c NSAssert().
static inline void _assert_state(const BOOL condition, NSString *msg) {
    if (!condition) {
        @throw [NSException exceptionWithName:NSInternalInconsistencyException
                                       reason:msg
                                     userInfo:nil];
    }
};

/// Get a property's name as a string. Prevents mistypings when using methods
/// like `valueForKey:`.
/// http://stackoverflow.com/questions/6615826/get-property-name-as-a-string/12623102#12623102
#define STRING_PROPERTY(prop) NSStringFromSelector(@selector(prop))

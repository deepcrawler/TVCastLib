//
//  OCMArg+ArgumentCaptor.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/13/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import <OCMock/OCMArg.h>

NS_ASSUME_NONNULL_BEGIN
@interface OCMArg (ArgumentCaptor)

/// A block type that has no arguments and no return value.
typedef dispatch_block_t VoidBlock;

/// Convenience method to capture an argument for later use/verification.
+ (id)captureTo:(out __strong __nullable id *__nonnull)objectPointer;

/// Convenience method to capture a block argument for later use/verification.
+ (id)captureBlockTo:(out __strong __nullable VoidBlock *__nonnull)blockPointer;

@end
NS_ASSUME_NONNULL_END

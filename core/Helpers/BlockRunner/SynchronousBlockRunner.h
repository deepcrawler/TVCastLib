//
//  SynchronousBlockRunner.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/4/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "BlockRunner.h"

/**
 * Runs a @c block synchronously on the current thread/queue (that is, in the
 * middle of @c -runBlock: call).
 */
@interface SynchronousBlockRunner : NSObject <BlockRunner>

@end

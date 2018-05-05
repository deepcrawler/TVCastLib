//
//  NSString+Common.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 3/16/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import <Foundation/Foundation.h>

@interface NSString (Common)

/// Returns itself if not `nil`, or an empty string otherwise.
- (NSString *)orEmpty;

@end

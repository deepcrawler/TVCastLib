//
//  ConnectUtil.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 3/6/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>


@interface ConnectUtil : NSObject

+ (NSString *) urlEncode:(NSString *)input;
+ (NSString *) urlDecode:(NSString *)input;
+ (NSString *) escapedUnicodeForString:(NSString *)input;

+ (NSString *) entityEncode:(NSString *)input
__deprecated_msg("use proper XML libraries instead");
+ (NSString *) entityDecode:(NSString *)input
__deprecated_msg("use proper XML libraries instead");

@end

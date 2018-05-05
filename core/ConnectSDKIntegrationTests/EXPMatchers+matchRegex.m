//
//  EXPMatchers+matchRegex.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/26/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "EXPMatchers+matchRegex.h"

EXPMatcherImplementationBegin(matchRegex, (NSString *expected)) {
    match(^BOOL {
        NSString *string = actual;
        NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:expected
                                                                               options:0
                                                                                 error:nil];
        NSRange wholeRange = NSMakeRange(0, string.length);
        NSRange matchedRange = [regex rangeOfFirstMatchInString:string
                                                        options:NSMatchingAnchored
                                                          range:wholeRange];
        return NSEqualRanges(matchedRange, wholeRange);
    });

    failureMessageForTo(^NSString * {
        return [NSString stringWithFormat:
                @"expected: a string matching regex %@, got: %@",
                expected, actual];
    });
}
EXPMatcherImplementationEnd

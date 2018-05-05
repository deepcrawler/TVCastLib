//
//  BlockRunnerTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/4/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "BlockRunner.h"

#import <objc/runtime.h>

@interface BlockRunnerTests : XCTestCase

@end

@implementation BlockRunnerTests

- (void)testProtocolShouldInheritFromNSObject {
    XCTAssertTrue(protocol_conformsToProtocol(@protocol(BlockRunner),
                                              @protocol(NSObject)),
                  @"BlockRunner should inherit from NSObject");
}

- (void)testProtocolShouldHaveRunBlockMethod {
    struct objc_method_description desc = protocol_getMethodDescription(@protocol(BlockRunner),
                                                                        @selector(runBlock:),
                                                                        YES,
                                                                        YES);
    XCTAssertNotEqual(desc.name, NULL, @"runBlock: should be defined");
    XCTAssertNotEqual(desc.types, NULL, @"runBlock: should be defined");
}

@end

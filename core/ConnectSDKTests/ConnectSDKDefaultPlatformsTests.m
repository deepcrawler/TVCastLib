//
//  TVCastLibDefaultPlatformsTests.m
//  TVCastLibDefaultPlatformsTests
//
//  Created by Eugene Nikolskyi on 11/11/14.
//  Copyright (c) 2014 Hamed Ghaderipour. All rights reserved.
//

//


#import "TVCastLibDefaultPlatforms.h"

/// Tests for the TVCastLib's default platforms list.
@interface TVCastLibDefaultPlatformsTests : XCTestCase

@end

@implementation TVCastLibDefaultPlatformsTests

/// Tests that the default platforms list is defined and not empty.
- (void)testThereShouldBeDefaultPlatforms {
    NSDictionary *platforms = kTVCastLibDefaultPlatforms;
    XCTAssertGreaterThan(platforms.count, 0, @"The default platforms list must not be empty");
}

/// Tests that the default service classes are available in runtime.
/// NB: the success of this test relies on the test target's setup.
- (void)testServiceClassesAreAvailable {
    NSDictionary *platforms = kTVCastLibDefaultPlatforms;
    [platforms enumerateKeysAndObjectsWithOptions:NSEnumerationConcurrent
                                       usingBlock:^(NSString *key, id obj, BOOL *stop) {
                                           XCTAssertNotNil(NSClassFromString(key),
                                                           @"Service class %@ must be available at runtime", key);
                                       }];
}

/// Tests that the default discovery provider classes are available at runtime.
/// NB: the success of this test relies on the test target's setup.
- (void)testDiscoveryProviderClassesAreAvailable {
    NSDictionary *platforms = kTVCastLibDefaultPlatforms;
    // we get the unique providers only because one can be used for different
    // services
    NSSet *uniqueDiscoveryProviders = [NSSet setWithArray:platforms.allValues];
    [uniqueDiscoveryProviders enumerateObjectsWithOptions:NSEnumerationConcurrent
                                               usingBlock:^(NSString *obj, BOOL *stop) {
                                                   XCTAssertNotNil(NSClassFromString(obj),
                                                                   @"Discovery provider class %@ must be available at runtime", obj);
                                               }];
}

@end

//
//  NSMutableDictionary+NilSafeTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-23.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "NSMutableDictionary+NilSafe.h"

@interface NSMutableDictionary_NilSafeTests : XCTestCase

@property(nonatomic, strong) NSMutableDictionary *dict;

@end

@implementation NSMutableDictionary_NilSafeTests

#pragma mark - Setup

- (void)setUp {
    [super setUp];
    self.dict = [NSMutableDictionary dictionary];
}

#pragma mark - Tests

- (void)testShouldSetNotNullObject {
    [self.dict setNullableObject:@42 forKey:@"key"];
    XCTAssertEqualObjects(self.dict[@"key"], @42);
}

- (void)testShouldNotSetNil {
    [self.dict setNullableObject:nil forKey:@"key"];
    XCTAssertNil(self.dict[@"key"]);
}

- (void)testNonNullObjectShouldOverwriteExistingObject {
    self.dict[@"key"] = @0;
    [self.dict setNullableObject:@42 forKey:@"key"];
    XCTAssertEqualObjects(self.dict[@"key"], @42);
}

- (void)testNilObjectShouldNotOverwriteExistingObject {
    self.dict[@"key"] = @0;
    [self.dict setNullableObject:nil forKey:@"key"];
    XCTAssertEqualObjects(self.dict[@"key"], @0);
}

@end

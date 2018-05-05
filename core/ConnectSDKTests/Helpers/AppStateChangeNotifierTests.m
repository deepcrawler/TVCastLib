//
//  AppStateChangeNotifierTests.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/15/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "AppStateChangeNotifier.h"
#import "DispatchQueueBlockRunner.h"
#import "SynchronousBlockRunner.h"

@interface AppStateChangeNotifierTests : XCTestCase

@property (strong) AppStateChangeNotifier *notifier;

@end

@implementation AppStateChangeNotifierTests

#pragma mark - Setup

- (void)setUp {
    [super setUp];

    self.notifier = [AppStateChangeNotifier new];
    self.notifier.blockRunner = [SynchronousBlockRunner new];
}

- (void)tearDown {
    [self.notifier stopListening];
    self.notifier = nil;

    [super tearDown];
}

#pragma mark - General Tests

- (void)testDefaultBlockRunnerShouldBeMainQueueRunner {
    AppStateChangeNotifier *notifier = [AppStateChangeNotifier new];
    XCTAssertEqualObjects(notifier.blockRunner,
                          [DispatchQueueBlockRunner mainQueueRunner],
                          @"blocks should run on main queue by default");
}

#pragma mark - DidEnterBackground Notification Tests

- (void)testStartListeningShouldSubscribeToDidBackgroundEvent {
    [self.notifier startListening];

    __block BOOL verified = NO;
    self.notifier.didBackgroundBlock = ^() {
        verified = YES;
    };
    [self postNotificationName:UIApplicationDidEnterBackgroundNotification];

    XCTAssertTrue(verified, @"didBackgroundBlock should be called");
}

// idempotence test
- (void)testStartListeningTwiceShouldSubscribeToDidBackgroundEventOnce {
    [self.notifier startListening];
    [self.notifier startListening];

    __block NSUInteger callCount = 0;
    self.notifier.didBackgroundBlock = ^() {
        ++callCount;
    };
    [self postNotificationName:UIApplicationDidEnterBackgroundNotification];

    XCTAssertEqual(callCount, 1, @"didBackgroundBlock should be called once");
}

- (void)testStopListeningShouldUnsubscribeFromDidBackgroundEvent {
    [self.notifier startListening];
    [self.notifier stopListening];

    __block BOOL verified = NO;
    self.notifier.didBackgroundBlock = ^() {
        verified = YES;
    };
    [self postNotificationName:UIApplicationDidEnterBackgroundNotification];

    XCTAssertFalse(verified, @"didBackgroundBlock should not be called after "
                   @"stopping listening");
}

// idempotence test
- (void)testStopListeningTwiceShouldUnsubscribeFromDidBackgroundEventOnce {
    [self.notifier startListening];
    [self.notifier stopListening];
    [self.notifier stopListening];

    __block BOOL verified = NO;
    self.notifier.didBackgroundBlock = ^() {
        verified = YES;
    };
    [self postNotificationName:UIApplicationDidEnterBackgroundNotification];

    XCTAssertFalse(verified, @"didBackgroundBlock should not be called after "
                   @"stopping listening");
}

- (void)testDidBackgroundBlockShouldBeCalledOnGivenQueue {
    dispatch_queue_t queue = dispatch_queue_create("test", DISPATCH_QUEUE_SERIAL);
    self.notifier.blockRunner = [[DispatchQueueBlockRunner alloc] initWithDispatchQueue:queue];
    [self.notifier startListening];

    XCTestExpectation *blockIsCalled = [self expectationWithDescription:
                                        @"didBackgroundBlock is called"];
    self.notifier.didBackgroundBlock = ^() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Warc-retain-cycles"
        XCTAssertEqual(dispatch_get_current_queue(), queue);
#pragma clang diagnostic pop
        [blockIsCalled fulfill];
    };
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        [self postNotificationName:UIApplicationDidEnterBackgroundNotification];
    });

    [self waitForExpectationsWithTimeout:kDefaultAsyncTestTimeout handler:nil];
}

#pragma mark - DidBecomeActive Notification Tests

- (void)testStartListeningShouldSubscribeToDidBecomeActiveEvent {
    [self.notifier startListening];

    __block BOOL verified = NO;
    self.notifier.didForegroundBlock = ^() {
        verified = YES;
    };
    [self postNotificationName:UIApplicationDidBecomeActiveNotification];

    XCTAssertTrue(verified, @"didForegroundBlock should be called");
}

// idempotence test
- (void)testStartListeningTwiceShouldSubscribeToDidBecomeActiveEventOnce {
    [self.notifier startListening];
    [self.notifier startListening];

    __block NSUInteger callCount = 0;
    self.notifier.didForegroundBlock = ^() {
        ++callCount;
    };
    [self postNotificationName:UIApplicationDidBecomeActiveNotification];

    XCTAssertEqual(callCount, 1, @"didForegroundBlock should be called once");
}

- (void)testStopListeningShouldUnsubscribeFromDidBecomeActiveEvent {
    [self.notifier startListening];
    [self.notifier stopListening];

    __block BOOL verified = NO;
    self.notifier.didForegroundBlock = ^() {
        verified = YES;
    };
    [self postNotificationName:UIApplicationDidBecomeActiveNotification];

    XCTAssertFalse(verified, @"didForegroundBlock should not be called after "
                   @"stopping listening");
}

// idempotence test
- (void)testStopListeningTwiceShouldUnsubscribeFromDidBecomeActiveEventOnce {
    [self.notifier startListening];
    [self.notifier stopListening];
    [self.notifier stopListening];

    __block BOOL verified = NO;
    self.notifier.didForegroundBlock = ^() {
        verified = YES;
    };
    [self postNotificationName:UIApplicationDidBecomeActiveNotification];

    XCTAssertFalse(verified, @"didBackgroundBlock should not be called after "
                   @"stopping listening");
}

- (void)testDidForegroundBlockShouldBeCalledOnGivenQueue {
    dispatch_queue_t queue = dispatch_queue_create("test", DISPATCH_QUEUE_SERIAL);
    self.notifier.blockRunner = [[DispatchQueueBlockRunner alloc] initWithDispatchQueue:queue];
    [self.notifier startListening];

    XCTestExpectation *blockIsCalled = [self expectationWithDescription:
                                        @"didForegroundBlock is called"];
    self.notifier.didForegroundBlock = ^() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Warc-retain-cycles"
        XCTAssertEqual(dispatch_get_current_queue(), queue);
#pragma clang diagnostic pop
        [blockIsCalled fulfill];
    };
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        [self postNotificationName:UIApplicationDidBecomeActiveNotification];
    });

    [self waitForExpectationsWithTimeout:kDefaultAsyncTestTimeout handler:nil];
}

#pragma mark - Helpers

- (void)postNotificationName:(NSString *)name {
    NSNotificationCenter *center = [NSNotificationCenter defaultCenter];
    [center postNotificationName:name
                          object:[UIApplication sharedApplication]];

}

@end

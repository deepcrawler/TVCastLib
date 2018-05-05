//
//  FireTVDiscoveryProvider_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-08.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "FireTVDiscoveryProvider.h"

#import <AmazonFling/DiscoveryController.h>

@protocol BlockRunner;

NS_ASSUME_NONNULL_BEGIN
@interface FireTVDiscoveryProvider () <DiscoveryListener>

/// Initializes the instance with the given @c DiscoveryController. Using @c nil
/// parameter will create a real object.
- (instancetype)initWithDiscoveryController:(nullable DiscoveryController *)controller;

/// The @c DiscoveryController object to control.
@property (nonatomic, strong, readonly) DiscoveryController *flingDiscoveryController;

/// The @c BlockRunner instance specifying where to run delegate callbacks. The
/// default value is the main dispatch queue runner. Cannot be @c nil, as it
/// will reset to the default value.
@property (nonatomic, strong) id<BlockRunner> delegateBlockRunner;

@end
NS_ASSUME_NONNULL_END

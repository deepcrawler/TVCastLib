//
//  NSObject+FeatureNotSupported_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-31.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "Capability.h"

@class ServiceSubscription;

NS_ASSUME_NONNULL_BEGIN
@interface NSObject (FeatureNotSupported)

/**
 * Calls the @c failure block with an unsupported error. Returns @c nil.
 *
 * @remarks It would be better to define this category on @c DeviceService
 * class, but a couple of other classes use this method as well.
 */
- (nullable ServiceSubscription *)sendNotSupportedFailure:(nullable FailureBlock)failure;

@end
NS_ASSUME_NONNULL_END

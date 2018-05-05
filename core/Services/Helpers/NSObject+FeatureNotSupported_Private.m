//
//  NSObject+FeatureNotSupported_Private.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-31.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "NSObject+FeatureNotSupported_Private.h"

#import "ConnectError.h"

NS_ASSUME_NONNULL_BEGIN
@implementation NSObject (FeatureNotSupported)

- (nullable ServiceSubscription *)sendNotSupportedFailure:(nullable FailureBlock)failure {
    if (failure) {
        failure([ConnectError generateErrorWithCode:ConnectStatusCodeNotSupported
                                         andDetails:nil]);
    }

    return nil;
}

@end
NS_ASSUME_NONNULL_END

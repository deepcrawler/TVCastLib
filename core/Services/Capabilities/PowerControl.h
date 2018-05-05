//
//  PowerControl.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 1/19/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "Capability.h"

#define kPowerControlAny @"PowerControl.Any"

#define kPowerControlOff @"PowerControl.Off"
#define kPowerControlOn @"PowerControl.On"

#define kPowerControlCapabilities @[\
    kPowerControlOff,\
    kPowerControlOn\
]

@protocol PowerControl <NSObject>

- (id<PowerControl>)powerControl;
- (CapabilityPriorityLevel)powerControlPriority;

- (void) powerOffWithSuccess:(SuccessBlock)success failure:(FailureBlock)failure;
- (void) powerOnWithSuccess:(SuccessBlock)success failure:(FailureBlock)failure;

@end

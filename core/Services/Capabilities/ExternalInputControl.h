//
//  ExternalInputControl.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 1/19/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "Capability.h"
#import "ExternalInputInfo.h"
#import "AppInfo.h"

#define kExternalInputControlAny @"ExternalInputControl.Any"

#define kExternalInputControlPickerLaunch @"ExternalInputControl.Picker.Launch"
#define kExternalInputControlPickerClose @"ExternalInputControl.Picker.Close"
#define kExternalInputControlList @"ExternalInputControl.List"
#define kExternalInputControlSet @"ExternalInputControl.Set"

#define kExternalInputControlCapabilities @[\
    kExternalInputControlPickerLaunch,\
    kExternalInputControlPickerClose,\
    kExternalInputControlList,\
    kExternalInputControlSet\
]

@protocol ExternalInputControl <NSObject>

/*!
 * Success block that is called upon successfully getting the external input list.
 *
 * @param externalInputList Array containing an ExternalInputInfo object for each available external input on the device
 */
typedef void (^ ExternalInputListSuccessBlock)(NSArray *externalInputList);

- (id<ExternalInputControl>)externalInputControl;
- (CapabilityPriorityLevel)externalInputControlPriority;

- (void)launchInputPickerWithSuccess:(AppLaunchSuccessBlock)success failure:(FailureBlock)failure;
- (void)closeInputPicker:(LaunchSession *)launchSession success:(SuccessBlock)success failure:(FailureBlock)failure;

- (void) getExternalInputListWithSuccess:(ExternalInputListSuccessBlock)success failure:(FailureBlock)failure;
- (void) setExternalInput:(ExternalInputInfo *)externalInputInfo success:(SuccessBlock)success failure:(FailureBlock)failure;

@end

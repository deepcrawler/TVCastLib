//
//  VolumeControl.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/16/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "Capability.h"
#import "ServiceSubscription.h"

#define kVolumeControlAny @"VolumeControl.Any"

#define kVolumeControlVolumeGet @"VolumeControl.Get"
#define kVolumeControlVolumeSet @"VolumeControl.Set"
#define kVolumeControlVolumeUpDown @"VolumeControl.UpDown"
#define kVolumeControlVolumeSubscribe @"VolumeControl.Subscribe"
#define kVolumeControlMuteGet @"VolumeControl.Mute.Get"
#define kVolumeControlMuteSet @"VolumeControl.Mute.Set"
#define kVolumeControlMuteSubscribe @"VolumeControl.Mute.Subscribe"

#define kVolumeControlCapabilities @[\
    kVolumeControlVolumeGet,\
    kVolumeControlVolumeSet,\
    kVolumeControlVolumeUpDown,\
    kVolumeControlVolumeSubscribe,\
    kVolumeControlMuteGet,\
    kVolumeControlMuteSet,\
    kVolumeControlMuteSubscribe\
]

@protocol VolumeControl <NSObject>

/*!
 * Success block that is called upon successfully getting the device's system volume.
 *
 * @param volume Current system volume, value is a float between 0.0 and 1.0
 */
typedef void (^ VolumeSuccessBlock)(float volume);

/*!
 * Success block that is called upon successfully getting the device's system mute status.
 *
 * @param mute Current system mute status
 */
typedef void (^ MuteSuccessBlock)(BOOL mute);

- (id<VolumeControl>)volumeControl;
- (CapabilityPriorityLevel)volumeControlPriority;

#pragma mark Volume
- (void) volumeUpWithSuccess:(SuccessBlock)success failure:(FailureBlock)failure;
- (void) volumeDownWithSuccess:(SuccessBlock)success failure:(FailureBlock)failure;

- (void) getVolumeWithSuccess:(VolumeSuccessBlock)success failure:(FailureBlock)failure;
- (void) setVolume:(float)volume success:(SuccessBlock)success failure:(FailureBlock)failure;

- (ServiceSubscription *)subscribeVolumeWithSuccess:(VolumeSuccessBlock)success failure:(FailureBlock)failure;

#pragma mark Mute
- (void) getMuteWithSuccess:(MuteSuccessBlock)success failure:(FailureBlock)failure;
- (void) setMute:(BOOL)mute success:(SuccessBlock)success failure:(FailureBlock)failure;

- (ServiceSubscription *)subscribeMuteWithSuccess:(MuteSuccessBlock)success failure:(FailureBlock)failure;

@end

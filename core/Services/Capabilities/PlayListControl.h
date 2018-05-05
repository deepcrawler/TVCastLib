//
//  PlayListControl.h
//  TVCastLib
//
//  Created by Ibrahim Adnan on 1/19/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol PlayListControl <NSObject>

#define kPlayListControlNext @"PlayListControl.Next"
#define kPlayListControlPrevious @"PlayListControl.Previous"
#define kPlayListControlJumpTrack @"PlayListControl.JumpTrack"

#define kPlayListControlCapabilities @[\
    kPlayListControlNext,\
    kPlayListControlPrevious,\
    kPlayListControlJumpTrack\
]

- (id<PlayListControl>) playListControl;
- (CapabilityPriorityLevel) playListControlPriority;

#pragma mark Playlist controls
/*!
 * Plays the next track in the playlist
 */
- (void) playNextWithSuccess:(SuccessBlock)success failure:(FailureBlock)failure;
/*!
 * Plays the previous track in the playlist
 * @param device ConnectableDevice that has been disconnected.
 */
- (void) playPreviousWithSuccess:(SuccessBlock)success failure:(FailureBlock)failure;
/*!
 * Jumps to track in the playlist
 *
 * @param index NSInteger a zero based index parameter.
 */
- (void)jumpToTrackWithIndex:(NSInteger)index success:(SuccessBlock)success failure:(FailureBlock)failure;


@end

//
//  MediaPlayer.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/16/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "Capability.h"
#import "Launcher.h"
#import "MediaControl.h"
#import "MediaInfo.h"
#import "MediaLaunchObject.h"

#define kMediaPlayerAny @"MediaPlayer.Any"

#define kMediaPlayerDisplayImage @"MediaPlayer.Display.Image"
#define kMediaPlayerPlayVideo @"MediaPlayer.Play.Video"
#define kMediaPlayerPlayAudio @"MediaPlayer.Play.Audio"
#define kMediaPlayerPlayPlaylist @"MediaPlayer.Play.Playlist"
#define kMediaPlayerLoop @"MediaPlayer.Loop"
#define kMediaPlayerClose @"MediaPlayer.Close"

#define kMediaPlayerMetaDataTitle @"MediaPlayer.MetaData.Title"
#define kMediaPlayerMetaDataDescription @"MediaPlayer.MetaData.Description"
#define kMediaPlayerMetaDataThumbnail @"MediaPlayer.MetaData.Thumbnail"
#define kMediaPlayerMetaDataMimeType @"MediaPlayer.MetaData.MimeType"

extern NSString *const kMediaPlayerSubtitleSRT;
extern NSString *const kMediaPlayerSubtitleWebVTT;


#define kMediaPlayerCapabilities @[\
    kMediaPlayerDisplayImage,\
    kMediaPlayerPlayVideo,\
    kMediaPlayerPlayAudio,\
    kMediaPlayerClose,\
    kMediaPlayerMetaDataTitle,\
    kMediaPlayerMetaDataDescription,\
    kMediaPlayerMetaDataThumbnail,\
    kMediaPlayerMetaDataMimeType\
]

@protocol MediaPlayer <NSObject>

/*!
 * Success block that is called upon successfully playing/displaying a media file.
 *
 * @param launchSession LaunchSession to allow closing this media player
 * @param mediaControl MediaControl object used to control playback
 */
typedef void (^MediaPlayerDisplaySuccessBlock)(LaunchSession *launchSession, id<MediaControl> mediaControl);
typedef void (^MediaPlayerSuccessBlock)(MediaLaunchObject *mediaLaunchObject);


- (id<MediaPlayer>) mediaPlayer;
- (CapabilityPriorityLevel) mediaPlayerPriority;

- (void) displayImageWithMediaInfo:(MediaInfo *)mediaInfo
                           success:(MediaPlayerSuccessBlock)success
                           failure:(FailureBlock)failure;

- (void) playMediaWithMediaInfo:(MediaInfo *)mediaInfo
                     shouldLoop:(BOOL)shouldLoop
                        success:(MediaPlayerSuccessBlock)success
                        failure:(FailureBlock)failure;

- (void) closeMedia:(LaunchSession *)launchSession
            success:(SuccessBlock)success
            failure:(FailureBlock)failure;

#pragma mark - Deprecated Methods

- (void) displayImage:(NSURL *)imageURL
              iconURL:(NSURL *)iconURL
                title:(NSString *)title
          description:(NSString *)description
             mimeType:(NSString *)mimeType
              success:(MediaPlayerDisplaySuccessBlock)success
              failure:(FailureBlock)failure
__deprecated_msg("Please use displayImageWithMediaInfo:success:failure: instead");

- (void) displayImage:(MediaInfo *)mediaInfo
              success:(MediaPlayerDisplaySuccessBlock)success
              failure:(FailureBlock)failure
__deprecated_msg("Please use displayImageWithMediaInfo:success:failure: instead");

- (void) playMedia:(NSURL *)mediaURL
           iconURL:(NSURL *)iconURL
             title:(NSString *)title
       description:(NSString *)description
          mimeType:(NSString *)mimeType
        shouldLoop:(BOOL)shouldLoop
           success:(MediaPlayerDisplaySuccessBlock)success
           failure:(FailureBlock)failure
__deprecated_msg("Please use playMediaWithMediaInfo:shouldLoop:success:failure: instead");

- (void) playMedia:(MediaInfo *)mediaInfo
        shouldLoop:(BOOL)shouldLoop
           success:(MediaPlayerDisplaySuccessBlock)success
           failure:(FailureBlock)failure
__deprecated_msg("Please use playMediaWithMediaInfo:shouldLoop:success:failure: instead");

@end

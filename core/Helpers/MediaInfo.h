//
//  MediaInfo.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 8/14/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "ImageInfo.h"

@class SubtitleInfo;

/*!
 * Normalized reference object for information about a media file to be sent to a device through the MediaPlayer capability. "Media file", in this context, refers to an audio or video resource.
 */
@interface MediaInfo : NSObject

/*! URL source of the media file */
@property (nonatomic, strong) NSURL *url;

/*! Mime-type of the media file */
@property (nonatomic, strong) NSString *mimeType;

/*! Title of the media file (optional) */
@property (nonatomic, strong) NSString *title;

/*! Short description of the media file (optional) */
@property (nonatomic, strong) NSString *description;

/*! Duration of the media file */
@property (nonatomic) NSTimeInterval duration;

/*! Collection of ImageInfo objects to send, as necessary, to the device when launching media through the MediaPlayer capability. */
@property (nonatomic, strong) NSArray *images;

/// Subtitle track for this media instance (optional).
@property (nonatomic, strong) SubtitleInfo *subtitleInfo;


/**
 * Creates an instance of MediaInfo with given property values.
 *
 * @param url URL source of the media file
 * @param mimeType Mime-type of the media file
 */
- (instancetype) initWithURL:(NSURL *)url mimeType:(NSString *)mimeType;

/*!
 * Adds an ImageInfo object to the array of images.
 *
 * @param image ImageInfo object to be added
 */
- (void) addImage:(ImageInfo *)image;

/*!
 * Adds an array of ImageInfo objects to the array of images.
 *
 * @param images Array of ImageInfo objects to be added
 */
- (void) addImages:(NSArray *)images;

@end

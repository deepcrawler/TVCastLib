//
//  DLNAService_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 11/13/14.
//  Copyright (c) 2014 Hamed Ghaderipour. All rights reserved.
//

//

#import "DLNAService.h"

extern NSString *const kDataFieldName;

@class DeviceServiceReachability;
@class DLNAHTTPServer;

@interface DLNAService ()

@property (nonatomic, strong) id<ServiceCommandDelegate> serviceCommandDelegate;

@property (nonatomic, strong) NSURL *avTransportControlURL;
@property (nonatomic, strong) NSURL *avTransportEventURL;
@property (nonatomic, strong) NSURL *renderingControlControlURL;
@property (nonatomic, strong) NSURL *renderingControlEventURL;

- (NSURL*)serviceURLForPath:(NSString *)path;
/// Parses and returns a metadata dictionary from the @c metaDataXML string.
- (NSDictionary *)parseMetadataDictionaryFromXMLString:(NSString *)metadataXML;

/// Creates a new @c DLNAHTTPServer instance.
- (DLNAHTTPServer *)createDLNAHTTPServer;
/// Creates a new @c DeviceServiceReachability instance with the given target URL.
- (DeviceServiceReachability *)createDeviceServiceReachabilityWithTargetURL:(NSURL *)url;

@end

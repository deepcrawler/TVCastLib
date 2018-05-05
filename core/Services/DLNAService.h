//
//  DLNAService.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/13/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#define kTVCastLibDLNAServiceId @"DLNA"

#import "DeviceService.h"
#import "MediaControl.h"
#import "MediaPlayer.h"
#import "VolumeControl.h"
#import "PlayListControl.h"

@interface DLNAService : DeviceService <MediaPlayer, MediaControl, VolumeControl, PlayListControl>

@end

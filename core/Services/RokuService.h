//
//  RokuService.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 2/14/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#define kTVCastLibRokuServiceId @"Roku"

#import "DIALService.h"
#import "MediaControl.h"
#import "MediaPlayer.h"
#import "KeyControl.h"
#import "TextInputControl.h"

enum
{
    RokuKeyCodeHome,
    RokuKeyCodeRewind,
    RokuKeyCodeFastForward,
    RokuKeyCodePlay,
    RokuKeyCodeSelect,
    RokuKeyCodeLeft,
    RokuKeyCodeRight,
    RokuKeyCodeDown,
    RokuKeyCodeUp,
    RokuKeyCodeBack,
    RokuKeyCodeInstantReplay,
    RokuKeyCodeInfo,
    RokuKeyCodeBackspace,
    RokuKeyCodeSearch,
    RokuKeyCodeEnter,
    RokuKeyCodeLiteral
};

// @cond INTERNAL
typedef NSUInteger RokuKeyCode;

#define kRokuKeyCodes @[ @"Home", @"Rev", @"Fwd", @"Play", @"Select", @"Left", @"Right", @"Down", @"Up", @"Back", @"InstantReplay", @"Info", @"Backspace", @"Search", @"Enter", @"Lit_" ]
// @endcond

@interface RokuService : DeviceService <Launcher, MediaPlayer, MediaControl, KeyControl, TextInputControl>

// @cond INTERNAL
- (void)sendKeyCode:(RokuKeyCode)keyCode success:(SuccessBlock)success failure:(FailureBlock)failure;
// @endcond

+ (void) registerApp:(NSString *)appId;

@end

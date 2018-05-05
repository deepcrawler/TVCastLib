//
//  DIALService.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/13/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#define kTVCastLibDIALServiceId @"DIAL"

#import "DeviceService.h"
#import "ServiceCommandDelegate.h"
#import "Launcher.h"

@interface DIALService : DeviceService <ServiceCommandDelegate, Launcher>

+ (void) registerApp:(NSString *)appId;

@end

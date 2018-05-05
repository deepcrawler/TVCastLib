//
//  CastService_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-24.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "CastService.h"

@interface CastService ()

- (GCKDeviceManager *)createDeviceManagerWithDevice:(GCKDevice *)device
                               andClientPackageName:(NSString *)clientPackageName;
- (GCKMediaControlChannel *)createMediaControlChannel;

@end

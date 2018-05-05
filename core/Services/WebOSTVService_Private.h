//
//  WebOSTVService_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-08-04.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "WebOSTVService.h"

@interface WebOSTVService ()

@property (nonatomic, strong) id<ServiceCommandDelegate> serviceCommandDelegate;

- (DeviceService *)dlnaService;

- (WebOSWebAppSession *)createWebAppSessionWithLaunchSession:(LaunchSession *)launchSession
                                                  andService:(WebOSTVService *)service;

@end

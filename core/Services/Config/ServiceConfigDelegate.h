//
//  ServiceConfigDelegate.h
//  TVCastLib
//
//  Created by Andrew Longstaff on 9/12/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>

@class ServiceConfig;

@protocol ServiceConfigDelegate <NSObject>

- (void) serviceConfigUpdate:(ServiceConfig*)serviceConfig;

@end

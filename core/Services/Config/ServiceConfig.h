//
//  ServiceConfig.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/9/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "ServiceDescription.h"
#import "ServiceConfigDelegate.h"
#import "JSONObjectCoding.h"

@interface ServiceConfig :  NSObject <JSONObjectCoding>

@property (nonatomic, strong) NSString *UUID;
@property (nonatomic) BOOL connected;
@property (nonatomic) BOOL wasConnected;
@property (nonatomic) double lastDetection;

@property (nonatomic, weak) id<ServiceConfigDelegate> delegate;

+ (instancetype) serviceConfigWithJSONObject:(NSDictionary *)dictionary;
- (instancetype) initWithServiceConfig:(ServiceConfig *)serviceConfig;
- (instancetype) initWithServiceDescription:(ServiceDescription *)serviceDescription;
- (void) addObservers;
- (void) removeObservers;

@end

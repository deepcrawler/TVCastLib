//
//  ServiceDescription.h
//  TVCastLib
//
//  Created by Andrew Longstaff on 9/6/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "JSONObjectCoding.h"

@interface ServiceDescription : NSObject <JSONObjectCoding, NSCopying>

@property (nonatomic, strong) NSString *address;
@property (nonatomic, strong) NSString *serviceId;
@property (nonatomic) NSUInteger port;
@property (nonatomic, strong) NSString *UUID;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *version;
@property (nonatomic, strong) NSString *friendlyName;
@property (nonatomic, strong) NSString *manufacturer;
@property (nonatomic, strong) NSString *modelName;
@property (nonatomic, strong) NSString *modelDescription;
@property (nonatomic, strong) NSString *modelNumber;
@property (nonatomic, strong) NSURL *commandURL;
@property (nonatomic, strong) NSString *locationXML;
@property (nonatomic, strong) NSArray *serviceList;
@property (nonatomic, strong) NSDictionary *locationResponseHeaders;
@property (nonatomic) double lastDetection;
/**
 * @brief A device object set by a discovery provider when a service requires it (that is, it is the
 * only way to control the remote device).
 *
 * For example, @c CastService requires a @c GCKDevice object retrieved during discovery in
 * <tt>CastDiscoveryProvider</tt>. On the other hand, @c DLNAService doesn't require any specific
 * object, because it works via HTTP using other properties.
 * @note The service is responsible for checking that the property is of the expected type.
 */
@property (nonatomic, strong) id device;

- (instancetype)initWithAddress:(NSString *)address UUID:(NSString*)UUID;
+ (instancetype)descriptionWithAddress:(NSString *)address UUID:(NSString*)UUID;

- (BOOL)isEqualToServiceDescription:(ServiceDescription *)service;

@end

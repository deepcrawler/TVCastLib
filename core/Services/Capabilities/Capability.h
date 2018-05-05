//
//  Capability.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/26/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>

/*!
 * CapabilityPriorityLevel values are used by ConnectableDevice to find the most suitable DeviceService capability to be presented to the user. Values of VeryLow and VeryHigh are not in use internally the SDK. TVCastLib uses Low, Normal, and High internally.
 *
 * Default behavior:
 * If you are unsatisfied with the default priority levels & behavior of TVCastLib, it is possible to subclass a particular DeviceService and provide your own value for each capability. That DeviceService subclass would need to be registered with DiscoveryManager.
 */
typedef enum {
    CapabilityPriorityLevelVeryLow = 1,
    CapabilityPriorityLevelLow = 25,
    CapabilityPriorityLevelNormal = 50,
    CapabilityPriorityLevelHigh = 75,
    CapabilityPriorityLevelVeryHigh = 100
} CapabilityPriorityLevel;

/*!
 * Generic asynchronous operation response success handler block. If there is any response data to be processed, it will be provided via the responseObject parameter.
 *
 * @param responseObject Contains the output data as a generic object reference. This value may be any of a number of types (NSString, NSDictionary, NSArray, etc). It is also possible that responseObject will be nil for operations that don't require data to be returned (move mouse, send key code, etc).
 */
typedef void (^ SuccessBlock)(id responseObject);

/*!
 * Generic asynchronous operation response error handler block. In all cases, you will get a valid NSError object. TVCastLib will make all attempts to give you the lowest-level error possible. In cases where an error is generated by TVCastLib, an enumerated error code (ConnectStatusCode) will be present on the NSError object.
 *
 * ###Low-level error example
 * ####Situation
 * TVCastLib receives invalid XML from a device, generating a parsing error
 *
 * ####Result
 * TVCastLib will call the FailureBlock and pass off the NSError generated during parsing of the XML.
 *
 * ###High-level error example
 * ####Situation
 * An invalid value is passed to a device capability method
 *
 * ####Result
 * The capability method will immediately invoke the FailureBlock and pass off an NSError object with a status code of ConnectStatusCodeArgumentError.
 *
 * @param error NSError object describing the nature of the problem. Error descriptions are not localized and mostly intended for developer use. It is not recommended to display most error descriptions in UI elements.
 */
typedef void (^ FailureBlock)(NSError *error);
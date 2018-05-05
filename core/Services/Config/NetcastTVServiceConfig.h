//
//  NetcastTVServiceConfig.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/30/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "ServiceConfig.h"

@interface NetcastTVServiceConfig : ServiceConfig <JSONObjectCoding>

@property (nonatomic, strong) NSString *pairingCode;

@end

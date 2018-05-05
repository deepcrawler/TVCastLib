//
//  WebOSTVServiceConfig.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 12/9/13.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import "ServiceConfig.h"

@interface WebOSTVServiceConfig : ServiceConfig <JSONObjectCoding>

@property (nonatomic, strong) NSString *clientKey;
@property (nonatomic, strong) NSArray *SSLCertificates;

@end

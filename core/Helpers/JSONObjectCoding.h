//
//  JSONObjectCoding.h
//  TVCastLib
//
//  Created by Jason Lai on 03/21/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>

@protocol JSONObjectCoding <NSObject>

- (id) initWithJSONObject:(NSDictionary*)dict;
- (NSDictionary*) toJSONObject;

@end

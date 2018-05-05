//
//  CastWebAppSession.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 2/23/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "CastService.h"
#import "WebAppSession.h"
#import "MediaControl.h"
#import "CastServiceChannel.h"


@interface CastWebAppSession : WebAppSession

@property (nonatomic, readonly) CastService *service;
@property (nonatomic) GCKApplicationMetadata *metadata;
@property (nonatomic, readonly) CastServiceChannel *castServiceChannel;

@end

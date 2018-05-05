//
//  OCMStubRecorder+SpectaAsync.m
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/27/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "OCMStubRecorder+SpectaAsync.h"

@implementation OCMStubRecorder (SpectaAsync)

- (id __nonnull)andDoneWaiting:(DoneCallback __nonnull)done {
    return [self andDo:^(NSInvocation *_) {
        done();
    }];
}

@end

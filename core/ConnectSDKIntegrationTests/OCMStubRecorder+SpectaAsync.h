//
//  OCMStubRecorder+SpectaAsync.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 5/27/15.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import <OCMock/OCMStubRecorder.h>
#import <Specta/SpectaDSL.h>

NS_ASSUME_NONNULL_BEGIN
@interface OCMStubRecorder (SpectaAsync)

/// Convenience method to call the Specta's @c DoneCallback received from the
/// @c waitUntil() method.
- (id)andDoneWaiting:(DoneCallback)done;

@end
NS_ASSUME_NONNULL_END

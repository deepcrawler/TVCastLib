//
//  ToastControl.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 1/19/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#import <Foundation/Foundation.h>
#import "Capability.h"
#import "AppInfo.h"

#define kToastControlAny @"ToastControl.Any"

#define kToastControlShowToast @"ToastControl.Show"
#define kToastControlShowClickableToastApp @"ToastControl.Show.Clickable.App"
#define kToastControlShowClickableToastAppParams @"ToastControl.Show.Clickable.App.Params"
#define kToastControlShowClickableToastURL @"ToastControl.Show.Clickable.URL"

#define kToastControlCapabilities @[\
    kToastControlShowToast,\
    kToastControlShowClickableToastApp,\
    kToastControlShowClickableToastAppParams,\
    kToastControlShowClickableToastURL\
]

@protocol ToastControl <NSObject>

- (id<ToastControl>)toastControl;
- (CapabilityPriorityLevel)toastControlPriority;

- (void) showToast:(NSString *)message success:(SuccessBlock)success failure:(FailureBlock)failure;
- (void) showToast:(NSString *)message iconData:(NSString *)iconData iconExtension:(NSString *)iconExtension success:(SuccessBlock)success failure:(FailureBlock)failure;

- (void) showClickableToast:(NSString *)message appInfo:(AppInfo *)appInfo params:(NSDictionary *)params success:(SuccessBlock)success failure:(FailureBlock)failure;
- (void) showClickableToast:(NSString *)message appInfo:(AppInfo *)appInfo params:(NSDictionary *)params iconData:(NSString *)iconData iconExtension:(NSString *)iconExtension success:(SuccessBlock)success failure:(FailureBlock)failure;

- (void) showClickableToast:(NSString *)message URL:(NSURL *)URL success:(SuccessBlock)success failure:(FailureBlock)failure;
- (void) showClickableToast:(NSString *)message URL:(NSURL *)URL iconData:(NSString *)iconData iconExtension:(NSString *)iconExtension success:(SuccessBlock)success failure:(FailureBlock)failure;

@end

//
//  DiscoveryManager_Private.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-06-16.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "DiscoveryManager.h"

@class AppStateChangeNotifier;
@class DiscoveryProvider;

NS_ASSUME_NONNULL_BEGIN
@interface DiscoveryManager ()

/// An @c AppStateChangeNotifier that allows to track app state changes.
@property (nonatomic, readonly) AppStateChangeNotifier *appStateChangeNotifier;


/// Initializes the instance with the given @c AppStateChangeNotifier. Using
/// @c nil parameter will create real object.
- (instancetype)initWithAppStateChangeNotifier:(nullable AppStateChangeNotifier *)stateNotifier;

/**
 * Registers a service with the given @c deviceClass and a @c DiscoveryProvider
 * created by the @c providerFactory.
 */
- (void)registerDeviceService:(Class)deviceClass
 withDiscoveryProviderFactory:(DiscoveryProvider *(^)(void))providerFactory;

@end
NS_ASSUME_NONNULL_END

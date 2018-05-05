//
//  FireTVDiscoveryProvider.h
//  TVCastLib
//
//  Created by Eugene Nikolskyi on 2015-07-08.
//  Copyright (c) 2015 Hamed Ghaderipour. All rights reserved.
//

//

#import "DiscoveryProvider.h"

/**
 * Discovery provider that can search for Amazon Fire TV and Fire TV Stick
 * devices.
 *
 * @warning Due to the specifics of the Amazon's Fling SDK, stopping the
 * discovery provider (via <tt>-[DiscoveryManager stopDiscovery]</tt>) will
 * remove all found Fire TV devices! The Fling SDK's discovery part is required
 * for @c FireTVService to work properly.
 */
@interface FireTVDiscoveryProvider : DiscoveryProvider

@end

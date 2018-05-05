//
//  TVCastLibDefaultPlatforms.h
//  TVCastLib
//
//  Created by Hamed Ghaderipour on 8/13/14.
//  Copyright (c) 2014 Hamed Ghaderipour.
//

//

#ifndef kTVCastLibDefaultPlatforms

#define kTVCastLibDefaultPlatforms (@{ \
    @"AirPlayService"     : @"ZeroConfDiscoveryProvider", \
    @"DIALService"        : @"SSDPDiscoveryProvider", \
    @"DLNAService"        : @"SSDPDiscoveryProvider", \
    @"NetcastTVService"   : @"SSDPDiscoveryProvider", \
    @"RokuService"        : @"SSDPDiscoveryProvider", \
    @"WebOSTVService"     : @"SSDPDiscoveryProvider", \
    @"CastService"        : @"CastDiscoveryProvider", \
    @"FireTVService"      : @"FireTVDiscoveryProvider", \
})

#endif

//
//  Reachability.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 11/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

struct sockaddr_in;

typedef enum {
	NotReachable = 0,
	ReachableViaWiFi,
	ReachableViaWWAN
} NetworkStatus;
#define kReachabilityChangedNotification @"kNetworkReachabilityChangedNotification"

@interface Reachability: NSObject

+ (Reachability*) reachabilityWithHostName: (NSString*) hostName;
+ (Reachability*) reachabilityWithAddress: (const struct sockaddr_in*) hostAddress;
+ (Reachability*) reachabilityForInternetConnection;
+ (Reachability*) reachabilityForLocalWiFi;
- (BOOL) startNotifier;
- (void) stopNotifier;
- (NetworkStatus) currentReachabilityStatus;
- (BOOL) connectionRequired;

@end
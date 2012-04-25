// Copyright (c) 2009, Sybase Inc.

#import "sybase_sup.h"

@interface SUPTimeUtil : NSObject

+ (SUPBoolean)equal:(SUPTime)a:(SUPTime)b;
+ (SUPBoolean)notEqual:(SUPTime)a:(SUPTime)b;
+ (SUPTime)getTime:(SUPNullableTime)time;
+ (SUPTime)getTime_s:(SUPString)s;
+ (SUPNullableTime)getNullableTime:(SUPTime)time;
+ (SUPNullableTime)getNullableTime_s:(SUPString)s;
+ (SUPTime)getTime3:(SUPInt)hour:(SUPInt)minute:(SUPInt)second;
+ (SUPTime)now;
+ (SUPInt)hour:(SUPTime)time;
+ (SUPInt)minute:(SUPTime)time;
+ (SUPInt)second:(SUPTime)time;
+ (SUPString)toString:(SUPTime)time;

@end

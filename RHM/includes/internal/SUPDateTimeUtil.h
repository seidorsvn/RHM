// Copyright (c) 2009, Sybase Inc.

#import "sybase_sup.h"

@interface SUPDateTimeUtil : NSObject

+ (SUPBoolean)equal:(SUPDateTime)a:(SUPDateTime)b;
+ (SUPBoolean)notEqual:(SUPDateTime)a:(SUPDateTime)b;
+ (SUPDateTime)getDateTime:(SUPNullableDateTime)dt;
+ (SUPDateTime)getDateTime_s:(SUPString)s;
+ (SUPNullableDateTime)getNullableDateTime:(SUPDateTime)dt;
+ (SUPNullableDateTime)getNullableDateTime_s:(SUPString)s;
+ (SUPDateTime)getDateTime6:(SUPInt)year:(SUPInt)month:(SUPInt)day:(SUPInt)hour:(SUPInt)minute:(SUPInt)second;
+ (SUPDateTime)now;
+ (SUPInt)year:(SUPDateTime)date;
+ (SUPInt)month:(SUPDateTime)date;
+ (SUPInt)day:(SUPDateTime)date;
+ (SUPInt)dayOfWeek:(SUPDateTime)date;
+ (SUPInt)dayOfYear:(SUPDateTime)date;
+ (SUPInt)hour:(SUPDateTime)time;
+ (SUPInt)minute:(SUPDateTime)time;
+ (SUPInt)second:(SUPDateTime)time;
+ (SUPString)toString:(SUPDateTime)dt;

@end

// Copyright (c) 2009, Sybase Inc.

#import "sybase_sup.h"

@interface SUPDateUtil : NSObject

+ (SUPBoolean)equal:(SUPDate)a:(SUPDate)b;
+ (SUPBoolean)notEqual:(SUPDate)a:(SUPDate)b;
+ (SUPDate)getDate:(SUPNullableDate)date;
+ (SUPDate)getDate_s:(SUPString)s;
+ (SUPNullableDate)getNullableDate:(SUPDate)date;
+ (SUPNullableDate)getNullableDate_s:(SUPString)s;
+ (SUPDate)getDate3:(SUPInt)year:(SUPInt)month:(SUPInt)day;
+ (SUPDate)now;
+ (SUPInt)year:(SUPDate)date;
+ (SUPInt)month:(SUPDate)date;
+ (SUPInt)day:(SUPDate)date;
+ (SUPInt)dayOfWeek:(SUPDate)date;
+ (SUPInt)dayOfYear:(SUPDate)date;
+ (SUPString)toString:(SUPDate)date;

@end

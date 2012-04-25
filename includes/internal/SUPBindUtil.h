// Copyright (c) 2009, Sybase Inc.

#import "sybase_sup.h"

@interface SUPBindUtil : NSObject

+ (SUPBoolean)parseBoolean:(SUPString)s;
+ (SUPString)parseString:(SUPString)s;
+ (SUPBinary)parseBinary:(SUPString)s;
+ (SUPChar)parseChar:(SUPString)s;
+ (SUPByte)parseByte:(SUPString)s;
+ (SUPShort)parseShort:(SUPString)s;
+ (SUPInt)parseInt:(SUPString)s;
+ (SUPLong)parseLong:(SUPString)s;
+ (SUPInteger)parseInteger:(SUPString)s;
+ (SUPDecimal)parseDecimal:(SUPString)s;
+ (SUPFloat)parseFloat:(SUPString)s;
+ (SUPDouble)parseDouble:(SUPString)s;
+ (SUPDate)parseDate:(SUPString)s;
+ (SUPTime)parseTime:(SUPString)s;
+ (SUPDateTime)parseDateTime:(SUPString)s;

+ (SUPNullableBoolean)parseNullableBoolean:(SUPString)s;
+ (SUPNullableString)parseNullableString:(SUPString)s;
+ (SUPNullableBinary)parseNullableBinary:(SUPString)s;
+ (SUPNullableChar)parseNullableChar:(SUPString)s;
+ (SUPNullableByte)parseNullableByte:(SUPString)s;
+ (SUPNullableShort)parseNullableShort:(SUPString)s;
+ (SUPNullableInt)parseNullableInt:(SUPString)s;
+ (SUPNullableLong)parseNullableLong:(SUPString)s;
+ (SUPNullableInteger)parseNullableInteger:(SUPString)s;
+ (SUPNullableDecimal)parseNullableDecimal:(SUPString)s;
+ (SUPNullableFloat)parseNullableFloat:(SUPString)s;
+ (SUPNullableDouble)parseNullableDouble:(SUPString)s;
+ (SUPNullableDate)parseNullableDate:(SUPString)s;
+ (SUPNullableTime)parseNullableTime:(SUPString)s;
+ (SUPNullableDateTime)parseNullableDateTime:(SUPString)s;

@end

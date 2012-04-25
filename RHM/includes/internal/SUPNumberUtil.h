// Copyright (c) 2009, Sybase Inc.

#import "sybase_sup.h"

@interface SUPNumberUtil : NSObject

+ (SUPNumber)add:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)add_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)add_m:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)subtract:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)subtract_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)subtract_m:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)multiply:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)multiply_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)multiply_m:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)divide:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)divide_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPNumber)divide_m:(SUPNumber)a:(SUPNumber)b;

+ (SUPBoolean)equal:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)equal_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)equal_m:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)notEqual:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)notEqual_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)notEqual_m:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)lessThan:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)lessThan_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)lessThan_m:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)lessEqual:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)lessEqual_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)lessEqual_m:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)greaterThan:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)greaterThan_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)greaterThan_m:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)greaterEqual:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)greaterEqual_d:(SUPNumber)a:(SUPNumber)b;
+ (SUPBoolean)greaterEqual_m:(SUPNumber)a:(SUPNumber)b;

+ (SUPByte)getByte:(SUPLong)n;
+ (SUPByte)getByte_d:(SUPDouble)n;
+ (SUPByte)getByte_n:(SUPNumber)n;
+ (SUPByte)getByte_s:(SUPString)s;
+ (SUPShort)getShort:(SUPLong)n;
+ (SUPShort)getShort_d:(SUPDouble)n;
+ (SUPShort)getShort_n:(SUPNumber)n;
+ (SUPShort)getShort_s:(SUPString)s;
+ (SUPInt)getInt:(SUPLong)n;
+ (SUPInt)getInt_d:(SUPDouble)n;
+ (SUPInt)getInt_n:(SUPNumber)n;
+ (SUPInt)getInt_s:(SUPString)s;
+ (SUPLong)getLong:(SUPLong)n;
+ (SUPLong)getLong_d:(SUPDouble)n;
+ (SUPLong)getLong_n:(SUPNumber)n;
+ (SUPLong)getLong_s:(SUPString)s;
+ (SUPInteger)getInteger:(SUPLong)n;
+ (SUPInteger)getInteger_d:(SUPDouble)n;
+ (SUPInteger)getInteger_n:(SUPNumber)n;
+ (SUPInteger)getInteger_s:(SUPString)s;
+ (SUPDecimal)getDecimal:(SUPLong)n;
+ (SUPDecimal)getDecimal_d:(SUPDouble)n;
+ (SUPDecimal)getDecimal_n:(SUPNumber)n;
+ (SUPDecimal)getDecimal_s:(SUPString)s;
+ (SUPFloat)getFloat:(SUPLong)n;
+ (SUPFloat)getFloat_d:(SUPDouble)n;
+ (SUPFloat)getFloat_n:(SUPNumber)n;
+ (SUPFloat)getFloat_s:(SUPString)s;
+ (SUPDouble)getDouble:(SUPLong)n;
+ (SUPDouble)getDouble_d:(SUPDouble)n;
+ (SUPDouble)getDouble_n:(SUPNumber)n;
+ (SUPDouble)getDouble_s:(SUPString)s;

+ (SUPNullableByte)getNullableByte:(SUPLong)n;
+ (SUPNullableByte)getNullableByte_d:(SUPDouble)n;
+ (SUPNullableByte)getNullableByte_n:(SUPNumber)n;
+ (SUPNullableByte)getNullableByte_s:(SUPString)n;
+ (SUPNullableShort)getNullableShort:(SUPLong)n;
+ (SUPNullableShort)getNullableShort_d:(SUPDouble)n;
+ (SUPNullableShort)getNullableShort_n:(SUPNumber)n;
+ (SUPNullableShort)getNullableShort_s:(SUPString)n;
+ (SUPNullableInt)getNullableInt:(SUPLong)n;
+ (SUPNullableInt)getNullableInt_d:(SUPDouble)n;
+ (SUPNullableInt)getNullableInt_n:(SUPNumber)n;
+ (SUPNullableInt)getNullableInt_s:(SUPString)n;
+ (SUPNullableLong)getNullableLong:(SUPLong)n;
+ (SUPNullableLong)getNullableLong_d:(SUPDouble)n;
+ (SUPNullableLong)getNullableLong_n:(SUPNumber)n;
+ (SUPNullableLong)getNullableLong_s:(SUPString)n;
+ (SUPNullableInteger)getNullableInteger:(SUPLong)n;
+ (SUPNullableInteger)getNullableInteger_d:(SUPDouble)n;
+ (SUPNullableInteger)getNullableInteger_n:(SUPNumber)n;
+ (SUPNullableInteger)getNullableInteger_s:(SUPString)n;
+ (SUPNullableDecimal)getNullableDecimal:(SUPLong)n;
+ (SUPNullableDecimal)getNullableDecimal_d:(SUPDouble)n;
+ (SUPNullableDecimal)getNullableDecimal_n:(SUPNumber)n;
+ (SUPNullableDecimal)getNullableDecimal_s:(SUPString)n;
+ (SUPNullableFloat)getNullableFloat:(SUPLong)n;
+ (SUPNullableFloat)getNullableFloat_d:(SUPDouble)n;
+ (SUPNullableFloat)getNullableFloat_n:(SUPNumber)n;
+ (SUPNullableFloat)getNullableFloat_s:(SUPString)n;
+ (SUPNullableDouble)getNullableDouble:(SUPLong)n;
+ (SUPNullableDouble)getNullableDouble_d:(SUPDouble)n;
+ (SUPNullableDouble)getNullableDouble_n:(SUPNumber)n;
+ (SUPNullableDouble)getNullableDouble_s:(SUPString)n;

@end

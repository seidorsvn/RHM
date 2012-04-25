// Copyright (c) 2009, Sybase Inc.

#import "sybase_sup.h"

@class SUPArrayList;

@interface SUPStringUtil : NSObject

+ (SUPBoolean)equal:(SUPString)a:(SUPString)b;
+ (SUPBoolean)notEqual:(SUPString)a:(SUPString)b;
+ (SUPBoolean)lessThan:(SUPString)a:(SUPString)b;
+ (SUPBoolean)lessEqual:(SUPString)a:(SUPString)b;
+ (SUPBoolean)greaterThan:(SUPString)a:(SUPString)b;
+ (SUPBoolean)greaterEqual:(SUPString)a:(SUPString)b;

+ (SUPChar)intToChar:(SUPInt)i;
+ (SUPInt)charToInt:(SUPChar)c;

+ (SUPChar)getChar:(SUPNullableChar)c;
+ (SUPNullableChar)getNullableChar:(SUPChar)c;

+ (SUPChar)getChar_s:(SUPString)s;
+ (SUPNullableChar)getNullableChar_s:(SUPString)s;

+ (SUPString)toString_object:(id)x;

+ (SUPString)toString_boolean:(SUPBoolean)b;
+ (SUPString)toString_string:(SUPString)s;
+ (SUPString)toString_binary:(SUPBinary)b;
+ (SUPString)toString_char:(SUPChar)c;
+ (SUPString)toString_byte:(SUPByte)n;
+ (SUPString)toString_short:(SUPShort)n;
+ (SUPString)toString_int:(SUPInt)n;
+ (SUPString)toString_long:(SUPLong)n;
+ (SUPString)toString_integer:(SUPInteger)n;
+ (SUPString)toString_decimal:(SUPDecimal)n;
+ (SUPString)toString_float:(SUPFloat)n;
+ (SUPString)toString_double:(SUPDouble)n;
+ (SUPString)toString_date:(SUPDate)x;
+ (SUPString)toString_time:(SUPTime)x;
+ (SUPString)toString_dateTime:(SUPDateTime)x;

+ (SUPString)toString_nullableBoolean:(SUPNullableBoolean)b;
+ (SUPString)toString_nullableString:(SUPString)s;
+ (SUPString)toString_nullableBinary:(SUPBinary)b;
+ (SUPString)toString_nullableChar:(SUPNullableChar)c;
+ (SUPString)toString_nullableByte:(SUPNullableByte)n;
+ (SUPString)toString_nullableShort:(SUPNullableShort)n;
+ (SUPString)toString_nullableInt:(SUPNullableInt)n;
+ (SUPString)toString_nullableLong:(SUPNullableLong)n;
+ (SUPString)toString_nullableInteger:(SUPNullableInteger)n;
+ (SUPString)toString_nullableDecimal:(SUPNullableDecimal)n;
+ (SUPString)toString_nullableFloat:(SUPNullableFloat)n;
+ (SUPString)toString_nullableDouble:(SUPNullableDouble)n;
+ (SUPString)toString_nullableDate:(SUPNullableDate)x;
+ (SUPString)toString_nullableTime:(SUPNullableTime)x;
+ (SUPString)toString_nullableDateTime:(SUPNullableDateTime)x;

+ (SUPChar)charAt:(SUPString)string:(SUPInt)index;
+ (SUPString)concat:(SUPArrayList*)strings;
+ (SUPBoolean)endsWith:(SUPString)s:(SUPString)x;
+ (SUPString)fromChars:(SUPArrayList*)chars;
+ (SUPInt)hashCode:(SUPString)s;
+ (SUPInt)indexOf:(SUPString)s:(SUPString)x;
+ (SUPInt)indexOf2:(SUPString)s:(SUPString)x:(SUPInt)start;
+ (SUPString)join:(SUPArrayList*)strings:(SUPString)separator;
+ (SUPInt)lastIndexOf:(SUPString)s:(SUPString)x;
+ (SUPInt)lastIndexOf2:(SUPString)s:(SUPString)x:(SUPInt)start;
+ (SUPBoolean)like:(SUPString)string:(SUPString)pattern;
+ (SUPBoolean)startsWith:(SUPString)s:(SUPString)x;
+ (SUPBoolean)startsWith2:(SUPString)s:(SUPString)x:(SUPInt)start;
+ (SUPString)substring:(SUPString)s:(SUPInt)start;
+ (SUPString)substring2:(SUPString)s:(SUPInt)start:(SUPInt)end;
+ (SUPString)toLowerCase:(SUPString)s;
+ (SUPString)toUpperCase:(SUPString)s;
+ (SUPString)trim:(SUPString)s;

+ (SUPString)fromUTF8:(SUPBinary)b;
+ (SUPBinary)toUTF8:(SUPString)s;

+ (SUPString)guid32;
+ (SUPString)guid36;

@end

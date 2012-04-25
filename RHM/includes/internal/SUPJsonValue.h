#import "sybase_sup.h"

@class SUPBase64Encoding;
@class SUPBooleanUtil;
@class SUPDateTimeUtil;
@class SUPDateUtil;
@class SUPJsonArray;
@class SUPJsonBoolean;
@class SUPJsonException;
@class SUPJsonNumber;
@class SUPJsonObject;
@class SUPJsonString;
@class SUPNumberUtil;
@class SUPStringList;
@class SUPStringUtil;
@class SUPTimeUtil;

@class SUPJsonValue;

@interface SUPJsonValue : NSObject
{
}

+ (id)fromArray:(SUPJsonArray*)value;
+ (id)fromObject:(SUPJsonObject*)value;
+ (id)fromBoolean:(SUPBoolean)value;
+ (id)fromString:(SUPString)value;
+ (id)fromBinary:(SUPBinary)value;
+ (id)fromChar:(SUPChar)value;
+ (id)fromByte:(SUPByte)value;
+ (id)fromShort:(SUPShort)value;
+ (id)fromInt:(SUPInt)value;
+ (id)fromLong:(SUPLong)value;
+ (id)fromInteger:(SUPInteger)value;
+ (id)fromDecimal:(SUPDecimal)value;
+ (id)fromFloat:(SUPFloat)value;
+ (id)fromDouble:(SUPDouble)value;
+ (id)fromDate:(SUPDate)value;
+ (id)fromTime:(SUPTime)value;
+ (id)fromDateTime:(SUPDateTime)value;
+ (id)fromNullableBoolean:(SUPNullableBoolean)value;
+ (id)fromNullableString:(SUPNullableString)value;
+ (id)fromNullableBinary:(SUPNullableBinary)value;
+ (id)fromNullableChar:(SUPNullableChar)value;
+ (id)fromNullableByte:(SUPNullableByte)value;
+ (id)fromNullableShort:(SUPNullableShort)value;
+ (id)fromNullableInt:(SUPNullableInt)value;
+ (id)fromNullableLong:(SUPNullableLong)value;
+ (id)fromNullableInteger:(SUPNullableInteger)value;
+ (id)fromNullableDecimal:(SUPNullableDecimal)value;
+ (id)fromNullableFloat:(SUPNullableFloat)value;
+ (id)fromNullableDouble:(SUPNullableDouble)value;
+ (id)fromNullableDate:(SUPNullableDate)value;
+ (id)fromNullableTime:(SUPNullableTime)value;
+ (id)fromNullableDateTime:(SUPNullableDateTime)value;
+ (SUPJsonArray*)getArray:(id)value;
+ (SUPJsonObject*)getObject:(id)value;
+ (SUPBoolean)getBoolean:(id)value;
+ (SUPString)getString:(id)value;
+ (SUPBinary)getBinary:(id)value;
+ (SUPChar)getChar:(id)value;
+ (SUPByte)getByte:(id)value;
+ (SUPShort)getShort:(id)value;
+ (SUPInt)getInt:(id)value;
+ (SUPLong)getLong:(id)value;
+ (SUPInteger)getInteger:(id)value;
+ (SUPDecimal)getDecimal:(id)value;
+ (SUPFloat)getFloat:(id)value;
+ (SUPDouble)getDouble:(id)value;
+ (SUPDate)getDate:(id)value;
+ (SUPTime)getTime:(id)value;
+ (SUPDateTime)getDateTime:(id)value;
+ (SUPNullableBoolean)getNullableBoolean:(id)value;
+ (SUPNullableString)getNullableString:(id)value;
+ (SUPNullableBinary)getNullableBinary:(id)value;
+ (SUPNullableChar)getNullableChar:(id)value;
+ (SUPNullableByte)getNullableByte:(id)value;
+ (SUPNullableShort)getNullableShort:(id)value;
+ (SUPNullableInt)getNullableInt:(id)value;
+ (SUPNullableLong)getNullableLong:(id)value;
+ (SUPNullableInteger)getNullableInteger:(id)value;
+ (SUPNullableDecimal)getNullableDecimal:(id)value;
+ (SUPNullableFloat)getNullableFloat:(id)value;
+ (SUPNullableDouble)getNullableDouble:(id)value;
+ (SUPNullableDate)getNullableDate:(id)value;
+ (SUPNullableTime)getNullableTime:(id)value;
+ (SUPNullableDateTime)getNullableDateTime:(id)value;
+ (SUPJsonException*)unexpectedNull;
- (void)dealloc;

@end

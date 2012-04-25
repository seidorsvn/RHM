#import "sybase_sup.h"

@class SUPJsonArray;
@class SUPJsonValue;
@class SUPJsonWriter;
@class SUPObjectList;
@class SUPStringList; 

@class SUPJsonObject;

@interface SUPJsonObject : NSObject
{
    NSMutableDictionary* _delegate;
}

+ (SUPJsonObject*)getInstance;
- (SUPJsonObject*)init;
- (SUPString)toString;
- (SUPJsonArray*)getArray:(SUPString)name;
- (SUPJsonObject*)getObject:(SUPString)name;
- (SUPBoolean)getBoolean:(SUPString)name;
- (SUPString)getString:(SUPString)name;
- (SUPBinary)getBinary:(SUPString)name;
- (SUPChar)getChar:(SUPString)name;
- (SUPByte)getByte:(SUPString)name;
- (SUPShort)getShort:(SUPString)name;
- (SUPInt)getInt:(SUPString)name;
- (SUPLong)getLong:(SUPString)name;
- (SUPInteger)getInteger:(SUPString)name;
- (SUPDecimal)getDecimal:(SUPString)name;
- (SUPFloat)getFloat:(SUPString)name;
- (SUPDouble)getDouble:(SUPString)name;
- (SUPDate)getDate:(SUPString)name;
- (SUPTime)getTime:(SUPString)name;
- (SUPDateTime)getDateTime:(SUPString)name;
- (SUPNullableBoolean)getNullableBoolean:(SUPString)name;
- (SUPNullableString)getNullableString:(SUPString)name;
- (SUPNullableBinary)getNullableBinary:(SUPString)name;
- (SUPNullableChar)getNullableChar:(SUPString)name;
- (SUPNullableByte)getNullableByte:(SUPString)name;
- (SUPNullableShort)getNullableShort:(SUPString)name;
- (SUPNullableInt)getNullableInt:(SUPString)name;
- (SUPNullableLong)getNullableLong:(SUPString)name;
- (SUPNullableInteger)getNullableInteger:(SUPString)name;
- (SUPNullableDecimal)getNullableDecimal:(SUPString)name;
- (SUPNullableFloat)getNullableFloat:(SUPString)name;
- (SUPNullableDouble)getNullableDouble:(SUPString)name;
- (SUPNullableDate)getNullableDate:(SUPString)name;
- (SUPNullableTime)getNullableTime:(SUPString)name;
- (SUPNullableDateTime)getNullableDateTime:(SUPString)name;
- (void)setArray:(SUPString)name:(SUPJsonArray*)value;
- (void)setObject:(SUPString)name:(SUPJsonObject*)value;
- (void)setBoolean:(SUPString)name:(SUPBoolean)value;
- (void)setString:(SUPString)name:(SUPString)value;
- (void)setBinary:(SUPString)name:(SUPBinary)value;
- (void)setChar:(SUPString)name:(SUPChar)value;
- (void)setByte:(SUPString)name:(SUPByte)value;
- (void)setShort:(SUPString)name:(SUPShort)value;
- (void)setInt:(SUPString)name:(SUPInt)value;
- (void)setLong:(SUPString)name:(SUPLong)value;
- (void)setInteger:(SUPString)name:(SUPInteger)value;
- (void)setDecimal:(SUPString)name:(SUPDecimal)value;
- (void)setFloat:(SUPString)name:(SUPFloat)value;
- (void)setDouble:(SUPString)name:(SUPDouble)value;
- (void)setDate:(SUPString)name:(SUPDate)value;
- (void)setTime:(SUPString)name:(SUPTime)value;
- (void)setDateTime:(SUPString)name:(SUPDateTime)value;
- (void)setNullableBoolean:(SUPString)name:(SUPNullableBoolean)value;
- (void)setNullableString:(SUPString)name:(SUPNullableString)value;
- (void)setNullableBinary:(SUPString)name:(SUPNullableBinary)value;
- (void)setNullableChar:(SUPString)name:(SUPNullableChar)value;
- (void)setNullableByte:(SUPString)name:(SUPNullableByte)value;
- (void)setNullableShort:(SUPString)name:(SUPNullableShort)value;
- (void)setNullableInt:(SUPString)name:(SUPNullableInt)value;
- (void)setNullableLong:(SUPString)name:(SUPNullableLong)value;
- (void)setNullableInteger:(SUPString)name:(SUPNullableInteger)value;
- (void)setNullableDecimal:(SUPString)name:(SUPNullableDecimal)value;
- (void)setNullableFloat:(SUPString)name:(SUPNullableFloat)value;
- (void)setNullableDouble:(SUPString)name:(SUPNullableDouble)value;
- (void)setNullableDate:(SUPString)name:(SUPNullableDate)value;
- (void)setNullableTime:(SUPString)name:(SUPNullableTime)value;
- (void)setNullableDateTime:(SUPString)name:(SUPNullableDateTime)value;
- (void)add:(SUPString)key:(id)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (id)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (NSMutableDictionary*)internalMap;
- (void)dealloc;

@end

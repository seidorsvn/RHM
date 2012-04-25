#import "sybase_sup.h"

@class SUPJsonObject;
@class SUPJsonValue;
@class SUPJsonWriter;

@class SUPJsonArray;

@interface SUPJsonArray : SUPArrayList
{
}

- (SUPJsonArray*)getArray:(SUPInt)index;
- (SUPJsonObject*)getObject:(SUPInt)index;
- (SUPBoolean)getBoolean:(SUPInt)index;
- (SUPString)getString:(SUPInt)index;
- (SUPBinary)getBinary:(SUPInt)index;
- (SUPChar)getChar:(SUPInt)index;
- (SUPByte)getByte:(SUPInt)index;
- (SUPShort)getShort:(SUPInt)index;
- (SUPInt)getInt:(SUPInt)index;
- (SUPLong)getLong:(SUPInt)index;
- (SUPInteger)getInteger:(SUPInt)index;
- (SUPDecimal)getDecimal:(SUPInt)index;
- (SUPFloat)getFloat:(SUPInt)index;
- (SUPDouble)getDouble:(SUPInt)index;
- (SUPDate)getDate:(SUPInt)index;
- (SUPTime)getTime:(SUPInt)index;
- (SUPDateTime)getDateTime:(SUPInt)index;
- (SUPNullableBoolean)getNullableBoolean:(SUPInt)index;
- (SUPNullableString)getNullableString:(SUPInt)index;
- (SUPNullableBinary)getNullableBinary:(SUPInt)index;
- (SUPNullableChar)getNullableChar:(SUPInt)index;
- (SUPNullableByte)getNullableByte:(SUPInt)index;
- (SUPNullableShort)getNullableShort:(SUPInt)index;
- (SUPNullableInt)getNullableInt:(SUPInt)index;
- (SUPNullableLong)getNullableLong:(SUPInt)index;
- (SUPNullableInteger)getNullableInteger:(SUPInt)index;
- (SUPNullableDecimal)getNullableDecimal:(SUPInt)index;
- (SUPNullableFloat)getNullableFloat:(SUPInt)index;
- (SUPNullableDouble)getNullableDouble:(SUPInt)index;
- (SUPNullableDate)getNullableDate:(SUPInt)index;
- (SUPNullableTime)getNullableTime:(SUPInt)index;
- (SUPNullableDateTime)getNullableDateTime:(SUPInt)index;
- (void)addArray:(SUPJsonArray*)value;
- (void)addObject:(SUPJsonObject*)value;
- (void)addBoolean:(SUPBoolean)value;
- (void)addString:(SUPString)value;
- (void)addBinary:(SUPBinary)value;
- (void)addChar:(SUPChar)value;
- (void)addByte:(SUPByte)value;
- (void)addShort:(SUPShort)value;
- (void)addInt:(SUPInt)value;
- (void)addLong:(SUPLong)value;
- (void)addInteger:(SUPInteger)value;
- (void)addDecimal:(SUPDecimal)value;
- (void)addFloat:(SUPFloat)value;
- (void)addDouble:(SUPDouble)value;
- (void)addDate:(SUPDate)value;
- (void)addTime:(SUPTime)value;
- (void)addDateTime:(SUPDateTime)value;
- (void)addNullableBoolean:(SUPNullableBoolean)value;
- (void)addNullableString:(SUPNullableString)value;
- (void)addNullableBinary:(SUPNullableBinary)value;
- (void)addNullableChar:(SUPNullableChar)value;
- (void)addNullableByte:(SUPNullableByte)value;
- (void)addNullableShort:(SUPNullableShort)value;
- (void)addNullableInt:(SUPNullableInt)value;
- (void)addNullableLong:(SUPNullableLong)value;
- (void)addNullableInteger:(SUPNullableInteger)value;
- (void)addNullableDecimal:(SUPNullableDecimal)value;
- (void)addNullableFloat:(SUPNullableFloat)value;
- (void)addNullableDouble:(SUPNullableDouble)value;
- (void)addNullableDate:(SUPNullableDate)value;
- (void)addNullableTime:(SUPNullableTime)value;
- (void)addNullableDateTime:(SUPNullableDateTime)value;
- (SUPString)toString;
- (SUPJsonArray*)finishInit;
+ (SUPJsonArray*)getInstance;
- (SUPJsonArray*)init;
- (SUPJsonArray*)initWithCapacity:(SUPInt)capacity;
+ (SUPJsonArray*)listWithCapacity:(SUPInt)capacity;
- (void)add:(id)item;
- (SUPBoolean)contains:(id)item;
- (id)item:(SUPInt)index;
- (void)clear;
- (SUPJsonArray*)addThis:(id)item;
- (SUPJsonArray*)slice:(SUPInt)start:(SUPInt)finish;
- (SUPInt)push:(id)item;
- (id)pop;
- (void)dealloc;

@end

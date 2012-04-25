#import "sybase_sup.h"

@protocol SUPResultSetWrapper;

@protocol SUPStatementWrapper

- (void)close;
- (void)setCached:(BOOL)cached;
- (id<SUPResultSetWrapper>)executeQuery;
- (void)execute;
- (void)executeInsert;
- (void)executeUpdate:(SUPBoolean)_checked_1;
- (void)executeDelete:(SUPBoolean)_checked_1;
- (void)setBoolean:(SUPInt)_index_1:(SUPString)_name_2:(SUPBoolean)_value_3;
- (void)setString:(SUPInt)_index_1:(SUPString)_name_2:(SUPString)_value_3;
- (void)setBinary:(SUPInt)_index_1:(SUPString)_name_2:(SUPBinary)_value_3;
- (void)setChar:(SUPInt)_index_1:(SUPString)_name_2:(SUPChar)_value_3;
- (void)setByte:(SUPInt)_index_1:(SUPString)_name_2:(SUPByte)_value_3;
- (void)setShort:(SUPInt)_index_1:(SUPString)_name_2:(SUPShort)_value_3;
- (void)setInt:(SUPInt)_index_1:(SUPString)_name_2:(SUPInt)_value_3;
- (void)setLong:(SUPInt)_index_1:(SUPString)_name_2:(SUPLong)_value_3;
- (void)setInteger:(SUPInt)_index_1:(SUPString)_name_2:(SUPInteger)_value_3;
- (void)setDecimal:(SUPInt)_index_1:(SUPString)_name_2:(SUPDecimal)_value_3;
- (void)setFloat:(SUPInt)_index_1:(SUPString)_name_2:(SUPFloat)_value_3;
- (void)setDouble:(SUPInt)_index_1:(SUPString)_name_2:(SUPDouble)_value_3;
- (void)setDate:(SUPInt)_index_1:(SUPString)_name_2:(SUPDate)_value_3;
- (void)setTime:(SUPInt)_index_1:(SUPString)_name_2:(SUPTime)_value_3;
- (void)setDateTime:(SUPInt)_index_1:(SUPString)_name_2:(SUPDateTime)_value_3;
- (void)setNullableBoolean:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableBoolean)_value_3;
- (void)setNullableString:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableString)_value_3;
- (void)setNullableBinary:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableBinary)_value_3;
- (void)setNullableChar:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableChar)_value_3;
- (void)setNullableByte:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableByte)_value_3;
- (void)setNullableShort:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableShort)_value_3;
- (void)setNullableInt:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableInt)_value_3;
- (void)setNullableLong:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableLong)_value_3;
- (void)setNullableInteger:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableInteger)_value_3;
- (void)setNullableDecimal:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableDecimal)_value_3;
- (void)setNullableFloat:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableFloat)_value_3;
- (void)setNullableDouble:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableDouble)_value_3;
- (void)setNullableDate:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableDate)_value_3;
- (void)setNullableTime:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableTime)_value_3;
- (void)setNullableDateTime:(SUPInt)_index_1:(SUPString)_name_2:(SUPNullableDateTime)_value_3;

@end

/*
 
 Copyright (c) Sybase, Inc. 2010   All rights reserved.                                    
 
 In addition to the license terms set out in the Sybase License Agreement for 
 the Sybase Unwired Platform ("Program"), the following additional or different 
 rights and accompanying obligations and restrictions shall apply to the source 
 code in this file ("Code").  Sybase grants you a limited, non-exclusive, 
 non-transferable, revocable license to use, reproduce, and modify the Code 
 solely for purposes of (i) maintaining the Code as reference material to better
 understand the operation of the Program, and (ii) development and testing of 
 applications created in connection with your licensed use of the Program.  
 The Code may not be transferred, sold, assigned, sublicensed or otherwise 
 conveyed (whether by operation of law or otherwise) to another party without 
 Sybase's prior written consent.  The following provisions shall apply to any 
 modifications you make to the Code: (i) Sybase will not provide any maintenance
 or support for modified Code or problems that result from use of modified Code;
 (ii) Sybase expressly disclaims any warranties and conditions, express or 
 implied, relating to modified Code or any problems that result from use of the 
 modified Code; (iii) SYBASE SHALL NOT BE LIABLE FOR ANY LOSS OR DAMAGE RELATING
 TO MODIFICATIONS MADE TO THE CODE OR FOR ANY DAMAGES RESULTING FROM USE OF THE 
 MODIFIED CODE, INCLUDING, WITHOUT LIMITATION, ANY INACCURACY OF DATA, LOSS OF 
 PROFITS OR DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, EVEN
 IF SYBASE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; (iv) you agree 
 to indemnify, hold harmless, and defend Sybase from and against any claims or 
 lawsuits, including attorney's fees, that arise from or are related to the 
 modified Code or from use of the modified Code. 
 
 */



#import "sybase_sup.h"

@class SUPAbstractOperationException;
@class SUPBinaryUtil;
@class SUPBooleanUtil;
@class SUPDateTimeUtil;
@class SUPDateUtil;
@class SUPJsonObject;
@class SUPNumberUtil;
@class SUPStringUtil;
@class SUPTimeUtil;
@class SUPBinaryValue;
@class SUPBooleanValue;
@class SUPByteValue;
@class SUPCharValue;
@class SUPDataType;
@class SUPDateTimeValue;
@class SUPDateValue;
@class SUPDecimalValue;
@class SUPDoubleValue;
@class SUPFloatValue;
@class SUPIntValue;
@class SUPIntegerValue;
@class SUPInvalidDataTypeException;
@class SUPLongValue;
@class SUPNullDataValueException;
@class SUPShortValue;
@class SUPStringValue;
@class SUPTimeValue;
@class SUPWrongDataTypeException;

@class SUPDataValue;


/*!
 @class SUPDataValue
 @abstract   An SUPDataValue object represents an attribute, its data type, and its value.
 @discussion This class and related classes are used in processing result sets from queries (@link //apple_ref/occ/cl/SUPQueryResultSet SUPQueryResultSet @/link).
 */

@interface SUPDataValue : NSObject
{
}


- (SUPInt)typeCode;

/*!
    @method     
    @abstract   Returns the SUPDataVaue object for the value of type SUPBoolean.
    @discussion 
    @param value The value.
    @result The SUPDataValue object.
*/
+ (SUPDataValue*)fromBoolean:(SUPBoolean)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPString.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromString:(SUPString)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPBinary.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromBinary:(SUPBinary)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPChar.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromChar:(SUPChar)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPByte.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromByte:(SUPByte)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPShort.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromShort:(SUPShort)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPBoolean.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromInt:(SUPInt)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPBoolean.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromLong:(SUPLong)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPBoolean.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromInteger:(SUPInteger)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPDecimal.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromDecimal:(SUPDecimal)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPFloat.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromFloat:(SUPFloat)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPDouble.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromDouble:(SUPDouble)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPBoolean.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromDate:(SUPDate)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPTime.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromTime:(SUPTime)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPDateTime.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromDateTime:(SUPDateTime)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableBoolean.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableBoolean:(SUPNullableBoolean)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableString.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableString:(SUPNullableString)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableBinary.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableBinary:(SUPNullableBinary)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableChar.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableChar:(SUPNullableChar)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableByte.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableByte:(SUPNullableByte)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableShort.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableShort:(SUPNullableShort)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableInt.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableInt:(SUPNullableInt)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableLong.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableLong:(SUPNullableLong)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableInteger.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableInteger:(SUPNullableInteger)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableDecimal.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableDecimal:(SUPNullableDecimal)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableFloat.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableFloat:(SUPNullableFloat)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableDouble.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableDouble:(SUPNullableDouble)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableDate.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableDate:(SUPNullableDate)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableTime.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableTime:(SUPNullableTime)value;

/*!
 @method     
 @abstract   Returns the SUPDataVaue object for the value of type SUPNullableDateTime.
 @discussion 
 @param value The value.
 @result The SUPDataValue object.
 */
+ (SUPDataValue*)fromNullableDateTime:(SUPNullableDateTime)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPBoolean)getBoolean:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPString)getString:(id)value;
/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPBinary)getBinary:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPChar)getChar:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPByte)getByte:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPShort)getShort:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPInt)getInt:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPLong)getLong:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPInteger)getInteger:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPDecimal)getDecimal:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPFloat)getFloat:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPDouble)getDouble:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPDate)getDate:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPTime)getTime:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPDateTime)getDateTime:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableBoolean)getNullableBoolean:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableString)getNullableString:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableBinary)getNullableBinary:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableChar)getNullableChar:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableByte)getNullableByte:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableShort)getNullableShort:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableInt)getNullableInt:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableLong)getNullableLong:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableInteger)getNullableInteger:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableDecimal)getNullableDecimal:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableFloat)getNullableFloat:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableDouble)getNullableDouble:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableDate)getNullableDate:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableTime)getNullableTime:(id)value;

/*!
 @method     
 @abstract   Returns the primitive SUPDatatype value of the object.
 @discussion 
 @param value The object.
 @result The value .
 */
+ (SUPNullableDateTime)getNullableDateTime:(id)value;
- (SUPString)toString;

/*!
 @method     
 @abstract   Returns the SUPDataValue object for text based on type.
 @discussion 
 @param text An SUPString.
 @param type The typecode.
 @result The SUPDataValueObject.
 */
+ (SUPDataValue*)parse:(SUPInt)type:(SUPString)text;

/*!
 @method     
 @abstract   Deallocates the memory occupied by this object.
 @discussion
 */
- (void)dealloc;

@end

@interface SUPDataValue(internal)

- (SUPDataValue*)finishInit;
+ (SUPDataValue*)fromJsonObject:(SUPJsonObject*)_object_1:(SUPInt)_flags;
+ (SUPJsonObject*)toJsonObject:(SUPDataValue*)_object:(SUPInt)_flags;
- (void)readJson:(SUPJsonObject*)_object_1:(SUPInt)_flags;
- (SUPJsonObject*)writeJson:(SUPInt)_flags;
- (void)initFields;

@end


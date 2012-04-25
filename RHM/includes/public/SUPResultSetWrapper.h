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

/*!
 @protocol
 @abstract    SUPResultSetWrapper protocol provides a common interface for database result sets.  The clientrt library for iPhone provides an 
               internal implementation of this protocol that wraps a SQLite3 result set.
 @discussion  
 */

@protocol SUPResultSetWrapper
/*!
    @method     
    @abstract   Close operation on result set.
    @discussion 
*/

- (void)close;
/*!
    @method     
    @abstract   Step operation on result set.            
    @discussion 
    @result YES - there is still data in result set
            NO - reach the end of the result set.
*/

/*!
    @method     
    @abstract   Get the result set count.            
    @discussion 
    @result The result set count.
*/
- (int32_t)count;

/*!
    @method     
    @abstract   Move to next row in result set.            
    @discussion 
    @result True if there are still more rows in the result set, false if the end has been reached.
*/
- (SUPBoolean)next;
/*!
    @method     
    @abstract   Retrieve boolean type data with given index and given name from the result set.
    @discussion 
    @param _index_1 - index in sql query list.
    @param -name_2 - name of the column.
    @result SUPBoolean type of not null data.
*/
- (SUPBoolean)getBoolean:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve string type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPString type of not null data.
 */
- (SUPString)getString:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve binary type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPBinary type of not null data.
 */
- (SUPBinary)getBinary:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrievechar type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPChar type of not null data.
 */
- (SUPChar)getChar:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve byte type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPByte type of not null data.
 */
- (SUPByte)getByte:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve short type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPShort type of not null data.
 */
- (SUPShort)getShort:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve int type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPInt type of not null data.
 */
- (SUPInt)getInt:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve long type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPLong type of not null data.
 */
- (SUPLong)getLong:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve Integer type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPInteger type of not null data.
 */
- (SUPInteger)getInteger:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve decimal type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPDecimal type of not null data.
 */
- (SUPDecimal)getDecimal:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve float type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPFloat type of not null data.
 */
- (SUPFloat)getFloat:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve double type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPDouble type of not null data.
 */
- (SUPDouble)getDouble:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve date type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPDate type of not null data.
 */
- (SUPDate)getDate:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve time type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPTime type of not null data.
 */
- (SUPTime)getTime:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve datetime type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPDateTime type of not null data.
 */
- (SUPDateTime)getDateTime:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract  Retrieve boolean type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableBoolean type of nullable data.
 */
- (SUPNullableBoolean)getNullableBoolean:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract    Retrieve string type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableString type of nullable data.
 */
- (SUPNullableString)getNullableString:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve binary type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableBinary type of nullable data.
 */
- (SUPNullableBinary)getNullableBinary:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve char type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableChar type of nullable data.
 */
- (SUPNullableChar)getNullableChar:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve byte type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableByte type of nullable data.
 */
- (SUPNullableByte)getNullableByte:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve short type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableShort type of nullable data.
 */
- (SUPNullableShort)getNullableShort:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve int type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableInt type of nullable data.
 */
- (SUPNullableInt)getNullableInt:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve long type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableLong type of nullable data.
 */
- (SUPNullableLong)getNullableLong:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve integer type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableInteger type of nullable data.
 */
- (SUPNullableInteger)getNullableInteger:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve decimal type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableDecimal type of nullable data.
 */
- (SUPNullableDecimal)getNullableDecimal:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve float type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableFloat type of nullable data.
 */
- (SUPNullableFloat)getNullableFloat:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve double type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableDouble type of nullable data.
 */
- (SUPNullableDouble)getNullableDouble:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve date type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableDate type of nullable data.
 */
- (SUPNullableDate)getNullableDate:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve time type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableTime type of nullable data.
 */
- (SUPNullableTime)getNullableTime:(SUPInt)_index_1:(SUPString)_name_2;

/*!
 @method     
 @abstract   Retrieve datetime type data with given index and given name from the result set.
 @discussion 
 @param _index_1 - index in sql query list.
 @param -name_2 - name of the column.
 @result SUPNullableDateTime type of nullable data.
 */
- (SUPNullableDateTime)getNullableDateTime:(SUPInt)_index_1:(SUPString)_name_2;

@end

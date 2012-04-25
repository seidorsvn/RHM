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

#import "SUPTestCriteria.h"

@class SUPAttributeTest;

/*!
 @class SUPAttributeTest
 @abstract    Represents the test for an MBO attribute that must be satisfied by rows returned for an @link //apple_ref/occ/cl/SUPQuery SUPQuery @/link.
 @discussion 
 */

@interface SUPAttributeTest : SUPTestCriteria
{
    SUPString _attribute;
    SUPInt _operator;
    id _testValue;
}

/*!
 @enum
 @abstract Possible SUPAttributeTest values
 @discussion
 */
typedef enum
{
	SUPAttributeTest_IS_NULL = 1,
	SUPAttributeTest_NOT_NULL = 2,
	SUPAttributeTest_EQUAL = 3,
	SUPAttributeTest_NOT_EQUAL = 4,
	SUPAttributeTest_LIKE = 5,
	SUPAttributeTest_NOT_LIKE = 6,
	SUPAttributeTest_MATCH = 7,
	SUPAttributeTest_NOT_MATCH = 8,
	SUPAttributeTest_LESS_THAN = 9,
	SUPAttributeTest_LESS_EQUAL = 10,
	SUPAttributeTest_GREATER_THAN = 11,
	SUPAttributeTest_GREATER_EQUAL = 12,
	SUPAttributeTest_CONTAINS = 13,
	SUPAttributeTest_NOT_CONTAINS = 14,
	SUPAttributeTest_STARTS_WITH = 15,
	SUPAttributeTest_NOT_STARTS_WITH = 16,
	SUPAttributeTest_ENDS_WITH = 17,
	SUPAttributeTest_NOT_ENDS_WITH = 18
} SUPAttributeTestType;

/*!
    @method     
    @abstract   Returns an instance of SUPAttributeTest.
    @result The SUPAttributeTest.
    @discussion 
*/

+ (SUPAttributeTest*)getInstance;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest.
 @result The SUPAttributeTest.
 @discussion This method is deprecated. use getInstance instead.
 */

+ (SUPAttributeTest*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method     
 @abstract   Returns an initialized SUPAttributeTest.
 @result The SUPAttributeTest.
 @discussion 
 */

- (SUPAttributeTest*)init;


/*!
 @method     
 @abstract   Returns the constant value for filter type IS_NULL.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)IS_NULL;

/*!
 @method     
 @abstract   Returns the constant value for filter type NOT_NULL.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)NOT_NULL;

/*!
 @method     
 @abstract   Returns the constant value for filter type EQUAL.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)EQUAL;

/*!
 @method     
 @abstract   Returns the constant value for filter type NOT_EQUAL.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)NOT_EQUAL;

/*!
 @method     
 @abstract   Returns the constant value for filter type LIKE.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)LIKE;

/*!
 @method     
 @abstract   Returns the constant value for filter type NOT_LIKE.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)NOT_LIKE;

/*!
 @method     
 @abstract   Returns the constant value for filter type MATCH.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)MATCH;

/*!
 @method     
 @abstract   Returns the constant value for filter type NOT_MATCH.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)NOT_MATCH;

/*!
 @method     
 @abstract   Returns the constant value for filter type LESS_THAN.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)LESS_THAN;

/*!
 @method     
 @abstract   Returns the constant value for filter type LESS_EQUAL.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)LESS_EQUAL;

/*!
 @method     
 @abstract   Returns the constant value for filter type GREATER_THAN.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)GREATER_THAN;

/*!
 @method     
 @abstract   Returns the constant value for filter type GREATER_EQUAL.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)GREATER_EQUAL;

/*!
 @method     
 @abstract   Returns the constant value for filter type CONTAINS.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)CONTAINS;

/*!
 @method     
 @abstract   Returns the constant value for filter type NOT_CONTAINS.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)NOT_CONTAINS;

/*!
 @method     
 @abstract   Returns the constant value for filter type STARTS_WITH.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)STARTS_WITH;

/*!
 @method     
 @abstract   Returns the constant value for filter type NOT_STARTS_WITH.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)NOT_STARTS_WITH;

/*!
 @method     
 @abstract   Returns the constant value for filter type ENDS_WITH.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)ENDS_WITH;

/*!
 @method     
 @abstract   Returns the constant value for filter type NOT_ENDS_WITH.
 @result The filter type.
 @discussion 
 */
+ (SUPInt)NOT_ENDS_WITH;

/*!
 @property     
 @abstract   The attribute name to use for the filter.
 @discussion 
 */
@property(readwrite, copy, nonatomic) SUPString attribute;

/*!
 @property     
 @abstract   The filter type.
 @discussion 
 */
@property(readwrite, assign, nonatomic) SUPInt operator;

/*!
 @property     
 @abstract   The test value used to filter.
 @discussion 
 */
@property(readwrite, retain, nonatomic) id testValue;



+ (SUPAttributeTest*)isNull:(SUPString)a;
+ (SUPAttributeTest*)notNull:(SUPString)a;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type EQUAL.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)equal:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type NOT_EQUAL.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)notEqual:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type LIKE.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)like:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type NOT_LIKE.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)notLike:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type MATCH.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)match:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type NOT_MATCH.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)notMatch:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type LESS_THAN.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)lessThan:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type LESS_EQUAL.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)lessEqual:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type GREATER_THAN.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)greaterThan:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type GREATER_EQUAL.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)greaterEqual:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type CONTAINS.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)contains:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type EQUAL.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)startsWith:(SUPString)a:(id)v;

/*!
 @method     
 @abstract   Returns an instance of SUPAttributeTest for filter type EQUAL.
 @param a The attribute name to filter.
 @param v The value to use as the criteria for filter.
 @result The SUPAttributeTest.
 @discussion 
 */
+ (SUPAttributeTest*)endsWith:(SUPString)a:(id)v;
- (void)dealloc;

@end

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

@class SUPObjectList;
@class SUPTestCriteria;

#import "SUPTestCriteria.h"

@class SUPCompositeTest;

/*!
 @class SUPCompositeTest
 @abstract   Contains composite filter information for getting data from Mobile Business Objects.  Used in @link //apple_ref/occ/cl/SUPQuery SUPQuery @/link objects.
 @discussion 
 */
@interface SUPCompositeTest : SUPTestCriteria
{
    SUPInt _operator;
    SUPObjectList* _operands;
}

/*!
 @enum
 @abstract Possible SUPCompositeTest values.
 @discussion
 */
typedef enum
{
	SUPCompositeTest_NOT = 1,
	SUPCompositeTest_AND = 2,
	SUPCompositeTest_OR = 3	
} SUPCompositeTestType;

/*!
    @method     
    @abstract   Returns a new instance of SUPCompositeTest.
    @result The SUPCompositeTest.
    @discussion 
*/
+ (SUPCompositeTest*)getInstance;

/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPCompositeTest.
 @result The SUPCompositeTest.
 @discussion This method is deprecated. use getInstance.
 */

+ (SUPCompositeTest*)newInstance DEPRECATED_ATTRIBUTE;
- (SUPCompositeTest*)init;

/*!
 @method     
 @abstract   Returns operator type "NOT".
 @result The operator type.
 @discussion 
 */
+ (SUPInt)NOT;

/*!
 @method     
 @abstract   Returns operator type "AND".
 @result The operator type.
 @discussion 
 */

+ (SUPInt)AND;
/*!
 @method     
 @abstract   Returns operator type "OR".
 @discussion
 @result The operator type.
 */
+ (SUPInt)OR;

/*!
 @property     
 @abstract   The operator type.
 @discussion 
 */
@property(readwrite,assign, nonatomic) SUPInt operator;

/*!
 @property     
 @abstract   The test criteria for composite tests.
 @discussion 
 */
@property(readwrite,retain, nonatomic) SUPObjectList* operands;

/*!
 @method     
 @abstract   Add test criteria for the composite test.
 @discussion 
 @param operand The SUPTestCriteria.
 */
- (void)add:(SUPTestCriteria*)operand;
- (void)dealloc;

@end

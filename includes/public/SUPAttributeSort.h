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

@class SUPSortOrder;

@class SUPAttributeSort;

/*!
 @class SUPAttributeSort
 @abstract   This class represents the sort order for a particular attribute in an @link //apple_ref/occ/cl/SUPQuery SUPQuery @/link.  See @link //apple_ref/occ/cl/SUPSortOrder SUPSortOrder @/link for the sort order definitions.
 @discussion 
 */

@interface SUPAttributeSort : NSObject
{
    SUPString _attribute;
    SUPInt _sortOrder;
}


/*!
    @method     
    @abstract   Returns a new instance of SUPAttributeSort.
    @result The SUPAttributeSort object.
    @discussion 
*/

+ (SUPAttributeSort*)getInstance;
/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPAttributeSort.
 @result The SUPAttributeSort object.
 @discussion This method is deprecated. use getInstance instead.
 */

+ (SUPAttributeSort*)newInstance DEPRECATED_ATTRIBUTE;

- (SUPAttributeSort*)init;

/*!
 @method     
 @abstract   Returns the sort attribute.
 @result The attribute.
 @discussion 
 */

- (SUPString)attribute;

/*!
 @property     
 @abstract  The sort attribute.
 @discussion 
 */
@property(readwrite,copy, nonatomic) SUPString attribute;

/*!
 @property     
 @abstract   The sort order.
 @discussion 
 */
@property(readwrite,assign, nonatomic) SUPInt sortOrder;

/*!
 @method     
 @abstract  Returns the SUPAttributeSort object for "a" for ascending sort order.
 @param _a The attribute.
 @discussion 
 */
+ (SUPAttributeSort*)ascending:(SUPString)a;

/*!
 @method     
 @abstract  Returns the SUPAttributeSort object for "a" for descending sort order.
 @param _a The attribute.
 @discussion 
 */
+ (SUPAttributeSort*)descending:(SUPString)a;
- (SUPAttributeSort*)finishInit;
- (void)dealloc;

@end

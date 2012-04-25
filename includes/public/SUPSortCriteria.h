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

@class SUPAttributeSort;

#import "SUPArrayList.h"

@class SUPSortCriteria;

/*!
 @class SUPSortCriteria
 @abstract   An object that describes one or more attribute sorts for an @link //apple_ref/occ/cl/SUPQuery SUPQuery @/link.  It is a collection of @link //apple_ref/occ/cl/SUPSortOrder SUPSortOrder @/link objects.
 @discussion 
 */
@interface SUPSortCriteria : SUPArrayList
{
}

/*!
    @method     
    @abstract   Returns a new instance of SUPSortCriteria.
    @result The SUPSortCriteria.
    @discussion 
*/
+ (SUPSortCriteria*)getInstance;
/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPSortCriteria.
 @result The SUPSortCriteria.
 @discussion This method is deprecated. use getInstance.
 */
+ (SUPSortCriteria*)newInstance DEPRECATED_ATTRIBUTE;

- (SUPSortCriteria*)init;

/*!
 @method     
 @abstract   Returns an SUPSortCriteria initialized to "capacity".
 @param capacity The capacity.
 @result The SUPSortCriteria.
 @discussion 
 */
- (SUPSortCriteria*)initWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Returns an SUPSortCriteria initialized to "capacity".
 @param capacity The capacity.
 @result The SUPSortCriteria.
 @discussion 
 */

+ (SUPSortCriteria*)listWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Add  "item" to the SUPSortCriteria.
 @param item The item to add.
 @discussion 
 */
- (void)add:(SUPAttributeSort*)item;

/*!
 @method     
 @abstract   Return item at "index" position in the SUPSortCriteria.
 @param index The index.
 @result The item of type SUPAttributeSort.
 @discussion 
 */
- (SUPAttributeSort*)item:(SUPInt)index;
- (void)clear;
- (void)dealloc;

@end

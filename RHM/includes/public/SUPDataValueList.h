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

@class SUPJsonArray;
@class SUPJsonObject;
@class SUPDataValue;

#import "SUPArrayList.h"

@class SUPDataValueList;


/*!
 @class SUPDataValueList
 @abstract   An SUPDataValueList is a collection of @link //apple_ref/occ/cl/SUPDataValue SUPDataValue @/link objects.
 @discussion This class and related classes are used in processing result sets from queries (@link //apple_ref/occ/cl/SUPQueryResultSet SUPQueryResultSet @/link).
 */
@interface SUPDataValueList : SUPArrayList
{
}

- (SUPDataValueList*)finishInit;

/*!
 @method
 @abstract   Returns a new instance of SUPDataValueList.
 @discussion 
 @result    The SUPDataValueList object.
 */
+ (SUPDataValueList*)getInstance;

/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPDataValueList.
 @discussion This method is deprecated. use getInstance.
 @result    The SUPDataValueList object.
 */
+ (SUPDataValueList*)newInstance DEPRECATED_ATTRIBUTE;

/*!
 @method
 @abstract   Initializes an SUPDataValueList object.
 @discussion 
 @result    The initialized SUPDataValueList object.
 */
- (SUPDataValueList*)init;

/*!
 @method
 @abstract   Initializes an SUPDataValueList object to the given capacity.
 @discussion 
 @result    The initialized SUPDataValueList object.
 */
- (SUPDataValueList*)initWithCapacity:(SUPInt)capacity;

/*!
 @method
 @abstract   Initializes an SUPDataValueList object to the  given capacity.
 @discussion 
 @result    The initialized SUPDataValueList object.
 */
+ (SUPDataValueList*)listWithCapacity:(SUPInt)capacity;

/*!
 @method
 @abstract   Adds an item to the SUPDataValueList object.
 @discussion 
 @param item   The item to be added.
 */
- (void)add:(SUPDataValue*)item;

/*!
 @method
 @abstract   Returns the SUPDataValue of the item at index.
 @discussion 
 @param index The index within the SUPDataValueList.
 @result    The SUPDataValue of item at index.
 */
- (SUPDataValue*)item:(SUPInt)index;

/*!
 @method
 @abstract   Removes all objects from the SUPDataValueList.
 @discussion     
 */
- (void)clear;

/*!
 @method
 @abstract   Deallocates the memory occupied by the SUPDataValueList object.
 @discussion     
 */
- (void)dealloc;

@end

@interface SUPDataValueList(internal)

+ (SUPDataValueList*)fromJsonArray:(SUPJsonArray*)_array_1:(SUPInt)_flags;
+ (SUPJsonArray*)toJsonArray:(SUPDataValueList*)_list_1:(SUPInt)_flags;

@end


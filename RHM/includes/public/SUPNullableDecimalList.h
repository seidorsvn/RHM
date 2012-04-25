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


#import "SUPJsonArray.h"

#import "SUPArrayList.h"


/*!
 @class SUPNullableDecimalList
 @abstract An SUPNullableDecimalList is a collection of @link //apple_ref/c/tdef/SUPNullableDecimal SUPNullableDecimal @/link objects.
 @discussion  
 */
@interface SUPNullableDecimalList : SUPArrayList
{
    
}

- (SUPNullableDecimalList*)finishInit;

/*!
 @method
 @abstract   Returns a new instance of SUPNullableDecimalList.
 @discussion
 @result The initalized SUPNullableDecimalList.
 */

+ (SUPNullableDecimalList*)getInstance;

/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPNullableDecimalList.
 @discussion This method is deprecated. use getInstance.
 @result The initalized SUPNullableDecimalList.
 */

+ (SUPNullableDecimalList*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method
 @abstract   Returns the initialized SUPNullableDecimalList.
 @discussion
 @result The initalized SUPNullableDecimalList.
 */

- (SUPNullableDecimalList*)init;

/*!
 @method
 @abstract   Returns an SUPNullableDecimalList initialized to the specified capacity.
 @discussion
 @param  capacity The inital capacity of the SUPNullableDecimalList.
 @result  The SUPNullableDecimalList initialized to the specified capacity.
 */
- (SUPNullableDecimalList*)initWithCapacity:(SUPInt)capacity;


/*!
 @method
 @abstract   Returns an SUPNullableDecimalList initialized to the specified capacity.
 @discussion 
 @param  capacity The inital capacity of the SUPNullableDecimalList.
 @result  The SUPNullableDecimalList initialized to the specified capacity.
 */

+ (SUPNullableDecimalList*)listWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Add an item to the SUPNullableDecimalList.
 @discussion 
 @param item The item to be added.
 */

- (void)add:(SUPNullableDecimal)item;

/*!
 @method
 @abstract   Returns an SUPBoolean value that indicates whether item is present in the SUPNullableDecimalList.
 @discussion
 @param item The item.
 @result YES if item is present, otherwise NO.
 */
- (SUPBoolean)contains:(SUPNullableDecimal)item;

/*!
 @method
 @abstract   Returns the lowest index whose corresponding array value is equal to item.
 @discussion
 @param item The item.
 @result The lowest index whose corresponding array value is equal to the item. If none of the items is equal to item, returns -1.
 */
- (SUPInt)indexOf:(SUPNullableDecimal)item;

/*!
 @method
 @abstract   Returns the SUPNullableDecimal item at index.
 @discussion
 @param index The index.
 @result The item at the given index. 
 */
- (SUPNullableDecimal)item:(SUPInt)index;

/*!
 @method
 @abstract   Replaces the item at index  with the given item.
 @discussion
 @param item The item with which to replace the item at the given index in the SUPNullableDecimalList.
 @param index  The index of the item to be replaced. This value must not exceed the bounds of the SUPNullableDecimalList.
 */
- (void)setItemAt:(SUPNullableDecimal)item:(SUPInt)index;

/*!
 @method
 @abstract   Sets the array value of index to item.
 @discussion
 @param item The item.
 @param index The index whose corresponding array value is made equal to item. 
 */
- (void)insertItemAt:(SUPNullableDecimal)item:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item at index.
 @discussion
 @param index The index from which to remove the item. The value must not exceed the bounds of the SUPNullableDecimalList.
 */
- (void)removeItemAt:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item from the SUPNullableDecimalList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)removeItem:(SUPNullableDecimal)item;

/*!
 @method
 @abstract   Removes item from the SUPNullableDecimalList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)remove:(SUPNullableDecimal)item;

/*!
 @method
 @abstract   Returns the SUPNullableDecimalList with the item added.
 @discussion
 @param item The item to be added.
 @result The SUPNullableDecimalList.
 */
- (SUPNullableDecimalList*)addThis:(SUPNullableDecimal)item;

/*!
 @method
 @abstract   Push an item onto the SUPNullableDecimalList.
 @discussion
 @param item The item.
 @result The size of the SUPNullableDecimalList after adding the item.
 */
- (SUPInt)push:(SUPNullableDecimal)item;

/*!
 @method
 @abstract   Pop an item from the SUPNullableDecimalList.
 @discussion
 @result The item.
 */
- (SUPNullableDecimal)pop;

/*!
 @method
 @abstract   Returns an SUPNullableDecimalList initialized with items from the start index value to finish index value of this SUPNullableDecimalList. 
 @discussion
 @param start The start index value.
 @param finish The finish index value.
 @result The SUPNullableDecimalList initialized with items from the start index value to finish index value of this SUPNullableDecimalList.
 */
- (SUPNullableDecimalList*)slice:(SUPInt)start:(SUPInt)finish;

/*!
 @method
 @abstract   Deallocate the memory occupied by the SUPNullableDecimalList object.
 @discussion
 */
- (void)dealloc;

@end

@interface SUPNullableDecimalList(internal)

+ (SUPNullableDecimalList*)fromJsonArray:(SUPJsonArray*)_array_1:(SUPInt)_flags;
+ (SUPJsonArray*)toJsonArray:(SUPNullableDecimalList*)_list_1:(SUPInt)_flags;
- (void)initFields;

@end


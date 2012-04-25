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
 @class SUPDoubleList
 @abstract An SUPDoubleList is a collection of @link //apple_ref/c/tdef/SUPDouble SUPDouble @/link primitives.
 @discussion  
 */


@interface SUPDoubleList : SUPArrayList
{
    
}

- (SUPDoubleList*)finishInit;

/*!
 @method
 @abstract   Returns a new instance of SUPDoubleList.
 @discussion
 @result The initalized SUPDoubleList.
 */

+ (SUPDoubleList*)getInstance;

/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPDoubleList.
 @discussion This method is deprecated. use getInstance.
 @result The initalized SUPDoubleList.
 */

+ (SUPDoubleList*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method
 @abstract   Returns the initialized SUPDoubleList.
 @discussion
 @result The initalized SUPDoubleList.
 */
- (SUPDoubleList*)init;

/*!
 @method
 @abstract   Returns an SUPDoubleList initialized to the specified capacity.
 @discussion
 @param  capacity The inital capacity of the SUPDoubleList.
 @result  The SUPDoubleList initialized to the specified capacity.
 */
- (SUPDoubleList*)initWithCapacity:(SUPInt)capacity;

/*!
 @method
 @abstract   Returns an SUPDoubleList initialized to the specified capacity.
 @discussion 
 @param  capacity The inital capacity of the SUPDoubleList.
 @result  The SUPDoubleList initialized to the specified capacity.
 */

+ (SUPDoubleList*)listWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Add an item to the SUPDoubleList.
 @discussion 
 @param item The item to be added.
 */
- (void)add:(SUPDouble)item;

/*!
 @method
 @abstract   Returns an SUPBoolean value that indicates whether item is present in the SUPDoubleList.
 @discussion
 @param item The item.
 @result YES if item is present, otherwise NO.
 */
- (SUPBoolean)contains:(SUPDouble)item;

/*!
 @method
 @abstract   Returns the lowest index whose corresponding array value is equal to item.
 @discussion
 @param item The item.
 @result The lowest index whose corresponding array value is equal to the item. If none of the items is equal to item, returns -1.
 */
- (SUPInt)indexOf:(SUPDouble)item;

/*!
 @method
 @abstract   Returns the SUPDouble item at index.
 @discussion
 @param index The index.
 @result The item at the given index. 
 */
- (SUPDouble)item:(SUPInt)index;

/*!
 @method
 @abstract   Replaces the item at index  with the given item.
 @discussion
 @param item The item with which to replace the item at the given index in the SUPDoubleList.
 @param index  The index of the item to be replaced. This value must not exceed the bounds of the SUPDoubleList.
 */
- (void)setItemAt:(SUPDouble)item:(SUPInt)index;

/*!
 @method
 @abstract   Sets the array value of index to item.
 @discussion
 @param item The item.
 @param index The index whose corresponding array value is made equal to item. 
 */
- (void)insertItemAt:(SUPDouble)item:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item at index.
 @discussion
 @param index The index from which to remove the item. The value must not exceed the bounds of the SUPDoubleList.
 */
- (void)removeItemAt:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item from the SUPDoubleList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)removeItem:(SUPDouble)item;

/*!
 @method
 @abstract   Removes item from the SUPDoubleList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)remove:(SUPDouble)item;

/*!
 @method
 @abstract   Returns the SUPDoubleList with the item added.
 @discussion
 @param item The item to be added.
 @result The SUPDoubleList.
 */
- (SUPDoubleList*)addThis:(SUPDouble)item;

/*!
 @method
 @abstract   Push an item onto the SUPDoubleList.
 @discussion
 @param item The item.
 @result The size of the SUPDoubleList after adding the item.
 */
- (SUPInt)push:(SUPDouble)item;

/*!
 @method
 @abstract   Pop an item from the SUPDoubleList.
 @discussion
 @result The item.
 */

- (SUPDouble)pop;

/*!
 @method
 @abstract   Returns an SUPDoubleList initialized with items from the start index value to finish index value of this SUPDoubleList. 
 @discussion
 @param start The start index value.
 @param finish The finish index value.
 @result The SUPDoubleList initialized with items from the start index value to finish index value of this SUPDoubleList.
 */
- (SUPDoubleList*)slice:(SUPInt)start:(SUPInt)finish;

/*!
 @method
 @abstract   Deallocate the memory occupied by the SUPDoubleList object.
 @discussion
 */
- (void)dealloc;

@end

@interface SUPDoubleList(internal)

+ (SUPDoubleList*)fromJsonArray:(SUPJsonArray*)_array_1:(SUPInt)_flags;
+ (SUPJsonArray*)toJsonArray:(SUPDoubleList*)_list_1:(SUPInt)_flags;
- (void)initFields;

@end

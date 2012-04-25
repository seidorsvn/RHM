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
 @class SUPBooleanList
 @abstract An SUPBooleanList is a collection of @link //apple_ref/c/tdef/SUPBoolean SUPBoolean @/link primitives.
 @discussion  
 */
@interface SUPBooleanList : SUPArrayList
{
    
}

- (SUPBooleanList*)finishInit;

/*!
 @method
 @abstract   Returns a new instance of SUPBooleanList.
 @discussion
 @result The initalized SUPBooleanList.
 */
+ (SUPBooleanList*)getInstance;

/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPBooleanList.
 @discussion This method is deprecated. use getInstance.
 @result The initalized SUPBooleanList.
 */
+ (SUPBooleanList*)newInstance DEPRECATED_ATTRIBUTE;

/*!
 @method
 @abstract   Returns the initialized SUPBooleanList.
 @discussion
 @result The initalized SUPBooleanList.
 */
- (SUPBooleanList*)init;

/*!
 @method
 @abstract   Returns an SUPBooleanList initialized to the specified capacity.
 @discussion
 @param  capacity The inital capacity of the SUPBooleanList.
 @result  The SUPBooleanList initialized to the specified capacity.
 */
- (SUPBooleanList*)initWithCapacity:(SUPInt)capacity;

/*!
 @method
 @abstract   Returns an SUPBooleanList initialized to the specified capacity.
 @discussion 
 @param  capacity The inital capacity of the SUPBooleanList.
 @result  The SUPBooleanList initialized to the specified capacity.
 */

+ (SUPBooleanList*)listWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Add an item to the SUPBooleanList.
 @discussion 
 @param item The item to be added.
 */
- (void)add:(SUPBoolean)item;

/*!
 @method
 @abstract   Returns an SUPBoolean value that indicates whether item is present in the SUPBooleanList.
 @discussion
 @param item The item.
 @result YES if item is present, otherwise NO.
 */

- (SUPBoolean)contains:(SUPBoolean)item;

/*!
 @method
 @abstract   Returns the lowest index whose corresponding array value is equal to item.
 @discussion
 @param item The item.
 @result The lowest index whose corresponding array value is equal to the item. If none of the items is equal to item, returns -1.
 */
- (SUPInt)indexOf:(SUPBoolean)item;

/*!
 @method
 @abstract   Returns the SUPBoolean item at index.
 @discussion
 @param index The index.
 @result The item at the given index. 
 */
- (SUPBoolean)item:(SUPInt)index;

/*!
 @method
 @abstract   Replaces the item at index  with the given item.
 @discussion
 @param item The item with which to replace the item at the given index in the SUPBooleanList.
 @param index  The index of the item to be replaced. This value must not exceed the bounds of the SUPBooleanList.
 */
- (void)setItemAt:(SUPBoolean)item:(SUPInt)index;

/*!
 @method
 @abstract   Sets the array value of index to item.
 @discussion
 @param item The item.
 @param index The index whose corresponding array value is made equal to item. 
 */
- (void)insertItemAt:(SUPBoolean)item:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item at index.
 @discussion
 @param index The index from which to remove the item. The value must not exceed the bounds of the SUPBooleanList.
 */
- (void)removeItemAt:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item from the SUPBooleanList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)removeItem:(SUPBoolean)item;

/*!
 @method
 @abstract   Removes item from the SUPBooleanList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)remove:(SUPBoolean)item;

/*!
 @method
 @abstract   Returns the SUPBooleanList with the item added.
 @discussion
 @param item The item to be added.
 @result The SUPBooleanList.
 */
- (SUPBooleanList*)addThis:(SUPBoolean)item;

/*!
 @method
 @abstract   Push an item onto the SUPBooleanList.
 @discussion
 @param item The item.
 @result The size of the SUPBooleanList after adding the item.
 */
- (SUPInt)push:(SUPBoolean)item;

/*!
 @method
 @abstract   Pop an item from the SUPBooleanList.
 @discussion
 @result The item.
 */
- (SUPBoolean)pop;

/*!
 @method
 @abstract   Returns an SUPBooleanList initialized with items from the start index value to finish index value of this SUPBooleanList. 
 @discussion
 @param start The start index value.
 @param finish The finish index value.
 @result The SUPBooleanList initialized with items from the start index value to finish index value of this SUPBooleanList.
 */
- (SUPBooleanList*)slice:(SUPInt)start:(SUPInt)finish;

/*!
 @method
 @abstract   Deallocate the memory occupied by the SUPBooleanList object.
 @discussion
 */
- (void)dealloc;

@end

@interface SUPBooleanList(internal)

+ (SUPBooleanList*)fromJsonArray:(SUPJsonArray*)_array_1:(SUPInt)_flags;
+ (SUPJsonArray*)toJsonArray:(SUPBooleanList*)_list_1:(SUPInt)_flags;
- (void)initFields;

@end

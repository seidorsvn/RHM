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
 @class SUPShortList
 @abstract An SUPShortList is a collection of @link //apple_ref/c/tdef/SUPShort SUPShort @/link primitives.
 @discussion  
 */

@interface SUPShortList : SUPArrayList
{
    
}

- (SUPShortList*)finishInit;

/*!
 @method
 @abstract   Returns a new instance of SUPShortList.
 @discussion
 @result The initalized SUPShortList.
 */
+ (SUPShortList*)getInstance;

/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPShortList.
 @discussion This method is deprecated. use getInstance.
 @result The initalized SUPShortList.
 */
+ (SUPShortList*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method
 @abstract   Returns the initialized SUPShortList.
 @discussion
 @result The initalized SUPShortList.
 */

- (SUPShortList*)init;

/*!
 @method
 @abstract   Returns an SUPShortList initialized to the specified capacity.
 @discussion
 @param  capacity The inital capacity of the SUPShortList.
 @result  The SUPShortList initialized to the specified capacity.
 */
- (SUPShortList*)initWithCapacity:(SUPInt)capacity;
/*!
 @method
 @abstract   Returns an SUPShortList initialized to the specified capacity.
 @discussion 
 @param  capacity The inital capacity of the SUPShortList.
 @result  The SUPShortList initialized to the specified capacity.
 */
+ (SUPShortList*)listWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Add an item to the SUPShortList.
 @discussion 
 @param item The item to be added.
 */
- (void)add:(SUPShort)item;

/*!
 @method
 @abstract   Returns an SUPBoolean value that indicates whether item is present in the SUPShortList.
 @discussion
 @param item The item.
 @result YES if item is present, otherwise NO.
 */
- (SUPBoolean)contains:(SUPShort)item;

/*!
 @method
 @abstract   Returns the lowest index whose corresponding array value is equal to item.
 @discussion
 @param item The item.
 @result The lowest index whose corresponding array value is equal to the item. If none of the items is equal to item, returns -1.
 */
- (SUPInt)indexOf:(SUPShort)item;

/*!
 @method
 @abstract   Returns the SUPShort item at index.
 @discussion
 @param index The index.
 @result The item at the given index. 
 */
- (SUPShort)item:(SUPInt)index;

/*!
 @method
 @abstract   Replaces the item at index  with the given item.
 @discussion
 @param item The item with which to replace the item at the given index in the SUPShortList.
 @param index  The index of the item to be replaced. This value must not exceed the bounds of the SUPShortList.
 */
- (void)setItemAt:(SUPShort)item:(SUPInt)index;

/*!
 @method
 @abstract   Sets the array value of index to item.
 @discussion
 @param item The item.
 @param index The index whose corresponding array value is made equal to item. 
 */
- (void)insertItemAt:(SUPShort)item:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item at index.
 @discussion
 @param index The index from which to remove the item. The value must not exceed the bounds of the SUPShortList.
 */
- (void)removeItemAt:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item from the SUPShortList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)removeItem:(SUPShort)item;

/*!
 @method
 @abstract   Removes item from the SUPShortList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)remove:(SUPShort)item;

/*!
 @method
 @abstract   Returns the SUPShortList with the item added.
 @discussion
 @param item The item to be added.
 @result The SUPShortList.
 */
- (SUPShortList*)addThis:(SUPShort)item;

/*!
 @method
 @abstract   Push an item onto the SUPShortList.
 @discussion
 @param item The item.
 @result The size of the SUPShortList after adding the item.
 */
- (SUPInt)push:(SUPShort)item;

/*!
 @method
 @abstract   Pop an item from the SUPShortList.
 @discussion
 @result The item.
 */

- (SUPShort)pop;

/*!
 @method
 @abstract   Returns an SUPShortList initialized with items from the start index value to finish index value of this SUPShortList. 
 @discussion
 @param start The start index value.
 @param finish The finish index value.
 @result The SUPShortList initialized with items from the start index value to finish index value of this SUPShortList.
 */
- (SUPShortList*)slice:(SUPInt)start:(SUPInt)finish;

/*!
 @method
 @abstract   Deallocate the memory occupied by the SUPShortList object.
 @discussion
 */
- (void)dealloc;

@end

@interface SUPShortList(internal)

+ (SUPShortList*)fromJsonArray:(SUPJsonArray*)_array_1:(SUPInt)_flags;
+ (SUPJsonArray*)toJsonArray:(SUPShortList*)_list_1:(SUPInt)_flags;
- (void)initFields;

@end


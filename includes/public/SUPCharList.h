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
 @class SUPCharList
 @abstract An SUPCharList is a collection of @link //apple_ref/c/tdef/SUPChar SUPChar @/link primitives.
 @discussion  
 */

@interface SUPCharList : SUPArrayList
{
    
}

- (SUPCharList*)finishInit;

/*!
 @method
 @abstract   Returns a new instance of SUPCharList.
 @discussion
 @result The initalized SUPCharList.
 */
+ (SUPCharList*)getInstance;

/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPCharList.
 @discussion This method is deprecated. use getInstance.
 @result The initalized SUPCharList.
 */
+ (SUPCharList*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method
 @abstract   Returns the initialized SUPCharList.
 @discussion
 @result The initalized SUPCharList.
 */
- (SUPCharList*)init;

/*!
 @method
 @abstract   Returns an SUPCharList initialized to the specified capacity.
 @discussion
 @param  capacity The inital capacity of the SUPCharList.
 @result  The SUPCharList initialized to the specified capacity.
 */
- (SUPCharList*)initWithCapacity:(SUPInt)capacity;

/*!
 @method
 @abstract   Returns an SUPCharList initialized to the specified capacity.
 @discussion 
 @param  capacity The inital capacity of the SUPCharList.
 @result  The SUPCharList initialized to the specified capacity.
 */
+ (SUPCharList*)listWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Add an item to the SUPCharList.
 @discussion 
 @param item The item to be added.
 */
- (void)add:(SUPChar)item;

/*!
 @method
 @abstract   Returns an SUPBoolean value that indicates whether item is present in the SUPCharList.
 @discussion
 @param item The item.
 @result YES if item is present, otherwise NO.
 */
- (SUPBoolean)contains:(SUPChar)item;


/*!
 @method
 @abstract   Returns the lowest index whose corresponding array value is equal to item.
 @discussion
 @param item The item.
 @result The lowest index whose corresponding array value is equal to the item. If none of the items is equal to item, returns -1.
 */
- (SUPInt)indexOf:(SUPChar)item;

/*!
 @method
 @abstract   Returns the SUPChar item at index.
 @discussion
 @param index The index.
 @result The item at the given index. 
 */
- (SUPChar)item:(SUPInt)index;

/*!
 @method
 @abstract   Replaces the item at index  with the given item.
 @discussion
 @param item The item with which to replace the item at the given index in the SUPCharList.
 @param index  The index of the item to be replaced. This value must not exceed the bounds of the SUPCharList.
 */
- (void)setItemAt:(SUPChar)item:(SUPInt)index;

/*!
 @method
 @abstract   Sets the array value of index to item.
 @discussion
 @param item The item.
 @param index The index whose corresponding array value is made equal to item. 
 */
- (void)insertItemAt:(SUPChar)item:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item at index.
 @discussion
 @param index The index from which to remove the item. The value must not exceed the bounds of the SUPCharList.
 */
- (void)removeItemAt:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item from the SUPCharList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)removeItem:(SUPChar)item;


/*!
 @method
 @abstract   Removes item from the SUPCharList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)remove:(SUPChar)item;

/*!
 @method
 @abstract   Returns the SUPCharList with the item added.
 @discussion
 @param item The item to be added.
 @result The SUPCharList.
 */
- (SUPCharList*)addThis:(SUPChar)item;

/*!
 @method
 @abstract   Push an item onto the SUPCharList.
 @discussion
 @param item The item.
 @result The size of the SUPCharList after adding the item.
 */
- (SUPInt)push:(SUPChar)item;

/*!
 @method
 @abstract   Pop an item from the SUPCharList.
 @discussion
 @result The item.
 */
- (SUPChar)pop;

/*!
 @method
 @abstract   Returns an SUPCharList initialized with items from the start index value to finish index value of this SUPCharList. 
 @discussion
 @param start The start index value.
 @param finish The finish index value.
 @result The SUPCharList initialized with items from the start index value to finish index value of this SUPCharList.
 */
- (SUPCharList*)slice:(SUPInt)start:(SUPInt)finish;

/*!
 @method
 @abstract   Returns a concatenation of the characters in this SUPCharList. 
 @discussion
 @result An SUPString object containing the characters in this SUPCharList.
 */
- (SUPString)concat;

/*!
 @method
 @abstract   Deallocate the memory occupied by the SUPCharList object.
 @discussion
 */
- (void)dealloc;

@end

@interface SUPCharList(internal)

+ (SUPCharList*)fromJsonArray:(SUPJsonArray*)_array_1:(SUPInt)_flags;
+ (SUPJsonArray*)toJsonArray:(SUPCharList*)_list_1:(SUPInt)_flags;
- (void)initFields;

@end

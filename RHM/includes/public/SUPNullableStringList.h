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
 @class SUPNullableStringList
 @abstract An SUPNullableStringList is a collection of @link //apple_ref/c/tdef/SUPNullableString SUPNullableString @/link objects.
 @discussion  
 */
@interface SUPNullableStringList : SUPArrayList
{
    
}

- (SUPNullableStringList*)finishInit;

/*!
 @method
 @abstract   Returns a new instance of SUPNullableStringList.
 @discussion
 @result The initalized SUPNullableStringList.
 */
+ (SUPNullableStringList*)getInstance;
/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPNullableStringList.
 @discussion This method is deprecated. use getInstance.
 @result The initalized SUPNullableStringList.
 */
+ (SUPNullableStringList*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method
 @abstract   Returns the initialized SUPNullableStringList.
 @discussion
 @result The initalized SUPNullableStringList.
 */

- (SUPNullableStringList*)init;

/*!
 @method
 @abstract   Returns an SUPNullableStringList initialized to the specified capacity.
 @discussion
 @param  capacity The inital capacity of the SUPNullableStringList.
 @result  The SUPNullableStringList initialized to the specified capacity.
 */
- (SUPNullableStringList*)initWithCapacity:(SUPInt)capacity;

/*!
 @method
 @abstract   Returns an SUPNullableStringList initialized to the specified capacity.
 @discussion 
 @param  capacity The inital capacity of the SUPNullableStringList.
 @result  The SUPNullableStringList initialized to the specified capacity.
 */
+ (SUPNullableStringList*)listWithCapacity:(SUPInt)capacity;


/*!
 @method     
 @abstract   Add an item to the SUPNullableStringList.
 @discussion 
 @param item The item to be added.
 */
- (void)add:(SUPNullableString)item;

/*!
 @method
 @abstract   Returns an SUPBoolean value that indicates whether item is present in the SUPNullableStringList.
 @discussion
 @param item The item.
 @result YES if item is present, otherwise NO.
 */
- (SUPBoolean)contains:(SUPNullableString)item;

/*!
 @method
 @abstract   Returns the lowest index whose corresponding array value is equal to item.
 @discussion
 @param item The item.
 @result The lowest index whose corresponding array value is equal to the item. If none of the items is equal to item, returns -1.
 */
- (SUPInt)indexOf:(SUPNullableString)item;

/*!
 @method
 @abstract   Returns the SUPNullableString item at index.
 @discussion
 @param index The index.
 @result The item at the given index. 
 */

- (SUPNullableString)item:(SUPInt)index;

/*!
 @method
 @abstract   Replaces the item at index  with the given item.
 @discussion
 @param item The item with which to replace the item at the given index in the SUPNullableStringList.
 @param index  The index of the item to be replaced. This value must not exceed the bounds of the SUPNullableStringList.
 */
- (void)setItemAt:(SUPNullableString)item:(SUPInt)index;

/*!
 @method
 @abstract   Sets the array value of index to item.
 @discussion
 @param item The item.
 @param index The index whose corresponding array value is made equal to item. 
 */
- (void)insertItemAt:(SUPNullableString)item:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item at index.
 @discussion
 @param index The index from which to remove the item. The value must not exceed the bounds of the SUPNullableStringList.
 */
- (void)removeItemAt:(SUPInt)index;


/*!
 @method
 @abstract   Removes the item from the SUPNullableStringList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */

- (SUPBoolean)removeItem:(SUPNullableString)item;

/*!
 @method
 @abstract   Removes item from the SUPNullableStringList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)remove:(SUPNullableString)item;

/*!
 @method
 @abstract   Returns the SUPNullableStringList with the item added.
 @discussion
 @param item The item to be added.
 @result The SUPNullableStringList.
 */
- (SUPNullableStringList*)addThis:(SUPNullableString)item;

/*!
 @method
 @abstract   Push an item onto the SUPNullableStringList.
 @discussion
 @param item The item.
 @result The size of the SUPNullableStringList after adding the item.
 */
- (SUPInt)push:(SUPNullableString)item;

/*!
 @method
 @abstract   Pop an item from the SUPNullableStringList.
 @discussion
 @result The item.
 */
- (SUPNullableString)pop;


/*!
 @method
 @abstract   Returns an SUPNullableStringList initialized with items from the start index value to finish index value of this SUPNullableStringList. 
 @discussion
 @param start The start index value.
 @param finish The finish index value.
 @result The SUPNullableStringList initialized with items from the start index value to finish index value of this SUPNullableStringList.
 */

- (SUPNullableStringList*)slice:(SUPInt)start:(SUPInt)finish;

/*!
 @method
 @abstract Returns a concatenation of the strings in this SUPNullableStringList.
 @discussion
 @result A single SUPString containing the strings in this SUPNullableStringList.
 */
- (SUPString)concat;

/*!
 @method
 @abstract Returns a string that is a concatenation of the strings in this SUPNullableStringList, with a separator string between adjacent items.
 @discussion
 @param separator The string used as a separator.
 @result A single SUPString containing the strings in this SUPNullableStringList, separated by the separator string.
 */
- (SUPString)join:(SUPString)separator;

/*!
 @method
 @abstract   Deallocate the memory occupied by the SUPNullableStringList object.
 @discussion
 */
- (void)dealloc;

@end

@interface SUPNullableStringList(internal)

+ (SUPNullableStringList*)fromJsonArray:(SUPJsonArray*)_array_1:(SUPInt)_flags;
+ (SUPJsonArray*)toJsonArray:(SUPNullableStringList*)_list_1:(SUPInt)_flags;
- (void)initFields;

@end

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
 @class SUPStringList
 @abstract An SUPStringList is a collection of @link //apple_ref/c/tdef/SUPString SUPString @/link objects.
 @discussion  
 */
@interface SUPStringList : SUPArrayList
{
    
}


/*!
 @method
 @abstract   Takes a single string "value" and breaks it up into a list of strings.The "separator" attribute (usually a comma) is used to decide where to divide up the string.
 @discussion
 @param value The string.
 @param separator separator to split string.
 @result The list of strings.
 */
+ (SUPStringList*)split:(SUPString)value:(SUPString)separator;

/*!
 @method
 @abstract   Split an SUPString to an SUPStringList based on the specified separator. If the string length exceeds the limit, remains will not be splitted.
 @discussion
 @param value String to split.
 @param separator separator to split string.
 @param limit maximum length to split.
 @result The list of strings.
 */
+ (SUPStringList*)splitWithLimit:(SUPString)value:(SUPString)separator:(SUPInt)limit;
- (SUPStringList*)finishInit;

/*!
 @method
 @abstract   Returns a new instance of SUPStringList.
 @discussion
 @result The initalized SUPStringList.
 */
+ (SUPStringList*)getInstance;

/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPStringList.
 @discussion This method is deprecated. use getInstance.
 @result The initalized SUPStringList.
 */
+ (SUPStringList*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method
 @abstract   Returns the initialized SUPStringList.
 @discussion
 @result The initalized SUPStringList.
 */


- (SUPStringList*)init;

/*!
 @method
 @abstract   Returns an SUPStringList initialized to the specified capacity.
 @discussion
 @param  capacity The inital capacity of the SUPStringList.
 @result  The SUPStringList initialized to the specified capacity.
 */
- (SUPStringList*)initWithCapacity:(SUPInt)capacity;

/*!
 @method
 @abstract   Returns an SUPStringList initialized to the specified capacity.
 @discussion 
 @param  capacity The inital capacity of the SUPStringList.
 @result  The SUPStringList initialized to the specified capacity.
 */
+ (SUPStringList*)listWithCapacity:(SUPInt)capacity;
/*!
 @method     
 @abstract   Add an item to the SUPStringList.
 @discussion 
 @param item The item to be added.
 */
- (void)add:(SUPString)item;


/*!
 @method
 @abstract   Returns an SUPBoolean value that indicates whether item is present in the SUPStringList.
 @discussion
 @param item The item.
 @result YES if item is present, otherwise NO.
 */
- (SUPBoolean)contains:(SUPString)item;

/*!
 @method
 @abstract   Returns the lowest index whose corresponding array value is equal to item.
 @discussion
 @param item The item.
 @result The lowest index whose corresponding array value is equal to the item. If none of the items is equal to item, returns -1.
 */
- (SUPInt)indexOf:(SUPString)item;

/*!
 @method
 @abstract   Returns the SUPString item at index.
 @discussion
 @param index The index.
 @result The item at the given index. 
 */
- (SUPString)item:(SUPInt)index;

/*!
 @method
 @abstract   Replaces the item at index  with the given item.
 @discussion
 @param item The item with which to replace the item at the given index in the SUPStringList.
 @param index  The index of the item to be replaced. This value must not exceed the bounds of the SUPStringList.
 */
- (void)setItemAt:(SUPString)item:(SUPInt)index;

/*!
 @method
 @abstract   Sets the array value of index to item.
 @discussion
 @param item The item.
 @param index The index whose corresponding array value is made equal to item. 
 */
- (void)insertItemAt:(SUPString)item:(SUPInt)index;
/*!
 @method
 @abstract   Removes the item at index.
 @discussion
 @param index The index from which to remove the item. The value must not exceed the bounds of the SUPStringList.
 */
- (void)removeItemAt:(SUPInt)index;

/*!
 @method
 @abstract   Removes the item from the SUPStringList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)removeItem:(SUPString)item;

/*!
 @method
 @abstract   Removes item from the SUPStringList.
 @discussion
 @param item The item to be removed.
 @result YES if the item was removed, otherwise NO.
 */
- (SUPBoolean)remove:(SUPString)item;

/*!
 @method
 @abstract   Returns the SUPStringList with the item added.
 @discussion
 @param item The item to be added.
 @result The SUPStringList.
 */
- (SUPStringList*)addThis:(SUPString)item;

/*!
 @method
 @abstract   Push an item onto the SUPStringList.
 @discussion
 @param item The item.
 @result The size of the SUPStringList after adding the item.
 */
- (SUPInt)push:(SUPString)item;

/*!
 @method
 @abstract   Pop an item from the SUPStringList.
 @discussion
 @result The item.
 */
- (SUPString)pop;

/*!
 @method
 @abstract   Returns an SUPStringList initialized with items from the start index value to finish index value of this SUPStringList. 
 @discussion
 @param start The start index value.
 @param finish The finish index value.
 @result The SUPStringList initialized with items from the start index value to finish index value of this SUPStringList.
 */
- (SUPStringList*)slice:(SUPInt)start:(SUPInt)finish;

/*!
 @method
 @abstract   Returns an SUPString concatenated with all the items in the SUPStringList.
 @result The concatenated string.
 @discussion
 */
- (SUPString)concat;


/*!
 @method
 @abstract   Return an  SUPString concatenated with  all the items with separator.
 @param separator The separator.
 @result The concatenated string.
 @discussion
 */
- (SUPString)join:(SUPString)separator;

/*!
 @method
 @abstract   Deallocate the memory occupied by the SUPStringList object.
 @discussion
 */
- (void)dealloc;

@end

@interface SUPStringList(internal)

+ (SUPStringList*)fromJsonArray:(SUPJsonArray*)_array_1:(SUPInt)_flags;
+ (SUPJsonArray*)toJsonArray:(SUPStringList*)_list_1:(SUPInt)_flags;
- (void)initFields;

@end


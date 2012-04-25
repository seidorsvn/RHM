/*
 
 Copyright (c) Sybase, Inc. 2010  All rights reserved.                                   
 
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


/*!
 @class SUPArrayList
 @abstract Manages a mutable array of objects.
 @discussion This class is the base class for SUPObjectList, SUPStringList, and the other SUP collections classes.
 */ 
@interface SUPArrayList : NSObject < NSFastEnumeration >
{
@public
    NSMutableArray* array;
}

/*!
 @method
 @abstract   Returns the initialized SUPArrayList Object.
 @discussion
 @result The initalized SUPArrayList object.
 */
- (SUPArrayList*)init;

/*!
 @method
 @abstract   Returns an SUPArrayList initialized with enough memory to initially hold a given number of objects.
 @discussion The SUPArrayList expands as needed. The paramter simply establishes the objects initial capacity. 
 @param  capacity The inital capacity of the SUPArrayList.
 @result  The SUPArrayList object initialized to the specified capacity.
 */
- (SUPArrayList*)initWithCapacity:(SUPInt)capacity;

- (NSMutableArray*)array;
/*!
 @property     
 @abstract   The NSMutableArray object contained by this SUPArrayList object.
 @discussion
 */
@property(readwrite,retain,nonatomic) NSMutableArray* array;

- (SUPInt)length;
/*!
 @property
 @abstract   The length (number of elements) of the SUPArrayList.
 @discussion
 */
@property(readonly,assign,nonatomic) SUPInt length;

/*!
 @method
 @abstract   Returns the size  of the SUPArrayList.
 @discussion 
 @result The SUPInt value denoting the size of the SUPArrayList.
 */
- (SUPInt)size;

/*!
 @method
 @abstract   Inserts the given object at the end of the SUPArrayList.
 @discussion
 @param object The object to add at the end of the SUPArrayList. It can be nil.
 */
- (void)addObject:(id)object;

/*!
 @method
 @abstract   Returns a reference to an object located within the SUPArrayList at a given index.
 @discussion
 @param index The index into the SUPArrayList from which the reference to an object is taken.
 @result A reference to an object located within the SUPArrayList at the given index.
 */
- (id)getObject:(SUPInt)index;
- (void)clear;

/*!
 @method
 @abstract   Returns an SUPBoolean value that indicates whether object is present in the SUPArrayList.
 @discussion
 @param object The object.
 @result YES if object is present in the SUPArrayList, otherwise NO.
 */
- (SUPBoolean)containsObject:(id)object;

/*!
 @method
 @abstract   Returns the lowest index whose corresponding array value is equal to object.
 @discussion
 @param object The object.
 @result The lowest index whose corresponding array value is equal to object. If none of the objects in the receiver is equal to object, returns -1.
 */
- (SUPInt)indexOfObject:(id)object;

/*!
 @method
 @abstract   Returns the object at index.
 @discussion
 @param index The index.
 @result The object at the given index. 
 */
- (id)objectAtIndex:(SUPInt)index;

/*!
 @method
 @abstract   Replaces the object at index  with item.
 @discussion
 @param item The object with which to replace the object at the given index in the SUPArrayList. This value must not be nil.
 @param index  The index of the object to be replaced. This value must not exceed the bounds of the receiver.
 */
- (void)setObjectAt:(id)item:(SUPInt)index;

/*!
 @method
 @abstract   Inserts the  given object into the list at the given index.
 @discussion
 @param item The object to insert.
 @param index The index at which to insert the object. 
 */
- (void)insertObjectAt:(id)item:(SUPInt)index;

/*!
 @method
 @abstract   Removes the object at index.
 @discussion
 @param index The index from which to remove the object. The value must not exceed the bounds of the SUPArrayList.
 */
- (void)removeObjectAt:(SUPInt)index;
/*!
 @method
 @abstract   Removes item from the SUPArrayList.
 @discussion
 @param item The object to be removed.
 @result YES if the object was removed, otherwise NO.
 */
- (SUPBoolean)removeObject:(id)item;

/*!
 @method
 @abstract   Returns by reference a C array of objects over which the sender should iterate, and as the return value the number of objects in the array.
 @discussion
 @param state Context information that is used in the enumeration to, in addition to other possibilities, ensure that the collection has not been mutated.
 @param stackbuf A C array of objects over which the sender is to iterate.
 @param len The maximum number of objects to return in stackbuf.
 @result The number of objects returned in stackbuf. Returns 0 when the iteration is finished.
 */
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackbuf count:(NSUInteger)len;

/*!
 @method
 @abstract   Takes a segment of another SUPArrayList, and adds the objects from that segment to this SUPArrayList.
 @discussion
 @param from The SUPArrayList from which the segment is taken.
 @param start The start of the segment.
 @param finish The end of the segment.
 */
- (void)addSlice:(SUPArrayList*)from:(SUPInt)start:(SUPInt)finish;

/*!
 @method     
 @abstract   Returns the string representation of the objects contained in the SUPArrayList.
 @discussion 
 */
- (SUPString)toString;


@end

@interface SUPArrayList(internal)

- (void)initFields;

@end

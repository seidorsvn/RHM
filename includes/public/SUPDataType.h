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

@class SUPJsonObject;
@class SUPBasicTypes;
@class SUPObjectNotFoundException;
@class SUPDataType;


/*!
 @class SUPDataType
 @abstract   This class defines the different allowed types for SUP class and entity attributes.
 @discussion 
 */
@interface SUPDataType : NSObject
{
    SUPInt _code;
    SUPNullableString _name;
    SUPBoolean _nullable;
	SUPDataType* _itemType;
}



/*!
 @method     
 @abstract   Returns a new instance of the SUPDataType object.
 @result     The SUPDataType object.
 @discussion 
 */
+ (SUPDataType*)getInstance;

/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of the SUPDataType object.
 @result     The SUPDataType object.
 @discussion This method is deprecated. use getInstance.
 */
+ (SUPDataType*)newInstance DEPRECATED_ATTRIBUTE;


/*!
 @method     
 @abstract   Returns the initialized SUPDataType object.
 @result     The SUPDataType object.
 @discussion 
 */
- (SUPDataType*)init;


/*!
 @method     
 @abstract   Returns the typecode for VOID.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)VOID;

/*!
 @method     
 @abstract   Returns the typecode for OBJECT.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)OBJECT;

/*!
 @method     
 @abstract   Returns the typecode for BOOLEAN.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)BOOLEAN;

/*!
 @method     
 @abstract   Returns the typecode for STRING.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)STRING;

/*!
 @method     
 @abstract   Returns the typecode for BINARY.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)BINARY;

/*!
 @method     
 @abstract   Returns the typecode for CHAR.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)CHAR;

/*!
 @method     
 @abstract   Returns the typecode for BYTE.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)BYTE;

/*!
 @method     
 @abstract   Returns the typecode for SHORT.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)SHORT;

/*!
 @method     
 @abstract   Returns the typecode for INT.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)INT;

/*!
 @method     
 @abstract   Returns the typecode for LONG.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)LONG;

/*!
 @method     
 @abstract   Returns the typecode for INTEGER.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)INTEGER;

/*!
 @method     
 @abstract   Returns the typecode for DECIMAL.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)DECIMAL;

/*!
 @method     
 @abstract   Returns the typecode for FLOAT.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)FLOAT;

/*!
 @method     
 @abstract   Returns the typecode for DOUBLE.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)DOUBLE;

/*!
 @method     
 @abstract   Returns the typecode for DATE.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)DATE;

/*!
 @method     
 @abstract   Returns the typecode for TIME.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)TIME;

/*!
 @method     
 @abstract   Returns the typecode for DATE_TIME.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)DATE_TIME;

/*!
 @method     
 @abstract   Returns the typecode for LIST.
 @result     The typecode.
 @discussion 
 */
+ (SUPInt)LIST;

/*!
 @property
 @abstract The typecode for this SUPDataType object.
 @discussion
 */
@property(readwrite, assign, nonatomic) SUPInt code;

/*!
 @property
 @abstract The name of this SUPDataType object.
 @discussion
 */
@property(readwrite, retain, nonatomic) SUPNullableString name;

/*!
 @property
 @abstract Nullability of this SUPDataType object (YES if nullable, NO if not).
 @discussion
 */
@property(readwrite, assign, nonatomic) SUPBoolean nullable;

/*!
 @property
 @abstract If this SUPDataType is a list, itemType specifies the type of the items in the list..
 @discussion
 */
@property(readwrite, retain, nonatomic) SUPDataType *itemType;

/*!
 @method
 @abstract Returns an SUPDataType object corresponding to the input name.
 @discussion
 @param theName The input name (should be one of the standard data types)
 @result An SUPDataType object.
 */
+ (SUPDataType*)forName:(SUPString)theName;

/*!
 @method
 @abstract Returns an SUPDataType object corresponding to a list of items of the input type.
 @discussion
 @param theType The input type
 @result An SUPDataType object.
 */
+ (SUPDataType*)listOf:(SUPDataType*)theType;


- (void)dealloc;
- (SUPDataType*)finishInit;
@end

@interface SUPDataType(internal)

+ (SUPDataType*)_dc4:(SUPInt)p_code:(SUPNullableString)p_name:(SUPBoolean)p_nullable;
+ (SUPDataType*)_dc5:(SUPInt)p_code:(SUPNullableString)p_name:(SUPBoolean)p_nullable:(SUPDataType*)p_itemType;
+ (SUPDataType*)fromJsonObject:(SUPJsonObject*)_object_1:(SUPInt)_flags;
+ (SUPJsonObject*)toJsonObject:(SUPDataType*)_object:(SUPInt)_flags;
- (void)readJson:(SUPJsonObject*)_object_1:(SUPInt)_flags;
- (SUPJsonObject*)writeJson:(SUPInt)_flags;
- (SUPString)toString;

@end


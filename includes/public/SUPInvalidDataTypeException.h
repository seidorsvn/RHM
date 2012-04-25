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

@class SUPInvalidDataTypeException;


/*!
 @class SUPInvalidDataTypeException
 @abstract   This exception may be thrown if an invalid data type is passed in when parsing an @link //apple_ref/occ/cl/SUPDataValue SUPDataValue @/link.
 @discussion 
 */
@interface SUPInvalidDataTypeException : NSException
{
}

/*!
 @method
 @abstract   Returns a new instance of SUPInvalidDataTypeException.
 @discussion 
 @result    SUPAbstractClassException object.
 */
+ (SUPInvalidDataTypeException*)getInstance;

/*!
 @method
 @abstract   (Deprecated) Returns a new instance of SUPInvalidDataTypeException.
 @discussion This method is deprecated. use getInstance.
 @result    SUPAbstractClassException object.
 */
+ (SUPInvalidDataTypeException*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method
 @abstract   Initializes an SUPInvalidDataTypeException object.
 @discussion 
 @result    The initialized SUPInvalidDataTypeException object.
 */
- (SUPInvalidDataTypeException*)init;
- (SUPInvalidDataTypeException*)finishInit;

/*!
 @method
 @abstract   Deallocates the memory occupied by the SUPInvalidDataTypeException object.
 @discussion 
 @result    
 */

- (void)dealloc;

/*!
 @method     
 @abstract   Overrides Apple's NSException method name()
 @result String with the exception name.
 @discussion 
 */
- (NSString*)name;


/*!
 @method
 @abstract  Overrides Apple's description method.
 @result String combining the name and reason strings.
 */
- (NSString*)description;


@end

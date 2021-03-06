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

#import "SUPPersistenceException.h"

@class SUPTooManyResultsException;


/*!
 @class SUPTooManyResultsException
 @abstract   This type of exception is for certain types of errors when getting a result set from the database.  This class is not used in this version of the SUP iPhone framework.
 @discussion 
 */
@interface SUPTooManyResultsException : SUPPersistenceException
{
}


/*!
    @method     
    @abstract   Returns a new instance of SUPTooManyResultsException object.
    @result The SUPTooManyResultsException object.
    @discussion 
*/

+ (SUPTooManyResultsException*)getInstance;

/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPTooManyResultsException object.
 @result The SUPTooManyResultsException object.
 @discussion This method is deprecated. use getInstance.
 */

+ (SUPTooManyResultsException*)newInstance DEPRECATED_ATTRIBUTE;


/*!
 @method     
 @abstract   Returns an initialized SUPTooManyResultsException object.
 @result The SUPTooManyResultsException object.
 @discussion 
 */
- (SUPTooManyResultsException*)init;

/*!
 @method     
 @abstract   Overrides Apple's NSException method name()
 @result String with the exception name.
 @discussion 
 */
- (NSString*)name;

/*!
 @method     
 @abstract   Overrides Apple's NSException method reason().
 @result String with the reason for the exception (in this case, the contents of the "message" field).
 @discussion 
 */
- (NSString*)reason;

/*!
 @method
 @abstract  Overrides Apple's description method.
 @result String combining the name and reason strings.
 */
- (NSString*)description;

/*!
 @method     
 @abstract   Deallocates the memory occupied by the SUPTooManyResultsException object.
 @discussion 
 */
- (void)dealloc;

@end

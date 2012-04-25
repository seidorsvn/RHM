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
/*!
 @class
 @abstract    Represents the allowed SUP synchronization action values.
 @discussion  An int value of: 0 or 1. Corresponds to CANCEL, CONTINUE.
 */

@interface SUPSynchronizationAction : NSObject
{
}

/*!
 @enum
 @abstract Possible SUPSynchronizationAction values.
 @discussion
 */
typedef enum
{
    SUPSynchronizationAction_CANCEL = 0,
    SUPSynchronizationAction_CONTINUE = 1
} SUPSynchronizationActionType;

/*!
 @enum
 @abstract Possible SUPSynchronizationAction values (deprecated 1.5.3 definitions).
 @discussion
 */
typedef enum
{
    SUPSynchronizationActionCANCEL = 0,
    SUPSynchronizationActionCONTINUE = 1
} SUPSynchronizationActionTypeDeprecated;

/*!
 @method     
 @abstract   Returns the synchronization action for CANCEL.
 @result An int describing the synchronization action.
 @discussion 
 */
+ (SUPInt)CANCEL;

/*!
 @method     
 @abstract   Returns the synchronization action for CONTINUE.
 @result An int describing the synchronization action.
 @discussion 
 */
+ (SUPInt)CONTINUE;

@end

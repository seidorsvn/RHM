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
 @abstract    Represents the allowed SUP synchronization status values.
 @discussion  An int value of: 1, 2, 3, 4, or 5. Corresponds to STARTING, UPLOADING, DOWNLOADING, FINISHING, ERROR.
 */

@interface SUPSynchronizationStatus : NSObject
{
}

/*!
 @enum
 @abstract Possible SUPSynchronizationStatus values.
 @discussion
 */
typedef enum
{
    SUPSynchronizationStatus_STARTING = 1,
    SUPSynchronizationStatus_UPLOADING = 2,
    SUPSynchronizationStatus_DOWNLOADING = 3,
    SUPSynchronizationStatus_FINISHING = 4,
    SUPSynchronizationStatus_ERROR = 5    
} SUPSynchronizationStatusType;

/*!
 @enum
 @abstract Possible SUPSynchronizationStatus values (deprecated 1.5.3 definitions).
 @discussion
 */
typedef enum
{
    SUPSynchronizationStatusSTARTING = 1,
    SUPSynchronizationStatusUPLOADING = 2,
    SUPSynchronizationStatusDOWNLOADING = 3,
    SUPSynchronizationStatusFINISHING = 4,
    SUPSynchronizationStatusERROR = 5    
} SUPSynchronizationStatusTypeDeprecated;


/*!
 @method     
 @abstract   Returns the synchronization status for STARTING.
 @result An int describing the synchronization status.
 @discussion 
 */
+ (SUPInt)STARTING;
/*!
 @method     
 @abstract   Returns the synchronization status for UPLOADING.
 @result An int describing the synchronization status.
 @discussion 
 */
+ (SUPInt)UPLOADING;
/*!
 @method     
 @abstract   Returns the synchronization status for DOWNLOADING.
 @result An int describing the synchronization status.
 @discussion 
 */
+ (SUPInt)DOWNLOADING;
/*!
 @method     
 @abstract   Returns the synchronization status for FINISHING.
 @result An int describing the synchronization status.
 @discussion 
 */
+ (SUPInt)FINISHING;
/*!
 @method     
 @abstract   Returns the synchronization status for ERROR.
 @result An int describing the synchronization status.
 @discussion 
 */
+ (SUPInt)ERROR;

@end

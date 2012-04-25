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
 @protocol
 @abstract    Protocol to be implemented by a synchronization group class.  
 @discussion  This protocol is implemented by the (package_name)_SynchronizationGroup class generated for an SUP package.
 */
@protocol SUPSynchronizationGroup<NSObject>

- (NSString*)name;
/*!
 @property     
 @abstract   Returns the name of the group.
 @discussion 
 */
@property(readonly,copy,nonatomic) NSString* name;
- (BOOL)adminLock;
/*!
 @property     
 @abstract   Returns true if there is an admin lock on the group.
 @discussion 
 */
@property(readonly,assign,nonatomic) BOOL adminLock;
- (BOOL)enableSIS;
- (void)setEnableSIS:(BOOL)_enableSIS;
/*!
 @property     
 @abstract   Returns true if SIS enabled.
 @discussion 
 */
@property(readwrite,assign,nonatomic) BOOL enableSIS;
- (int32_t)interval;
/*!
 @property     
 @abstract   Returns the synchronization interval.
 @discussion 
 */
@property(readonly,assign,nonatomic) int32_t interval;

/*!
 @method     
 @abstract   Get the names of all MBOs included in the sync group.
 @discussion 
 @returns  An SUPStringList of the entity names.
 */
- (SUPStringList*)getEntityNames;

/*!
 @method     
 @abstract   Not currently implemented, reserved for future use.
 @discussion 
 */
- (void)save;
/*!
 @method     
 @abstract   Not currently implemented, reserved for future use.
 @discussion 
 */
- (void)synchronize;
/*!
 @method     
 @abstract   Not currently implemented, reserved for future use.
 @discussion 
 */
- (void)submitPendingOperations;
/*!
 @method     
 @abstract   Not currently implemented, reserved for future use.
 @discussion 
 */
- (void)cancelPendingOperations;

@end

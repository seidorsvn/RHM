/*
 
 Copyright (c) Sybase, Inc. 2010   All rights reserved.
 
 In addition to the license terms set out in the Sybase License Agreement for
 the Sybase Unwired Platform (Program), the following additional or different
 rights and accompanying obligations and restrictions shall apply to the source
 code in this file (Code).  Sybase grants you a limited, non-exclusive,
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

#import "SUPCallbackHandler.h"

@class SUPConnectionProfile;
@class SUPDefaultCallbackHandler;



/*!
 @class SUPDefaultCallbackHandler
 @abstract   Superclass for implementation of a callback handler.  
 @discussion This class implements the protocol defined in @link //apple_ref/occ/intf/SUPCallbackHandler SUPCallbackHandler @/link, providing empty implementations of all the required methods.
 This class may be subclassed by user code.
 */

@interface SUPDefaultCallbackHandler : NSObject<SUPCallbackHandler> {
}

/*!
    @method     
    @abstract   Returns a new instance of SUPDefaultCallbackHandler.
    @discussion 
*/

+ (SUPDefaultCallbackHandler*)getInstance;

/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPDefaultCallbackHandler.
 @discussion This method is deprecated. use getInstance instead.
 */

+ (SUPDefaultCallbackHandler*)newInstance DEPRECATED_ATTRIBUTE;

/*!
 @method     
 @abstract   Called before applying an import message to database
 @param entityObject The Mobile Business Object to be imported
 @discussion 
 */
- (void)beforeImport:(id)entityObject;

/*!
 @method     
 @abstract   Called when there is server message received marked method "import".
 @param entityObject The object.
 @discussion 
 */
- (void)onImport:(id)entityObject;

/*!
 @method     
 @abstract   Callback method invoked on replay failure.
 @param entityObject The object.
 @discussion 
 */
- (void)onReplayFailure:(id)entityObject;

/*!
 @method     
 @abstract   Callback method invoked on replay success.
 @param entityObject The object.
 @discussion 
 */
- (void)onReplaySuccess:(id)entityObject;

/*!
 @method     
 @abstract   Callback method invoked on search failure.
 @param entityObject The object.
 @discussion 
 */
- (void)onSearchFailure:(id)entityObject;

/*!
 @method     
 @abstract   Callback method invoked on search success.
 @param entityObject The object.
 @discussion 
 */
- (void)onSearchSuccess:(id)entityObject;

/*!
 @method     
 @abstract   Callback method invoked on login failure.
 @discussion 
 */
- (void)onLoginFailure;

/*!
 @method     
 @abstract   Callback method invoked on login success.
 @discussion 
 */
- (void)onLoginSuccess;

/*!
 @method     
 @abstract   Callback method invoked on recover failure.
 @discussion 
 */
- (void)onRecoverFailure;

/*!
 @method     
 @abstract   Callback method invoked on recover success.
 @discussion 
 */
- (void)onRecoverSuccess;

/*!
 @method     
 @abstract   Callback method invoked on subscribe failure.
 @discussion 
 */
- (void)onSubscribeFailure;

/*!
 @method     
 @abstract   Callback method invoked on subscribe success.
 @discussion 
 */
- (void)onSubscribeSuccess;

/*!
 @method     
 @abstract   Callback method invoked on synchronize failure (deprecated).
 @discussion 
 */
- (void)onSynchronizeFailure DEPRECATED_ATTRIBUTE;

/*!
 @method     
 @abstract   Callback method invoked on synchronize success (deprecated).
 @discussion 
 */
- (void)onSynchronizeSuccess DEPRECATED_ATTRIBUTE;

/*!
 @method     
 @abstract   Callback method invoked when synchronization status changes.
 @param syncGroupList List of affected synchronization groups.
 @param context The current synchronization context.
 @return An @link //apple_ref/c/tdef/SUPSynchronizationStatusType SUPSynchronizationStatusType @/link value (SUPSynchronizationActionCANCEL or SUPSynchronizationActionCONTINUE)
 @discussion 
 */
- (SUPSynchronizationActionType)onSynchronize:(SUPObjectList*)syncGroupList withContext:(SUPSynchronizationContext*)context;

/*!
 @method     
 @abstract   Callback method invoked when suspend subscription fails.
 @discussion 
 */
- (void)onSuspendSubscriptionFailure;

/*!
 @method     
 @abstract   Callback method invoked when suspend subscription is successful.
 @discussion 
 */
- (void)onSuspendSubscriptionSuccess;

/*!
 @method     
 @abstract   Callback method invoked when resume subscription fails.
 @discussion 
 */
- (void)onResumeSubscriptionFailure;

/*!
 @method     
 @abstract   Callback method invoked when  resume subscription is successful.
 @discussion 
 */
- (void)onResumeSubscriptionSuccess;

/*!
 @method     
 @abstract   Callback method invoked on unsubscribe failure.
 @discussion 
 */
- (void)onUnsubscribeFailure;

/*!
 @method     
 @abstract   Callback method invoked on unsubscribe success.
 @discussion 
 */
- (void)onUnsubscribeSuccess;

/*!
 @method     
 @abstract   Called when server message with method "importResult" is received by client, indicating end of the importing.
 @discussion 
 */
- (void)onImportSuccess;

/*!
 @method     
 @abstract   Called when an exception occurs during message processing.
 @discussion Other callbacks in this interface (whose names begin with "on") are invoked inside a database transaction.  If the transaction will be rolled back due to an unexpected exception, this operation will be called with the exception (before rollback occurs).
 
 */
- (void)onMessageException:(NSException*)e;

/*!
 @method     
 @abstract   Called when the transaction of processing server message is committed.
 @discussion This method is only called at the end of handling an incoming message from the server - not for client initiated database changes that involve database transactions.
 Normally, onTransactionCommit is called at the end of the message handling to indicate that all database operations for the message have completed.

 */
- (void)onTransactionCommit;

/*!
 @method     
 @abstract   Called when the transaction of server msg process is rollbacked.
 @discussion This method is only called at the end of handling an incoming message from the server - not for client initiated database changes that involve database transactions.
 If there is a database error or some other problem that throws an exception during incoming message handling, e.g. when importing data, onTransactionRollback will be called.
 */
- (void)onTransactionRollback;

/*!
 @method     
 @abstract   Callback method invoked when reset is successful.
 @discussion 
 */
- (void)onResetSuccess;

/*!
 @method     
 @abstract   Callback method invoked on subscription end.
 @discussion 
 */
- (void)onSubscriptionEnd;

/*!
 @method     
 @abstract   Callback method invoked when storage space is low.
 @discussion 
 */
- (void)onStorageSpaceLow;

/*!
 @method     
 @abstract   Callback method invoked when storage space is recovered.
 @discussion 
 */
- (void)onStorageSpaceRecovered;

/*!
 @method     
 @abstract   Callback method invoked on connection status change.
 @param connStatus The connection status.
 @param connType The connection type
 @param errorCode An error code (0 if no error)
 @param errorString An error string (null if no error)
 @discussion 
 */
- (void)onConnectionStatusChange:(SUPDeviceConnectionStatus)connStatus:(SUPDeviceConnectionType)connType:(int32_t)errorCode:(NSString*)errorString;
- (void)dealloc;

@end

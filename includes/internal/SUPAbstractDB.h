/*
 
 Copyright (c) Sybase, Inc. 2009   All rights reserved.                                    
 
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

#import "SUPMessageListener.h"
#import "SUPParameterMetaData.h"
#import "SUPAttributeMetaData.h"
#import "SUPAttributeMetaData_DC.h"
#import "SUPEntityMetaData.h"
#import "SUPOperationMetaData.h"
#import "SUPDatabaseMetaData.h"
#import "SUPOperationMap.h"
#import "SUPAttributeMap.h"
#import "SUPEntityMap.h"
#import "SUPDataType.h"
#import "SUPStatementWrapper.h"
#import "SUPConnectionWrapper.h"
#import "SUPObjectNotFoundException.h"
#import "SUPPersistenceException.h"
#import "SUPProtocolException.h"
#import "SUPQuery.h"
#import "SUPQueryResultSet.h"
#import "SUPSortOrder.h"
#import "SUPAttributeTest.h"
#import "SUPLogger.h"
#import "SUPObjectList.h"
#import "SUPStringList.h"
#import "SUPOnlineLoginStatus.h"
#import "SUPReadWriteLock.h"

/*
#import "PimContact.h"
#import "PimCalendar.h"
#import "PimTask.h"
#import "PimDraft.h"
#import "PimOutbox.h"
#import "PimInbox.h"
#import "PimSentItem.h"
#import "PimDeletedItem.h"
#import "PimNotepad.h"
*/
#import "SUPCallbackHandler.h"

@protocol SUPConnectionWrapper;
@protocol SUPDatabaseManager;
@protocol SUPQueueConnection;

@class SUPConnectionProfile;
@class SUPDatabaseMetaData;
@class SUPLocalTransaction;
@class SUPMessageListenerMap;


@interface SUPAbstractDB : NSObject<SUPMessageListener>
{
@protected
    SUPMessageListenerMap*  _messageListenerMap;
    NSObject<SUPQueueConnection> *_queueConnection;
    NSObject<SUPLogger>   *_logger;
        
@private
    NSObject<SUPCallbackHandler> *_callbackHandler;
    SUPConnectionProfile         *_connectionProfile;
    NSObject<SUPDatabaseManager> *_manager;
    NSString                     *_name;
    BOOL                          _backgroundSyncStarted;
    BOOL                          _needSync;
    SUPOnlineLoginStatus         *_onlineLoginStatus;
    NSString                     *_onlineLoginReqID;
}

@property(readwrite, retain, nonatomic) NSObject<SUPCallbackHandler> *callbackHandler;
@property(readonly, retain, nonatomic)  SUPConnectionProfile         *connectionProfile;
@property(readonly, copy, nonatomic)    NSString                     *name;
@property(readwrite, retain, nonatomic) NSObject<SUPQueueConnection> *queueConnection;
@property(readonly, retain, nonatomic)  SUPConnectionProfile         *synchronizationProfile;
@property(readwrite, retain, nonatomic) NSObject<SUPLogger>          *logger;
@property(readwrite, retain, nonatomic) SUPOnlineLoginStatus         *onlineLoginStatus;
@property(readwrite, copy, nonatomic)   NSString                     *onlineLoginReqID;
@property(readonly, retain, nonatomic)  id                           dblock;


+ (SUPDatabaseMetaData*)metaData;

+ (SUPAttributeMetaData_DC*)createAttributeMetaData:(SUPInt)a_id:(SUPString)a_name:(SUPDataType*)a_type;
+ (SUPOperationMetaData*)createOperationMetaData:(SUPInt)o_id:(SUPString)o_name:(SUPDataType*)o_type:(bool)o_isStatic;
+ (SUPParameterMetaData*)createParameterMetaData:(SUPInt)p_id:(SUPString)p_name:(SUPDataType*)p_type;

+ (SUPObjectList*)getLogRecords:(SUPQuery*)query;
+ (void)uploadLogs;

- (id)initWithName:(NSString*)name;
- (SUPLocalTransaction*)beginTransaction;
- (void)closeConnection;
- (void)clearConnection;
- (void)createDatabase;
- (void)deleteDatabase;
- (BOOL)databaseExists;
- (SUPQueryResultSet*)executeQuery:(SUPDatabaseMetaData*)metaData query:(SUPQuery*)query;
- (id<SUPConnectionWrapper>)getConnectionWrapper;
- (void)onMessage:(SUPJsonMessage*)message;
- (void)recover;
- (void)resume;
- (void)startBackgroundSynchronization;
- (void)stopBackgroundSynchronization;
- (void)subscribe;
- (void)subscribeWithSyncParams;
- (void)suspend;
- (void)unsubscribe;
- (void)beginSynchronize:(SUPLong)counter withContent:(SUPJsonObject*)content;
- (void)replay:(SUPString)mbo withId:(SUPLong)counter withContent:(SUPJsonArray*)content;
- (void)search:(SUPString)mbo withId:(SUPLong)counter withContent:(SUPJsonArray*)content;
- (BOOL)onlineLogin;
- (void)asyncLogin;
- (BOOL)offlineLogin:(SUPString)user password:(SUPString)pass;
- (BOOL)offlineLogin;
- (BOOL)packageIsSubscribed;
- (BOOL)packageIsSubscribePending;
- (BOOL)packageIsSuspended;
- (BOOL)packageIsResumed;
- (void)trackSubscriptionStatusOnMethod:(SUPString)method andRequestID:(SUPLong)counter;
- (void)recordSubscriptionStatus:(SUPJsonMessage*)message;

- (void)registerCallbackHandler:(NSObject<SUPCallbackHandler>*)handler;
//-(int)writeToPim:(id)entity;
- (void)setNeedSync;
- (void)synchronizeIfNeeded;
- (void)synchronize;
- (void)storeCredential: (SUPString)user passwordHash:(NSUInteger)passHash;
- (void)changeEncryptionKey:(NSString *)newKey;
+ (NSString*)defaultDomainName;
+ (int32_t)getSchemaVersion;
+ (int32_t)getProtocolVersion;

+ (void)vacuum;

@end

@interface SUPAbstractDB(internal)
- (void)notifyOnlineLoginFailed:(NSString *)reqID withMessage:(NSString *)msg withCode:(int32_t)code;
- (void)notifyOnlineLoginSuccess:(NSString *)reqID;
+ (void)writeLogFromHeader:(SUPJsonObject*)o:(SUPNullableString)mbo:(SUPNullableString)method;
- (void)setManager:(NSObject<SUPDatabaseManager>*)newManager;
@end
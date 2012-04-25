//
//  SEIDOR_SHAREPOINTCallbackHandler.h
//  SEIDOR_SHAREPOINT
//
//  Created by David Reifs on 4/13/11.
//  Copyright 2011 Seidor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SUPDefaultCallbackHandler.h"

// These strings will be used to send out NSNotifications.
#define ON_IMPORT_SUCCESS @"SUPImportSuccess"
#define ON_LOGIN_SUCCESS @"SUPLoginSuccess"
#define ON_LOGIN_FAILURE @"SUPLoginFailure"
#define ON_CONNECT_SUCCESS @"SUPConnectSuccess"
#define ON_CONNECT_FAILURE @"SUPConnectFailure"
#define ON_REPLAY_SUCCESS @"SUPReplaySuccess"
#define ON_REPLAY_FAILURE @"SUPReplayFailure"
#define ON_SYNCHRONIZE_SUCCESS @"SUPSynchronizeSuccess"
#define ON_SYNCHRONIZE_FAILURE @"SUPSynchronizeFailure"
#define ON_SYNC_FINISHED @"SUPSynchronizeFinished"
#define ON_SYNC_STARTED @"SUPSynchronizeStarted"

//ADDED
#define ON_SUBSCRIBE_FAILURE @"SUPSubscribeFailure"

@interface CallbackHandler:SUPDefaultCallbackHandler
{
    SUPInt field_importCount;
    SUPInt field_replaySuccessCount;
    SUPInt field_replayFailureCount;
    SUPInt field_searchSuccessCount;
    SUPInt field_searchFailureCount;
    SUPInt field_loginSuccessCount;
	SUPInt field_loginFailureCount; 
    SUPInt field_importSuccessCount;
    SUPInt field_syncSuccessCount;
}

+ (CallbackHandler*)newInstance;
- (SUPInt)importCount;
- (void)setImportCount:(SUPInt)_importCount;
@property(assign) SUPInt importCount;
- (SUPInt)replaySuccessCount;
- (void)setReplaySuccessCount:(SUPInt)_replaySuccessCount;
@property(assign) SUPInt replaySuccessCount;
- (SUPInt)replayFailureCount;
- (void)setReplayFailureCount:(SUPInt)_replayFailureCount;
@property(assign) SUPInt replayFailureCount;
- (SUPInt)searchSuccessCount;
- (void)setSearchSuccessCount:(SUPInt)_searchSuccessCount;
@property(assign) SUPInt searchSuccessCount;
- (SUPInt)searchFailureCount;
- (void)setSearchFailureCount:(SUPInt)_searchFailureCount;
@property(assign) SUPInt searchFailureCount;
- (SUPInt)loginSuccessCount;
- (void)setLoginSuccessCount:(SUPInt)_loginSuccessCount;
@property(assign) SUPInt loginSuccessCount;
- (SUPInt)loginFailureCount;
- (void)setLoginFailureCount:(SUPInt)_loginFailureCount;
@property(assign) SUPInt loginFailureCount;
- (SUPInt)importSuccessCount;
- (void)setImportSuccessCount:(SUPInt)_importSuccessCount;
@property(assign) SUPInt importSuccessCount;
- (void)onImport:(id)theObject;
- (void)onReplayFailure:(id)theObject;
- (void)onReplaySuccess:(id)theObject;
- (void)onSearchFailure:(id)theObject;
- (void)onSearchSuccess:(id)theObject;
- (void)onLoginFailure;
- (void)onLoginSuccess;
- (void)onSubscribeSuccess;
- (void)onSubscribeFailure;
- (void)onUnsubscribeSuccess;
- (void)onImportSuccess;
- (void)dealloc;

@property(assign) SUPInt syncSuccessCount;

- (int32_t)onSynchronize:(SUPObjectList*)syncGroupList withContext:(SUPSynchronizationContext*)context;

- (SUPInt)syncSuccessCount;
- (void)setSyncSuccessCount:(SUPInt)_syncSuccessCount;

- (void)sendNotification:(NSNotification *)notification;

- (void)postNotification:(NSString *)notification withObject:(id)obj;


@end

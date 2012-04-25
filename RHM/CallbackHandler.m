//
//  SEIDOR_SHAREPOINTCallbackHandler.m
//  SEIDOR_SHAREPOINT
//
//  Created by David Reifs on 4/13/11.
//  Copyright 2011 Seidor. All rights reserved.
//

#import "CallbackHandler.h"


@implementation CallbackHandler

+ (CallbackHandler*)newInstance
{
    CallbackHandler* _me_1 = [[CallbackHandler alloc] init];
    [_me_1 autorelease];
    return _me_1;
}

- (SUPInt)importCount
{
    return field_importCount;
}

- (void)setImportCount:(SUPInt)_importCount
{
    field_importCount = _importCount;
}

- (SUPInt)replaySuccessCount
{
    return field_replaySuccessCount;
}

- (void)setReplaySuccessCount:(SUPInt)_replaySuccessCount
{
    field_replaySuccessCount = _replaySuccessCount;
}

- (SUPInt)replayFailureCount
{
    return field_replayFailureCount;
}

- (void)setReplayFailureCount:(SUPInt)_replayFailureCount
{
    field_replayFailureCount = _replayFailureCount;
}

- (SUPInt)searchSuccessCount
{
    return field_searchSuccessCount;
}

- (void)setSearchSuccessCount:(SUPInt)_searchSuccessCount
{
    field_searchSuccessCount = _searchSuccessCount;
}

- (SUPInt)searchFailureCount
{
    return field_searchFailureCount;
}

- (void)setSearchFailureCount:(SUPInt)_searchFailureCount
{
    field_searchFailureCount = _searchFailureCount;
}

- (SUPInt)loginSuccessCount
{
    return field_loginSuccessCount;
}

- (void)setLoginSuccessCount:(SUPInt)_loginSuccessCount
{
    field_loginSuccessCount = _loginSuccessCount;
}

- (SUPInt)loginFailureCount {
    return field_loginFailureCount;
}
- (void)setLoginFailureCount:(SUPInt)_loginFailureCount {
	
	field_loginFailureCount = _loginFailureCount;
}

- (SUPInt)importSuccessCount
{
    return field_importSuccessCount;
}

- (void)setImportSuccessCount:(SUPInt)_importSuccessCount
{
    field_importSuccessCount = _importSuccessCount;
}
- (SUPInt)syncSuccessCount
{
    return field_syncSuccessCount;
}

- (void)setSyncSuccessCount:(SUPInt)_syncSuccessCount
{
    field_syncSuccessCount = _syncSuccessCount;
}
- (void)onImport:(id)theObject
{
    self.importCount = self.importCount + 1;
    
    NSLog(@"\t\t\tonImport count - %d de %@",self.importCount, [[[theObject description] componentsSeparatedByString:@"="] objectAtIndex:0]);
}

- (void)onReplayFailure:(id)theObject
{
    self.replayFailureCount = self.replayFailureCount + 1;
	
    NSLog(@"Replay Failure de %@",[[[theObject description] componentsSeparatedByString:@"_pull_pq"] objectAtIndex:0]);
    
    [self postNotification:ON_REPLAY_FAILURE withObject:theObject];
}

- (void)onReplaySuccess:(id)theObject
{
    self.replaySuccessCount = self.replaySuccessCount + 1;
    
    NSLog(@"Replay Successful de %@",[[[theObject description] componentsSeparatedByString:@"_pull_pq"] objectAtIndex:0]);
    
    //NSLog(@"=================================================");
	
	[self postNotification:ON_REPLAY_SUCCESS withObject:theObject];
	
}

- (void)onSearchFailure:(id)theObject
{
    self.searchFailureCount = self.searchFailureCount + 1;
}

- (void)onSearchSuccess:(id)theObject
{
    self.searchSuccessCount = self.searchSuccessCount + 1;
}

- (void)onLoginSuccess
{
    /*NSLog(@"================================");
     NSLog(@"Login Successful");
     NSLog(@"================================");*/
    
	self.loginSuccessCount++;
	
    [self postNotification:ON_LOGIN_SUCCESS withObject:nil];
}

- (void)onLoginFailure {
    
	NSLog(@"=============================");
	NSLog(@"Login Failed");
	NSLog(@"=============================");
    
	self.loginFailureCount++;
	
	[self postNotification:ON_LOGIN_FAILURE withObject:nil];
}

- (void)onSubscribeSuccess
{
    /*NSLog(@"=================================");
     NSLog(@"Subscribe Successful");
     NSLog(@"==================================");*/
    
}

-(void)onSubscribeFailure {
    NSLog(@"============================="); 
    NSLog(@"Subscribe Failed"); 
    NSLog(@"=============================");
	
	[self postNotification:ON_SUBSCRIBE_FAILURE withObject:nil];
}

- (void)onUnsubscribeSuccess
{
    NSLog(@"=========================");
    NSLog(@"Unsubscribe Successful");
    NSLog(@"=========================");
    
}

- (void)onImportSuccess
{
	//NSDictionary *res = [[NSDictionary alloc] initWithObjectsAndKeys:@"YES", @"SUCCESS", nil];
	NSLog(@"=================================");
	NSLog(@"Import ends Successful");
	NSLog(@"=================================");
    
    self.importSuccessCount++;
	
	[self postNotification:ON_IMPORT_SUCCESS withObject:nil];
}

- (int32_t)onSynchronize:(SUPObjectList*)syncGroupList withContext:(SUPSynchronizationContext*)context{
	
	if (context.status == SUPSynchronizationStatusFINISHING)
	{
		NSLog(@"=================================");
		NSLog(@"Synchronization ends Successful");
		NSLog(@"=================================");
		
		self.syncSuccessCount++;
		
		[self postNotification:ON_SYNCHRONIZE_SUCCESS withObject:nil];
	}
	else if (context.status == SUPSynchronizationStatusERROR)
	{
		NSException *ex = context.exception;
		NSString *text = [NSString stringWithFormat:@"Synchronization failure - %@", ex.reason];
        
		NSLog(@"====================");
		NSLog(@"%@", text);
		NSLog(@"===================");
		self.syncSuccessCount++;
		
		[self postNotification:ON_SYNCHRONIZE_FAILURE withObject:nil];
	}
	else if (context.status == SUPSynchronizationStatusDOWNLOADING)
	{		
		NSLog(@"===================");
		NSLog(@"Synchronization Downloading Data");
		NSLog(@"===================");
	}
	
	return context.status;
}

- (void)onConnectionStatusChange:(SUPDeviceConnectionStatus)connStatus:(SUPDeviceConnectionType)connType:(int32_t)errCode:(NSString*)errString
{
    NSString *notification = nil;
    switch(connStatus)
    {
        case CONNECTED_NUM:
            notification = ON_CONNECT_SUCCESS;
            break;
        case DISCONNECTED_NUM:
            notification = ON_CONNECT_FAILURE;
            break;
        default:
            // Ignore all other status changes for this example.
            break;
    }
    
    if (notification != nil) [self postNotification:notification withObject:nil];
}

- (void)sendNotification:(NSNotification *)notification
{
    [[NSNotificationCenter defaultCenter] postNotification:notification];
    [notification release];
}

- (void)postNotification:(NSString *)notification withObject:(id)obj
{
    // All callback notifications other than onSubscribe: will happen on a thread other than the main UI thread. So, if you
    // want to update the UI in response to a callback you need to post the notification from the main thread.
    NSNotification *n = [NSNotification notificationWithName:notification object:obj];
    [n retain];
    [self performSelectorOnMainThread:@selector(sendNotification:) withObject:n waitUntilDone:NO];
}

- (void)dealloc
{
    [super dealloc];
}

@end

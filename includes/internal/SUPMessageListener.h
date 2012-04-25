/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPMessageListener.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Required interface for the listener object in SUPQueueConnection.
 ******************************************************************************/

#import "sybase_sup.h"

@class SUPJsonMessage;

@protocol SUPMessageListener

- (void)onMessage:(SUPJsonMessage*)_message_1;

@end

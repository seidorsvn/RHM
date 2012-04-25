/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPQueueConnection.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Required interface for queue connection used by SUP application.
 ******************************************************************************/

#import <Foundation/Foundation.h>

#import "sybase_sup.h"


@class SUPJsonMessage;

@protocol SUPMessageListener;

@protocol SUPQueueConnection

- (void)acknowledge:(SUPJsonMessage*)_message_1;
- (SUPJsonMessage*)receive:(SUPInt)_timeout_1;
- (void)send:(SUPJsonMessage*)_message_1;
- (void)setListener:(id<SUPMessageListener>)_listener_1;

@end

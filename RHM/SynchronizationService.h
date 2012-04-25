//
//  SynchronizationService.h
//  RHM
//
//  Created by Apple1 Seidor on 4/4/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CallbackHandler.h"

@interface SynchronizationService : NSObject

@property (nonatomic, retain) NSDate *connectStartTime;
@property (nonatomic, retain) CallbackHandler *callbackHandler;

- (void) onConnectSuccess:(NSNotification *)obj;
- (void) onConnectFailure:(NSNotification *)obj;
- (void) onLoginSuccess:(NSNotification *)obj;

- (void) suscribir;
- (void) sincronizar;
- (void) sincronizarDatos;
- (void) login;

- (void) sendNotification:(NSString*)notification;
- (void) postNotification:(NSString *)notification withObject:(id)obj;
- (void) showAlert:(NSString*) message;

@end

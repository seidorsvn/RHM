//
//  AppDelegate.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 11/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UIKit/UIKit.h>
#import "DataService.h"
#import "CallbackHandler.h"
#import "SynchronizationService.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate, UIAlertViewDelegate>
{
	DataService *_dataService;
	SynchronizationService *_syncService;
}

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, retain) DataService *dataService;
@property (nonatomic, retain) SynchronizationService *syncService;

- (void)dismissKeyboard;
- (void)showNoTransportAlert:(NSInteger) ret;
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;

@end
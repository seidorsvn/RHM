//
//  MasterViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 11/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Reachability;

@interface MasterViewController : UITableViewController <UIAlertViewDelegate>

@property (strong, nonatomic) Reachability *rInternet;
@property (strong, nonatomic) Reachability *rHost;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *bbiSincronizacion;
@property (strong, nonatomic) IBOutlet NSIndexPath *ipSeleccionado;
@property (nonatomic) BOOL bAnimacionTerminada;

- (IBAction)doAcercaDe:(id)sender;
- (IBAction)doSincronizacion:(id)sender;

@end
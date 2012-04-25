//
//  ListadoClientesViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ListadoClientesViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UIMenuController *mcOrdenarPor;
@property (strong, nonatomic) IBOutlet UITableView *tvListadoClientes;
@property (strong, nonatomic) IBOutlet UISearchBar *sbListadoClientes;
@property (strong, nonatomic) IBOutlet NSArray *aItems;
@property (strong, nonatomic) IBOutlet NSArray *aItemsAux;

- (IBAction)doOrdenarPor:(id)sender;

@end
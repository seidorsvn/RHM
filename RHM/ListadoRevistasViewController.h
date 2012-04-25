//
//  ListadoRevistasViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ListadoRevistasViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate, UIDocumentInteractionControllerDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UITableView *tvListadoRevistas;
@property (strong, nonatomic) IBOutlet UISearchBar *sbListadoRevistas;
@property (strong, nonatomic) IBOutlet NSArray *aItems;
@property (strong, nonatomic) IBOutlet NSArray *aItemsAux;

@end
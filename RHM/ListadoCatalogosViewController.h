//
//  ListadoCatalogosViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ListadoCatalogosViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UISearchBar *sbListadoCatalogos;
@property (strong, nonatomic) IBOutlet UITableView *tvListadoCatalogos;
@property (strong, nonatomic) IBOutlet NSArray *aItemsCentralizados;
@property (strong, nonatomic) IBOutlet NSArray *aItemsCentralizadosAux;
@property (strong, nonatomic) IBOutlet NSArray *aItemsPropios;
@property (strong, nonatomic) IBOutlet NSArray *aItemsPropiosAux;

@end
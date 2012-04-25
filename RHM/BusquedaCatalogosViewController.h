//
//  BusquedaCatalogosViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BusquedaCatalogosViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate, UISearchBarDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcBuscarMatchCode;
@property (strong, nonatomic) IBOutlet UITableView *tvBusquedaCatalogos;
@property (strong, nonatomic) IBOutlet UITableView *tvBuscarMatchCode;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scTipo;
@property (nonatomic) NSInteger iBuscarMatchCodeTag;
@property (strong, nonatomic) IBOutlet UITextField *tfCampoActivo;
@property (strong, nonatomic) IBOutlet NSArray *aItems;

- (IBAction)doBuscar:(id)sender;
- (IBAction)doBuscarMatchCode:(id)sender;

@end
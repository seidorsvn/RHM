//
//  BusquedaRevistasViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BusquedaRevistasViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UIPickerViewDelegate, UIPickerViewDataSource, UITextFieldDelegate, UISearchBarDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcBuscarMatchCode;
@property (strong, nonatomic) IBOutlet UITableView *tvBusquedaRevistas;
@property (strong, nonatomic) IBOutlet UITableView *tvBuscarMatchCode;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scFechas;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scDivisionEditorial;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcFechas;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcDivisionEditorial;
@property (strong, nonatomic) IBOutlet UIMenuController *mcReiniciarFecha;
@property (strong, nonatomic) IBOutlet UIMenuController *mcReiniciarDivisionEditorial;
@property (nonatomic) NSInteger iBuscarMatchCodeTag;
@property (strong, nonatomic) IBOutlet UITextField *tfCampoActivo;
@property (strong, nonatomic) IBOutlet NSArray *aItems;

- (IBAction)doBuscar:(id)sender;
- (IBAction)doBuscarMatchCode:(id)sender;
- (IBAction)doEstablecerFechaPublicacion:(id)sender;
- (IBAction)doEstablecerDivisionEditorial:(id)sender;

@end
//
//  BusquedaArticulosViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZBarReaderViewController.h"

@interface BusquedaArticulosViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UIPickerViewDelegate, UIPickerViewDataSource, UITextFieldDelegate, ZBarReaderDelegate, UISearchBarDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcBuscarMatchCode;
@property (strong, nonatomic) IBOutlet UITableView *tvBusquedaArticulos;
@property (strong, nonatomic) IBOutlet UITableView *tvBuscarMatchCode;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scNovedad;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scFechas;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scEstados;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scTapas;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scDivisionEditorial;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scTargetEdad;
@property (strong, nonatomic) IBOutlet UISegmentedControl *scMaterial;
@property (strong, nonatomic) IBOutlet UITextField *tfCodigoArticulo;
@property (strong, nonatomic) IBOutlet UITextField *tfTituloDefinitivo;
@property (strong, nonatomic) IBOutlet UITextField *tfAutor;
@property (strong, nonatomic) IBOutlet UITextField *tfSello;
@property (strong, nonatomic) IBOutlet UITextField *tfColeccion;
@property (strong, nonatomic) IBOutlet UITextField *tfCliente;
@property (strong, nonatomic) IBOutlet UITextField *tfCodigoEAN;
@property (strong, nonatomic) IBOutlet UITextField *tfManuscrito;
@property (strong, nonatomic) IBOutlet UITextField *tfCategoriaEditorial;
@property (strong, nonatomic) IBOutlet UITextField *tfTematica;
@property (strong, nonatomic) IBOutlet UITextField *tfBIC;
@property (strong, nonatomic) IBOutlet UITextField *tfPersonaje;
@property (strong, nonatomic) IBOutlet UITextField *tfAmbito;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcFechas;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcEstados;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcTapas;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcDivisionEditorial;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcTargetEdad;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcMaterial;
@property (strong, nonatomic) IBOutlet UIMenuController *mcReiniciarFecha;
@property (strong, nonatomic) IBOutlet UIMenuController *mcReiniciarEstado;
@property (strong, nonatomic) IBOutlet UIMenuController *mcReiniciarTapa;
@property (strong, nonatomic) IBOutlet UIMenuController *mcReiniciarDivisionEditorial;
@property (strong, nonatomic) IBOutlet UIMenuController *mcReiniciarTargetEdad;
@property (strong, nonatomic) IBOutlet UIMenuController *mcReiniciarMaterial;
@property (nonatomic) NSInteger iBuscarMatchCodeTag;
@property (strong, nonatomic) IBOutlet UITextField *tfCampoActivo;
@property (strong, nonatomic) IBOutlet NSArray *aItems;
@property (strong, nonatomic) IBOutlet UIActivityIndicatorView *aivCargando;
@property (strong, nonatomic) IBOutlet NSString *sCodigoArticulo;
@property (strong, nonatomic) IBOutlet NSString *sTituloDefinitivo;
@property (strong, nonatomic) IBOutlet NSString *sAutor;
@property (strong, nonatomic) IBOutlet NSString *sSello;
@property (strong, nonatomic) IBOutlet NSString *sColeccion;
@property (strong, nonatomic) IBOutlet NSString *sNovedad;
@property (strong, nonatomic) IBOutlet NSString *sFechaPublicacion;
@property (strong, nonatomic) IBOutlet NSString *sEstado;
@property (strong, nonatomic) IBOutlet NSString *sCliente;
@property (strong, nonatomic) IBOutlet NSString *sCodigoEAN;
@property (strong, nonatomic) IBOutlet NSString *sTipoTapa;
@property (strong, nonatomic) IBOutlet NSString *sManuscrito;
@property (strong, nonatomic) IBOutlet NSString *sDivisionEditorial;
@property (strong, nonatomic) IBOutlet NSString *sCategoriaEditorial;
@property (strong, nonatomic) IBOutlet NSString *sTematica;
@property (strong, nonatomic) IBOutlet NSString *sBIC;
@property (strong, nonatomic) IBOutlet NSString *sTargetEdad;
@property (strong, nonatomic) IBOutlet NSString *sPersonaje;
@property (strong, nonatomic) IBOutlet NSString *sTipoMaterial;
@property (strong, nonatomic) IBOutlet NSString *sAmbito;

- (IBAction)doBuscar:(id)sender;
- (IBAction)doEstablecerFechaPublicacion:(id)sender;
- (IBAction)doEstablecerEstado:(id)sender;
- (IBAction)doEstablecerTipoTapa:(id)sender;
- (IBAction)doEstablecerDivisionEditorial:(id)sender;
- (IBAction)doEstablecerTargetEdad:(id)sender;
- (IBAction)doEstablecerTipoMaterial:(id)sender;
- (IBAction)doBuscarMatchCode:(id)sender;
- (IBAction)doBuscarEAN:(id)sender;

@end
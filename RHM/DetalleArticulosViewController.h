//
//  DetalleArticulosViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetalleArticulosViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UIGestureRecognizerDelegate, UIDocumentInteractionControllerDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UITableView *tvDetalleArticulos;
@property (strong, nonatomic) IBOutlet NSArray *aItems;
@property (nonatomic) NSInteger *iPosicion;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcContenidoMultimedia;

- (IBAction)doContenidoMultimedia:(id)sender;
- (IBAction)doVisualizarFormatos:(id)sender;
- (IBAction)doConsultarStock:(id)sender;
- (IBAction)doVerAutor:(id)sender;

@end
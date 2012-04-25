//
//  DetalleClientesViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EventKitUI/EventKitUI.h>

@interface DetalleClientesViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, EKEventEditViewDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UITableView *tvDetalleClientes;
@property (strong, nonatomic) IBOutlet NSArray *aItems;
@property (nonatomic) NSInteger *iPosicion;

- (IBAction)doConsultarNotas:(id)sender;
- (IBAction)doVisualizarPlantillas:(id)sender;
- (IBAction)doVisualizarArticulos:(id)sender;
- (IBAction)doCrearPedido:(id)sender;

@end
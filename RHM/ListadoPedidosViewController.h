//
//  ListadoPedidosViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ListadoPedidosViewController : UIViewController

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *bbiPendientesEnviar;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *bbiRealizadosHoy;
@property (strong, nonatomic) IBOutlet UIBarButtonItem *bbiRealizadosSemana;

- (IBAction)doPendientesEnviar:(id)sender;
- (IBAction)doRealizadosHoy:(id)sender;
- (IBAction)doRealizadosSemana:(id)sender;

@end
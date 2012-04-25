//
//  DetalleAutoresViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetalleAutoresViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UIGestureRecognizerDelegate, UIDocumentInteractionControllerDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UITableView *tvDetalleAutores;
@property (strong, nonatomic) IBOutlet NSArray *aItems;
@property (nonatomic) NSInteger *iPosicion;
@property (strong, nonatomic) IBOutlet UIPopoverController *pcContenidoMultimedia;

- (IBAction)doContenidoMultimedia:(id)sender;
- (IBAction)doVisualizarArticulos:(id)sender;

@end
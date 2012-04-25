//
//  ListadoAutoresViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ListadoAutoresViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate, UIGestureRecognizerDelegate, UIDocumentInteractionControllerDelegate>

@property (strong, nonatomic) IBOutlet UIPopoverController *masterPopoverController;
@property (strong, nonatomic) IBOutlet UITableView *tvListadoAutores;
@property (strong, nonatomic) IBOutlet UISearchBar *sbListadoAutores;
@property (strong, nonatomic) IBOutlet NSArray *aItems;
@property (strong, nonatomic) IBOutlet NSArray *aItemsAux;

@end
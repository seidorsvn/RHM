//
//  ListadoClientesViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "ListadoClientesViewController.h"
#import "InicioViewController.h"
#import "DetalleClientesViewController.h"
#import "AppDelegate.h"

@implementation ListadoClientesViewController

@synthesize masterPopoverController, mcOrdenarPor, tvListadoClientes, sbListadoClientes, aItemsAux, aItems;

- (void)viewDidLoad
{
    [super viewDidLoad];
    if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
    [self setAItemsAux:aItems];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [(AppDelegate *)[[UIApplication sharedApplication] delegate] dismissKeyboard];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillHide:) name:UIKeyboardWillHideNotification object:nil];
    if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillHideNotification object:nil];
    [(AppDelegate *)[[UIApplication sharedApplication] delegate] dismissKeyboard];
}

- (void)doShowPopover:(id)sender
{
    if ([self masterPopoverController] == nil) {
        [self setMasterPopoverController:[(InicioViewController *)[[[[self.splitViewController viewControllers] objectAtIndex:1] viewControllers] objectAtIndex:0] masterPopoverController]];
        [masterPopoverController presentPopoverFromBarButtonItem:sender permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    } else {
        [masterPopoverController dismissPopoverAnimated:YES];
    }
    [self setMasterPopoverController:nil];
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
{
    if (toInterfaceOrientation == UIInterfaceOrientationPortrait || toInterfaceOrientation == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if (toInterfaceOrientation == UIInterfaceOrientationLandscapeLeft || toInterfaceOrientation == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
}

- (void)viewDidUnload
{
    [self setAItems:nil];
    [self setAItemsAux:nil];
    [self setMcOrdenarPor:nil];
    [self setTvListadoClientes:nil];
    [self setSbListadoClientes:nil];
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return YES;
}

#pragma mark - Split view

- (void)splitViewController:(UISplitViewController *)splitController willHideViewController:(UIViewController *)viewController withBarButtonItem:(UIBarButtonItem *)barButtonItem forPopoverController:(UIPopoverController *)popoverController
{
    [self.navigationItem setLeftItemsSupplementBackButton:YES];
    [self.navigationItem setLeftBarButtonItem:barButtonItem animated:YES];
    [self setMasterPopoverController:popoverController];
}

- (void)splitViewController:(UISplitViewController *)splitController willShowViewController:(UIViewController *)viewController invalidatingBarButtonItem:(UIBarButtonItem *)barButtonItem
{
    [self.navigationItem setLeftBarButtonItem:nil animated:YES];
    [self setMasterPopoverController:nil];
}

#pragma mark - Keyboard

- (void)keyboardWillShow:(NSNotification *)note
{
    CGRect keyboardBounds;
    [[note.userInfo valueForKey:UIKeyboardFrameBeginUserInfoKey] getValue: &keyboardBounds];
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    CGRect frame = self.view.frame;
    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationDuration:0.3f];
    if (orientation == UIInterfaceOrientationPortrait || orientation == UIInterfaceOrientationPortraitUpsideDown){
        frame.size.height -= keyboardBounds.size.height;
    }else{ 
        frame.size.height -= keyboardBounds.size.width;
    }
    CGRect rToolbar = [[self.view.superview.superview.superview.subviews objectAtIndex:2] frame];
    frame.size.height += rToolbar.size.height;
    self.view.frame = frame;    
    [UIView commitAnimations];
}

- (void)keyboardWillHide:(NSNotification *)note
{
    CGRect keyboardBounds;
    [[note.userInfo valueForKey:UIKeyboardFrameBeginUserInfoKey] getValue: &keyboardBounds];
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    CGRect frame = self.view.frame;
    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationDuration:0.2f];
    if (orientation == UIInterfaceOrientationPortrait || orientation == UIInterfaceOrientationPortraitUpsideDown){
        frame.size.height += keyboardBounds.size.height;
    }else{
        frame.size.height += keyboardBounds.size.width;
    }
    CGRect rToolbar = [[self.view.superview.superview.superview.subviews objectAtIndex:2] frame];
    frame.size.height -= rToolbar.size.height;
    self.view.frame = frame;
    [UIView commitAnimations];
}

#pragma mark - Table view

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self performSegueWithIdentifier:@"DetalleClientes" sender:indexPath];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"DetalleClientes"]) {
        DetalleClientesViewController *dcvcDetalleClientes = [segue destinationViewController];
        [dcvcDetalleClientes setAItems:aItemsAux];
        [dcvcDetalleClientes setIPosicion:(NSInteger *)[(NSIndexPath *)sender row]];
    }
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [NSString stringWithFormat:@"%d clientes:", [aItemsAux count]];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [aItemsAux count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *tvcListadoRevistas = [[[NSBundle mainBundle] loadNibNamed:@"ListadoClientesCell" owner:self options:nil] objectAtIndex:0];
    for (UIView *view in [[[tvcListadoRevistas subviews] objectAtIndex:0] subviews]) {
        if ([view isKindOfClass:[UILabel class]]) {
            if ([view tag] == 1) {
                [(UILabel *)view setText:[NSString stringWithFormat:@"%@ del %@", [(UILabel *)view text], [aItemsAux objectAtIndex:[indexPath row]]]];
            }
        }
    }
    return tvcListadoRevistas;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 91;
}

#pragma mark - Filtrado

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText
{
    [self setAItemsAux:aItems];
    if (![[searchText stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItems filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF contains[cd] %@", searchText]]];
        [self setAItemsAux:aAuxiliar];
    }
    [tvListadoClientes reloadData];
}

#pragma mark - Ordenaciones

- (IBAction)doOrdenarPor:(id)sender
{
    if ([mcOrdenarPor isMenuVisible]) {
        [mcOrdenarPor setMenuVisible:NO animated:YES];
        [self setMcOrdenarPor:nil];
    } else {
        [self becomeFirstResponder];
        [self setMcOrdenarPor:[UIMenuController sharedMenuController]];
        UIMenuItem *miCodigo = [[UIMenuItem alloc] initWithTitle:@"Código" action:@selector(doOrdenarPorCodigo:)];
        UIMenuItem *miNombre = [[UIMenuItem alloc] initWithTitle:@"Nombre" action:@selector(doOrdenarPorNombre:)];
        UIMenuItem *miCanal = [[UIMenuItem alloc] initWithTitle:@"Canal" action:@selector(doOrdenarPorCanal:)];
        UIMenuItem *miCalle = [[UIMenuItem alloc] initWithTitle:@"Calle" action:@selector(doOrdenarPorCalle:)];
        UIMenuItem *miPoblacion = [[UIMenuItem alloc] initWithTitle:@"Población" action:@selector(doOrdenarPorPoblacion:)];
        UIMenuItem *miCodigoPostal = [[UIMenuItem alloc] initWithTitle:@"Código postal" action:@selector(doOrdenarPorCodigoPostal:)];
        UIMenuItem *miProvincia = [[UIMenuItem alloc] initWithTitle:@"Provincia" action:@selector(doOrdenarPorProvincia:)];
        UIMenuItem *miPais = [[UIMenuItem alloc] initWithTitle:@"País" action:@selector(doOrdenarPorPais:)];
        UIMenuItem *miBloqueoEntrega = [[UIMenuItem alloc] initWithTitle:@"Bloqueo de entrega" action:@selector(doOrdenarPorBloqueoEntrega:)];
        [mcOrdenarPor setMenuItems:[NSArray arrayWithObjects:miCodigo, miNombre, miCanal, miCalle, miPoblacion, miCodigoPostal, miProvincia, miPais, miBloqueoEntrega, nil]];
        [mcOrdenarPor setTargetRect:[[sender view] frame] inView:self.navigationController.toolbar];
        [mcOrdenarPor setMenuVisible:YES animated:YES];
    }
}

- (void)doOrdenarPorCodigo:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:0]];
}

- (void)doOrdenarPorNombre:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:1]];
}

- (void)doOrdenarPorCanal:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:2]];
}

- (void)doOrdenarPorCalle:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:3]];
}

- (void)doOrdenarPorPoblacion:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:4]];
}

- (void)doOrdenarPorCodigoPostal:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:5]];
}

- (void)doOrdenarPorProvincia:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:6]];
}

- (void)doOrdenarPorPais:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:7]];
}

- (void)doOrdenarPorBloqueoEntrega:(id)sender
{
    [mcOrdenarPor setMenuVisible:NO animated:YES];
    UIMenuItem *miConBloqueoEntrega = [[UIMenuItem alloc] initWithTitle:@"Con bloqueo de entrega" action:@selector(doOrdenarConBloqueoEntrega:)];
    UIMenuItem *miSinBloqueoEntrega = [[UIMenuItem alloc] initWithTitle:@"Sin bloqueo de entrega" action:@selector(doOrdenarSinBloqueoEntrega:)];
    [mcOrdenarPor setMenuItems:[NSArray arrayWithObjects:miConBloqueoEntrega, miSinBloqueoEntrega, nil]];
    [self performSelector:@selector(doShowAscDesc:) withObject:nil afterDelay:0.3];
}

- (void)doOrdenarConBloqueoEntrega:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:8]];
}

- (void)doOrdenarSinBloqueoEntrega:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:9]];
}

- (void)doShowAscDesc:(id)sender
{
    [mcOrdenarPor setMenuVisible:YES animated:YES];
}

- (BOOL)canBecomeFirstResponder {
    return YES;
}

- (void)doOrdenar:(id)sender
{
    switch ([sender intValue]) {
        case 0:
            NSLog(@"Ordenar clientes por código asc.");
            break;
        case 1:
            NSLog(@"Ordenar clientes por nombre asc.");
            break;
        case 2:
            NSLog(@"Ordenar clientes por canal asc.");
            break;
        case 3:
            NSLog(@"Ordenar clientes por calle asc.");
            break;
        case 4:
            NSLog(@"Ordenar clientes por población asc.");
            break;
        case 5:
            NSLog(@"Ordenar clientes por código postal asc.");
            break;
        case 6:
            NSLog(@"Ordenar clientes por provincia asc.");
            break;
        case 7:
            NSLog(@"Ordenar clientes por país asc.");
            break;
        case 8:
            NSLog(@"Ordenar clientes con bloqueo de entrega");
            break;
        case 9:
            NSLog(@"Ordenar clientes sin bloqueo de entrega");
            break;
    }
}

@end
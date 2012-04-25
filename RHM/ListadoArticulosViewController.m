//
//  ListadoArticulosViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "ListadoArticulosViewController.h"
#import "InicioViewController.h"
#import "DetalleArticulosViewController.h"
#import "AppDelegate.h"

@implementation ListadoArticulosViewController

@synthesize masterPopoverController, mcOrdenarPor, tvListadoArticulos, sbListadoArticulos, aItems, aItemsAux;

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
    [self setMcOrdenarPor:nil];
    [self setAItems:nil];
    [self setAItemsAux:nil];
    [self setTvListadoArticulos:nil];
    [self setSbListadoArticulos:nil];
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
    [self performSegueWithIdentifier:@"DetalleArtículos" sender:indexPath];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"DetalleArtículos"]) {
        DetalleArticulosViewController *davcDetalleArticulos = [segue destinationViewController];
        [davcDetalleArticulos setAItems:aItemsAux];
        [davcDetalleArticulos setIPosicion:(NSInteger *)[(NSIndexPath *)sender row]];
    }
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [NSString stringWithFormat:@"%d artículos:", [aItemsAux count]];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [aItemsAux count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *tvcListadoArticulos = [[[NSBundle mainBundle] loadNibNamed:@"ListadoArticulosCell" owner:self options:nil] objectAtIndex:0];
    for (UIView *view in [[[tvcListadoArticulos subviews] objectAtIndex:0] subviews]) {
        if ([view isKindOfClass:[UIImageView class]]) {
            UITapGestureRecognizer *tgrImagen = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(doMostrarImagen:)];
            [view addGestureRecognizer:tgrImagen];
        }
        if ([view isKindOfClass:[UILabel class]]) {
            switch ([view tag]) {
                case 1:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZTITULO"]]];
                    break;
                case 2:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZSUBTIT"]]];
                    break;
                case 3:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZCODAUTC"]]];
                    break;
                case 4:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZPAGS"]]];
                    break;
                case 5:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZSELLO"]]];
                    break;
                case 6:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZTIPOTAPA"]]];
                    break;
                case 7:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@ €", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZCIVAVIG"]]];
                    break;
                case 8:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZCIVAVIG"]]];
                    break;
                case 9:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"ZZCOLECCION"]]];
                    break;
                case 10:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItemsAux objectAtIndex:[indexPath row]] objectForKey:@"KUNNR"]]];
                    break;
            }
        }
    }
    return tvcListadoArticulos;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 160;
}

#pragma mark - Imagen

- (void)doMostrarImagen:(id)sender
{
    NSString *sPathImagen = [[NSBundle mainBundle] pathForResource:@"P889140" ofType:@"jpg"];
    NSURL *urlImagen = [NSURL fileURLWithPath:sPathImagen];
    UIDocumentInteractionController *dicImagen = [UIDocumentInteractionController interactionControllerWithURL: urlImagen];
    [dicImagen setDelegate:self];
    [dicImagen presentPreviewAnimated: YES];
}

- (UIViewController *)documentInteractionControllerViewControllerForPreview:(UIDocumentInteractionController *)controller
{
    return self;
}

#pragma mark - Filtrado

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText
{
    [self setAItemsAux:aItems];
    if (![[searchText stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItems filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF contains[cd] %@", searchText]]];
        [self setAItemsAux:aAuxiliar];
    }
    [tvListadoArticulos reloadData];
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
        UIMenuItem *miTitulo = [[UIMenuItem alloc] initWithTitle:@"Título" action:@selector(doOrdenarPorTitulo:)];
        UIMenuItem *miAutor = [[UIMenuItem alloc] initWithTitle:@"Autor" action:@selector(doOrdenarPorAutor:)];
        UIMenuItem *miSello = [[UIMenuItem alloc] initWithTitle:@"Sello" action:@selector(doOrdenarPorSello:)];
        UIMenuItem *miColeccion = [[UIMenuItem alloc] initWithTitle:@"Colección" action:@selector(doOrdenarPorColeccion:)];
        UIMenuItem *miPrecio = [[UIMenuItem alloc] initWithTitle:@"Precio" action:@selector(doOrdenarPorPrecio:)];
        UIMenuItem *miFechaPublicacion = [[UIMenuItem alloc] initWithTitle:@"Fecha de publicación" action:@selector(doOrdenarPorFechaPublicacion:)];
        [mcOrdenarPor setMenuItems:[NSArray arrayWithObjects:miCodigo, miTitulo, miAutor, miSello, miColeccion, miPrecio, miFechaPublicacion, nil]];
        [mcOrdenarPor setTargetRect:[[sender view] frame] inView:self.navigationController.toolbar];
        [mcOrdenarPor setMenuVisible:YES animated:YES];
    }
}

- (void)doOrdenarPorCodigo:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:0]];
}

- (void)doOrdenarPorTitulo:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:1]];
}

- (void)doOrdenarPorAutor:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:2]];
}

- (void)doOrdenarPorSello:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:3]];
}

- (void)doOrdenarPorColeccion:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:4]];
}

- (void)doOrdenarPorPrecio:(id)sender
{
    [mcOrdenarPor setMenuVisible:NO animated:YES];
    UIMenuItem *miAscendente = [[UIMenuItem alloc] initWithTitle:@"Precio ascendente" action:@selector(doOrdenarPorPrecioAscendente:)];
    UIMenuItem *miDescendente = [[UIMenuItem alloc] initWithTitle:@"Precio descendente" action:@selector(doOrdenarPorPrecioDescendente:)];
    [mcOrdenarPor setMenuItems:[NSArray arrayWithObjects:miAscendente, miDescendente, nil]];
    [self performSelector:@selector(doShowAscDesc:) withObject:nil afterDelay:0.3];
}

- (void)doOrdenarPorPrecioAscendente:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:5]];
}

- (void)doOrdenarPorPrecioDescendente:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:6]];
}

- (void)doOrdenarPorFechaPublicacion:(id) sender {
    [mcOrdenarPor setMenuVisible:NO animated:YES];
    UIMenuItem *miAscendente = [[UIMenuItem alloc] initWithTitle:@"Fecha de publicación ascendente" action:@selector(doOrdenarPorFechaAscendente:)];
    UIMenuItem *miDescendente = [[UIMenuItem alloc] initWithTitle:@"Fecha de publicación descendente" action:@selector(doOrdenarPorFechaDescendente:)];
    [mcOrdenarPor setMenuItems:[NSArray arrayWithObjects:miAscendente, miDescendente, nil]];
    [self performSelector:@selector(doShowAscDesc:) withObject:nil afterDelay:0.3];
}

- (void)doOrdenarPorFechaAscendente:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:7]];
}

- (void)doOrdenarPorFechaDescendente:(id)sender
{
    [self performSelector:@selector(doOrdenar:) withObject:[NSNumber numberWithInt:8]];
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
            NSLog(@"Ordenar artículos por código asc.");
            break;
        case 1:
            NSLog(@"Ordenar artículos por título asc.");
            break;
        case 2:
            NSLog(@"Ordenar artículos por autor asc.");
            break;
        case 3:
            NSLog(@"Ordenar artículos por sello asc.");
            break;
        case 4:
            NSLog(@"Ordenar artículos por colección asc.");
            break;
        case 5:
            NSLog(@"Ordenar artículos por precio asc.");
            break;
        case 6:
            NSLog(@"Ordenar artículos por precio desc.");
            break;
        case 7:
            NSLog(@"Ordenar artículos por fecha asc.");
            break;
        case 8:
            NSLog(@"Ordenar artículos por fecha desc.");
            break;
    }
}

@end
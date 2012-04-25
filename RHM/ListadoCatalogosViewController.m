//
//  ListadoCatalogosViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "ListadoCatalogosViewController.h"
#import "InicioViewController.h"
#import "DetalleCatalogosViewController.h"
#import "AppDelegate.h"

@implementation ListadoCatalogosViewController

@synthesize masterPopoverController, sbListadoCatalogos, tvListadoCatalogos, aItemsCentralizados, aItemsCentralizadosAux, aItemsPropios, aItemsPropiosAux;

- (void)viewDidLoad
{
    [super viewDidLoad];
    if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
    [self setAItemsCentralizadosAux:aItemsCentralizados];
    [self setAItemsPropiosAux:aItemsPropios];
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
    [self setAItemsCentralizados:nil];
    [self setAItemsCentralizadosAux:nil];
    [self setAItemsPropios:nil];
    [self setAItemsPropiosAux:nil];
    [self setSbListadoCatalogos:nil];
    [self setTvListadoCatalogos:nil];
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
    [self performSegueWithIdentifier:@"DetalleCatálogos" sender:indexPath];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"DetalleCatálogos"]) {
        //DetalleCatalogosViewController *dcvcDetalleCatalogos = [segue destinationViewController];
        //[dcvcDetalleCatalogos setAItems:aItemsAux];
        //[dcvcDetalleCatalogos setIPosicion:(NSInteger *)[(NSIndexPath *)sender row]];
    }
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    if (aItemsCentralizadosAux != nil && aItemsPropiosAux != nil) {
        return 2;
    } else if (!(aItemsCentralizadosAux == nil && aItemsPropiosAux == nil)) {
        return 1;
    }
    return 0;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    switch (section) {
        case 0:
            if (aItemsCentralizadosAux == nil) {
                return [NSString stringWithFormat:@"%d catálogos propios:", [aItemsPropiosAux count]];
            } else {
                return [NSString stringWithFormat:@"%d catálogos centralizados:", [aItemsCentralizadosAux count]];
            }
            break;
        case 1:
            return [NSString stringWithFormat:@"%d catálogos propios:", [aItemsPropiosAux count]];
            break;
    }
    return nil;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    switch (section) {
        case 0:
            if (aItemsCentralizadosAux == nil) {
                return [aItemsPropiosAux count];
            } else {
                return [aItemsCentralizadosAux count];
            }
            break;
        case 1:
            return [aItemsPropiosAux count];
            break;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *tvcListadoCatalogos = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
    if (tvcListadoCatalogos == nil) {
        tvcListadoCatalogos = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
    }
    switch ([indexPath section]) {
        case 0:
            if (aItemsCentralizadosAux == nil) {
                [[tvcListadoCatalogos textLabel] setText:[NSString stringWithFormat:@"Descripción del %@", [aItemsPropiosAux objectAtIndex:[indexPath row]]]];
                [[tvcListadoCatalogos detailTextLabel] setText:[NSString stringWithFormat:@"Cliente del %@, Cliente principal del %@, Ramo 1 del %@", [aItemsPropiosAux objectAtIndex:[indexPath row]], [aItemsPropiosAux objectAtIndex:[indexPath row]], [aItemsPropiosAux objectAtIndex:[indexPath row]]]];
            } else {
                [[tvcListadoCatalogos textLabel] setText:[NSString stringWithFormat:@"Descripción del %@", [aItemsCentralizadosAux objectAtIndex:[indexPath row]]]];
                [[tvcListadoCatalogos detailTextLabel] setText:[NSString stringWithFormat:@"Cliente del %@, Cliente principal del %@, Ramo 1 del %@", [aItemsCentralizadosAux objectAtIndex:[indexPath row]], [aItemsCentralizadosAux objectAtIndex:[indexPath row]], [aItemsCentralizadosAux objectAtIndex:[indexPath row]]]];
            }
            break;
        case 1:
            [[tvcListadoCatalogos textLabel] setText:[NSString stringWithFormat:@"Descripción del %@", [aItemsPropiosAux objectAtIndex:[indexPath row]]]];
            [[tvcListadoCatalogos detailTextLabel] setText:[NSString stringWithFormat:@"Cliente del %@, Cliente principal del %@, Ramo 1 del %@", [aItemsPropiosAux objectAtIndex:[indexPath row]], [aItemsPropiosAux objectAtIndex:[indexPath row]], [aItemsPropiosAux objectAtIndex:[indexPath row]]]];
            break;
    }
    /*for (UIView *view in [[[tvcListadoRevistas subviews] objectAtIndex:0] subviews]) {
     if ([view isKindOfClass:[UILabel class]]) {
     if ([view tag] == 1) {
     switch ([indexPath section]) {
     case 0:
     if (aItemsCentralizadosAux == nil) {
     [(UILabel *)view setText:[NSString stringWithFormat:@"%@ del %@", [(UILabel *)view text], [aItemsPropiosAux objectAtIndex:[indexPath row]]]];
     } else {
     [(UILabel *)view setText:[NSString stringWithFormat:@"%@ del %@", [(UILabel *)view text], [aItemsCentralizadosAux objectAtIndex:[indexPath row]]]];
     }
     break;
     case 1:
     [(UILabel *)view setText:[NSString stringWithFormat:@"%@ del %@", [(UILabel *)view text], [aItemsPropiosAux objectAtIndex:[indexPath row]]]];
     break;
     }
     }
     }
     }*/
    return tvcListadoCatalogos;
}

#pragma mark - Filtrado

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText
{
    [self setAItemsCentralizadosAux:aItemsCentralizados];
    [self setAItemsPropiosAux:aItemsPropios];
    if (![[searchText stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItemsCentralizados filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF contains[cd] %@", searchText]]];
        [self setAItemsCentralizadosAux:aAuxiliar];
        aAuxiliar = [[NSArray alloc] initWithArray:[aItemsPropios filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF contains[cd] %@", searchText]]];
        [self setAItemsPropiosAux:aAuxiliar];
    }
    [tvListadoCatalogos reloadData];
}

@end
//
//  ListadoRevistasViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "ListadoRevistasViewController.h"
#import "InicioViewController.h"
#import "AppDelegate.h"

@implementation ListadoRevistasViewController

@synthesize masterPopoverController, tvListadoRevistas, sbListadoRevistas, aItems, aItemsAux;

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
    [self setTvListadoRevistas:nil];
    [self setSbListadoRevistas:nil];
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
    NSString *sPathImagen = [[NSBundle mainBundle] pathForResource:@"ipad_manual_del_usuario" ofType:@"pdf"];
    NSURL *urlImagen = [NSURL fileURLWithPath:sPathImagen];
    UIDocumentInteractionController *dicImagen = [UIDocumentInteractionController interactionControllerWithURL: urlImagen];
    [dicImagen setDelegate:self];
    [dicImagen presentPreviewAnimated: YES];
}

- (UIViewController *)documentInteractionControllerViewControllerForPreview:(UIDocumentInteractionController *)controller
{
    return self;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return [NSString stringWithFormat:@"%d revistas:", [aItemsAux count]];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [aItemsAux count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *tvcListadoRevistas = [[[NSBundle mainBundle] loadNibNamed:@"ListadoRevistasCell" owner:self options:nil] objectAtIndex:0];
    for (UIView *view in [[[tvcListadoRevistas subviews] objectAtIndex:0] subviews]) {
        if ([view isKindOfClass:[UILabel class]]) {
            if ([view tag] == 1) {
                [(UILabel *)view setText:[NSString stringWithFormat:@"%@ de la %@", [(UILabel *)view text], [aItemsAux objectAtIndex:[indexPath row]]]];
            }
        }
    }
    return tvcListadoRevistas;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 76;
}

#pragma mark - Filtrado

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText
{
    [self setAItemsAux:aItems];
    if (![[searchText stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItems filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF contains[cd] %@", searchText]]];
        [self setAItemsAux:aAuxiliar];
    }
    [tvListadoRevistas reloadData];
}

@end
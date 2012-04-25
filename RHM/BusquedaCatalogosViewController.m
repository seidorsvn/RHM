//
//  BusquedaCatalogosViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "BusquedaCatalogosViewController.h"
#import "InicioViewController.h"
#import "ListadoCatalogosViewController.h"
#import "AppDelegate.h"

@implementation BusquedaCatalogosViewController

@synthesize masterPopoverController, tvBusquedaCatalogos, tvBuscarMatchCode, scTipo, pcBuscarMatchCode, iBuscarMatchCodeTag, tfCampoActivo, aItems;

- (void)viewDidLoad
{
    [super viewDidLoad];
    if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [(AppDelegate *)[[UIApplication sharedApplication] delegate] dismissKeyboard];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardDidShow:) name:UIKeyboardDidShowNotification object:nil];
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
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardDidShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillHideNotification object:nil];
    [(AppDelegate *)[[UIApplication sharedApplication] delegate] dismissKeyboard];
    if ([pcBuscarMatchCode isPopoverVisible]) {
        [pcBuscarMatchCode dismissPopoverAnimated:YES];
    }
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
    [self setPcBuscarMatchCode:nil];
    [self setTvBuscarMatchCode:nil];
    [self setTvBusquedaCatalogos:nil];
    [self setTfCampoActivo:nil];
    [self setAItems:nil];
    [self setScTipo:nil];
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return YES;
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    if ([pcBuscarMatchCode isPopoverVisible]) {
        [pcBuscarMatchCode dismissPopoverAnimated:YES];
    }
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

- (void)doResizePopoverContent:(NSNotification *)note
{
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    if (orientation != UIInterfaceOrientationPortrait && orientation != UIInterfaceOrientationPortraitUpsideDown) {
        if ([[note name] isEqualToString:@"UIKeyboardDidShowNotification"] && [pcBuscarMatchCode isPopoverVisible]) {
            CGRect rBuscarMatchCode = [[[[[pcBuscarMatchCode contentViewController] view] subviews] objectAtIndex:1] frame];
            rBuscarMatchCode.size.height = 310;
            [[[[[pcBuscarMatchCode contentViewController] view] subviews] objectAtIndex:1] setFrame:rBuscarMatchCode];
        } else if ([[note name] isEqualToString:@"UIKeyboardWillHideNotification"] && [pcBuscarMatchCode isPopoverVisible]) {
            CGRect rBuscarMatchCode = [(UITableView *)[[[[pcBuscarMatchCode contentViewController] view] subviews] objectAtIndex:1] frame];
            rBuscarMatchCode.size.height = 450;
            [(UITableView *)[[[[pcBuscarMatchCode contentViewController] view] subviews] objectAtIndex:1] setFrame:rBuscarMatchCode];
        }
    }
}

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    [tvBusquedaCatalogos scrollToRowAtIndexPath:[self.tvBusquedaCatalogos indexPathForCell:(UITableViewCell *)[[textField superview] superview]] atScrollPosition:UITableViewScrollPositionMiddle animated:YES];
    [self setTfCampoActivo:textField];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [self performSelector:@selector(doBuscar:) withObject:nil];
    return YES;
}

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
    if (tfCampoActivo)
    {
        CGRect textFieldRect = [self.tvBusquedaCatalogos convertRect:[tfCampoActivo bounds] fromView:tfCampoActivo];
        [self.tvBusquedaCatalogos scrollRectToVisible:textFieldRect animated:NO];
    }
    [UIView commitAnimations];
}

- (void)keyboardDidShow:(NSNotification *)note
{
    [self doResizePopoverContent:note];
}

- (void)keyboardWillHide:(NSNotification *)note
{
    [self doResizePopoverContent:note];
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
    int i=-1;
    BOOL bEncontrado = NO;
    while (!bEncontrado) {
        i++;
        if ([[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] count]>1 && [[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] count]>2 && [[[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] isKindOfClass:[UIButton class]] && [[[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] tag] == iBuscarMatchCodeTag) {
            bEncontrado = YES;
        }
    }
    UITextField *tfBuscarMatchCode = [[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:1];
    [tfBuscarMatchCode setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] textLabel] text]];
    [pcBuscarMatchCode dismissPopoverAnimated:YES];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    switch ([tableView tag]) {
        case 0:
            return 1;
            break;
        case 1:
            return 1;
            break;
    }
    return 0;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    switch ([tableView tag]) {
        case 0:
            switch (section) {
                case 0:
                    return @"Búsqueda general:";
                    break;
            }
            break;
        case 1:
            return [NSString stringWithFormat:@"%d resultados:", [aItems count]];
            break;
    }
    return nil;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    switch ([tableView tag]) {
        case 0:
            switch (section) {
                case 0:
                    return 5;
                    break;
            }
            break;
        case 1:
            return [aItems count];
            break;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    switch ([tableView tag]) {
        case 0:
        {
            UITableViewCell *tvcBusquedaCatalogos = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
            if (tvcBusquedaCatalogos == nil) {
                tvcBusquedaCatalogos = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
            }
            if ([[[[tvcBusquedaCatalogos subviews] lastObject] subviews] count]>1) {
                [[[[[tvcBusquedaCatalogos subviews] lastObject] subviews] objectAtIndex:1] setDelegate:self];
            }
            return tvcBusquedaCatalogos;
            break;
        }
        case 1:
        {
            UITableViewCell *tvcBuscarMatchCode = [tableView dequeueReusableCellWithIdentifier:@"ciBuscarMatchCode"];
            if (tvcBuscarMatchCode == nil) {
                tvcBuscarMatchCode = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"ciBuscarMatchCode"];
            }
            [tvcBuscarMatchCode setAccessoryType:UITableViewCellAccessoryDisclosureIndicator];
            [tvcBuscarMatchCode.textLabel setText:[aItems objectAtIndex:[indexPath row]]];
            return tvcBuscarMatchCode;
            break;
        }
    }
    return nil;
}

#pragma mark - Buscar match code

- (IBAction)doBuscarMatchCode:(id)sender
{
    [(AppDelegate *)[[UIApplication sharedApplication] delegate] dismissKeyboard];
    [self doSetItems];
    UIView *vBuscarMatchCode = [[UIView alloc] init];
    UISearchBar *sbBuscarMatchCode = [[UISearchBar alloc] init];
    [sbBuscarMatchCode setFrame:CGRectMake(0, 0, 500, 50)];
    [sbBuscarMatchCode setDelegate:self];
    [self setIBuscarMatchCodeTag:[sender tag]];
    [vBuscarMatchCode addSubview:sbBuscarMatchCode];
    [self setTvBuscarMatchCode:[[UITableView alloc] initWithFrame:CGRectMake(0, sbBuscarMatchCode.frame.size.height, 500, 450) style:UITableViewStyleGrouped]];
    [tvBuscarMatchCode setTag:1];
    [tvBuscarMatchCode setDelegate:self];
    [tvBuscarMatchCode setDataSource:self];
    [vBuscarMatchCode addSubview:tvBuscarMatchCode];
    UIViewController *vcBuscarMatchCode = [[UIViewController alloc] init];
    [vcBuscarMatchCode setView:vBuscarMatchCode];
    [vcBuscarMatchCode setContentSizeForViewInPopover:CGSizeMake(500, 500)];
    int i=-1;
    BOOL bEncontrado = NO;
    while (!bEncontrado) {
        i++;
        if ([[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] count]>1 && [[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] count]>2 && [[[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] isKindOfClass:[UIButton class]] && [[[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] tag] == [sender tag]) {
            bEncontrado = YES;
        }
    }
    UIButton *buDisclosure = [[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2];
    [sbBuscarMatchCode setText:[[NSString stringWithFormat:@"%@", [(UITextField *)[[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:1] text]]stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]]];
    if (![[[sbBuscarMatchCode text] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItems filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF contains[cd] %@", [sbBuscarMatchCode text]]]];
        [self setAItems:aAuxiliar];
        [tvBuscarMatchCode reloadData];
    }
    [sbBuscarMatchCode setPlaceholder:[[[[[[[[tvBusquedaCatalogos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:1] placeholder] stringByReplacingOccurrencesOfString:@"Establecer " withString:@"Filtrar "]];
    [self setPcBuscarMatchCode:[[UIPopoverController alloc] initWithContentViewController:vcBuscarMatchCode]];
    if (buDisclosure.superview.window != nil) {
        [pcBuscarMatchCode presentPopoverFromRect:CGRectMake(buDisclosure.frame.origin.x, buDisclosure.frame.origin.y, buDisclosure.frame.origin.x, buDisclosure.frame.size.height) inView:buDisclosure.superview permittedArrowDirections:UIPopoverArrowDirectionRight animated:YES];
    }
}

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText
{
    [self doSetItems];
    if (![[searchText stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItems filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF contains[cd] %@", searchText]]];
        [self setAItems:aAuxiliar];
    }
    [tvBuscarMatchCode reloadData];
}

- (void)doSetItems{
    NSMutableArray *aAuxiliar = [[NSMutableArray alloc] init];
    for (int i=0; i<5000; i++) {
        [aAuxiliar addObject:[NSString stringWithFormat:@"Item %d", i]];
    }
    [self setAItems:aAuxiliar];
}

#pragma mark - Buscar

- (IBAction)doBuscar:(id)sender
{
    [self performSegueWithIdentifier:@"ListadoCatálogos" sender:sender];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"ListadoCatálogos"]) {
        ListadoCatalogosViewController *lcvcListadoCatalogos = [segue destinationViewController];
        NSMutableArray *aAuxiliar = [[NSMutableArray alloc] init];
        for (int i=0; i<5; i++) {
            [aAuxiliar addObject:[NSString stringWithFormat:@"Catálogo centralizado %d", i]];
        }
        [lcvcListadoCatalogos setAItemsCentralizados:aAuxiliar];
        aAuxiliar = [[NSMutableArray alloc] init];
        for (int i=0; i<10; i++) {
            [aAuxiliar addObject:[NSString stringWithFormat:@"Catálogo propio %d", i]];
        }
        [lcvcListadoCatalogos setAItemsPropios:aAuxiliar];
    }
}

@end
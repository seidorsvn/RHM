//
//  DetalleClientesViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "DetalleClientesViewController.h"
#import "InicioViewController.h"
#import <EventKit/EventKit.h>
#import <EventKitUI/EventKitUI.h>

@implementation DetalleClientesViewController

@synthesize masterPopoverController, tvDetalleClientes, aItems, iPosicion;

- (void)viewDidLoad
{
    [super viewDidLoad];
    if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
    [self.navigationItem setRightBarButtonItems:[[NSArray alloc] initWithObjects:[[UIBarButtonItem alloc] initWithTitle:@"Cita" style:UIBarButtonItemStyleBordered target:self action:@selector(doCita)], [[UIBarButtonItem alloc] initWithTitle:@"E-mail" style:UIBarButtonItemStyleBordered target:self action:@selector(doEmail)], [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace target:nil action:nil], [[UIBarButtonItem alloc] initWithTitle:@"QlikView" style:UIBarButtonItemStyleBordered target:self action:@selector(doQlikView)], nil]];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
    [self.navigationItem setRightBarButtonItems:[[NSArray alloc] initWithObjects:[[UIBarButtonItem alloc] initWithTitle:@"Cita" style:UIBarButtonItemStyleBordered target:self action:@selector(doCita)], [[UIBarButtonItem alloc] initWithTitle:@"E-mail" style:UIBarButtonItemStyleBordered target:self action:@selector(doEmail)], [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace target:nil action:nil], [[UIBarButtonItem alloc] initWithTitle:@"QlikView" style:UIBarButtonItemStyleBordered target:self action:@selector(doQlikView)], nil]];
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
    [self setTvDetalleClientes:nil];
    [self setAItems:nil];
    [self setIPosicion:nil];
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

#pragma mark - Table view

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    switch (section) {
        case 0:
            return @"Información general";
            break;
        case 1:
            return @"Información adicional";
            break;
    }
    return nil;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    switch ([indexPath section]) {
        case 0:
            return 208;
            break;
        case 1:
            return 237;
            break;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *tvcDetalleClientes = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
    if (tvcDetalleClientes == nil) {
        tvcDetalleClientes = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
    }
    for (UIView *view in [[[tvcDetalleClientes subviews]objectAtIndex:0] subviews]) {
        if ([view isKindOfClass:[UILabel class]]) {
            [(UILabel *)view setText:[NSString stringWithFormat:@"%@ del %@", [(UILabel *)view text], [aItems objectAtIndex:(NSUInteger)iPosicion]]];
        }
    }
    return tvcDetalleClientes;
}

#pragma mark - Cita

- (void)doCita
{
    EKEventStore *esCalendario = [[EKEventStore alloc] init];
    EKEvent *eEvento  = [EKEvent eventWithEventStore:esCalendario];
    [eEvento setCalendar:[esCalendario defaultCalendarForNewEvents]];
    [eEvento setTitle:[NSString stringWithFormat:@"Cita con %@", [(UILabel *)[[[[[[tvDetalleClientes subviews] objectAtIndex:2] subviews] objectAtIndex:1] subviews] objectAtIndex:4] text]]];
    [eEvento setLocation:[NSString stringWithFormat:@"%@", [(UILabel *)[[[[[[tvDetalleClientes subviews] objectAtIndex:2] subviews] objectAtIndex:1] subviews] objectAtIndex:5] text]]];
    EKEventEditViewController *eevcCalendario = [[EKEventEditViewController alloc] init];
    [eevcCalendario setEventStore:esCalendario];
    [eevcCalendario setEvent:eEvento];
    [eevcCalendario setEditViewDelegate:self];
    [eevcCalendario setModalPresentationStyle:UIModalPresentationFormSheet];
    [eevcCalendario setModalTransitionStyle:UIModalTransitionStyleFlipHorizontal];
    [self presentModalViewController:eevcCalendario animated:YES];
}

- (void)eventEditViewController:(EKEventEditViewController *)controller didCompleteWithAction:(EKEventEditViewAction)action
{
    if (action == EKEventEditViewActionSaved) {
        [[[UIAlertView alloc] initWithTitle:@"Información" message:@"La cita ha sido guardada correctamente en su calendario por defecto." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil] show];
    }
    [self dismissModalViewControllerAnimated:YES];
}

#pragma mark - E-mail

- (void)doEmail
{
    NSURL *uPath = [NSURL URLWithString:@"mailto:csolana@seidor.es?subject=Test&body=Hola,%20esto%20es%20una%20prueba."];
    if ([[UIApplication sharedApplication] canOpenURL:uPath]) {
        [[UIApplication sharedApplication] openURL:uPath];
    } else {
        [[[UIAlertView alloc] initWithTitle:@"Advertencia" message:@"No ha sido posible iniciar Mail con la información especificada." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil] show];
    }
}

#pragma mark - QlikView

- (void)doQlikView
{
    NSURL *uPath = [NSURL URLWithString:@"http://www.google.es/#hl=es&q=poner%20la%20url%20del%20qlikview"];
    if ([[UIApplication sharedApplication] canOpenURL:uPath]) {
        [[UIApplication sharedApplication] openURL:uPath];
    } else {
        [[[UIAlertView alloc] initWithTitle:@"Advertencia" message:@"No ha sido posible iniciar Safari con la URL especificada." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil] show];
    }
}

#pragma mark - Consultar notas

- (IBAction)doConsultarNotas:(id)sender
{
    [self performSegueWithIdentifier:@"NotasClientes" sender:sender];
}

#pragma mark - Visualizar plantillas

- (IBAction)doVisualizarPlantillas:(id)sender
{
    [self performSegueWithIdentifier:@"ListadoCatálogo" sender:sender];
}

#pragma mark - Visualizar articulos

- (IBAction)doVisualizarArticulos:(id)sender
{
    [self performSegueWithIdentifier:@"BúsquedaArtículo" sender:sender];
}

#pragma mark - Crear pedido

- (IBAction)doCrearPedido:(id)sender
{
    [self performSegueWithIdentifier:@"DetallePedido" sender:sender];
}

@end
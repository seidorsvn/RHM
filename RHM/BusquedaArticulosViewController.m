//
//  BusquedaArticulosViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "BusquedaArticulosViewController.h"
#import "InicioViewController.h"
#import "ZBarReaderViewController.h"
#import "ListadoArticulosViewController.h"
#import "AppDelegate.h"

@implementation BusquedaArticulosViewController

@synthesize masterPopoverController, tvBusquedaArticulos, scNovedad, scFechas, pcFechas, mcReiniciarFecha, scEstados, pcEstados, mcReiniciarEstado, scTapas, pcTapas, mcReiniciarTapa, scDivisionEditorial, pcDivisionEditorial, mcReiniciarDivisionEditorial, scTargetEdad, pcTargetEdad, mcReiniciarTargetEdad, scMaterial, pcMaterial, mcReiniciarMaterial, pcBuscarMatchCode, tvBuscarMatchCode, iBuscarMatchCodeTag, tfCampoActivo, aItems, aivCargando, tfAmbito, tfBIC, tfAutor, tfSello, tfCliente, tfTematica, tfCodigoEAN, tfColeccion, tfPersonaje, tfManuscrito, tfCodigoArticulo, tfTituloDefinitivo, tfCategoriaEditorial, sBIC, sAutor, sSello, sAmbito, sEstado, sCliente, sNovedad, sTematica, sTipoTapa, sCodigoEAN, sColeccion, sPersonaje, sCategoriaEditorial, sTargetEdad, sTituloDefinitivo, sManuscrito, sFechaPublicacion, sCodigoArticulo, sDivisionEditorial, sTipoMaterial;

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
    if ([pcFechas isPopoverVisible]) {
        [pcFechas dismissPopoverAnimated:YES];
    }
    if ([pcEstados isPopoverVisible]) {
        [pcEstados dismissPopoverAnimated:YES];
    }
    if ([pcTapas isPopoverVisible]) {
        [pcTapas dismissPopoverAnimated:YES];
    }
    if ([pcDivisionEditorial isPopoverVisible]) {
        [pcDivisionEditorial dismissPopoverAnimated:YES];
    }
    if ([pcTargetEdad isPopoverVisible]) {
        [pcTargetEdad dismissPopoverAnimated:YES];
    }
    if ([pcMaterial isPopoverVisible]) {
        [pcMaterial dismissPopoverAnimated:YES];
    }
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
    [self setScFechas:nil];
    [self setScEstados:nil];
    [self setScTapas:nil];
    [self setScDivisionEditorial:nil];
    [self setScTargetEdad:nil];
    [self setScMaterial:nil];
    [self setPcFechas:nil];
    [self setPcEstados:nil];
    [self setPcTapas:nil];
    [self setPcDivisionEditorial:nil];
    [self setPcTargetEdad:nil];
    [self setPcMaterial:nil];
    [self setPcBuscarMatchCode:nil];
    [self setMcReiniciarFecha:nil];
    [self setMcReiniciarEstado:nil];
    [self setMcReiniciarTapa:nil];
    [self setMcReiniciarDivisionEditorial:nil];
    [self setMcReiniciarTargetEdad:nil];
    [self setMcReiniciarMaterial:nil];
    [self setTvBusquedaArticulos:nil];
    [self setTvBuscarMatchCode:nil];
    [self setTfCampoActivo:nil];
    [self setAItems:nil];
    [self setScNovedad:nil];
    [self setTfCodigoArticulo:nil];
    [self setTfTituloDefinitivo:nil];
    [self setTfAutor:nil];
    [self setTfSello:nil];
    [self setTfColeccion:nil];
    [self setTfCliente:nil];
    [self setTfCodigoEAN:nil];
    [self setTfManuscrito:nil];
    [self setTfCategoriaEditorial:nil];
    [self setTfTematica:nil];
    [self setTfBIC:nil];
    [self setTfPersonaje:nil];
    [self setTfAmbito:nil];
    [self setSCodigoArticulo:nil];
    [self setSTituloDefinitivo:nil];
    [self setSAutor:nil];
    [self setSSello:nil];
    [self setSColeccion:nil];
    [self setSNovedad:nil];
    [self setSFechaPublicacion:nil];
    [self setSEstado:nil];
    [self setSCliente:nil];
    [self setSCodigoEAN:nil];
    [self setSTipoTapa:nil];
    [self setSManuscrito:nil];
    [self setSDivisionEditorial:nil];
    [self setSCategoriaEditorial:nil];
    [self setSTematica:nil];
    [self setSBIC:nil];
    [self setSTargetEdad:nil];
    [self setSPersonaje:nil];
    [self setSTipoMaterial:nil];
    [self setSAmbito:nil];
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return YES;
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    if ([pcFechas isPopoverVisible]) {
        [pcFechas dismissPopoverAnimated:YES];
    }
    if ([pcEstados isPopoverVisible]) {
        [pcEstados dismissPopoverAnimated:YES];
    }
    if ([pcTapas isPopoverVisible]) {
        [pcTapas dismissPopoverAnimated:YES];
    }
    if ([pcDivisionEditorial isPopoverVisible]) {
        [pcDivisionEditorial dismissPopoverAnimated:YES];
    }
    if ([pcTargetEdad isPopoverVisible]) {
        [pcTargetEdad dismissPopoverAnimated:YES];
    }
    if ([pcMaterial isPopoverVisible]) {
        [pcMaterial dismissPopoverAnimated:YES];
    }
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
    [tvBusquedaArticulos scrollToRowAtIndexPath:[self.tvBusquedaArticulos indexPathForCell:(UITableViewCell *)[[textField superview] superview]] atScrollPosition:UITableViewScrollPositionMiddle animated:YES];
    [self setTfCampoActivo:textField];
}

- (BOOL)textFieldShouldClear:(UITextField *)textField
{
    NSIndexPath *ipCampoActivo = [tvBusquedaArticulos indexPathForCell:(UITableViewCell *)[[textField superview] superview]];
    switch ([ipCampoActivo section]) {
        case 0:
            switch ([ipCampoActivo row]) {
                case 0:
                    [self setSCodigoArticulo:@""];
                    break;
                case 1:
                    [self setSTituloDefinitivo:@""];
                    break;
                case 2:
                    [self setSAutor:@""];
                    break;
                case 3:
                    [self setSSello:@""];
                    break;
                case 4:
                    [self setSColeccion:@""];
                    break;
                case 8:
                    [self setSCliente:@""];
                    break;
            }
            break;
        case 1:
            switch ([ipCampoActivo row]) {
                case 0:
                    [self setSCodigoEAN:@""];
                    break;
                case 2:
                    [self setSManuscrito:@""];
                    break;
                case 4:
                    [self setSCategoriaEditorial:@""];
                    break;
                case 5:
                    [self setSTematica:@""];
                    break;
                case 6:
                    [self setSBIC:@""];
                    break;
                case 8:
                    [self setSPersonaje:@""];
                    break;
                case 10:
                    [self setSAmbito:@""];
                    break;
            }
            break;
    }
    return YES;
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    NSIndexPath *ipCampoActivo = [tvBusquedaArticulos indexPathForCell:(UITableViewCell *)[[textField superview] superview]];
    switch ([ipCampoActivo section]) {
        case 0:
            switch ([ipCampoActivo row]) {
                case 0:
                    if (range.length == 1) {
                        [self setSCodigoArticulo:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSCodigoArticulo:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 1:
                    if (range.length == 1) {
                        [self setSTituloDefinitivo:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSTituloDefinitivo:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 2:
                    if (range.length == 1) {
                        [self setSAutor:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSAutor:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 3:
                    if (range.length == 1) {
                        [self setSSello:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSSello:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 4:
                    if (range.length == 1) {
                        [self setSColeccion:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSColeccion:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 8:
                    if (range.length == 1) {
                        [self setSCliente:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSCliente:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
            }
            break;
        case 1:
            switch ([ipCampoActivo row]) {
                case 0:
                    if (range.length == 1) {
                        [self setSCodigoEAN:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSCodigoEAN:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 2:
                    if (range.length == 1) {
                        [self setSManuscrito:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSManuscrito:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 4:
                    if (range.length == 1) {
                        [self setSCategoriaEditorial:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSCategoriaEditorial:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 5:
                    if (range.length == 1) {
                        [self setSTematica:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSTematica:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 6:
                    if (range.length == 1) {
                        [self setSBIC:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSBIC:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 8:
                    if (range.length == 1) {
                        [self setSPersonaje:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSPersonaje:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
                case 10:
                    if (range.length == 1) {
                        [self setSAmbito:[[textField text] substringToIndex:[[textField text] length] - 1]];
                    } else {
                        [self setSAmbito:[NSString stringWithFormat:@"%@%@", [textField text], string]];
                    }
                    break;
            }
            break;
    }
    return YES;
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
        CGRect textFieldRect = [self.tvBusquedaArticulos convertRect:[tfCampoActivo bounds] fromView:tfCampoActivo];
        [self.tvBusquedaArticulos scrollRectToVisible:textFieldRect animated:NO];
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
    switch (iBuscarMatchCodeTag) {
        case 0:
            [tfCodigoArticulo setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] textLabel] text]];
            [self setSCodigoArticulo:[tfCodigoArticulo text]];
            break;
        case 1:
            [tfTituloDefinitivo setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] textLabel] text]];
            [self setSTituloDefinitivo:[tfTituloDefinitivo text]];
            break;
        case 2:
            [tfAutor setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSAutor:[tfAutor text]];
            break;
        case 3:
            [tfSello setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSSello:[tfSello text]];
            break;
        case 4:
            [tfColeccion setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSColeccion:[tfColeccion text]];
            break;
        case 8:
            [tfCliente setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSCliente:[tfCliente text]];
            break;
        case 11:
            [tfManuscrito setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSManuscrito:[tfManuscrito text]];
            break;
        case 13:
            [tfCategoriaEditorial setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSCategoriaEditorial:[tfCategoriaEditorial text]];
            break;
        case 14:
            [tfTematica setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSTematica:[tfTematica text]];
            break;
        case 15:
            [tfBIC setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSBIC:[tfBIC text]];
            break;
        case 17:
            [tfPersonaje setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSPersonaje:[tfPersonaje text]];
            break;
        case 19:
            [tfAmbito setText:[[(UITableViewCell *)[tableView cellForRowAtIndexPath:indexPath] detailTextLabel] text]];
            [self setSAmbito:[tfAmbito text]];
            break;
    }
    [pcBuscarMatchCode dismissPopoverAnimated:YES];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    switch ([tableView tag]) {
        case 0:
            return 2;
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
                case 1:
                    return @"Búsqueda avanzada:";
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
                    return 9;
                    break;
                case 1:
                    return 11;
                    break;
            }
            break;
        case 1:
            return [aItems count];
            break;
    }
    return 0;
}

- (UITextField *)doFindCampoTexto:(UIView *)tvccvContenedor
{
    for (id tfCampoTexto in [tvccvContenedor subviews]) {
        if ([tfCampoTexto isKindOfClass:[UITextField class]]) {
            return tfCampoTexto;
        }
    }
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    switch ([tableView tag]) {
        case 0:
        {
            UITableViewCell *tvcBusquedaArticulos = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
            if (tvcBusquedaArticulos == nil) {
                tvcBusquedaArticulos = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
            }
            switch ([indexPath section]) {
                case 0:
                    switch ([indexPath row]) {
                        case 0:
                            tfCodigoArticulo = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 1:
                            tfTituloDefinitivo = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 2:
                            tfAutor = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 3:
                            tfSello = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 4:
                            tfColeccion = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 8:
                            tfCliente = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                    }
                    break;
                case 1:
                    switch ([indexPath row]) {
                        case 0:
                            tfCodigoEAN = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 2:
                            tfManuscrito = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 4:
                            tfCategoriaEditorial = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 5:
                            tfTematica = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 6:
                            tfBIC = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 8:
                            tfPersonaje = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                        case 10:
                            tfAmbito = [self doFindCampoTexto:[[tvcBusquedaArticulos subviews] lastObject]];
                            break;
                    }
                    break;
            }
            if ([indexPath section] == 0 && [indexPath row] == 6 && scFechas == nil) {
                [self setScFechas:[[[[tvcBusquedaArticulos subviews] lastObject] subviews] lastObject]];
                UILongPressGestureRecognizer *lpgrFechas = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doReiniciarFecha:)];
                [scFechas addGestureRecognizer:lpgrFechas];
            }
            if ([indexPath section] == 0 && [indexPath row] == 7 && scEstados == nil) {
                [self setScEstados:[[[[tvcBusquedaArticulos subviews] lastObject] subviews] lastObject]];
                UILongPressGestureRecognizer *lpgrEstados = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doReiniciarEstado:)];
                [scEstados addGestureRecognizer:lpgrEstados];
            }
            if ([indexPath section] == 1 && [indexPath row] == 1 && scTapas == nil) {
                [self setScTapas:[[[[tvcBusquedaArticulos subviews] lastObject] subviews] lastObject]];
                UILongPressGestureRecognizer *lpgrTapas = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doReiniciarTipoTapa:)];
                [scTapas addGestureRecognizer:lpgrTapas];
            }
            if ([indexPath section] == 1 && [indexPath row] == 3 && scDivisionEditorial == nil) {
                [self setScDivisionEditorial:[[[[tvcBusquedaArticulos subviews] lastObject] subviews] lastObject]];
                UILongPressGestureRecognizer *lpgrDivisionEditorial = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doReiniciarDivisionEditorial:)];
                [scDivisionEditorial addGestureRecognizer:lpgrDivisionEditorial];
            }
            if ([indexPath section] == 1 && [indexPath row] == 7 && scTargetEdad == nil) {
                [self setScTargetEdad:[[[[tvcBusquedaArticulos subviews] lastObject] subviews] lastObject]];
                UILongPressGestureRecognizer *lpgrTargetEdad = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doReiniciarTargetEdad:)];
                [scTargetEdad addGestureRecognizer:lpgrTargetEdad];
            }
            if ([indexPath section] == 1 && [indexPath row] == 9 && scMaterial == nil) {
                [self setScMaterial:[[[[tvcBusquedaArticulos subviews] lastObject] subviews] lastObject]];
                UILongPressGestureRecognizer *lpgrMaterial = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doReiniciarMaterial:)];
                [scMaterial addGestureRecognizer:lpgrMaterial];
            }
            if ([[[[tvcBusquedaArticulos subviews] lastObject] subviews] count]>1) {
                [[[[[tvcBusquedaArticulos subviews] lastObject] subviews] objectAtIndex:1] setDelegate:self];
            }
            return tvcBusquedaArticulos;
            break;
        }
        case 1:
        {
            UITableViewCell *tvcBuscarMatchCode = [tableView dequeueReusableCellWithIdentifier:@"ciBuscarMatchCode"];
            if (tvcBuscarMatchCode == nil) {
                if (iBuscarMatchCodeTag == 0 || iBuscarMatchCodeTag == 1) {
                    tvcBuscarMatchCode = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"ciBuscarMatchCode"];
                }else {
                    tvcBuscarMatchCode = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"ciBuscarMatchCode"];
                }
            }
            switch (iBuscarMatchCodeTag) {
                case 0:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"MATNR"]]];
                    break;
                case 1:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZZTITULO"]]];
                    break;
                case 2:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"NOMAUT"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"CODAUT"]]];
                    break;
                case 3:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZDESCR"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZCODSELLO"]]];
                    break;
                case 4:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZDESCR"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZCODCOLEC"]]];
                    break;
                case 8:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"NAME1"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"KUNNR"]]];
                    break;
                case 11:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZZCGMAN"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZZCGMAN"]]];
                    break;
                case 13:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"DESCR"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"CATEGORIA"]]];
                    break;
                case 14:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZDESCR"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZCODTEM"]]];
                    break;
                case 15:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"MATERIA"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"CODBIC"]]];
                    break;
                case 17:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZDESNAJE"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"ZNAJE"]]];
                    break;
                case 19:
                    [tvcBuscarMatchCode.textLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"AMBITTXT"]]];
                    [tvcBuscarMatchCode.detailTextLabel setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:[indexPath row]] objectForKey:@"AMBITO"]]];
                    break;
            }
            [tvcBuscarMatchCode setAccessoryType:UITableViewCellAccessoryDisclosureIndicator];
            return tvcBuscarMatchCode;
            break;
        }
    }
    return nil;
}

#pragma mark - Buscar

- (IBAction)doBuscar:(id)sender
{
    if (![[scFechas titleForSegmentAtIndex:0] isEqualToString:@"Establecer fecha inicial"] && ![[scFechas titleForSegmentAtIndex:1] isEqualToString:@"Establecer fecha final"]) {
        NSDateFormatter *dfFormato = [[NSDateFormatter alloc] init];
        [dfFormato setDateFormat:@"dd/MM/yyyy"];
        NSDate *dInicial = [dfFormato dateFromString:[scFechas titleForSegmentAtIndex:0]];
        NSDate *dFinal = [dfFormato dateFromString:[scFechas titleForSegmentAtIndex:1]];
        switch ([dFinal compare:dInicial]) {
            case NSOrderedAscending:
                [[[UIAlertView alloc] initWithTitle:@"Advertencia" message:@"La fecha inicial no puede ser posterior a la fecha final al establecer un rango entre fechas." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil] show];
                break;
            case NSOrderedSame:
                [[[UIAlertView alloc] initWithTitle:@"Información" message:@"Las fechas son coincidentes, así que se muestran las coincidencias para una fecha en particular." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil] show];
                [self performSegueWithIdentifier:@"ListadoArtículos" sender:self];
                break;
            case NSOrderedDescending:
                [self performSegueWithIdentifier:@"ListadoArtículos" sender:self];
                break;
        }
    }else {
        [self performSegueWithIdentifier:@"ListadoArtículos" sender:self];
    }
}

- (NSPredicate *)doMontarPredicadoBusqueda
{
    NSMutableArray *maPredicados = [[NSMutableArray alloc] init];
    if (sCodigoArticulo != nil && ![[sCodigoArticulo stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"MATNR contains[cd] %@", sCodigoArticulo]];
    }
    if (sTituloDefinitivo != nil && ![[sTituloDefinitivo stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"ZZTITULO contains[cd] %@", sTituloDefinitivo]];
    }
    if (sAutor != nil && ![[sAutor stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"ZZCODAUTC contains[cd] %@", sAutor]];
    }
    if (sSello != nil && ![[sSello stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"ZZSELLO contains[cd] %@", sSello]];
    }
    if (sColeccion != nil && ![[sColeccion stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"ZZCOLECCION contains[cd] %@", sColeccion]];
    }
    //novedad zznovedad
    //fechapublicacion zzfechav
    //estado estado_rhm
    if (sCliente != nil && ![[sCliente stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"KUNNR contains[cd] %@", sCliente]];
    }
    if (sCodigoEAN != nil && ![[sCodigoEAN stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"EAN11 contains[cd] %@", sCodigoEAN]];
    }
    //tipotapa zztipotapa
    if (sManuscrito != nil && ![[sManuscrito stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"ZZCGMAN contains[cd] %@", sManuscrito]];
    }
    //divisioneditorial zzdadve
    if (sCategoriaEditorial != nil && ![[sCategoriaEditorial stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"ZZDACED contains[cd] %@", sCategoriaEditorial]];
    }
    if (sTematica != nil && ![[sTematica stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"ZZCODTEM contains[cd] %@", sTematica]];
    }
    if (sBIC != nil && ![[sBIC stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"CODBIC contains[cd] %@", sBIC]];
    }
    //targetedad zzdatge
    if (sPersonaje != nil && ![[sPersonaje stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"ZZNAJE contains[cd] %@", sPersonaje]];
    }
    //tipomaterial mtart
    if (sAmbito != nil && ![[sAmbito stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
    {
        [maPredicados addObject:[NSPredicate predicateWithFormat:@"AMBITO contains[cd] %@", sAmbito]];
    }
    NSPredicate *pPredicado = [NSCompoundPredicate andPredicateWithSubpredicates:maPredicados];
    NSLog(@"%@", pPredicado);
    return pPredicado;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"ListadoArtículos"]) {
        ListadoArticulosViewController *lavcListadoArticulos = [segue destinationViewController];
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getArticulos] filteredArrayUsingPredicate:[self doMontarPredicadoBusqueda]]];
        NSLog(@"%@", [[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getArticulos] objectAtIndex:69] description]);
        NSLog(@"%d", [aAuxiliar count]);
        NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZZTITULO" ascending:YES];
        [lavcListadoArticulos setAItems:[aAuxiliar sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
    }
}

#pragma mark - Fecha de publicación

- (IBAction)doEstablecerFechaPublicacion:(id)sender
{
    UIDatePicker *dpFechas = [[UIDatePicker alloc] init];
    [dpFechas setDatePickerMode:UIDatePickerModeDate];
    [dpFechas addTarget:self action:@selector(doSeleccionarFecha:) forControlEvents:UIControlEventValueChanged];
    [dpFechas setTag:[sender selectedSegmentIndex]];
    UIViewController *vcFechas = [[UIViewController alloc] init];
    UIView *vFechas = [[UIView alloc] init];
    [vFechas addSubview:dpFechas];
    [vcFechas setView:vFechas];
    [vcFechas setContentSizeForViewInPopover:CGSizeMake(320, 220)];
    [self setPcFechas:[[UIPopoverController alloc] initWithContentViewController:vcFechas]];
    if (scFechas.superview.window != nil) {
        switch ([sender selectedSegmentIndex]) {
            case 0:
                [pcFechas presentPopoverFromRect:CGRectMake(scFechas.frame.origin.x, scFechas.frame.origin.y, scFechas.frame.size.width/2, scFechas.frame.size.height) inView:scFechas.superview permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
                break;
            case 1:
                [pcFechas presentPopoverFromRect:CGRectMake(scFechas.frame.origin.x, scFechas.frame.origin.y, (scFechas.frame.size.width/2)*3, scFechas.frame.size.height) inView:scFechas.superview permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
                break;
        }
        NSDateFormatter *dfFecha = [[NSDateFormatter alloc] init];
        [dfFecha setLocale:[[NSLocale alloc] initWithLocaleIdentifier:@"ES_es"]];
        [dfFecha setDateStyle:NSDateFormatterMediumStyle];
        [scFechas setTitle:[NSString stringWithFormat:@"%@", [dfFecha stringFromDate:[dpFechas date]]] forSegmentAtIndex:[sender selectedSegmentIndex]];
        [self becomeFirstResponder];
        [self setMcReiniciarFecha:[UIMenuController sharedMenuController]];
        UIMenuItem *miReiniciarFecha = [[UIMenuItem alloc] initWithTitle:@"Mantenga presionado para descartar la fecha" action:@selector(doFinalizarInfoReiniciarFecha)];
        [mcReiniciarFecha setArrowDirection:UIMenuControllerArrowDown];
        [mcReiniciarFecha setMenuItems:[NSArray arrayWithObjects:miReiniciarFecha, nil]];
        switch ([sender selectedSegmentIndex]) {
            case 0:
                [mcReiniciarFecha setTargetRect:CGRectMake(0, 0, scFechas.frame.size.width/2, scFechas.frame.size.height-scFechas.frame.origin.y) inView:scFechas];
                break;
            case 1:
                [mcReiniciarFecha setTargetRect:CGRectMake(0, 0, (scFechas.frame.size.width/2)*3, scFechas.frame.size.height-scFechas.frame.origin.y) inView:scFechas];
                break;
        }
        [mcReiniciarFecha setMenuVisible:YES animated:YES];
        [self performSelector:@selector(doFinalizarInfoReiniciarFecha) withObject:nil afterDelay:2];
    }
}

- (void)doSeleccionarFecha:(id)sender
{
    NSDateFormatter *dfFecha = [[NSDateFormatter alloc] init];
    [dfFecha setLocale:[[NSLocale alloc] initWithLocaleIdentifier:@"ES_es"]];
    [dfFecha setDateStyle:NSDateFormatterMediumStyle];
    [scFechas setTitle:[NSString stringWithFormat:@"%@", [dfFecha stringFromDate:[sender date]]] forSegmentAtIndex:[sender tag]];
    [self becomeFirstResponder];
    [self setMcReiniciarFecha:[UIMenuController sharedMenuController]];
    UIMenuItem *miReiniciarFecha = [[UIMenuItem alloc] initWithTitle:@"Mantenga presionado para descartar la fecha" action:@selector(doFinalizarInfoReiniciarFecha)];
    [mcReiniciarFecha setArrowDirection:UIMenuControllerArrowDown];
    [mcReiniciarFecha setMenuItems:[NSArray arrayWithObjects:miReiniciarFecha, nil]];
    switch ([sender tag]) {
        case 0:
            [mcReiniciarFecha setTargetRect:CGRectMake(0, 0, scFechas.frame.size.width/2, scFechas.frame.size.height-scFechas.frame.origin.y) inView:scFechas];
            break;
        case 1:
            [mcReiniciarFecha setTargetRect:CGRectMake(0, 0, (scFechas.frame.size.width/2)*3, scFechas.frame.size.height-scFechas.frame.origin.y) inView:scFechas];
            break;
    }
    [mcReiniciarFecha setMenuVisible:YES animated:YES];
    [self performSelector:@selector(doFinalizarInfoReiniciarFecha) withObject:nil afterDelay:2];
}

- (BOOL)canBecomeFirstResponder {
    return YES;
}

-(BOOL)canPerformAction:(SEL)action withSender:(id)sender
{
    if ([UIMenuController sharedMenuController] && ([pcBuscarMatchCode isPopoverVisible] || [pcDivisionEditorial isPopoverVisible] || [pcEstados isPopoverVisible] || [pcFechas isPopoverVisible] || [pcMaterial isPopoverVisible] || [pcTapas isPopoverVisible] || [pcTargetEdad isPopoverVisible])) {
        return [super canPerformAction:action withSender:sender];
    }else {
        return NO;
    }
}

- (void)doFinalizarInfoReiniciarFecha
{
    if ([mcReiniciarFecha isMenuVisible]) {
        [mcReiniciarFecha setMenuVisible:NO animated:YES];
    }
}

- (void)doReiniciarFecha:(UILongPressGestureRecognizer *)gesture
{
    [pcFechas dismissPopoverAnimated:YES];
    switch ([[[[[pcFechas contentViewController]view]subviews]lastObject] tag]) {
        case 0:
            [scFechas setTitle:@"Establecer fecha inicial" forSegmentAtIndex:[[[[[pcFechas contentViewController]view]subviews]lastObject] tag]];
            break;
        case 1:
            [scFechas setTitle:@"Establecer fecha final" forSegmentAtIndex:[[[[[pcFechas contentViewController]view]subviews]lastObject] tag]];
            break;
    }
}

#pragma mark - Estado

- (IBAction)doEstablecerEstado:(id)sender
{
    if ([sender selectedSegmentIndex] == 0) {
        UIPickerView *pvEstados = [[UIPickerView alloc] init];
        [pvEstados setDelegate:self];
        [pvEstados setDataSource:self];
        [pvEstados setTag:0];
        [pvEstados setShowsSelectionIndicator:YES];
        UIViewController *vcEstados = [[UIViewController alloc] init];
        [vcEstados setView:pvEstados];
        [vcEstados setContentSizeForViewInPopover:CGSizeMake(600, 162)];
        [self setPcEstados:[[UIPopoverController alloc] initWithContentViewController:vcEstados]];
        if (scEstados.superview.window != nil) {
            [pcEstados presentPopoverFromRect:CGRectMake(scEstados.frame.origin.x, scEstados.frame.origin.y, scEstados.frame.size.width/2, scEstados.frame.origin.y) inView:scEstados.superview permittedArrowDirections:UIPopoverArrowDirectionDown animated:YES];
            [self pickerView:pvEstados didSelectRow:0 inComponent:0];
        }
    }
}

- (void)doFinalizarInfoReiniciarEstado
{
    if ([mcReiniciarEstado isMenuVisible]) {
        [mcReiniciarEstado setMenuVisible:NO animated:YES];
    }
}

- (void)doReiniciarEstado:(UILongPressGestureRecognizer *)gesture
{
    [pcEstados dismissPopoverAnimated:YES];
    [scEstados setTitle:@"Establecer estado" forSegmentAtIndex:0];
    [scEstados setTitle:@"" forSegmentAtIndex:1];
}

#pragma mark - Tipo de tapa

- (IBAction)doEstablecerTipoTapa:(id)sender
{
    if ([sender selectedSegmentIndex] == 0) {
        UIPickerView *pvTapas = [[UIPickerView alloc] init];
        [pvTapas setDelegate:self];
        [pvTapas setDataSource:self];
        [pvTapas setTag:1];
        [pvTapas setShowsSelectionIndicator:YES];
        UIViewController *vcTapas = [[UIViewController alloc] init];
        [vcTapas setView:pvTapas];
        [vcTapas setContentSizeForViewInPopover:CGSizeMake(200, 162)];
        [self setPcTapas:[[UIPopoverController alloc] initWithContentViewController:vcTapas]];
        if (scTapas.superview.window != nil) {
            [pcTapas presentPopoverFromRect:CGRectMake(scTapas.frame.origin.x, scTapas.frame.origin.y, scTapas.frame.size.width/2, scTapas.frame.origin.y) inView:scTapas.superview permittedArrowDirections:UIPopoverArrowDirectionDown animated:YES];
            [self pickerView:pvTapas didSelectRow:0 inComponent:0];
        }
    }
}

- (void)doFinalizarInfoReiniciarTipoTapa
{
    if ([mcReiniciarTapa isMenuVisible]) {
        [mcReiniciarTapa setMenuVisible:NO animated:YES];
    }
}

- (void)doReiniciarTipoTapa:(UILongPressGestureRecognizer *)gesture
{
    [pcTapas dismissPopoverAnimated:YES];
    [scTapas setTitle:@"Establecer tipo de tapa" forSegmentAtIndex:0];
    [scTapas setTitle:@"" forSegmentAtIndex:1];
}

#pragma mark - División editorial

- (IBAction)doEstablecerDivisionEditorial:(id)sender
{
    if ([sender selectedSegmentIndex] == 0) {
        UIPickerView *pvDivisionEditorial = [[UIPickerView alloc] init];
        [pvDivisionEditorial setDelegate:self];
        [pvDivisionEditorial setDataSource:self];
        [pvDivisionEditorial setTag:2];
        [pvDivisionEditorial setShowsSelectionIndicator:YES];
        UIViewController *vcDivisionEditorial = [[UIViewController alloc] init];
        [vcDivisionEditorial setView:pvDivisionEditorial];
        [vcDivisionEditorial setContentSizeForViewInPopover:CGSizeMake(200, 162)];
        [self setPcDivisionEditorial:[[UIPopoverController alloc] initWithContentViewController:vcDivisionEditorial]];
        if (scDivisionEditorial.superview.window != nil) {
            [pcDivisionEditorial presentPopoverFromRect:CGRectMake(scDivisionEditorial.frame.origin.x, scDivisionEditorial.frame.origin.y, scDivisionEditorial.frame.size.width/2, scDivisionEditorial.frame.origin.y) inView:scDivisionEditorial.superview permittedArrowDirections:UIPopoverArrowDirectionDown animated:YES];
            [self pickerView:pvDivisionEditorial didSelectRow:0 inComponent:0];
        }
    }
}

- (void)doFinalizarInfoReiniciarDivisionEditorial
{
    if ([mcReiniciarDivisionEditorial isMenuVisible]) {
        [mcReiniciarDivisionEditorial setMenuVisible:NO animated:YES];
    }
}

- (void)doReiniciarDivisionEditorial:(UILongPressGestureRecognizer *)gesture
{
    [pcDivisionEditorial dismissPopoverAnimated:YES];
    [scDivisionEditorial setTitle:@"Establecer división editorial" forSegmentAtIndex:0];
    [scDivisionEditorial setTitle:@"" forSegmentAtIndex:1];
}

#pragma mark - Target de edad

- (IBAction)doEstablecerTargetEdad:(id)sender
{
    if ([sender selectedSegmentIndex] == 0) {
        UIPickerView *pvTargetEdad = [[UIPickerView alloc] init];
        [pvTargetEdad setDelegate:self];
        [pvTargetEdad setDataSource:self];
        [pvTargetEdad setTag:3];
        [pvTargetEdad setShowsSelectionIndicator:YES];
        UIViewController *vcTargetEdad = [[UIViewController alloc] init];
        [vcTargetEdad setView:pvTargetEdad];
        [vcTargetEdad setContentSizeForViewInPopover:CGSizeMake(250, 162)];
        [self setPcTargetEdad:[[UIPopoverController alloc] initWithContentViewController:vcTargetEdad]];
        if (scTargetEdad.superview.window != nil) {
            [pcTargetEdad presentPopoverFromRect:CGRectMake(scTargetEdad.frame.origin.x, scTargetEdad.frame.origin.y, scTargetEdad.frame.size.width/2, scTargetEdad.frame.origin.y) inView:scTargetEdad.superview permittedArrowDirections:UIPopoverArrowDirectionDown animated:YES];
            [self pickerView:pvTargetEdad didSelectRow:0 inComponent:0];
        }
    }
}

- (void)doFinalizarInfoReiniciarTargetEdad
{
    if ([mcReiniciarTargetEdad isMenuVisible]) {
        [mcReiniciarTargetEdad setMenuVisible:NO animated:YES];
    }
}

- (void)doReiniciarTargetEdad:(UILongPressGestureRecognizer *)gesture
{
    [pcTargetEdad dismissPopoverAnimated:YES];
    [scTargetEdad setTitle:@"Establecer target de edad" forSegmentAtIndex:0];
    [scTargetEdad setTitle:@"" forSegmentAtIndex:1];
}

#pragma mark - Tipo de material

- (IBAction)doEstablecerTipoMaterial:(id)sender
{
    if ([sender selectedSegmentIndex] == 0) {
        UIPickerView *pvMaterial = [[UIPickerView alloc] init];
        [pvMaterial setDelegate:self];
        [pvMaterial setDataSource:self];
        [pvMaterial setTag:4];
        [pvMaterial setShowsSelectionIndicator:YES];
        UIViewController *vcMaterial = [[UIViewController alloc] init];
        [vcMaterial setView:pvMaterial];
        [vcMaterial setContentSizeForViewInPopover:CGSizeMake(250, 162)];
        [self setPcMaterial:[[UIPopoverController alloc] initWithContentViewController:vcMaterial]];
        if (scMaterial.superview.window != nil) {
            [pcMaterial presentPopoverFromRect:CGRectMake(scMaterial.frame.origin.x, scMaterial.frame.origin.y, scMaterial.frame.size.width/2, scMaterial.frame.origin.y) inView:scMaterial.superview permittedArrowDirections:UIPopoverArrowDirectionDown animated:YES];
            [self pickerView:pvMaterial didSelectRow:0 inComponent:0];
        }
    }
}

- (void)doFinalizarInfoReiniciarMaterial
{
    if ([mcReiniciarMaterial isMenuVisible]) {
        [mcReiniciarMaterial setMenuVisible:NO animated:YES];
    }
}

- (void)doReiniciarMaterial:(UILongPressGestureRecognizer *)gesture
{
    [pcMaterial dismissPopoverAnimated:YES];
    [scMaterial setTitle:@"Establecer tipo de material" forSegmentAtIndex:0];
    [scMaterial setTitle:@"" forSegmentAtIndex:1];
}

#pragma mark - Buscar match code

- (IBAction)doBuscarMatchCode:(id)sender
{
    [self performSelectorInBackground:@selector(doPonerCargando:) withObject:sender];
    [(AppDelegate *)[[UIApplication sharedApplication] delegate] dismissKeyboard];
    UIView *vBuscarMatchCode = [[UIView alloc] init];
    UISearchBar *sbBuscarMatchCode = [[UISearchBar alloc] init];
    [sbBuscarMatchCode setFrame:CGRectMake(0, 0, 500, 50)];
    [sbBuscarMatchCode setDelegate:self];
    [self setIBuscarMatchCodeTag:[sender tag]];
    [self doSetItems:iBuscarMatchCodeTag];
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
        if ([[[[tvBusquedaArticulos subviews] objectAtIndex:i] subviews] count]>1 && [[[[[[tvBusquedaArticulos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] count]>2 && [[[[[[[tvBusquedaArticulos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] isKindOfClass:[UIButton class]] && [[[[[[[tvBusquedaArticulos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] tag] == [sender tag]) {
            bEncontrado = YES;
        }
    }
    UIButton *buDisclosure = [[[[[[tvBusquedaArticulos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2];
    [sbBuscarMatchCode setText:[[NSString stringWithFormat:@"%@", [(UITextField *)[[[[[[tvBusquedaArticulos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:1] text]]stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]]];
    if (![[[sbBuscarMatchCode text] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItems filteredArrayUsingPredicate:[self performSelector:@selector(doMontarPredicadoFiltrado:) withObject:[sbBuscarMatchCode text]]]];
        [self setAItems:aAuxiliar];
        [tvBuscarMatchCode reloadData];
    }
    [sbBuscarMatchCode setPlaceholder:[[[[[[[[tvBusquedaArticulos subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:1] placeholder] stringByReplacingOccurrencesOfString:@"Establecer " withString:@"Filtrar "]];
    [self setPcBuscarMatchCode:[[UIPopoverController alloc] initWithContentViewController:vcBuscarMatchCode]];
    if (buDisclosure.superview.window != nil) {
        [pcBuscarMatchCode presentPopoverFromRect:CGRectMake(buDisclosure.frame.origin.x, buDisclosure.frame.origin.y, buDisclosure.frame.origin.x, buDisclosure.frame.size.height) inView:buDisclosure.superview permittedArrowDirections:UIPopoverArrowDirectionRight animated:YES];
    }
    [aivCargando removeFromSuperview];
}

- (void)doPonerCargando:(id)sender
{
    aivCargando = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    [aivCargando setFrame:CGRectMake([sender frame].origin.x+50, [sender frame].origin.y+6, aivCargando.frame.size.width, aivCargando.frame.size.height)];
    [[sender superview] addSubview:aivCargando];
    [aivCargando startAnimating];
}

- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText
{
    [self doSetItems:iBuscarMatchCodeTag];
    if (![[searchText stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItems filteredArrayUsingPredicate:[self performSelector:@selector(doMontarPredicadoFiltrado:) withObject:searchText]]];
        [self setAItems:aAuxiliar];
    }
    [tvBuscarMatchCode reloadData];
}

- (NSPredicate *)doMontarPredicadoFiltrado:(NSString *)searchText
{
    NSPredicate *pFiltrado = [NSPredicate alloc];
    switch (iBuscarMatchCodeTag) {
        case 0:
            pFiltrado = [NSPredicate predicateWithFormat:@"MATNR contains[cd] %@", searchText];
            break;
        case 1:
            pFiltrado = [NSPredicate predicateWithFormat:@"ZZTITULO contains[cd] %@", searchText];
            break;
        case 2:
            pFiltrado = [NSPredicate predicateWithFormat:@"NOMAUT contains[cd] %@ or CODAUT contains[cd] %@", searchText, searchText];
            break;
        case 3:
            pFiltrado = [NSPredicate predicateWithFormat:@"ZDESCR contains[cd] %@ or ZCODSELLO contains[cd] %@", searchText, searchText];
            break;
        case 4:
            pFiltrado = [NSPredicate predicateWithFormat:@"ZDESCR contains[cd] %@ or ZCODCOLEC contains[cd] %@", searchText, searchText];
            break;
        case 8:
            pFiltrado = [NSPredicate predicateWithFormat:@"NAME1 contains[cd] %@ or KUNNR contains[cd] %@", searchText, searchText];
            break;
        case 11:
            pFiltrado = [NSPredicate predicateWithFormat:@"ZZCGMAN contains[cd] %@ or MATNR contains[cd] %@", searchText, searchText];
            break;
        case 13:
            pFiltrado = [NSPredicate predicateWithFormat:@"DESCR contains[cd] %@ or CATEGORIA contains[cd] %@", searchText, searchText];
            break;
        case 14:
            pFiltrado = [NSPredicate predicateWithFormat:@"ZDESCR contains[cd] %@ or ZCODTEM contains[cd] %@", searchText, searchText];
            break;
        case 15:
            pFiltrado = [NSPredicate predicateWithFormat:@"MATERIA contains[cd] %@ or CODBIC contains[cd] %@", searchText, searchText];
            break;
        case 17:
            pFiltrado = [NSPredicate predicateWithFormat:@"ZDESNAJE contains[cd] %@ or ZNAJE contains[cd] %@", searchText, searchText];
            break;
        case 19:
            pFiltrado = [NSPredicate predicateWithFormat:@"AMBITTXT contains[cd] %@ or AMBITO contains[cd] %@", searchText, searchText];
            break;
    }
    return pFiltrado;
}

- (void)doSetItems:(NSInteger)tag
{
    switch (tag) {
        case 0:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"MATNR" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getCodigos] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 1:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZZTITULO" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTitulos] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 2:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"NOMAUT" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getAutores] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 3:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZDESCR" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getSellos] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 4:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZDESCR" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getColecciones]sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 8:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"NAME1" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getClientes] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 11:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZZCGMAN" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getManuscritos] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 13:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"DESCR" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getCatsMov] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 14:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"DESCR" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTematicas] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 15:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"MATERIA" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getBICs] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 17:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZDESNAJE" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getPersonajes]sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
        case 19:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"AMBITTXT" ascending:YES];
            [self setAItems:[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getAmbitos] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]]];
            break;
        }
    }
}

#pragma mark - Buscar EAN

- (IBAction)doBuscarEAN:(id)sender
{
    ZBarReaderViewController *rvcCamaraLectorEAN = [ZBarReaderViewController new];
    rvcCamaraLectorEAN.readerDelegate = self;
    rvcCamaraLectorEAN.supportedOrientationsMask = ZBarOrientationMaskAll;
    ZBarImageScanner *bisCamaraLectorEAN = rvcCamaraLectorEAN.scanner;
    [bisCamaraLectorEAN setSymbology:0 config:ZBAR_CFG_ENABLE to:0];
    [bisCamaraLectorEAN setSymbology: ZBAR_EAN13 config: ZBAR_CFG_ENABLE to: 1];
    [self presentModalViewController: rvcCamaraLectorEAN animated: YES];
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    id<NSFastEnumeration> results = [info objectForKey: ZBarReaderControllerResults];
    ZBarSymbol *symbol = nil;
    for(symbol in results){
        [tfCodigoEAN setText:symbol.data];
        [self setSCodigoEAN:[tfCodigoEAN text]];
    }
    [picker dismissModalViewControllerAnimated: YES];
}

#pragma mark - Picker view

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    switch ([pickerView tag]) {
        case 0:
            return 1;
            break;
        case 1:
            return 1;
            break;
        case 2:
            return 1;
            break;
        case 3:
            return 1;
            break;
        case 4:
            return 1;
            break;
    }
    return 0;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    switch ([pickerView tag]) {
        case 0:
            return [[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getEstados] count];
            break;
        case 1:
            return [[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTiposTapa] count];
            break;
        case 2:
            return [[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getDivisionesEditorial] count];
            break;
        case 3:
            return [[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getEdades] count];
            break;
        case 4:
            return [[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTiposMat] count];
            break;
    }
    return 0;
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    switch ([pickerView tag]) {
        case 0:
        {
            if ([[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getEstados] count] != 0) {
                NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"DESCR" ascending:YES];
                return [NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getEstados] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"DESCR"]];
            }
            break;
        }
        case 1:
        {
            if ([[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTiposTapa] count] != 0) {
                NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"DESCR" ascending:YES];
                return [NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTiposTapa] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"DESCR"]];
            }
            break;
        }
        case 2:
        {
            if ([[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getDivisionesEditorial] count] != 0) {
                NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZZDADVET" ascending:YES];
                return [NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getDivisionesEditorial] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"ZZDADVET"]];
            }
            break;
        }
        case 3:
        {
            if ([[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getEdades] count] != 0) {
                NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZZDATGET" ascending:YES];
                return [NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getEdades] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"ZZDATGET"]];
            }
            break;
        }
        case 4:
        {
            if ([[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTiposMat] count] != 0) {
                NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"MTBEZ" ascending:YES];
                return [NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTiposMat] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"MTBEZ"]];
            }
            break;
        }
    }
    return nil;
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    switch ([pickerView tag]) {
        case 0:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ESTADO_RHM" ascending:YES];
            [scEstados setTitle:[NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getEstados] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"ESTADO_RHM"]] forSegmentAtIndex:1];
            [scEstados setTitle:@"Editar estado" forSegmentAtIndex:0];
            fixLineBreakMode([[scEstados subviews] objectAtIndex:0]);
            [self becomeFirstResponder];
            [self setMcReiniciarEstado:[UIMenuController sharedMenuController]];
            UIMenuItem *miReiniciarEstado = [[UIMenuItem alloc] initWithTitle:@"Mantenga presionado para descartar el estado" action:@selector(doFinalizarInfoReiniciarEstado)];
            [mcReiniciarEstado setArrowDirection:UIMenuControllerArrowUp];
            [mcReiniciarEstado setMenuItems:[NSArray arrayWithObjects:miReiniciarEstado, nil]];
            [mcReiniciarEstado setTargetRect:CGRectMake(0, 0, scEstados.frame.size.width/2, scEstados.frame.size.height-scEstados.frame.origin.y) inView:scEstados];
            [mcReiniciarEstado setMenuVisible:YES animated:YES];
            [self performSelector:@selector(doFinalizarInfoReiniciarEstado) withObject:nil afterDelay:2];
            break;
        }
        case 1:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZZTIPOTAPA" ascending:YES];
            [scTapas setTitle:[NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTiposTapa] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"ZZTIPOTAPA"]] forSegmentAtIndex:1];
            [scTapas setTitle:@"Editar tipo de tapa" forSegmentAtIndex:0];
            fixLineBreakMode([[scTapas subviews] objectAtIndex:0]);
            [self becomeFirstResponder];
            [self setMcReiniciarTapa:[UIMenuController sharedMenuController]];
            UIMenuItem *miReiniciarTapa = [[UIMenuItem alloc] initWithTitle:@"Mantenga presionado para descartar el tipo de tapa" action:@selector(doFinalizarInfoReiniciarTipoTapa)];
            [mcReiniciarTapa setArrowDirection:UIMenuControllerArrowUp];
            [mcReiniciarTapa setMenuItems:[NSArray arrayWithObjects:miReiniciarTapa, nil]];
            [mcReiniciarTapa setTargetRect:CGRectMake(0, 0, scTapas.frame.size.width/2, scTapas.frame.size.height-scTapas.frame.origin.y) inView:scTapas];
            [mcReiniciarTapa setMenuVisible:YES animated:YES];
            [self performSelector:@selector(doFinalizarInfoReiniciarTipoTapa) withObject:nil afterDelay:2];
            break;
        }
        case 2:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZZDADVE" ascending:YES];
            [scDivisionEditorial setTitle:[NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getDivisionesEditorial] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"ZZDADVE"]] forSegmentAtIndex:1];
            [scDivisionEditorial setTitle:@"Editar división editorial" forSegmentAtIndex:0];
            fixLineBreakMode([[scDivisionEditorial subviews] objectAtIndex:0]);
            [self becomeFirstResponder];
            [self setMcReiniciarDivisionEditorial:[UIMenuController sharedMenuController]];
            UIMenuItem *miReiniciarDivisionEditorial = [[UIMenuItem alloc] initWithTitle:@"Mantenga presionado para descartar la división editorial" action:@selector(doFinalizarInfoReiniciarDivisionEditorial)];
            [mcReiniciarDivisionEditorial setArrowDirection:UIMenuControllerArrowUp];
            [mcReiniciarDivisionEditorial setMenuItems:[NSArray arrayWithObjects:miReiniciarDivisionEditorial, nil]];
            [mcReiniciarDivisionEditorial setTargetRect:CGRectMake(0, 0, scDivisionEditorial.frame.size.width/2, scDivisionEditorial.frame.size.height-scDivisionEditorial.frame.origin.y) inView:scDivisionEditorial];
            [mcReiniciarDivisionEditorial setMenuVisible:YES animated:YES];
            [self performSelector:@selector(doFinalizarInfoReiniciarDivisionEditorial) withObject:nil afterDelay:2];
            break;
        }
        case 3:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"ZZDATGE" ascending:YES];
            [scTargetEdad setTitle:[NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getEdades] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"ZZDATGE"]] forSegmentAtIndex:1];
            [scTargetEdad setTitle:@"Editar target de edad" forSegmentAtIndex:0];
            fixLineBreakMode([[scTargetEdad subviews] objectAtIndex:0]);
            [self becomeFirstResponder];
            [self setMcReiniciarTargetEdad:[UIMenuController sharedMenuController]];
            UIMenuItem *miReiniciarTargetEdad = [[UIMenuItem alloc] initWithTitle:@"Mantenga presionado para descartar el target de edad" action:@selector(doFinalizarInfoReiniciarTargetEdad)];
            [mcReiniciarTargetEdad setArrowDirection:UIMenuControllerArrowUp];
            [mcReiniciarTargetEdad setMenuItems:[NSArray arrayWithObjects:miReiniciarTargetEdad, nil]];
            [mcReiniciarTargetEdad setTargetRect:CGRectMake(0, 0, scTargetEdad.frame.size.width/2, scTargetEdad.frame.size.height-scTargetEdad.frame.origin.y) inView:scTargetEdad];
            [mcReiniciarTargetEdad setMenuVisible:YES animated:YES];
            [self performSelector:@selector(doFinalizarInfoReiniciarTargetEdad) withObject:nil afterDelay:2];
            break;
        }
        case 4:
        {
            NSSortDescriptor *sdOrdenador = [[NSSortDescriptor alloc] initWithKey:@"MTART" ascending:YES];
            [scMaterial setTitle:[NSString stringWithFormat:@"%@", [[[[[(AppDelegate *)[[UIApplication sharedApplication] delegate] dataService] getTiposMat] sortedArrayUsingDescriptors:[NSArray arrayWithObject:sdOrdenador]] objectAtIndex:row] objectForKey:@"MTART"]] forSegmentAtIndex:1];
            [scMaterial setTitle:@"Editar tipo de material" forSegmentAtIndex:0];
            fixLineBreakMode([[scMaterial subviews] objectAtIndex:0]);
            [self becomeFirstResponder];
            [self setMcReiniciarMaterial:[UIMenuController sharedMenuController]];
            UIMenuItem *miReiniciarMaterial = [[UIMenuItem alloc] initWithTitle:@"Mantenga presionado para descartar el tipo de material" action:@selector(doFinalizarInfoReiniciarMaterial)];
            [mcReiniciarMaterial setArrowDirection:UIMenuControllerArrowUp];
            [mcReiniciarMaterial setMenuItems:[NSArray arrayWithObjects:miReiniciarMaterial, nil]];
            [mcReiniciarMaterial setTargetRect:CGRectMake(0, 0, scMaterial.frame.size.width/2, scMaterial.frame.size.height-scMaterial.frame.origin.y) inView:scMaterial];
            [mcReiniciarMaterial setMenuVisible:YES animated:YES];
            [self performSelector:@selector(doFinalizarInfoReiniciarMaterial) withObject:nil afterDelay:2];
            break;
        }
    }
}

@end
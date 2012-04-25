//
//  BusquedaRevistasViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "BusquedaRevistasViewController.h"
#import "InicioViewController.h"
#import "ListadoRevistasViewController.h"
#import "AppDelegate.h"

@implementation BusquedaRevistasViewController

@synthesize masterPopoverController, tvBusquedaRevistas, scFechas, scDivisionEditorial, pcFechas, pcDivisionEditorial, mcReiniciarFecha, mcReiniciarDivisionEditorial, tvBuscarMatchCode, pcBuscarMatchCode, iBuscarMatchCodeTag, tfCampoActivo, aItems;

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
    if ([pcFechas isPopoverVisible]) {
        [pcFechas dismissPopoverAnimated:YES];
    }
    if ([pcDivisionEditorial isPopoverVisible]) {
        [pcDivisionEditorial dismissPopoverAnimated:YES];
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
    [self setTvBusquedaRevistas:nil];
    [self setTfCampoActivo:nil];
    [self setAItems:nil];
    [self setScFechas:nil];
    [self setScDivisionEditorial:nil];
    [self setPcFechas:nil];
    [self setPcDivisionEditorial:nil];
    [self setMcReiniciarFecha:nil];
    [self setMcReiniciarDivisionEditorial:nil];
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
    if ([pcFechas isPopoverVisible]) {
        [pcFechas dismissPopoverAnimated:YES];
    }
    if ([pcDivisionEditorial isPopoverVisible]) {
        [pcDivisionEditorial dismissPopoverAnimated:YES];
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
    [tvBusquedaRevistas scrollToRowAtIndexPath:[self.tvBusquedaRevistas indexPathForCell:(UITableViewCell *)[[textField superview] superview]] atScrollPosition:UITableViewScrollPositionMiddle animated:YES];
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
        CGRect textFieldRect = [self.tvBusquedaRevistas convertRect:[tfCampoActivo bounds] fromView:tfCampoActivo];
        [self.tvBusquedaRevistas scrollRectToVisible:textFieldRect animated:NO];
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
        if ([[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] count]>1 && [[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] count]>2 && [[[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] isKindOfClass:[UIButton class]] && [[[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] tag] == iBuscarMatchCodeTag) {
            bEncontrado = YES;
        }
    }
    UITextField *tfBuscarMatchCode = [[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:1];
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
                    return 4;
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
            UITableViewCell *tvcBusquedaRevistas = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
            if (tvcBusquedaRevistas == nil) {
                tvcBusquedaRevistas = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
            }
            if ([indexPath section] == 0 && [indexPath row] == 1 && scFechas == nil) {
                [self setScFechas:[[[[tvcBusquedaRevistas subviews] lastObject] subviews] lastObject]];
                UILongPressGestureRecognizer *lpgrFechas = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doReiniciarFecha:)];
                [scFechas addGestureRecognizer:lpgrFechas];
            }
            if ([indexPath section] == 0 && [indexPath row] == 2 && scDivisionEditorial == nil) {
                [self setScDivisionEditorial:[[[[tvcBusquedaRevistas subviews] lastObject] subviews] lastObject]];
                UILongPressGestureRecognizer *lpgrDivisionEditorial = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doReiniciarDivisionEditorial:)];
                [scDivisionEditorial addGestureRecognizer:lpgrDivisionEditorial];
            }
            if ([[[[tvcBusquedaRevistas subviews] lastObject] subviews] count]>1) {
                [[[[[tvcBusquedaRevistas subviews] lastObject] subviews] objectAtIndex:1] setDelegate:self];
            }
            return tvcBusquedaRevistas;
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
    if ([UIMenuController sharedMenuController] && ([pcBuscarMatchCode isPopoverVisible] || [pcDivisionEditorial isPopoverVisible] || [pcFechas isPopoverVisible])) {
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

#pragma mark - División editorial

- (IBAction)doEstablecerDivisionEditorial:(id)sender
{
    if ([sender selectedSegmentIndex] == 0) {
        UIPickerView *pvDivisionEditorial = [[UIPickerView alloc] init];
        [pvDivisionEditorial setDelegate:self];
        [pvDivisionEditorial setDataSource:self];
        [pvDivisionEditorial setTag:0];
        [pvDivisionEditorial setShowsSelectionIndicator:YES];
        UIViewController *vcDivisionEditorial = [[UIViewController alloc] init];
        [vcDivisionEditorial setView:pvDivisionEditorial];
        [vcDivisionEditorial setContentSizeForViewInPopover:CGSizeMake(200, 162)];
        [self setPcDivisionEditorial:[[UIPopoverController alloc] initWithContentViewController:vcDivisionEditorial]];
        if (scDivisionEditorial.superview.window != nil) {
            [pcDivisionEditorial presentPopoverFromRect:CGRectMake(scDivisionEditorial.frame.origin.x, scDivisionEditorial.frame.origin.y, scDivisionEditorial.frame.size.width/2, scDivisionEditorial.frame.size.height) inView:scDivisionEditorial.superview permittedArrowDirections:UIPopoverArrowDirectionUp animated:YES];
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

#pragma mark - Picker view

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    switch ([pickerView tag]) {
        case 0:
            return 1;
            break;
    }
    return 0;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    switch ([pickerView tag]) {
        case 0:
            return 17;
            break;
    }
    return 0;
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    switch ([pickerView tag]) {
        case 0:
            return [NSString stringWithFormat:@"17 div ed: %d", row];
            break;
    }
    return nil;
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    switch ([pickerView tag]) {
        case 0:
        {
            [scDivisionEditorial setTitle:[self pickerView:pickerView titleForRow:row forComponent:component] forSegmentAtIndex:1];
            [scDivisionEditorial setTitle:@"Editar división editorial" forSegmentAtIndex:0];
            [self becomeFirstResponder];
            [self setMcReiniciarDivisionEditorial:[UIMenuController sharedMenuController]];
            UIMenuItem *miReiniciarDivisionEditorial = [[UIMenuItem alloc] initWithTitle:@"Mantenga presionado para descartar la división editorial" action:@selector(doFinalizarInfoReiniciarDivisionEditorial)];
            [mcReiniciarDivisionEditorial setArrowDirection:UIMenuControllerArrowDown];
            [mcReiniciarDivisionEditorial setMenuItems:[NSArray arrayWithObjects:miReiniciarDivisionEditorial, nil]];
            [mcReiniciarDivisionEditorial setTargetRect:CGRectMake(0, 0, scDivisionEditorial.frame.size.width/2, scDivisionEditorial.frame.size.height-scDivisionEditorial.frame.origin.y) inView:scDivisionEditorial];
            [mcReiniciarDivisionEditorial setMenuVisible:YES animated:YES];
            [self performSelector:@selector(doFinalizarInfoReiniciarDivisionEditorial) withObject:nil afterDelay:2];
            break;
        }
    }
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
        if ([[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] count]>1 && [[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] count]>2 && [[[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] isKindOfClass:[UIButton class]] && [[[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2] tag] == [sender tag]) {
            bEncontrado = YES;
        }
    }
    UIButton *buDisclosure = [[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:2];
    [sbBuscarMatchCode setText:[[NSString stringWithFormat:@"%@", [(UITextField *)[[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:1] text]]stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]]];
    if (![[[sbBuscarMatchCode text] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""]) {
        NSArray *aAuxiliar = [[NSArray alloc] initWithArray:[aItems filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF contains[cd] %@", [sbBuscarMatchCode text]]]];
        [self setAItems:aAuxiliar];
        [tvBuscarMatchCode reloadData];
    }
    [sbBuscarMatchCode setPlaceholder:[[[[[[[[tvBusquedaRevistas subviews] objectAtIndex:i] subviews] objectAtIndex:1] subviews] objectAtIndex:1] placeholder] stringByReplacingOccurrencesOfString:@"Establecer " withString:@"Filtrar "]];
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
                [self performSegueWithIdentifier:@"ListadoRevistas" sender:self];
                break;
            case NSOrderedDescending:
                [self performSegueWithIdentifier:@"ListadoRevistas" sender:self];
                break;
        }
    }else {
        [self performSegueWithIdentifier:@"ListadoRevistas" sender:self];
    }
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"ListadoRevistas"]) {
        ListadoRevistasViewController *lrvcListadoRevistas = [segue destinationViewController];
        NSMutableArray *aAuxiliar = [[NSMutableArray alloc] init];
        for (int i=0; i<50; i++) {
            [aAuxiliar addObject:[NSString stringWithFormat:@"Revista %d", i]];
        }
        [lrvcListadoRevistas setAItems:aAuxiliar];
    }
}

@end
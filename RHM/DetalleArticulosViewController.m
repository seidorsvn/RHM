//
//  DetalleArticulosViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 14/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "DetalleArticulosViewController.h"
#import "InicioViewController.h"
#import "ListadoArticulosViewController.h"
#import "DetalleAutoresViewController.h"
#import "StockArticulosViewController.h"

@implementation DetalleArticulosViewController

@synthesize masterPopoverController, tvDetalleArticulos, pcContenidoMultimedia, aItems, iPosicion;

- (void)viewDidLoad
{
    [super viewDidLoad];
    if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
    [self.navigationItem setRightBarButtonItems:[[NSArray alloc] initWithObjects:[[UIBarButtonItem alloc] initWithTitle:@"Me gusta leer" style:UIBarButtonItemStyleBordered target:self action:@selector(doMeGustaLeer)], [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace target:nil action:nil], [[UIBarButtonItem alloc] initWithTitle:@"QlikView" style:UIBarButtonItemStyleBordered target:self action:@selector(doQlikView)], nil]];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortrait || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationPortraitUpsideDown) {
        [self splitViewController:self.splitViewController willHideViewController:self withBarButtonItem:[[UIBarButtonItem alloc] initWithTitle:@"Menú" style:UIBarButtonItemStylePlain target:self action:@selector(doShowPopover:)] forPopoverController:masterPopoverController];
    } else if ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) {
        [self splitViewController:self.splitViewController willShowViewController:self invalidatingBarButtonItem:nil];
    }
    [self.navigationItem setRightBarButtonItems:[[NSArray alloc] initWithObjects:[[UIBarButtonItem alloc] initWithTitle:@"Me gusta leer" style:UIBarButtonItemStyleBordered target:self action:@selector(doMeGustaLeer)], [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace target:nil action:nil], [[UIBarButtonItem alloc] initWithTitle:@"QlikView" style:UIBarButtonItemStyleBordered target:self action:@selector(doQlikView)], nil]];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    if ([pcContenidoMultimedia isPopoverVisible]) {
        [pcContenidoMultimedia dismissPopoverAnimated:YES];
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
    [self setTvDetalleArticulos:nil];
    [self setPcContenidoMultimedia:nil];
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
    return 4;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    switch (section) {
        case 0:
            return @"Información general";
            break;
        case 1:
            return @"Sinopsis";
            break;
        case 2:
            return @"Contraportada";
            break;
        case 3:
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
            return 300;
            break;
        case 1:
            return 200;
            break;
        case 2:
            break;
        case 3:
            break;
    }
    return 44;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *tvcDetalleArticulos = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
    if (tvcDetalleArticulos == nil) {
        tvcDetalleArticulos = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:[NSString stringWithFormat:@"ciS%dR%d", [indexPath section], [indexPath row]]];
    }
    for (UIView *view in [[[tvcDetalleArticulos subviews]objectAtIndex:0] subviews]) {
        if ([view isKindOfClass:[UIImageView class]]) {
            UITapGestureRecognizer *tgrImagen = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(doMostrarImagen:)];
            [view addGestureRecognizer:tgrImagen];
        }
        if ([view isKindOfClass:[UILabel class]]) {
            switch ([view tag]) {
                case 2:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:(NSUInteger)iPosicion] objectForKey:@"ZZTITULO"]]];
                    break;
                case 3:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:(NSUInteger)iPosicion] objectForKey:@"ZZSUBTIT"]]];
                    break;
                case 4:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [[aItems objectAtIndex:(NSUInteger)iPosicion] objectForKey:@"ZZCOLECCION"]]];
                    break;
                case 5:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@ €", [[aItems objectAtIndex:(NSUInteger)iPosicion] objectForKey:@"ZZCIVAVIG"]]];
                    break;
                default:
                    [(UILabel *)view setText:[NSString stringWithFormat:@"%@", [aItems objectAtIndex:(NSUInteger)iPosicion]]];
                    break;
            }
        }
        //borrar siguiente if
        if ([view isKindOfClass:[UITextView class]]) {
            CGRect rSinopsis = view.frame;
            rSinopsis.size.height = 180;
            rSinopsis.size.width = 700;
            [view setFrame:rSinopsis];
        }
    }
    return tvcDetalleArticulos;
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

#pragma mark - Me gusta leer

- (void)doMeGustaLeer
{
    NSURL *uPath = [NSURL URLWithString:@"http://www.google.es/#hl=es&q=poner%20la%20url%20de%20megustaleer"];
    if ([[UIApplication sharedApplication] canOpenURL:uPath]) {
        [[UIApplication sharedApplication] openURL:uPath];
    } else {
        [[[UIAlertView alloc] initWithTitle:@"Advertencia" message:@"No ha sido posible iniciar Safari con la URL especificada." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil] show];
    }
}

#pragma mark - Contenido multimedia

- (IBAction)doContenidoMultimedia:(id)sender
{
    if (![pcContenidoMultimedia isPopoverVisible]) {
        UIView *vContenidoMultimedia = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 0, 160)];
        for (int i=0; i<10; i++) {
            CGRect rContenidoMultimedia = [vContenidoMultimedia frame];
            [vContenidoMultimedia addSubview:[self contenidoMultimediaButtonPos:i]];
            rContenidoMultimedia.size.width += 200;
            [vContenidoMultimedia setFrame:rContenidoMultimedia];
        }
        UIScrollView *svContenidoMultimedia = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, 700, 160)];
        [svContenidoMultimedia addSubview:vContenidoMultimedia];
        [svContenidoMultimedia setShowsHorizontalScrollIndicator:YES];
        [svContenidoMultimedia setScrollEnabled:YES];
        UIViewController *vcContenidoMultimedia = [[UIViewController alloc] init];
        [vcContenidoMultimedia setView:svContenidoMultimedia];
        [svContenidoMultimedia setIndicatorStyle:UIScrollViewIndicatorStyleWhite];
        [svContenidoMultimedia setContentSize:vContenidoMultimedia.frame.size];
        [vcContenidoMultimedia setContentSizeForViewInPopover:CGSizeMake(700, 160)];
        [self setPcContenidoMultimedia:[[UIPopoverController alloc] initWithContentViewController:vcContenidoMultimedia]];
        [pcContenidoMultimedia presentPopoverFromBarButtonItem:sender permittedArrowDirections:UIPopoverArrowDirectionDown animated:YES];
    } else {
        [pcContenidoMultimedia dismissPopoverAnimated:YES];
    }
}

- (UIView *)contenidoMultimediaButtonPos:(NSInteger)i
{
    UIView *btnContenidoMultimedia = [[UIView alloc] initWithFrame:CGRectMake(200*i, 0, 200, 100)];
    UIImageView *ivImagen = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 200, 100)];
    switch (i) {
        case 0: case 3: case 6: case 9:
            [ivImagen setImage:[UIImage imageWithCGImage:[[UIImage imageNamed:@"iphoto.png"] CGImage]  scale:1.5 orientation:UIImageOrientationUp]];
            break;
        case 1: case 4: case 7:
            [ivImagen setImage:[UIImage imageWithCGImage:[[UIImage imageNamed:@"movies.png"] CGImage]  scale:1.5 orientation:UIImageOrientationUp]];
            break;
        case 2: case 5: case 8:
            [ivImagen setImage:[UIImage imageWithCGImage:[[UIImage imageNamed:@"book_cd_vide.png"] CGImage]  scale:1.5 orientation:UIImageOrientationUp]];
            break;
    }
    [ivImagen setContentMode:UIViewContentModeScaleAspectFit];
    [btnContenidoMultimedia addSubview:ivImagen];
    UILabel *lTitulo = [[UILabel alloc] initWithFrame:CGRectMake(0, btnContenidoMultimedia.frame.size.height, 200, 20)];
    [lTitulo setTextAlignment:UITextAlignmentCenter];
    [lTitulo setBackgroundColor:[UIColor clearColor]];
    [lTitulo setTextColor:[UIColor whiteColor]];
    [lTitulo setText:[NSString stringWithFormat:@"Contenido %d", i]];
    [btnContenidoMultimedia addSubview:lTitulo];
    UILabel *lPeso = [[UILabel alloc] initWithFrame:CGRectMake(0, btnContenidoMultimedia.frame.size.height+lTitulo.frame.size.height, 200, 10)];
    [lPeso setFont:[[lPeso font] fontWithSize:10]];
    [lPeso setTextAlignment:UITextAlignmentCenter];
    [lPeso setBackgroundColor:[UIColor clearColor]];
    [lPeso setTextColor:[UIColor whiteColor]];
    [lPeso setText:[NSString stringWithFormat:@"(%.2f MB)",(i+0.25)]];
    [btnContenidoMultimedia addSubview:lPeso];
    UIImageView *ivIndicador = [[UIImageView alloc] initWithFrame:CGRectMake(0, btnContenidoMultimedia.frame.size.height+lTitulo.frame.size.height+lPeso.frame.size.height, 200, 30)];
    [ivIndicador setContentMode:UIViewContentModeBottom];
    switch (i%3) {
        case 0:
            [ivIndicador setImage:[UIImage imageNamed:@"bullet-red-icon.png"]];
            break;
        case 1:
            [ivIndicador setImage:[UIImage imageNamed:@"bullet-orange-icon.png"]];
            break;
        case 2:
            [ivIndicador setImage:[UIImage imageNamed:@"bullet-green-icon.png"]];
            break;
    }
    [btnContenidoMultimedia addSubview:ivIndicador];
    UILongPressGestureRecognizer *lpgrBotonContenidoMultimedia = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(doTapBotonContenidoMultimedia:)];
    [lpgrBotonContenidoMultimedia setMinimumPressDuration:0.05];
    [btnContenidoMultimedia addGestureRecognizer:lpgrBotonContenidoMultimedia];
    return btnContenidoMultimedia;
}

- (void)doTapBotonContenidoMultimedia:(id)sender
{
    if ([sender state] == UIGestureRecognizerStateBegan) {
        UIColor *cSeleccionado = [[UIColor alloc] initWithWhite:1 alpha:0.5];
        for (UIView *v in [[sender view] subviews]) {
            [v setBackgroundColor:cSeleccionado];
        }
    } else if ([sender state] == UIGestureRecognizerStateEnded) {
        for (UIView *v in [[sender view] subviews]) {
            [v setBackgroundColor:[UIColor clearColor]];
        }
        //NSLog(@"TAAAAAAP del elemento %d", (NSInteger)[[sender view] frame].origin.x/200);
        NSData *dImagen = [NSData dataWithContentsOfURL:[NSURL URLWithString:@"http://2.bp.blogspot.com/-5wgz6O1_0Z0/TnPkSz_RQnI/AAAAAAAAAl4/T_pt60OeRrQ/s1600/vlcsnap-2010-07-27-13h58m01s127.jpg"]];
        NSString *sPath = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0] stringByAppendingPathComponent:@"/LosPilaresDeLaTierra.jpg"];
        //
        NSError *eData;
        for (NSData *dFile in [[NSFileManager defaultManager] contentsOfDirectoryAtPath:[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0] error:&eData]) {
            NSLog(@"%@", [dFile description]);
        }
        //NSLog(@"Cantidad: %d", [[[NSFileManager defaultManager] contentsOfDirectoryAtPath:[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0] error:&eData] count]);
        //
        [dImagen writeToFile:sPath atomically:YES];
        if ([[sender view] frame].origin.x/200 == 1) {
            NSURL *urlImagen = [NSURL fileURLWithPath:sPath];
            UIDocumentInteractionController *dicImagen = [UIDocumentInteractionController interactionControllerWithURL: urlImagen];
            [dicImagen setDelegate:self];
            [dicImagen presentPreviewAnimated: YES];
        }
    }
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    if ([pcContenidoMultimedia isPopoverVisible]) {
        [pcContenidoMultimedia dismissPopoverAnimated:YES];
    }
}

#pragma mark - Formatos

- (IBAction)doVisualizarFormatos:(id)sender
{
    [self performSegueWithIdentifier:@"ListadoManuscrito" sender:sender];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"ListadoManuscrito"]) {
        ListadoArticulosViewController *lavc = [segue destinationViewController];
        NSMutableArray *maItems = [[NSMutableArray alloc] initWithArray:aItems copyItems:YES];
        [maItems removeLastObject];
        [lavc setAItems:maItems];
    }
    if ([[segue identifier] isEqualToString:@"DetalleAutor"]) {
        //DetalleAutoresViewController *davc = [segue destinationViewController];
    }
    if ([[segue identifier] isEqualToString:@"StockArtículos"]) {
        //StockArticulosViewController *savc = [segue destinationViewController];
    }
}

#pragma mark - Consultar stock

- (IBAction)doConsultarStock:(id)sender
{
    [self performSegueWithIdentifier:@"StockArtículos" sender:sender];
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

#pragma mark - Ver autor

- (IBAction)doVerAutor:(id)sender
{
    [self performSegueWithIdentifier:@"DetalleAutor" sender:sender];
}

@end
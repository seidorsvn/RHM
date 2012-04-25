//
//  MasterViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 11/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "Reachability.h"
#import <QuartzCore/QuartzCore.h>
#import "MasterViewController.h"
#import "SynchronizationService.h"
#import "Utils.h"

@implementation MasterViewController

@synthesize rInternet, rHost, bbiSincronizacion, bAnimacionTerminada, ipSeleccionado;

- (void)awakeFromNib
{
    [super awakeFromNib];
    self.clearsSelectionOnViewWillAppear = NO;
    self.contentSizeForViewInPopover = CGSizeMake(200.0, 545.0);
    [self.splitViewController setValue:[NSNumber numberWithFloat:210.0] forKey:@"_masterColumnWidth"];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self.tableView selectRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:0] animated:YES scrollPosition:UITableViewScrollPositionNone];
    [self tableView:self.tableView didSelectRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:0]];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(checkNetworkStatus:) name:kReachabilityChangedNotification object:nil];
    rInternet = [Reachability reachabilityForInternetConnection];
    [rInternet startNotifier];
    rHost = [Reachability reachabilityWithHostName:[Utils retrieveFromUserDefaults:@"servername_preference"]];
    [rHost startNotifier];
    [self.navigationItem setLeftBarButtonItem:[[UIBarButtonItem alloc] initWithCustomView: [[UIImageView alloc] initWithImage: [UIImage imageNamed: @"bullet-red-icon.png"]]]];
    bAnimacionTerminada = YES;
}

- (void)viewDidUnload
{
    [self setRInternet:nil];
    [self setRHost:nil];
    [self setBbiSincronizacion:nil];
    [self setIpSeleccionado:nil];
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return YES;
}

#pragma mark - Table View

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] != 0 && [indexPath section] != 7 && bAnimacionTerminada) {
        [self setIpSeleccionado:indexPath];
        if ([[(UINavigationController *)[[self.splitViewController viewControllers] objectAtIndex:1] viewControllers] count] == 1) {
            [self performSelector:@selector(doSeleccion:) withObject:indexPath];
        } else {
            bAnimacionTerminada = NO;
            [(UINavigationController *)[[self.splitViewController viewControllers] objectAtIndex:1] popToRootViewControllerAnimated:YES];
            [self performSelector:@selector(doSeleccion:) withObject:indexPath afterDelay:0.75];
        }
    } else if ([indexPath section] == 0) {
        [(UINavigationController *)[[self.splitViewController viewControllers] objectAtIndex:1] popToRootViewControllerAnimated:YES];
    } else if ([indexPath section] == 7) {
        NSURL *uPath = [NSURL URLWithString:@"http://www.google.es/#hl=es&q=poner%20la%20url%20del%20qlikview"];
        if ([[UIApplication sharedApplication] canOpenURL:uPath]) {
            [[UIApplication sharedApplication] openURL:uPath];
        } else {
            [[[UIAlertView alloc] initWithTitle:@"Advertencia" message:@"No ha sido posible iniciar Safari con la URL especificada." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil] show];
        }
    } else {
        [tableView deselectRowAtIndexPath:indexPath animated:YES];
        [tableView selectRowAtIndexPath:ipSeleccionado animated:YES scrollPosition:UITableViewScrollPositionNone];
    }
}

- (void)doSeleccion:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 6) {
        [[[[[self.splitViewController viewControllers] objectAtIndex:1] viewControllers] objectAtIndex:0] performSegueWithIdentifier:[NSString stringWithFormat:@"Listado%@", [[[self.tableView cellForRowAtIndexPath:indexPath] textLabel] text]] sender:self];
    } else {
        [[[[[self.splitViewController viewControllers] objectAtIndex:1] viewControllers] objectAtIndex:0] performSegueWithIdentifier:[NSString stringWithFormat:@"Búsqueda%@", [[[self.tableView cellForRowAtIndexPath:indexPath] textLabel] text]] sender:self];
    }
    bAnimacionTerminada = YES;
}

#pragma mark - Acerca de

- (IBAction)doAcercaDe:(id)sender
{
    [[[UIAlertView alloc] initWithTitle:@"Créditos de la aplicación" message:@"Versión: 0.5\nNombre en clave: Dafne\nDesarrollo: Carlos Solana Martínez\n\n\n\n\n\n\nSeidor Consulting © 2012" delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil] show];
}

- (void)willPresentAlertView:(UIAlertView *)alertView
{
    if ([alertView title] == @"Créditos de la aplicación") {
        UIImageView *ivLogo = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Seidor.png"]];
        [[ivLogo layer] setOpacity:0.85];
        [[ivLogo layer] setFrame:CGRectMake((alertView.frame.size.width/2) - (ivLogo.frame.size.width/2), (alertView.frame.size.height/2) - (ivLogo.frame.size.height/2), ivLogo.frame.size.width, ivLogo.frame.size.height)];
        [alertView addSubview:ivLogo];
    }
    if ([alertView title] == @"¿Qué desea sincronizar?") {
        UIImageView *ivLogo = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"sync-header.png"]];
        [[ivLogo layer] setOpacity:0.85];
        [[ivLogo layer] setFrame:CGRectMake((alertView.frame.size.width/2) - (ivLogo.frame.size.width/4), (alertView.frame.size.height/2) - (ivLogo.frame.size.height/2), ivLogo.frame.size.width/2, ivLogo.frame.size.height/2)];
        [alertView addSubview:ivLogo];
    }
}

#pragma mark - Sincronización

- (IBAction)doSincronizacion:(id)sender
{
    [[[UIAlertView alloc] initWithTitle:@"¿Qué desea sincronizar?" message:@"\n\n\n\n\n\n" delegate:self cancelButtonTitle:@"Cancelar" otherButtonTitles:@"Maestros", @"Pedidos", nil] show];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if ([alertView title] == @"¿Qué desea sincronizar?" && buttonIndex != 0) {
        UIAlertView *avSincronizando = [[UIAlertView alloc] initWithTitle:@"Por favor, espere..." message:[NSString stringWithFormat:@"Sincronizando %@", [[alertView buttonTitleAtIndex:buttonIndex] lowercaseString]] delegate:self cancelButtonTitle:nil otherButtonTitles:nil];
        UIActivityIndicatorView *aivCargando = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
        [[aivCargando layer] setFrame:CGRectMake((alertView.frame.size.width/2)-(aivCargando.frame.size.width/2), (alertView.frame.size.height/4) - (aivCargando.frame.size.height/3), aivCargando.frame.size.width, aivCargando.frame.size.height)];
        [avSincronizando addSubview:aivCargando];
        [aivCargando startAnimating];
        [avSincronizando show];
        switch (buttonIndex) {
            case 1:
                [self performSelectorInBackground:@selector(doSincronizarDatosMaestros:) withObject:avSincronizando];
                break;
            case 2:
                [self performSelectorInBackground:@selector(doSincronizarPedidos:) withObject:avSincronizando];
                break;
        }
    }
}

- (void)doSincronizarDatosMaestros:(UIAlertView *)avSincronizando
{
    [[NSNotificationCenter defaultCenter] addObserverForName:@"SUPSynchronizeFinished" object:nil queue:nil usingBlock:^(NSNotification *notification){[avSincronizando dismissWithClickedButtonIndex:0 animated:YES];}];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"iniciarSincro" object:nil];
    /*sleep(1);
     [avSincronizando performSelectorOnMainThread:@selector(setMessage:) withObject:@"Sincronizando artículos" waitUntilDone:NO];
     sleep(1);
     [avSincronizando performSelectorOnMainThread:@selector(setMessage:) withObject:@"Sincronizando autores" waitUntilDone:NO];
     sleep(1);
     [avSincronizando performSelectorOnMainThread:@selector(setMessage:) withObject:@"Sincronizando revistas" waitUntilDone:NO];
     sleep(1);
     [avSincronizando performSelectorOnMainThread:@selector(setMessage:) withObject:@"Sincronizando catálogos" waitUntilDone:NO];
     sleep(1);
     [avSincronizando performSelectorOnMainThread:@selector(setMessage:) withObject:@"Sincronizando clientes" waitUntilDone:NO];
     sleep(1);*/
}

- (void)doSincronizarPedidos:(UIAlertView *)avSincronizando
{
    sleep(1);
    [avSincronizando dismissWithClickedButtonIndex:0 animated:YES];
}

#pragma mark - Conectividad

- (void)checkNetworkStatus:(NSNotification *)notice
{
    NetworkStatus nsInternet = [rInternet currentReachabilityStatus];
    if (nsInternet == ReachableViaWiFi || nsInternet == ReachableViaWWAN) {
        NetworkStatus nsHost = [rHost currentReachabilityStatus];
        if (nsHost == ReachableViaWiFi || nsHost == ReachableViaWWAN) {
            [self.navigationItem setLeftBarButtonItem:[[UIBarButtonItem alloc] initWithCustomView: [[UIImageView alloc] initWithImage: [UIImage imageNamed: @"bullet-green-icon.png"]]]];
            [bbiSincronizacion setEnabled:YES];
        } else {
            [self.navigationItem setLeftBarButtonItem:[[UIBarButtonItem alloc] initWithCustomView: [[UIImageView alloc] initWithImage: [UIImage imageNamed: @"bullet-orange-icon.png"]]]];
            [bbiSincronizacion setEnabled:NO];
        }
    } else {
        [self.navigationItem setLeftBarButtonItem:[[UIBarButtonItem alloc] initWithCustomView: [[UIImageView alloc] initWithImage: [UIImage imageNamed: @"bullet-red-icon.png"]]]];
        [bbiSincronizacion setEnabled:NO];
    }
}

@end
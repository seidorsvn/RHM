//
//  SynchronizationService.m
//  RHM
//
//  Created by Apple1 Seidor on 4/4/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "SynchronizationService.h"
#import "SUPMessageClient.h"
#import "RHM_Comercial_RHM_ComercialDB.h"
#import "Utils.h"
#import <QuartzCore/QuartzCore.h>
#import "RHM_Comercial_Articulos.h"
#import "RHM_Comercial_ClientesSynchronizationParameters.h"
#import "RHM_Comercial_Clientes_pull_pq.h"
#import "RHM_Comercial_Clientes.h"
#import "RHM_Comercial_Autores.h"
#import "RHM_Comercial_Agentes.h"
#import "RHM_Comercial_Plantillas.h"
#import <AudioToolbox/AudioServices.h>

@implementation SynchronizationService

@synthesize connectStartTime;
@synthesize callbackHandler;

#pragma mark - Init

- (id)init
{
    if (self = [super init])
    {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(iniciarSincro)
                                                     name:@"iniciarSincro"
                                                   object:nil];
    }
    return self;
}

#pragma mark - Handlers

-(void)onConnectSuccess:(NSNotification *)obj
{
    // Connection to the server was made, so log in.
    // See [CallbackHandler onLoginSuccess] and [CallbackHandler onLoginFailure]. One of those
    // callbacks will be called at some point in the future.
    NSLog(@"\t\tConexion correcta con el SUP!");
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_CONNECT_SUCCESS object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_CONNECT_FAILURE object:nil];
    [self login];
}

-(void)onConnectFailure:(NSNotification *)obj
{
    // Once [SUPMessageClient start] is called, ON_CONNECT_FAILURE is sent from our callback handler
    // until the device is connected or something changes. If we haven't connected in 30 seconds, give up.
    NSDate *now = [NSDate date];
    if ([now timeIntervalSinceDate:self.connectStartTime] > 20) 
    {
        [self postNotification:ON_SYNC_FINISHED withObject:nil];
        [SUPMessageClient stop];
        [self showAlert:@"\n\n\n\n\n\nHa ocurrido un error al establecer conexión con el servidor."];
    }
}

-(void)onLoginSuccess:(NSNotification *)obj 
{    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_LOGIN_SUCCESS object:nil];  
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_LOGIN_FAILURE object:nil];  
    NSLog(@"\t\tLogueo correcto!");
    [self sincronizarDatos];
}

-(void)onLoginFailure:(NSNotification *)obj 
{
    [self postNotification:ON_SYNC_FINISHED withObject:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_LOGIN_FAILURE object:nil]; 
    UIAlertView *loginAlert = [[UIAlertView alloc] initWithTitle:@"Advertencia" 
                                                         message:@"\n\n\n\n\n\nHa ocurrido un error durante la identificación." 
                                                        delegate:self cancelButtonTitle:@"Aceptar"
                                               otherButtonTitles: nil];
    [loginAlert show];
    [loginAlert release];
}

- (void) onImportSuccess:(NSNotification *)object 
{
    [self postNotification:ON_SYNC_FINISHED withObject:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_IMPORT_SUCCESS object:nil];
    // We have data, so present the view that will display it.
    UIAlertView *subscribeAlert = [[UIAlertView alloc] initWithTitle:@"Información" message:@"\n\n\n\n\n\nLa suscripción se ha realizado con éxito." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil];
    [subscribeAlert setTag:9];
    [subscribeAlert show];
    [subscribeAlert release];
    AudioServicesPlaySystemSound(1007);
}

- (void) onSubscribeFailure:(NSNotification *)object 
{
    [self postNotification:ON_SYNC_FINISHED withObject:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_SUBSCRIBE_FAILURE object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_IMPORT_SUCCESS object:nil];
    UIAlertView *subscribeAlert = [[UIAlertView alloc] initWithTitle:@"Advertencia" message:@"\n\n\n\n\n\nHa ocurrido un error durante la suscripción." delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles: nil];
    [subscribeAlert show];
    [subscribeAlert release];
}

- (void) onSynchronizeSuccess:(NSNotification *)object 
{
    [self postNotification:ON_SYNC_FINISHED withObject:nil];
    //Printamos el total de registros sincronizados
    
    RHM_Comercial_ArticulosList *arts = [RHM_Comercial_Articulos findAll];
    RHM_Comercial_AgentesList *agentes = [RHM_Comercial_Agentes findAll];
    RHM_Comercial_AutoresList *autores = [RHM_Comercial_Autores findAll];
    RHM_Comercial_ClientesList *clientes = [RHM_Comercial_Clientes findAll];
    RHM_Comercial_PlantillasList *plants = [RHM_Comercial_Plantillas findAll];
    NSLog(@"+++++++++++++++++++++++++++++++++++++++");
    NSLog(@"Se han sincronizado: %i artículos", [arts length]);
    NSLog(@"Se han sincronizado: %i agentes", [agentes length]);
    NSLog(@"Se han sincronizado: %i clientes", [clientes length]);
    NSLog(@"Se han sincronizado: %i autores", [autores length]);
    NSLog(@"Se han sincronizado: %i plantillas", [plants length]);
    NSLog(@"+++++++++++++++++++++++++++++++++++++++");
    // We have data, so present the view that will display it.
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_SYNCHRONIZE_SUCCESS object:nil];
    UIAlertView * alert = [[UIAlertView alloc] initWithTitle:@"Información"
                                                     message:@"\n\n\n\n\n\nLa sincronización se ha realizado con éxito."
                                                    delegate:self
                                           cancelButtonTitle:@"Aceptar" 
                                           otherButtonTitles:nil];
    
    [alert setTag:9];
    [alert performSelectorOnMainThread:@selector(show) withObject:self waitUntilDone:YES];
    [alert release];
    AudioServicesPlaySystemSound(1007);
}

- (void) onSynchronizeFailure:(NSNotification *)object 
{
    [self postNotification:ON_SYNC_FINISHED withObject:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:ON_SYNCHRONIZE_FAILURE object:nil]; 
    UIAlertView *subscribeAlert = [[UIAlertView alloc] initWithTitle:@"Advertencia" 
                                                             message:@"\n\n\n\n\n\nHa ocurrido un error durante la sincronización." 
                                                            delegate:self cancelButtonTitle:@"Aceptar" 
                                                   otherButtonTitles: nil];
    [subscribeAlert show];
    [subscribeAlert release];
}

#pragma mark - Métodos de sincronización

- (void)iniciarSincro
{
    //[[self dataService] getValoracionPedido:nil posiciones:nil nuevaDir:nil];
    [self postNotification:ON_SYNC_STARTED withObject:nil];
    //[NSThread sleepForTimeInterval:2];
    
    if([[RHM_Comercial_RHM_ComercialDB getOnlineLoginStatus] status] == 0)
    {
        // JOSUE
        //RHM_Comercial_RHM_ComercialDB.callbackHandler.onImportSuccess = 0;
        // FIN JOSUE
        [self sincronizarDatos];
    }
    else
    {
        // MEGAPRUEBAS
        /*NSLog([NSString stringWithFormat:@"Status: %d",[[RHM_Comercial_RHM_ComercialDB getOnlineLoginStatus] status]]);
         
         if ([RHM_Comercial_RHM_ComercialDB isSubscribed]){
         NSLog(@"Esta suscrito");
         } else {
         NSLog(@"No esta suscrito");
         }
         
         NSLog([NSString stringWithFormat:@"Esta suscrito?: %d",[SUPMessageClient status]]);
         
         if ( [SUPMessageClient provisioned]) {
         NSLog(@"Esta provisioned");
         } else {
         NSLog(@"No esta provisioned");
         }*/
        
        // FIN DE MEGAPRUEBAS
        
        //registramos el CallbackHandler
        self.callbackHandler = [CallbackHandler new];
        [RHM_Comercial_RHM_ComercialDB registerCallbackHandler:self.callbackHandler];
        // Set log level (optional -- this will generate a lot of output in the debug console)
        [MBOLogger setLogLevel:LOG_OFF];
        [RHM_Comercial_RHM_ComercialDB createDatabase];            
        // Start listening for messages from the server.
        [RHM_Comercial_RHM_ComercialDB startBackgroundSynchronization];
        // Start up the messaging client. This will attempt to connect to the server. If a connection was
        // established we can proceed with login. See onConnectFailure: for more information about handling connection failure.
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onConnectSuccess:) name:ON_CONNECT_SUCCESS object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onConnectFailure:) name:ON_CONNECT_FAILURE object:nil];
        NSLog(@"1 - Intentando conectar con el SUP...");
        self.connectStartTime = [NSDate date];
        [SUPMessageClient start];
    }
}

- (void) login
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onLoginSuccess:) name:ON_LOGIN_SUCCESS object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onLoginSuccess:) name:ON_LOGIN_FAILURE object:nil];
    /*NSLog(@"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
     NSLog(@" Empieza el LOGIN  ");
     NSLog(@"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");*/
    NSLog(@"2 - Logueando...");
    
    [RHM_Comercial_RHM_ComercialDB beginOnlineLogin:@"Seidor" password:@"inicial123!"];
}

- (void) sincronizarDatos
{
    if(![RHM_Comercial_RHM_ComercialDB isSubscribed])
    {
        [self suscribir];
    }
    else
    {
        [NSThread detachNewThreadSelector:@selector(sincronizar) toTarget:self withObject:nil];
    }
}

- (void)suscribir
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onImportSuccess:) name:ON_IMPORT_SUCCESS object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onSubscribeFailure:) name:ON_SUBSCRIBE_FAILURE object:nil];
    NSLog(@"Subscribiendo...");
    [RHM_Comercial_RHM_ComercialDB subscribe];
}

- (void)sincronizar
{
    //--------------------------------------
    //Enviamos las operaciones pendientes
    //--------------------------------------
    
    NSLog(@"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    NSLog(@" 1 - Enviando operaciones pendientes...  ");
    NSLog(@"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    
    [RHM_Comercial_RHM_ComercialDB submitPendingOperations];
    
    while([RHM_Comercial_RHM_ComercialDB hasPendingOperations])
        [NSThread sleepForTimeInterval:0.5];
    
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onSynchronizeSuccess:) name:ON_SYNCHRONIZE_SUCCESS object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onSynchronizeFailure:) name:ON_SYNCHRONIZE_FAILURE object:nil];
    //--------------------------------------
    //Cargamos el usuario
    //--------------------------------------
    NSString *user = [NSString stringWithString:[Utils retrieveFromUserDefaults:@"username_preference"]];
    //--------------------------------------
    //Sincronizamos los MBOs con parámetros
    //--------------------------------------
    RHM_Comercial_ClientesSynchronizationParameters *sp1 = [RHM_Comercial_Clientes getSynchronizationParameters];
    [sp1 setUser:user];
    [sp1 delete];
    sp1 = [RHM_Comercial_Clientes getSynchronizationParameters];
    [sp1 setUser:user];
    [sp1 setSize:10];
    [sp1 setAgente:user];
    [sp1 save];
    while([RHM_Comercial_RHM_ComercialDB hasPendingOperations])
        [NSThread sleepForTimeInterval:0.5];
    NSLog(@"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    NSLog(@" 2 - Sincronizando  MBO's con parametros...  ");
    NSLog(@"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    //--------------------------------------
    //Montamos los grupos de sincronización
    //--------------------------------------
    
    //OrdesaFuerzaVentas_SynchronizationGroup *group = [OrdesaFuerzaVentas_SynchronizationGroup getInstance:@"Clientes"];
    //SUPObjectList *groups = [[SUPObjectList alloc] initWithCapacity:1];
    //[groups addObject:group];
    //----------------------------------------------
    //Iniciamos la sincronización de datos maestros
    //----------------------------------------------
    //NSLog(@"Empieza el beginSynchronize...");
    
    NSLog(@"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    NSLog(@" 3 - Sincronizando  MBO's de Datos Maestros...   ");
    NSLog(@"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    
    //[RHM_Comercial_RHM_ComercialDB beginSynchronize:groups withContext:nil];
    [RHM_Comercial_RHM_ComercialDB beginSynchronize];
    ////[self onSynchronizeSuccess:nil];
}

#pragma mark - Métodos auxiliares

- (void)sendNotification:(NSNotification *)notification
{
    [[NSNotificationCenter defaultCenter] postNotification:notification];
    [notification release];
}

- (void)postNotification:(NSString *)notification withObject:(id)obj
{
    NSNotification *n = [NSNotification notificationWithName:notification object:obj];
    [n retain];
    [self performSelectorOnMainThread:@selector(sendNotification:) withObject:n waitUntilDone:NO];
}

- (void)showAlert:(NSString*) message
{
    UIAlertView * noTransportAlert = [[UIAlertView alloc] initWithTitle:@"Advertencia" message:message delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles:nil];
    [noTransportAlert performSelectorOnMainThread:@selector(show) withObject:self waitUntilDone:YES];
    [noTransportAlert release];
}

- (void)willPresentAlertView:(UIAlertView *)alertView
{
    if ([alertView title] == @"Información") {
        UIImageView *ivLogo = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Actions-dialog-ok-apply-icon.png"]];
        [[ivLogo layer] setOpacity:0.85];
        [[ivLogo layer] setFrame:CGRectMake((alertView.frame.size.width/2) - (ivLogo.frame.size.width/2), (alertView.frame.size.height/1.65) - (ivLogo.frame.size.height), ivLogo.frame.size.width, ivLogo.frame.size.height)];
        [alertView addSubview:ivLogo];
    }
    if ([alertView title] == @"Advertencia") {
        UIImageView *ivLogo = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Actions-edit-delete-icon.png"]];
        [[ivLogo layer] setOpacity:0.85];
        [[ivLogo layer] setFrame:CGRectMake((alertView.frame.size.width/2) - (ivLogo.frame.size.width/2), (alertView.frame.size.height/1.65) - (ivLogo.frame.size.height), ivLogo.frame.size.width, ivLogo.frame.size.height)];
        [alertView addSubview:ivLogo];
    }
}

#pragma mark - Dealloc

- (void)dealloc
{
    [self setConnectStartTime:nil];
    [self setCallbackHandler:nil];
    [connectStartTime release];
    [callbackHandler release];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"iniciarSincro" object:nil];
    [super dealloc];
}

@end
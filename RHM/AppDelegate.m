//
//  AppDelegate.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 11/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "AppDelegate.h"
#import "SUPMessageClient.h"
#import "RHM_Comercial_RHM_ComercialDB.h"
#import <QuartzCore/QuartzCore.h>

@implementation AppDelegate

@synthesize window = _window;
@synthesize dataService = _dataService;
@synthesize syncService = _syncService;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    UISplitViewController *splitViewController = (UISplitViewController *)self.window.rootViewController;
    UINavigationController *navigationController = [splitViewController.viewControllers lastObject];
    splitViewController.delegate = (id)navigationController.topViewController;
    NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
	
	if (![SUPMessageClient provisioned]) {
		[self showNoTransportAlert:kSUPMessageClientNoSettings];
    } else {
		
        [self setDataService:[[DataService alloc] init]];
		[self setSyncService:[[SynchronizationService alloc] init]];
		
		//Guardamos el usuario
		NSString *user = [Utils retrieveFromUserDefaults:@"username_preference"];
		//NSString *u = [NSString stringWithFormat:@"000000%i",[user intValue]];
		//u = [u substringFromIndex:[u length]-10];
		[[self dataService] setLoggedUser:user];
		
		[self.window makeKeyAndVisible];
		
		[RHM_Comercial_RHM_ComercialDB offlineLogin:@"Seidor" password:@"inicial123!"];
        
    }
	
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    
}

- (void)applicationWillTerminate:(UIApplication *)application
{
	[SUPMessageClient stop];
	[RHM_Comercial_RHM_ComercialDB stopBackgroundSynchronization];
	
	[self setWindow:nil];
	[self setDataService:nil];
	[self setSyncService:nil];
}

- (void)dismissKeyboard {
    [self globalResignFirstResponder];
}

- (void)globalResignFirstResponder {
    UIWindow * w = [[UIApplication sharedApplication] keyWindow];
    for (UIView * v in [w subviews]){
        [self globalResignFirstResponderRec:v];
    }
}

- (void)globalResignFirstResponderRec:(UIView *) v {
    if ([v respondsToSelector:@selector(resignFirstResponder)]){
        [v resignFirstResponder];
    }
    for (UIView * sv in [v subviews]){
        [self globalResignFirstResponderRec:sv];
    }
}

static void uncaughtExceptionHandler(NSException *exception) 
{
    [[[UIAlertView alloc] initWithTitle:@"Disculpe las molestias" message:[NSString stringWithFormat:@"Ha ocurrido un error inesperado.\n\nEs recomendable que guarde su trabajo y reinicie la aplicación.\n\nTipo del error: %@\n\nDescripción: %@\n\nTraza de la pila: %@", [exception name], [exception reason], [exception callStackReturnAddresses]] delegate:[[UIApplication sharedApplication] delegate] cancelButtonTitle:@"Continuar" otherButtonTitles:@"Salir", nil] show];
    [[NSRunLoop currentRunLoop] run];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    switch (buttonIndex) {
        case 0:
            if ([[alertView title] isEqualToString:@"Disculpe las molestias"]) {
                [[[UIAlertView alloc] initWithTitle:@"Advertencia" message:@"\n\n\n\n\n\nLa aplicación continuará ejecutándose pero puede ser inestable." delegate:[[UIApplication sharedApplication] delegate] cancelButtonTitle:@"Continuar" otherButtonTitles:nil] show];
            } else if ([[alertView title] isEqualToString:@"Advertencia"] && [[alertView message] isEqualToString:@"\n\n\n\n\n\n\nLa configuración de la aplicación está incompleta."]) {
                exit(0);
            }
            break;
        case 1:
            exit(0);
            break;
    }
}

- (void)showNoTransportAlert:(NSInteger) ret
{
    NSString *message = nil;
    
    if (ret == kSUPMessageClientNoSettings) {
        message = @"\n\n\n\n\n\n\nLa configuración de la aplicación está incompleta.";
    } else if (ret == kSUPMessageClientKeyNotAvailable) {
        message = @"\n\n\n\n\n\nHa ocurrido un error al acceder a la contraseña.";
    } else {
        message = @"\n\n\n\n\n\nHa ocurrido un error durante la identificación.";
    }
    
    UIAlertView * noTransportAlert = [[UIAlertView alloc] initWithTitle:@"Advertencia" message:message delegate:self cancelButtonTitle:@"Aceptar" otherButtonTitles:nil];
	
	if(ret == kSUPMessageClientNoSettings) [noTransportAlert setTag:8];
	
    [noTransportAlert performSelectorOnMainThread:@selector(show) withObject:self waitUntilDone:YES];
    [noTransportAlert release];
}

- (void)willPresentAlertView:(UIAlertView *)alertView
{
    if ([[alertView message] isEqualToString:@"\n\n\n\n\n\n\nLa configuración de la aplicación está incompleta."]) {
        UIImageView *ivLogo = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Categories-preferences-system-icon.png"]];
        [[ivLogo layer] setOpacity:0.85];
        [[ivLogo layer] setFrame:CGRectMake((alertView.frame.size.width/2) - (ivLogo.frame.size.width/2), (alertView.frame.size.height/1.70) - (ivLogo.frame.size.height), ivLogo.frame.size.width, ivLogo.frame.size.height)];
        [alertView addSubview:ivLogo];
    }
    if ([[alertView message] isEqualToString:@"\n\n\n\n\n\nLa aplicación continuará ejecutándose pero puede ser inestable."]) {
        UIImageView *ivLogo = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"Status-dialog-warning-icon.png"]];
        [[ivLogo layer] setOpacity:0.85];
        [[ivLogo layer] setFrame:CGRectMake((alertView.frame.size.width/2) - (ivLogo.frame.size.width/2), (alertView.frame.size.height/1.80) - (ivLogo.frame.size.height), ivLogo.frame.size.width, ivLogo.frame.size.height)];
        [alertView addSubview:ivLogo];
    }
}

#pragma mark - Dealloc

- (void)dealloc
{	
    [_window release];
    [_dataService release];
	[_syncService release];
    
    [super dealloc];
}

@end
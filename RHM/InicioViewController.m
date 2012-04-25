//
//  InicioViewController.m
//  RHM
//
//  Created by Carlos Solana Martí­nez on 11/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import "InicioViewController.h"

@implementation InicioViewController

@synthesize masterPopoverController;

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [masterPopoverController dismissPopoverAnimated:YES];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return YES;
}

#pragma mark - Split view

- (void)splitViewController:(UISplitViewController *)splitController willHideViewController:(UIViewController *)viewController withBarButtonItem:(UIBarButtonItem *)barButtonItem forPopoverController:(UIPopoverController *)popoverController
{
    [barButtonItem setTitle:@"Menú"];
    [self.navigationItem setLeftBarButtonItem:barButtonItem animated:YES];
    [self setMasterPopoverController:popoverController];
}

- (void)splitViewController:(UISplitViewController *)splitController willShowViewController:(UIViewController *)viewController invalidatingBarButtonItem:(UIBarButtonItem *)barButtonItem
{
    [self.navigationItem setLeftBarButtonItem:nil animated:NO];
    [self setMasterPopoverController:nil];
}

- (void)performSegueWithIdentifier:(NSString *)identifier sender:(id)sender
{
    [super performSegueWithIdentifier:identifier sender:sender];
    [masterPopoverController dismissPopoverAnimated:YES];
}

@end
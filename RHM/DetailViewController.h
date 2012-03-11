//
//  DetailViewController.h
//  RHM
//
//  Created by Carlos Solana Martí­nez on 11/03/12.
//  Copyright (c) 2012 Seidor Consulting. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController <UISplitViewControllerDelegate>

@property (strong, nonatomic) id detailItem;

@property (strong, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end

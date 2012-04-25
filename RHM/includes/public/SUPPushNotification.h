/*
 
 Copyright (c) Sybase, Inc. 2010  All rights reserved.                                    
 
 In addition to the license terms set out in the Sybase License Agreement for 
 the Sybase Unwired Platform ("Program"), the following additional or different 
 rights and accompanying obligations and restrictions shall apply to the source 
 code in this file ("Code").  Sybase grants you a limited, non-exclusive, 
 non-transferable, revocable license to use, reproduce, and modify the Code 
 solely for purposes of (i) maintaining the Code as reference material to better
 understand the operation of the Program, and (ii) development and testing of 
 applications created in connection with your licensed use of the Program.  
 The Code may not be transferred, sold, assigned, sublicensed or otherwise 
 conveyed (whether by operation of law or otherwise) to another party without 
 Sybase's prior written consent.  The following provisions shall apply to any 
 modifications you make to the Code: (i) Sybase will not provide any maintenance
 or support for modified Code or problems that result from use of modified Code;
 (ii) Sybase expressly disclaims any warranties and conditions, express or 
 implied, relating to modified Code or any problems that result from use of the 
 modified Code; (iii) SYBASE SHALL NOT BE LIABLE FOR ANY LOSS OR DAMAGE RELATING
 TO MODIFICATIONS MADE TO THE CODE OR FOR ANY DAMAGES RESULTING FROM USE OF THE 
 MODIFIED CODE, INCLUDING, WITHOUT LIMITATION, ANY INACCURACY OF DATA, LOSS OF 
 PROFITS OR DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, EVEN
 IF SYBASE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; (iv) you agree 
 to indemnify, hold harmless, and defend Sybase from and against any claims or 
 lawsuits, including attorney's fees, that arise from or are related to the 
 modified Code or from use of the modified Code. 
 
 */

//  Created by Jane Yang on 11/10/09.



#import <UIKit/UIKit.h>


/*!
 @class SUPPushNotification
 @abstract This class provides the programmatic interface for the SUP Client to handle and process notifications
 via the Apple Push Notification Service.
 */ 
@interface SUPPushNotification : NSObject {

}

/*!
 @method
 @abstract  Abstracts the inner working of Mobile Office server,resolves the push related settings and registers with Apple Push server if necessary
 @discussion This should be called in "applicatinDidFinishLaunching" function of the client application. 
 @param application The UIApplication object.
 */
+(void)setupForPush:(UIApplication*)application;

/*!
 @method
 @abstract   Sends the registered device token to Mobile Office server.
 @discussion  The iPhone OS calls "didRegisterForRemoteNotificationWithDeviceToken" in the client application
 after the device is successfully registered for push by notifications.
 It will p the device token to this function which
 in turn should call this deviceTokenForPush API so that it can be passed on
 to Mobile Office server.
 @param  application    The UIApplication object.
 @param  devToken    The device token object.
 */
+(void)deviceTokenForPush:(UIApplication*)application deviceToken:(NSData *)devToken;

/*!
 @method
 @abstract   This function is invoked when registration with Apple Push Notification Service fails.
 @discussion  When registration fails,the iPhone OS calls "didFailToRegisterForRemoteNotificationsWithError" in the client application which in turn should call this API.
 @param  application    The UIApplication object.
 @param  err   The NSError object with error information.
 */
+(void)pushRegistrationFailed:(UIApplication*)application errorInfo:(NSError *)err;

/*!
 @method
 @abstract   This function is invoked when a push notification is received.
 @discussion The iPhone OS on receiving a push notification for an application will call “didReceiveRemoteNotification” in the client application.This in turn should call push Notification API.
 @param   application   The UIApplication object.
 @result   userInfo NSDistionary object with the user information.
 */
+(void)pushNotification:(UIApplication*)application notifyData:(NSDictionary *)userInfo;

@end

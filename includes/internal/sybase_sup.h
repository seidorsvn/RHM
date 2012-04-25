// Copyright (c) 2009, Sybase Inc.
#import <Foundation/Foundation.h>
#import "AvailabilityMacros.h"

/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "boolean". 
 @discussion 
 */
typedef BOOL SUPBoolean;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "string".   
 @discussion 
 */
typedef NSString* SUPString;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "binary".   
 @discussion 
 */
typedef NSData* SUPBinary;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "char".   
 @discussion 
 */
typedef unichar SUPChar;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "byte".   
 @discussion 
 */
typedef signed char SUPByte;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "short".   
 @discussion 
 */
typedef short SUPShort;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "int".   
 @discussion 
 */
typedef int32_t SUPInt;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "long".   
 @discussion 
 */
typedef int64_t SUPLong;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "integer".   
 @discussion 
 */
typedef NSNumber* SUPInteger;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "decimal".   
 @discussion 
 */
typedef NSNumber* SUPDecimal;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "float".   
 @discussion 
 */
typedef float SUPFloat;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "double".   
 @discussion 
 */
typedef double SUPDouble;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "date".   
 @discussion 
 */
typedef NSDate* SUPDate;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "time".   
 @discussion 
 */
typedef NSDate* SUPTime;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "dateTime".   
 @discussion 
 */
typedef NSDate* SUPDateTime;

/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "boolean?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableBoolean;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "string?" (nullable).   
 @discussion 
 */
typedef NSString* SUPNullableString;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "binary?" (nullable).   
 @discussion 
 */
typedef NSData* SUPNullableBinary;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "char?" (nullable).   
 @discussion 
 */
typedef NSString* SUPNullableChar;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "byte?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableByte;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "short?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableShort;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "int?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableInt;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "long?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableLong;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "integer?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableInteger;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "decimal?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableDecimal;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "float?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableFloat;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "double?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNullableDouble;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "date?" (nullable).   
 @discussion 
 */
typedef NSDate* SUPNullableDate;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "time?" (nullable).   
 @discussion 
 */
typedef NSDate* SUPNullableTime;
/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "dateTime?" (nullable).   
 @discussion 
 */
typedef NSDate* SUPNullableDateTime;

/*!
 @typedef 
 @abstract  Objective-C type of attributes with SUP type "number?" (nullable).   
 @discussion 
 */
typedef NSNumber* SUPNumber;

/*!
 @enum 
 @abstract   Enumeration of the possible current login status values returned by the database class method getOnlineLoginStatus.
 @discussion Example of usage in a callback handler to handle a login failure:
 
 <pre>
 - (void)onLoginFailure
 {
    NSString *status;
    switch([Test_TestDB getOnlineLoginStatus].status)
    {
        case SUPLoginSuccess:
            status = @"Success";
            break;
        case SUPLoginFailure:
            status = @"Failure";
            break;
        case SUPLoginPending:
            status = @"Pending";
            break;
    }
    NSLog(@"------------------------------------------------------------");
    NSLog(@"login failed.... status = %@, code = %ld, message = %@",
           status,[Test_TestDB getOnlineLoginStatus].code,[Test_TestDB getOnlineLoginStatus].message);
    NSLog(@"------------------------------------------------------------");
 
 }
 </pre>
 
 */
typedef enum
{
    SUPLoginPending = 2,
    SUPLoginSuccess = 0,
    SUPLoginFailure = 1,
	
} SUPLoginStatus;


#import "SUPNull.h"

#import "SUPArrayList.h"
#import "SUPBase64Encoding.h"
#import "SUPBase64EncodingException.h"
#import "SUPBinaryUtil.h"
#import "SUPBindUtil.h"
#import "SUPBooleanUtil.h"
#import "SUPConsoleUtil.h"
#import "SUPDateTimeUtil.h"
#import "SUPDateUtil.h"
#import "SUPNumberUtil.h"
#import "SUPStringCache.h"
#import "SUPStringUtil.h"
#import "SUPThreadUtil.h"
#import "SUPTimeUtil.h"

#import "SUPAbstractOperationException.h"
#import "SUPAssertionFailedException.h"
#import "SUPNullPointerException.h"
#import "MBOLogger.h"
#import "SUPJSONLogger.h"

#import "SUPReadWriteLock.h"
#import "SUPLockUtil.h"


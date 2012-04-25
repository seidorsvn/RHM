#import "sybase_sup.h"

@class SUPNullDataValueException;

@interface SUPNullDataValueException : NSException
{
}

+ (SUPNullDataValueException*)getInstance;
- (SUPNullDataValueException*)init;
- (SUPNullDataValueException*)finishInit;
- (void)dealloc;
/*!
 @method     
 @abstract   Overrides Apple's NSException method name()
 @result String with the exception name.
 @discussion 
 */
- (NSString*)name;

/*!
 @method
 @abstract  Overrides Apple's description method.
 @result String combining the name and reason strings.
 */
- (NSString*)description;

@end

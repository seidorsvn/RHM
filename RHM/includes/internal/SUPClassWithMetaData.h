#import "sybase_sup.h"

@class SUPClassMetaData;

@protocol SUPClassWithMetaData

- (SUPClassMetaData*)getClassMetaData;

@end

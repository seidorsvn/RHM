#import "sybase_sup.h"

#import "SUPPackageMetaData.h"

@class SUPStringList;

@class SUPPackageMetaData;

@class SUPDatabaseMetaData;

@interface SUPDatabaseMetaData : SUPPackageMetaData
{
    SUPString _databaseName;
    SUPString _databaseFile;
    SUPStringList* _publications;
}

+ (SUPDatabaseMetaData*)getInstance;
- (SUPDatabaseMetaData*)init;
@property(readwrite, copy, nonatomic) SUPString databaseName;
@property(readwrite, copy, nonatomic) SUPString databaseFile;
@property(readwrite, retain, nonatomic) SUPStringList* publications;
/*
- (SUPDatabaseMetaData*)finishInit;
- (void)initFields;
+ (void)initialize;
 */
- (void)dealloc;

@end

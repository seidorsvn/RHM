#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPClassMap;
@class SUPClassMetaData;
@class SUPEntityMap;
@class SUPEntityMetaData;
@class SUPNoSuchClassException;
@class SUPServiceMap;
@class SUPServiceMetaData;

#import "SUPClassMetaData.h"

@class SUPPackageMetaData;

@interface SUPPackageMetaData : SUPClassMetaData
{
    SUPObjectList* _classList;
    SUPObjectList* _entityList;
    SUPObjectList* _serviceList;
    SUPClassMap* _classMap;
    SUPEntityMap* _entityMap;
    SUPServiceMap* _serviceMap;
}

+ (SUPPackageMetaData*)getInstance;
- (SUPPackageMetaData*)init;

@property(readwrite, retain, nonatomic) SUPObjectList* classList;
@property(readwrite, retain, nonatomic) SUPObjectList* entityList;
@property(readwrite, retain, nonatomic) SUPObjectList* serviceList;
@property(readwrite, retain, nonatomic) SUPClassMap* classMap;
@property(readwrite, retain, nonatomic) SUPEntityMap* entityMap;
@property(readwrite, retain, nonatomic) SUPServiceMap* serviceMap;

- (SUPClassMetaData*)getClass:(SUPString)className;
- (SUPEntityMetaData*)getEntity:(SUPString)className;
- (SUPServiceMetaData*)getService:(SUPString)className;
- (void)dealloc;
- (SUPPackageMetaData*)finishInit;
@end

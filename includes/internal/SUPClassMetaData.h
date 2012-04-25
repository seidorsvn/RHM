#import "sybase_sup.h"

@class SUPObjectList;
@class SUPAttributeMap;
@class SUPAttributeMetaData;
@class SUPNoSuchAttributeException;
@class SUPNoSuchOperationException;
@class SUPOperationMap;
@class SUPOperationMetaData;

@class SUPClassMetaData;

@interface SUPClassMetaData : NSObject
{
    SUPInt _id;
    SUPString _name;
    SUPObjectList* _attributes;
    SUPObjectList* _operations;
    SUPAttributeMap* _attributeMap;
    SUPOperationMap* _operationMap;
	Class _class;
}

+ (SUPClassMetaData*)getInstance;
- (SUPClassMetaData*)init;
@property(readwrite, assign, nonatomic) SUPInt id;
@property(readwrite, copy, nonatomic) SUPString name;
- (Class)getClass;
- (void)setClass:(Class)aClass;
@property(readwrite, retain, nonatomic) SUPObjectList* attributes;
@property(readwrite, retain, nonatomic) SUPObjectList* operations;
@property(readwrite, retain, nonatomic) SUPAttributeMap* attributeMap;
@property(readwrite, retain, nonatomic) SUPOperationMap* operationMap;
- (SUPBoolean)isEntity;
- (SUPBoolean)isService;
- (SUPAttributeMetaData*)getAttribute:(SUPString)name;
- (SUPOperationMetaData*)getOperation:(SUPString)name;
- (SUPClassMetaData*)finishInit;
- (void)initFields;
- (void)dealloc;

@end

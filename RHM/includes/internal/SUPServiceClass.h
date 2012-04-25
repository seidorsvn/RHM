#import "sybase_sup.h"

@class SUPObjectList;
@class SUPAttributeMetaData;
@class SUPOperationMetaData;
@class SUPServiceMetaData;

@protocol SUPObjectManager;

@class SUPServiceClass;

@interface SUPServiceClass : NSObject
{
    SUPServiceMetaData* field_classMetaData;
    id<SUPObjectManager> field_objectManager;
}

+ (SUPServiceClass*)newInstance;
- (SUPServiceClass*)init;
- (SUPServiceMetaData*)classMetaData;
- (void)setClassMetaData:(SUPServiceMetaData*)_classMetaData;
@property(readwrite, retain) SUPServiceMetaData* classMetaData;
- (id<SUPObjectManager>)objectManager;
- (void)setObjectManager:(id<SUPObjectManager>)_objectManager;
@property(readwrite, retain) id<SUPObjectManager> objectManager;
+ (SUPServiceClass*)getInstance:(SUPServiceMetaData*)md:(id<SUPObjectManager>)om;
- (id)newObject;
- (id)getValue:(id)service:(SUPAttributeMetaData*)attribute;
- (void)setValue:(id)service:(SUPAttributeMetaData*)attribute:(id)value;
- (id)invoke:(id)service:(SUPOperationMetaData*)operation:(SUPObjectList*)parameters;
- (void)dealloc;

@end

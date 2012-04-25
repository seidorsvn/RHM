#import "sybase_sup.h"

@class SUPObjectList;
@class SUPAttributeMetaData;
@class SUPClassMetaData;
@class SUPOperationMetaData;

@protocol SUPObjectManager

- (id)newObject:(SUPClassMetaData*)_theClass_1;
- (id)getValue:(id)_theObject_1:(SUPAttributeMetaData*)_attribute_2;
- (void)setValue:(id)_theObject_1:(SUPAttributeMetaData*)_attribute_2:(id)_value_3;
- (id)invoke:(id)_theObject_1:(SUPOperationMetaData*)_operation_2:(SUPObjectList*)_parameters_3;

@end

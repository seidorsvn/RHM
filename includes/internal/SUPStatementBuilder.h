#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPStringUtil;
@class SUPAttributeMetaData;
@class SUPAttributeSort;
@class SUPAttributeTest;
@class SUPCompositeTest;
@class SUPDataType;
@class SUPDataValue;
@class SUPDatabaseMetaData;
@class SUPEntityMetaData;
@class SUPJoinCondition;
@class SUPPersistenceException;
@class SUPQuery;
@class SUPSelectItem;
@class SUPSortOrder;
@class SUPTestCriteria;

@protocol SUPConnectionWrapper;
@protocol SUPStatementWrapper;

@class SUPStatementBuilder;

#define HASLOGRECORD_SYNTHETIC_ATTRIBUTE @"hasLogRecords"

@interface SUPStatementBuilder : NSObject
{
}

+ (id<SUPStatementWrapper>)prepareQuery:(id<SUPConnectionWrapper>)connection:(SUPDatabaseMetaData*)database:(SUPEntityMetaData*)entity:(SUPQuery*)query;
+ (SUPEntityMetaData*)findEntity:(SUPDatabaseMetaData*)database:(SUPQuery*)query:(SUPString)alias;
+ (SUPTestCriteria*)match:(SUPEntityMetaData*)entity:(SUPString)attribute:(SUPString)testValue;
- (void)dealloc;

@end

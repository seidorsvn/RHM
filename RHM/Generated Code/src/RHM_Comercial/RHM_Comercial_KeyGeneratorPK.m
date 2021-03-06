/*
 Generated by Sybase Unwired Platform 
 Compiler version - 2.0.1.314
*/ 

#import "RHM_Comercial_KeyGeneratorPK.h"
#import "SUPJsonObject.h"

@implementation RHM_Comercial_KeyGeneratorPK

@synthesize remoteId = _remoteId;
@synthesize batchId = _batchId;

- (id)initFromJson:(SUPJsonObject*)json:(int32_t)flags
{
    if (json == nil)
    {
        [self release];
        return nil;
    }
    if ((self = [super init]))
    {
        [self readJson:json:flags];
    }
    return self;   
}

- (void)readJson:(SUPJsonObject*)json:(int32_t)flags
{
    self.remoteId = [json getString:@"remoteId"];
    self.batchId = [json getLong:@"batchId"];
}

- (SUPJsonObject*)json:(int32_t)flags
{
    SUPJsonObject *newJson = [[SUPJsonObject alloc] init];
	[newJson setString:@"remoteId":self.remoteId];
	[newJson setLong:@"batchId":self.batchId];
    [newJson autorelease];
    return newJson;
}
+ (SUPObjectList*)fromJSONList:(SUPJsonArray*)jsonArray
{
	if(jsonArray == nil)
		return nil;
	
	SUPObjectList* instanceList = [[SUPObjectList alloc] initWithCapacity:1];
	if(instanceList == nil)
		return nil;

	for (SUPJsonObject* jsonObject in jsonArray)
	{
	    RHM_Comercial_KeyGeneratorPK* inst = [[RHM_Comercial_KeyGeneratorPK alloc] initFromJson:jsonObject:0];
	    [instanceList add:inst];
	    [inst release];
	}
	return instanceList;
}

+ (SUPJsonArray*)toJSONList:(SUPObjectList*)instanceList
{
	SUPJsonArray* jsonArray = [[SUPJsonArray alloc] init];
	[jsonArray autorelease];
	for (RHM_Comercial_KeyGeneratorPK* inst in instanceList)
	{
		[jsonArray add:[inst json:0]];
	}
	return jsonArray;
}
- (void)dealloc
{
    if(_remoteId)
    {
        [_remoteId release];
        _remoteId = nil;
    }
	[super dealloc];
}

static SUPClassMetaData* RHM_Comercial_KeyGeneratorPK_META_DATA;
static BOOL _valid_ = NO;

+ (SUPClassMetaData*)metaData
{
    if (! (_valid_))
    {
 	   	RHM_Comercial_KeyGeneratorPK_META_DATA = [[SUPEntityMetaData alloc] init];
 	   	SUPObjectList *attributes = [SUPObjectList listWithCapacity:7];
       	RHM_Comercial_KeyGeneratorPK_META_DATA.name = @"KeyGeneratorPK";
       	[RHM_Comercial_KeyGeneratorPK_META_DATA setClass:[RHM_Comercial_KeyGeneratorPK class]];
 
        	// Handle attributes
 		int attribute_counter = 0;
 
 		attribute_counter++;
		SUPAttributeMetaData_DC* a_remoteId = [RHM_Comercial_RHM_ComercialDB createAttributeMetaData:attribute_counter:(SUPString)@"remoteId":[SUPDataType forName:@"string"]];
  		[attributes addThis:a_remoteId];
 
 		attribute_counter++;
		SUPAttributeMetaData_DC* a_batchId = [RHM_Comercial_RHM_ComercialDB createAttributeMetaData:attribute_counter:(SUPString)@"batchId":[SUPDataType forName:@"long"]];
  		[attributes addThis:a_batchId];
 		RHM_Comercial_KeyGeneratorPK_META_DATA.attributes = attributes;
 		
 		SUPAttributeMap * attributeMap = [SUPAttributeMap getInstance];
    	[attributeMap setAttributes:attributes];
    	RHM_Comercial_KeyGeneratorPK_META_DATA.attributeMap = [attributeMap finishInit];
  
  		// Handle operations
 		int operation_counter = 0;	
 
  		SUPObjectList *operations = [SUPObjectList listWithCapacity:operation_counter];
 		RHM_Comercial_KeyGeneratorPK_META_DATA.operations = operations;
 		
		SUPOperationMap *operationMap = [SUPOperationMap getInstance];
		[operationMap setOperations:operations];
		RHM_Comercial_KeyGeneratorPK_META_DATA.operationMap = [operationMap finishInit];
	
     	_valid_ = YES;
	}
	return RHM_Comercial_KeyGeneratorPK_META_DATA;
}

+ (RHM_Comercial_KeyGeneratorPK*)getInstance
{
    RHM_Comercial_KeyGeneratorPK* me = [[RHM_Comercial_KeyGeneratorPK alloc] init];
    [me autorelease];
    return me;
}

@end
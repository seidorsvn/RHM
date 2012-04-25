// Copyright (c) 2009, Sybase Inc.

#import "sybase_sup.h"

@class SUPArrayList;

@interface SUPBinaryUtil : NSObject

+ (SUPBinary)emptyBinary;

+ (SUPBinary)getBinary:(SUPNullableBinary)b;
+ (SUPBinary)getBinary_s:(SUPString)s;

+ (SUPNullableBinary)getNullableBinary:(SUPBinary)b;
+ (SUPNullableBinary)getNullableBinary_s:(SUPString)s;

// + (SUPBinary)getBinaryWithBytes:(SUPArrayList*)bytes;

+ (SUPBoolean)equal:(SUPBinary)a:(SUPBinary)b;
+ (SUPBoolean)notEqual:(SUPBinary)a:(SUPBinary)b;

+ (SUPBinary)fromStringBase16:(SUPString)s;
+ (SUPString)toStringBase16:(SUPBinary)b;

+ (SUPBinary)fromBytes:(SUPArrayList*)bytes;

@end

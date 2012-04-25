// Copyright (c) 2009, Sybase Inc.

#import "sybase_sup.h"

@interface SUPStringCache : NSObject
{
}

+ (SUPString)fromChar:(SUPChar)c;
+ (SUPString)fromLong:(SUPLong)n;

@end

//
//  SUPLockUtil.h
//  clientrt
//
//  Created by Jane Yang on 10/14/09.
//  Copyright 2009 Sybase, Inc.. All rights reserved.
//

@interface SUPLockUtil : NSObject

+ (void)lock:(id)theLock;
+ (void)unlock:(id)theLock;

@end

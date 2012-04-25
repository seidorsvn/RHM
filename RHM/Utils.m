//
//  Utils.m
//  OrdesaFuerzaVentas
//
//  Created by sap on 11/20/11.
//  Copyright (c) 2011 Seidor Consulting. All rights reserved.
//

#import "Utils.h"
#import <CommonCrypto/CommonDigest.h>

@implementation Utils
@synthesize tiposVisita = _tiposVisitas;

+ (NSArray *)searchArray:(NSArray *)array clave:(NSString *)key campos:(NSArray*)campos
{
    NSMutableArray* res = [[NSMutableArray alloc] init];
	bool ok;
	NSString* field;
	
	for(NSDictionary* dic in array)
	{
		ok = false;
		
		for(NSString* campo in campos)
		{
			field = (NSString*)[dic objectForKey:campo];
			if([field rangeOfString:key].location != NSNotFound)
			{
				ok = true;
				break;
			}
		}
		
		if(ok) [res addObject:dic];
	}
	
	NSArray* ret = [[NSArray alloc] initWithArray:res];
	[res release];
	
	return ret;
}


+ (NSArray *)sort:(NSArray *)datos{
    NSArray *sortedArray = [datos sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
    return sortedArray;
}

+ (NSArray *)buildArrayToTable:(NSArray *)datos campo:(NSString *)campo{
    NSMutableArray *mutableArray = [[NSMutableArray alloc] init];
    
    for (int i=0; i<[datos count]; i++) {
        NSDictionary *dicti = [datos objectAtIndex:i];
        NSString *str = [dicti objectForKey:campo];
        
        [mutableArray addObject:str];
    }
    
    NSArray *array = [NSArray arrayWithArray:mutableArray];
    [mutableArray release];
    
    return array;
}

+ (NSString *)convertDateToString:(NSDate *)fecha{
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@"dd/MM/yyyy"];
    NSString *theDate = [dateFormat stringFromDate:fecha];
    [dateFormat release];
    
    return theDate;
}

+ (NSDate *)convertStringToDate:(NSString *)str{
	NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    //[dateFormatter setLocale:[[NSLocale alloc] initWithLocaleIdentifier:]];
    [dateFormatter setDateFormat:@"yyyy/MM/dd"];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
    
	NSDate *dateFromString = [[NSDate alloc] init];
	// voila!
	dateFromString = [dateFormatter dateFromString:str];
	[dateFormatter release];
    
    return dateFromString;
}

+ (NSDate *)getFechaActual{
    return [NSDate date];
}

+ (NSDate *)getFechaInicioMes{
    NSDate *today = [NSDate date];
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSGregorianCalendar];
    NSDateComponents *weekdayComponents = 
    [gregorian components:(NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit) fromDate:today];
    
    [gregorian release];
    
    NSInteger mont = [weekdayComponents month];
    NSInteger year = [weekdayComponents year];
    
    NSString *str = [NSString stringWithFormat:@"%i/%i/%i", 1, mont, year];
    
    NSDateFormatter *dateFormatter = [[[NSDateFormatter alloc] init] autorelease];
    
    [dateFormatter setDateFormat:@"dd/MM/yyyy"];
    [dateFormatter dateFromString:str];
    
    return [dateFormatter dateFromString:str];
}

+ (NSString *)stringToMD5:(NSString*)text
{
    const char *cStr = [text UTF8String];
    unsigned char result[16];
    CC_MD5( cStr, strlen(cStr), result ); // This is the md5 call
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3], 
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];  
}

+ (NSString*) getValorArray:(NSArray*)array key:(NSString*)key valor:(NSString*)valor{
	int i = 0;
	BOOL b = FALSE;
	NSString *n; 
	
	if ([valor isEqualToString:@""]) {
		n = @"";
	}else{
        
		while (i<[array count] && !b) {
			NSDictionary *dicti = (NSDictionary*)[array objectAtIndex:i];
			NSString *str = (NSString*)[dicti objectForKey:@"CODIGO"];
			NSString *desc = (NSString*)[dicti objectForKey:@"DESCRIPCION"];
			
			if ([str isEqualToString:valor]) {
				n = desc;
				b = TRUE;
			}
			i++;
		}
	}
	return n;
}

+ (NSArray *) sort:(NSArray *)datos byDictionaryField:(NSString*)field
{
	NSMutableDictionary* dic = [[NSMutableDictionary alloc] init];
	NSMutableArray* arr;
	
	for(NSDictionary* item in datos)
	{
		if([dic objectForKey:(NSString*)[item objectForKey:field]] == nil)
		{
			arr = [[NSMutableArray alloc] initWithObjects:item, nil];
			[dic setValue:arr forKey:(NSString*)[item objectForKey:field]];
			[arr release];
		}
		else
		{
			[(NSMutableArray*)[dic objectForKey:(NSString*)[item objectForKey:field]] addObject:item];
		}
	}
	
	NSArray* sortedKeys = [[self class] sort:[dic allKeys]];
	NSMutableArray *res = [[NSMutableArray alloc] init];
	
	for(NSString* key in sortedKeys)
	{
		[res addObjectsFromArray:(NSMutableArray*)[dic objectForKey:key]];
	}
	
	[dic release];
	
	NSArray* ret = [[NSArray alloc] initWithArray:res];
	[res release];
	
	return ret;
}

+ (bool)validarNif:(NSString *)nif
{
	nif = [nif uppercaseString];
	int dni = [[nif substringToIndex:[nif length]-1] intValue];
	unichar letra = [nif characterAtIndex:[nif length]-1];
	NSString* tabla = [[NSString alloc] initWithString:@"TRWAGMYFPDXBNJZSQVHLCKE"];
	unichar letraCalc = [tabla characterAtIndex:dni%23];
	[tabla release];
	return letra == letraCalc;
}

+ (bool)validarCuenta:(NSString *)cuenta
{
	int suma = 0;
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 6; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 3; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 7; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 9; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 10; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 5; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 8; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 4; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 2; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 1; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	int digito = [[cuenta substringFromIndex:[cuenta length]-2] intValue]; cuenta = [cuenta substringToIndex:[cuenta length]-2];
	int digitoCalc = 11 - (suma%11);
	if(digitoCalc == 10) digitoCalc = 1;
	else if(digitoCalc == 11) digitoCalc = 0;
	suma = 0;
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 6; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 3; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 7; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 9; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 10; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 5; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 8; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	suma += [[cuenta substringFromIndex:[cuenta length]-1] intValue] * 4; cuenta = [cuenta substringToIndex:[cuenta length]-1];
	int primerDig = 11 - (suma%11);
	if(primerDig == 10) primerDig = 1;
	else if(digitoCalc == 11) digitoCalc = 0;
	digitoCalc = primerDig*10 + digitoCalc;
	return digito == digitoCalc;
}

+ (NSString*)retrieveFromUserDefaults:(NSString*)key
{
	NSUserDefaults *standardUserDefaults = [NSUserDefaults standardUserDefaults];
	NSString *val = nil;
	
	if (standardUserDefaults) 
		val = [standardUserDefaults objectForKey:key];
	
	// TODO: / apparent Apple bug: if user hasn't opened Settings for this app yet (as if?!), then
	// the defaults haven't been copied in yet.  So do so here.  Adds another null check
	// for every retrieve, but should only trip the first time
	if (val == nil) { 
		NSLog(@"user defaults may not have been loaded from Settings.bundle ... doing that now ...");
		//Get the bundle path
		NSString *bPath = [[NSBundle mainBundle] bundlePath];
		NSString *settingsPath = [bPath stringByAppendingPathComponent:@"Settings.bundle"];
		NSString *plistFile = [settingsPath stringByAppendingPathComponent:@"Root.plist"];
		
		//Get the Preferences Array from the dictionary
		NSDictionary *settingsDictionary = [NSDictionary dictionaryWithContentsOfFile:plistFile];
		NSArray *preferencesArray = [settingsDictionary objectForKey:@"PreferenceSpecifiers"];
		
		//Loop through the array
		NSDictionary *item;
		for(item in preferencesArray)
		{
			//Get the key of the item.
			NSString *keyValue = [item objectForKey:@"Key"];
			
			//Get the default value specified in the plist file.
			id defaultValue = [item objectForKey:@"DefaultValue"];
			
			if (keyValue && defaultValue) {				
				[standardUserDefaults setObject:defaultValue forKey:keyValue];
				if ([keyValue compare:key] == NSOrderedSame)
					val = defaultValue;
			}
		}
		[standardUserDefaults synchronize];
	}
	return val;
}

+ (NSDictionary*) convertPlistStringToDictionary:(NSString*)strPlist
{
	NSDictionary* plist = nil;
	NSString *error;
	
	@try {
		NSData *plistData = [strPlist dataUsingEncoding:NSUTF8StringEncoding];
		NSPropertyListFormat format;
		plist = [NSPropertyListSerialization propertyListFromData:plistData mutabilityOption:NSPropertyListImmutable format:&format errorDescription:&error];
		NSLog( @"plist is %@", plist );
	}
	@catch (NSException *exception) {
		plist = nil;
	}
	
	if(plist == nil || [plist count]==0){
        NSLog(@"Error: %@",error);
        [error release];
	}
	
	return plist;
}

+ (NSDictionary*) getDictionaryArray:(NSArray*)array campo:(NSString*)campo valor:(NSString*)valor{
	int i = 0;
	BOOL b = FALSE;
	NSDictionary *d; 
	
	if ([valor isEqualToString:@""]) {
		d = nil;
	}else{
		
		while (i<[array count] && !b) {
			NSDictionary *dicti = (NSDictionary*)[array objectAtIndex:i];
			NSString *str = (NSString*)[dicti objectForKey:campo];
			
			if ([str isEqualToString:valor]) {
				d = dicti;
				b = TRUE;
			}
			i++;
		}
	}
	return d;
}

void fixLineBreakMode(UIView *view)
{
    if ([view respondsToSelector:@selector(setLineBreakMode:)]) {
        CGRect rMargenes = CGRectInset([view.superview bounds], 6, 0);
        if (view.frame.size.width>rMargenes.size.width) {
            [(id)view setLineBreakMode:UILineBreakModeTailTruncation];
            [view setFrame:rMargenes];
        }
    } else {
        for (UIView *subview in view.subviews)
            fixLineBreakMode(subview);
    }
}

+ (NSDate*) dateFromComponents:(NSString*)year month:(NSString*)month day:(NSString*)day
{
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *fechaComps = [[NSDateComponents alloc] init];
    NSDate *fecha = nil;
    NSTimeZone* destinationTimeZone = [NSTimeZone systemTimeZone];
    NSInteger destinationGMTOffset;
    [fechaComps setYear:[year intValue]];
    [fechaComps setMonth:[month intValue]];
    [fechaComps setDay:[day intValue]];
    fecha = [calendar dateFromComponents:fechaComps];
    destinationGMTOffset = [destinationTimeZone secondsFromGMTForDate:fecha];
    fecha = [[[NSDate alloc] initWithTimeInterval:destinationGMTOffset sinceDate:fecha] autorelease];
    return fecha;
}

+ (NSDate *)correctDateTimeZone:(NSDate *)date
{
	NSCalendar *calendar = [NSCalendar currentCalendar];
	NSInteger comps = (NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit);
	NSDateComponents *fechaComps = nil;
	NSDate *fecha = nil;
	
	NSTimeZone* destinationTimeZone = [NSTimeZone systemTimeZone];
	NSInteger destinationGMTOffset;
	
	fechaComps = [calendar components:comps fromDate:date];
	fecha = [calendar dateFromComponents:fechaComps];
	destinationGMTOffset = [destinationTimeZone secondsFromGMTForDate:fecha];
	fecha = [[[NSDate alloc] initWithTimeInterval:destinationGMTOffset sinceDate:fecha] autorelease];
	
	return fecha;
}

@end

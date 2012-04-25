//
//  Utils.h
//  OrdesaFuerzaVentas
//
//  Created by sap on 11/20/11.
//  Copyright (c) 2011 Seidor Consulting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Utils : NSObject{
    NSArray *_tiposVisita;
}

@property (nonatomic, retain) NSArray *tiposVisita;

+ (NSArray *)searchArray:(NSArray *)array clave:(NSString *)key campos:(NSArray*)campos;
+ (NSArray *) sort:(NSArray *)datos;
+ (NSArray *) sort:(NSArray *)datos byDictionaryField:(NSString*)field;
+ (NSArray *) buildArrayToTable:(NSArray *)datos campo:(NSString *)campo;
+ (NSString *) convertDateToString:(NSDate *)fecha;
+ (NSDate *) convertStringToDate:(NSString *)str;
+ (NSDate *) getFechaActual;
+ (NSDate *) getFechaInicioMes;
+ (NSString *)stringToMD5:(NSString*)text;
+ (NSString*) getValorArray:(NSArray*)array key:(NSString*)key valor:(NSString*)valor;
+ (NSDictionary*) getDictionaryArray:(NSArray*)array campo:(NSString*)campo valor:(NSString*)valor;
+ (bool)validarNif:(NSString *)nif;
+ (bool)validarCuenta:(NSString *)cuenta;
+ (NSString*)retrieveFromUserDefaults:(NSString*)key;
+ (NSDictionary*) convertPlistStringToDictionary:(NSString*)strPlist;
void fixLineBreakMode(UIView *view);
+ (NSDate*) dateFromComponents:(NSString*)year month:(NSString*)month day:(NSString*)day;
+ (NSDate*) correctDateTimeZone:(NSDate*)date;

@end

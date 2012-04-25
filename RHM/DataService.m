//
//  DataService.m
//  OrdesaFuerzaVentas
//
//  Created by Apple1 Seidor on 11/23/11.
//  Copyright (c) 2011 Seidor Consulting. All rights reserved.
//

#import "DataService.h"
#import "RHM_Comercial_Articulos.h"
#import "RHM_Comercial_TS_ALMACENES.h"
#import "RHM_Comercial_TS_AMBITO.h"
#import "RHM_Comercial_TS_ART_BIC.h"
#import "RHM_Comercial_TS_ART_CONTENIDO.h"
#import "RHM_Comercial_TS_ART_STOCK.h"
#import "RHM_Comercial_TS_ART_TEXTOS.h"
#import "RHM_Comercial_TS_BIC.h"
#import "RHM_Comercial_TS_CATSMOV.h"
#import "RHM_Comercial_TS_CENTROS.h"
#import "RHM_Comercial_TS_CLI_MAT.h"
#import "RHM_Comercial_TS_COLECCION.h"
#import "RHM_Comercial_TS_DIVEDI.h"
#import "RHM_Comercial_TS_ESTADO.h"
#import "RHM_Comercial_TS_FORMATO.h"
#import "RHM_Comercial_TS_IDIOMAS.h"
#import "RHM_Comercial_TS_LINEAS.h"
#import "RHM_Comercial_TS_MANUSCRITOS.h"
#import "RHM_Comercial_TS_NEGOCIO.h"
#import "RHM_Comercial_TS_ORG.h"
#import "RHM_Comercial_TS_PAISES.h"
#import "RHM_Comercial_TS_PERSONAJE.h"
#import "RHM_Comercial_TS_SELLOS.h"
#import "RHM_Comercial_TS_TEMATICA.h"
#import "RHM_Comercial_TS_TIPENC.h"
#import "RHM_Comercial_TS_TIPOMAT.h"
#import "RHM_Comercial_TS_TIPOTAPA.h"
#import "RHM_Comercial_TS_EDADES.h"

#import "RHM_Comercial_Autores.h"
#import "RHM_Comercial_TS_AUTOR_CONTENIDO.h"

#import "RHM_Comercial_Agentes.h"

#import "RHM_Comercial_Clientes.h"


@implementation DataService

//#pragma mark - static variables
//
//static NSString *loggedUser;

#pragma mark - Synthesize statements

@synthesize loggedUser = _loggedUser;

@synthesize articulos = _articulos;
@synthesize articulosDic = _articulosDic;
@synthesize artsBICDic = _artsBICDic;
@synthesize autores = _autores;
@synthesize manuscritos = _manuscritos;
@synthesize clientes = _clientes;
@synthesize artsClientsDic = _artsClientsDic;
@synthesize autoresDic = _autoresDic;
@synthesize clientesDic = _clientesDic;

#pragma mark - init

- (id)init
{
	if (self = [super init])
	{
		[[NSNotificationCenter defaultCenter] addObserver:self
												 selector:@selector(reiniciarCaches)
													 name:@"importFinished"
												   object:nil];
		
	}
	
	return self;
}

#pragma mark - Articulos

- (NSArray*) getArticulos
{	
	if([self articulos]==nil)
	{
		RHM_Comercial_ArticulosList *arts = [RHM_Comercial_Articulos findAll];
		
		NSDictionary *tmpDic;
		NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[arts length]];
		NSString* BICs = nil;
		NSString* boletin = nil;
		NSDate* fDisp = nil;
		NSString* str = nil;
		NSString* clients = nil;
		NSString* novedad = nil;
		NSDate* aYearAgo = [Utils correctDateTimeZone:[NSDate dateWithTimeIntervalSinceNow:-31536000]];
		
		//Variables para el diccionario
		NSMutableArray *tmpArray = nil;
		NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
		
		//Recorremos la lista
		
		for(RHM_Comercial_Articulos *art in arts)
		{
			//Comprobamos que no sea un boletin
			
			if([art valueForKey:@"BOLETIN"]==nil || [(NSString*)[art valueForKey:@"BOLETIN"] length]==0)
			{
				//Calculamos el campo Boletin para que no sea nil
				if([art valueForKey:@"BOLETIN"]==nil) boletin = @"";
				else boletin = [art valueForKey:@"BOLETIN"];
				
				//Calculamos el campo BICs
				BICs = [self getArtBIC:(NSString*)[art valueForKey:@"MATNR"]];
				clients = [self getArtClients:(NSString*)[art valueForKey:@"MATNR"]];
				
				//Montamos la fechaDisp como un NSDate
				str = (NSString*)[art valueForKey:@"FECHADISP"];
				
				if(str!=nil && [str length]==6)
				{
					fDisp = [Utils dateFromComponents:[str substringToIndex:4] 
												month:[[str substringFromIndex:4] substringToIndex:2] 
												  day:[[str substringFromIndex:6] substringToIndex:2]];
				}
				else 
				{
					fDisp = [[NSDate alloc] init];
				}
				
				//Calculamos si el artículo es una novedad
				if([(NSDate*)[art valueForKey:@"ZZNOVEDAD"] compare:aYearAgo] != NSOrderedAscending)
					novedad = @"X";
				else novedad = @"";
				
				//Montamos el diccionario de artículo
				
				tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
						  [art valueForKey:@"BUKRS"], @"BUKRS",
						  [art valueForKey:@"MATNR"], @"MATNR",
						  boletin, @"BOLETIN",
						  [art valueForKey:@"MAKTX"], @"MAKTX",
						  [art valueForKey:@"ZZTITMANUS"], @"ZZTITMANUS",
						  [art valueForKey:@"ZZTITULO"], @"ZZTITULO",
						  [art valueForKey:@"ZZSUBTIT"], @"ZZSUBTIT",
						  [art valueForKey:@"ZZDADVE"], @"ZZDADVE",
						  [art valueForKey:@"ZZSELLO"], @"ZZSELLO",
						  [art valueForKey:@"ZZLINEA"], @"ZZLINEA",
						  [art valueForKey:@"ZZCOLECCION"], @"ZZCOLECCION",
						  [art valueForKey:@"ZZCODNEG"], @"ZZCODNEG",
						  [art valueForKey:@"ZZDACED"], @"ZZDACED",
						  [art valueForKey:@"ZZNAJE"], @"ZZNAJE",
						  [art valueForKey:@"ZZDATGE"], @"ZZDATGE",
						  [art valueForKey:@"ZZFECHAV"], @"ZZFECHAV",
						  (NSDate*)[art valueForKey:@"ZZNOVEDAD"], @"ZZNOVEDAD",
						  novedad, @"ES_NOVEDAD",
						  [art valueForKey:@"ZZCODTEM"], @"ZZCODTEM",
						  [art valueForKey:@"MTART"], @"MTART",
						  [art valueForKey:@"EAN11"], @"EAN11",
						  [art valueForKey:@"ZZARTCAT"], @"ZZARTCAT",
						  [art valueForKey:@"ESTADO_RHM"], @"ESTADO_RHM",
						  fDisp, @"FECHADISP",
						  [art valueForKey:@"ZZCGMAN"], @"ZZCGMAN",
						  [art valueForKey:@"ZZCODAUTC"], @"ZZCODAUTC",
						  [art valueForKey:@"ZZCIVAVIG"], @"ZZCIVAVIG",
						  [art valueForKey:@"ZZSIVAVIG"], @"ZZSIVAVIG",
						  [art valueForKey:@"EDICION"], @"EDICION",
						  [art valueForKey:@"TIRAJE_STD"], @"TIRAJE_STD",
						  [art valueForKey:@"AMBITO"], @"AMBITO",
						  [art valueForKey:@"ZZIDIOPU"], @"ZZIDIOPU",
						  [art valueForKey:@"ZZIDIOOR"], @"ZZIDIOOR",
						  [art valueForKey:@"ZZCATMOV"], @"ZZCATMOV",
						  [art valueForKey:@"PRVRE"], @"PRVRE",
						  [art valueForKey:@"ZZTIPOTAPA"], @"ZZTIPOTAPA",
						  [art valueForKey:@"ZZTIPENC"], @"ZZTIPENC",
						  [art valueForKey:@"ZZFORMATO"], @"ZZFORMATO",
						  [art valueForKey:@"ZZPAGS"], @"ZZPAGS",
						  [art valueForKey:@"LAENG"], @"LAENG",
						  [art valueForKey:@"BREIT"], @"BREIT",
						  [art valueForKey:@"ZZARTCOL"], @"ZZARTCOL",
						  [art valueForKey:@"ZZARTBIB"], @"ZZARTBIB",
						  [art valueForKey:@"WAERS"], @"WAERS",
						  [art valueForKey:@"MEABM"], @"MEABM",
						  [art valueForKey:@"IHIVI"], @"IHIVI",
						  BICs, @"CODBIC",
						  clients, @"KUNNR",
						  nil];	
				
				[array addObject:tmpDic];
				
				//Lo añadimos también al Diccionario de artículos
				if([dic objectForKey:(NSString*)[art valueForKey:@"MATNR"]]==nil)
				{
					tmpArray = [[NSMutableArray alloc] initWithObjects:tmpDic, nil];			
					[dic setValue:tmpArray forKey:(NSString*)[art valueForKey:@"MATNR"]];
				}
				else 
				{
					[(NSMutableArray*)[dic objectForKey:(NSString*)[art valueForKey:@"MATNR"]] addObject:tmpDic];
				}
			}
		}
		
		[self setArticulos:[[NSArray alloc] initWithArray:array]];
		[self setArticulosDic:dic];
	}
	
	return [self articulos];
}

- (NSDictionary*) getArticuloByCode:(NSString*)matnr
{	
	return [[self articulosDic] objectForKey:matnr];
}

- (NSArray*) getTitulos
{
	NSArray* arts = [self getArticulos];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[arts count]];
	NSString* tit = nil;
	
	for(NSDictionary *art in arts)
	{
		tit = (NSString*)[art valueForKey:@"ZZTITULO"];
		
		if(tit!=nil && [tit length]>0)
		{
			tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
					  [art valueForKey:@"ZZTITULO"], @"ZZTITULO",
					  nil];	
			
			[array addObject:tmpDic];
		}
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getCodigos
{
	NSArray* arts = [self getArticulos];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[arts count]];
	
	for(RHM_Comercial_Articulos *art in arts)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [art valueForKey:@"MATNR"], @"MATNR",
				  nil];	
		
		[array addObject:tmpDic];
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getAlmacenes
{
	RHM_Comercial_TS_ALMACENESList *list = [RHM_Comercial_TS_ALMACENES findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_ALMACENES *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"WERKS"], @"WERKS",
				  [item valueForKey:@"LGORT"], @"LGORT",
				  [item valueForKey:@"LGOBE"], @"LGOBE",
				  nil];
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getAmbitos
{
	RHM_Comercial_TS_AMBITOList *list = [RHM_Comercial_TS_AMBITO findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_AMBITO *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"AMBITO"], @"AMBITO",
				  [item valueForKey:@"AMBITTXT"], @"AMBITTXT",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSString*) getArtBIC:(NSString*)matnr
{
	NSMutableDictionary* artsBIC = [self getArtsBICDic];
	NSArray *list = [artsBIC valueForKey:matnr];
	
	NSString* BICs = @"";
	
	for(NSDictionary *item in list)
		BICs = [NSString stringWithFormat:@"%@%@%@",BICs,(NSString*)[item valueForKey:@"CODBIC"],@";"];
	
	return BICs;
}

- (NSMutableDictionary*) getArtsBICDic
{
	if([self artsBICDic]==nil)
	{
		RHM_Comercial_TS_ART_BICList *list = [RHM_Comercial_TS_ART_BIC findAll];
		
		NSMutableArray *tmpArray = nil;
		NSDictionary *tmpDic = nil;
		NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
		
		for(RHM_Comercial_TS_ART_BIC *item in list)
		{
			tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
					  [item valueForKey:@"BUKRS"], @"BUKRS",
					  [item valueForKey:@"MATNR"], @"MATNR",
					  [item valueForKey:@"CODBIC"], @"CODBIC",
					  nil];	
			
			if([dic objectForKey:(NSString*)[item valueForKey:@"MATNR"]]==nil)
			{
				tmpArray = [[NSMutableArray alloc] initWithObjects:tmpDic, nil];			
				[dic setValue:tmpArray forKey:(NSString*)[item valueForKey:@"MATNR"]];
			}
			else 
			{
				[(NSMutableArray*)[dic objectForKey:(NSString*)[item valueForKey:@"MATNR"]] addObject:tmpDic];
			}	
		}
		
		[self setArtsBICDic:dic];
	}
	
	return [self artsBICDic];
}

- (NSArray*) getArtContenido
{
	RHM_Comercial_TS_ART_CONTENIDOList *list = [RHM_Comercial_TS_ART_CONTENIDO findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_ART_CONTENIDO *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"MATNR"], @"MATNR",
				  [item valueForKey:@"ZDAM_UOID"], @"ZDAM_UOID",
				  [item valueForKey:@"ZDAM_TIPO"], @"ZDAM_TIPO",
				  [item valueForKey:@"SDOK_CT128"], @"SDOK_CT128",
				  [item valueForKey:@"ZDAM_TAMA"], @"ZDAM_TAMA",
				  [item valueForKey:@"ZDAM_NOMBRE"], @"ZDAM_NOMBRE",
				  [item valueForKey:@"ZDAM_DESCRIPCION"], @"ZDAM_DESCRIPCION",
				  [item valueForKey:@"ZDAM_DESC_SUP"], @"ZDAM_DESC_SUP",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getArtStock
{
	RHM_Comercial_TS_ART_STOCKList *list = [RHM_Comercial_TS_ART_STOCK findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_ART_STOCK *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"MATNR"], @"MATNR",
				  [item valueForKey:@"WERKS"], @"WERKS",
				  [item valueForKey:@"LGORT"], @"LGORT",
				  [item valueForKey:@"FISICO"], @"FISICO",
				  [item valueForKey:@"DISPONIBLE"], @"DISPONIBLE",
				  [item valueForKey:@"PENDIENTE"], @"PENDIENTE",
				  [item valueForKey:@"BLOQUEADO"], @"BLOQUEADO",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getArtTexto
{
	RHM_Comercial_TS_ART_TEXTOSList *list = [RHM_Comercial_TS_ART_TEXTOS findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_ART_TEXTOS *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"MATNR"], @"MATNR",
				  [item valueForKey:@"TIPO"], @"TIPO",
				  [item valueForKey:@"TEXTO"], @"TEXTO",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getBICs
{
	RHM_Comercial_TS_BICList *list = [RHM_Comercial_TS_BIC findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_BIC *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"CODBIC"], @"CODBIC",
				  [item valueForKey:@"MATERIA"], @"MATERIA",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getCatsMov
{
	RHM_Comercial_TS_CATSMOVList *list = [RHM_Comercial_TS_CATSMOV findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_CATSMOV *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"CATEGORIA"], @"CATEGORIA",
				  [item valueForKey:@"DESCR"], @"DESCR",
				  nil];	

		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getCentros
{
	RHM_Comercial_TS_CENTROSList *list = [RHM_Comercial_TS_CENTROS findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_CENTROS *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"WERKS"], @"WERKS",
				  [item valueForKey:@"NAME1"], @"NAME1",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getColecciones
{
	RHM_Comercial_TS_COLECCIONList *list = [RHM_Comercial_TS_COLECCION findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_COLECCION *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZCODCOLEC"], @"ZCODCOLEC",
				  [item valueForKey:@"ZDESCR"], @"ZDESCR",
				  [item valueForKey:@"ZDESCBR"], @"ZDESCBR",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSDictionary *)getColeccionByCode:(NSString *)zzcodcolec
{
	NSArray* colecciones = [self getColecciones];
	NSDictionary* coleccion = nil;
	
	NSPredicate *predicate = [NSPredicate alloc];
	predicate = [NSPredicate predicateWithFormat:@"ZZTIPOTAPA == %@", zzcodcolec];
	
	NSArray *array = [colecciones filteredArrayUsingPredicate:predicate];
	if([array count]>0) coleccion = [array objectAtIndex:0];
	
	return coleccion;
}

- (NSArray*) getDivisionesEditorial
{
	RHM_Comercial_TS_DIVEDIList *list = [RHM_Comercial_TS_DIVEDI findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_DIVEDI *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZZDADVE"], @"ZZDADVE",
				  [item valueForKey:@"ZZDADVET"], @"ZZDADVET",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getEstados
{
	RHM_Comercial_TS_ESTADOList *list = [RHM_Comercial_TS_ESTADO findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_ESTADO *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ESTADO_RHM"], @"ESTADO_RHM",
				  [item valueForKey:@"DESCR"], @"DESCR",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getFormatos
{
	RHM_Comercial_TS_FORMATOList *list = [RHM_Comercial_TS_FORMATO findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_FORMATO *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZZFORMATO"], @"ZZFORMATO",
				  [item valueForKey:@"ZDESC_FORM"], @"ZDESC_FORM",
				  nil];	
		
		[array addObject:tmpDic];
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getIdiomas
{
	RHM_Comercial_TS_IDIOMASList *list = [RHM_Comercial_TS_IDIOMAS findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_IDIOMAS *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"SPRAS"], @"SPRAS",
				  [item valueForKey:@"SPRSL"], @"SPRSL",
				  [item valueForKey:@"SPTXT"], @"SPTXT",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getLineas
{
	RHM_Comercial_TS_LINEASList *list = [RHM_Comercial_TS_LINEAS findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_LINEAS *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZCODLINEA"], @"ZCODLINEA",
				  [item valueForKey:@"ZDESCR"], @"ZDESCR",
				  [item valueForKey:@"ZDESCBR"], @"ZDESCBR",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getManuscritos
{
	if([self manuscritos]==nil)
	{
		RHM_Comercial_TS_MANUSCRITOSList *list = [RHM_Comercial_TS_MANUSCRITOS findAll];
		
		NSDictionary *tmpDic = nil;
		NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
		
		for(RHM_Comercial_TS_MANUSCRITOS *item in list)
		{
			tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
					  [item valueForKey:@"BUKRS"], @"BUKRS",
					  [item valueForKey:@"ZZCGMAN"], @"ZZCGMAN",
					  [item valueForKey:@"MATNR"], @"MATNR",
					  nil];	
			
			[array addObject:tmpDic];		
		}
		
		[self setManuscritos:[[NSArray alloc] initWithArray:array]];
	}
	
	return [self manuscritos];
}

- (NSArray*) getNegocios
{
	RHM_Comercial_TS_NEGOCIOList *list = [RHM_Comercial_TS_NEGOCIO findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_NEGOCIO *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZCODNEG"], @"ZCODNEG",
				  [item valueForKey:@"ZDESCR"], @"ZDESCR",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getPersonajes
{
	RHM_Comercial_TS_PERSONAJEList *list = [RHM_Comercial_TS_PERSONAJE findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_PERSONAJE *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZNAJE"], @"ZNAJE",
				  [item valueForKey:@"ZDESNAJE"], @"ZDESNAJE",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getSellos
{
	RHM_Comercial_TS_SELLOSList *list = [RHM_Comercial_TS_SELLOS findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_SELLOS *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZCODSELLO"], @"ZCODSELLO",
				  [item valueForKey:@"ZDESCR"], @"ZDESCR",
				  [item valueForKey:@"ZDESCBR"], @"ZDESCBR",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSDictionary *)getSelloByCode:(NSString *)zcodsello
{
	NSArray* sellos = [self getSellos];
	NSDictionary* sello = nil;
	
	NSPredicate *predicate = [NSPredicate alloc];
	predicate = [NSPredicate predicateWithFormat:@"ZCODSELLO == %@", zcodsello];
	
	NSArray *array = [sellos filteredArrayUsingPredicate:predicate];
	if([array count]>0) sello = [array objectAtIndex:0];
	
	return sello;
}

- (NSArray*) getTematicas
{
	RHM_Comercial_TS_TEMATICAList *list = [RHM_Comercial_TS_TEMATICA findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_TEMATICA *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZCODTEM"], @"ZCODTEM",
				  [item valueForKey:@"ZDESCR"], @"ZDESCR",
				  [item valueForKey:@"ZDESBR"], @"ZDESBR",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getTipoEnc
{
	RHM_Comercial_TS_TIPENCList *list = [RHM_Comercial_TS_TIPENC findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_TIPENC *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZTIPENC"], @"ZTIPENC",
				  [item valueForKey:@"ZDESCRIP"], @"ZDESCRIP",
				  nil];			
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getTiposMat
{
	RHM_Comercial_TS_TIPOMATList *list = [RHM_Comercial_TS_TIPOMAT findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_TIPOMAT *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"SPRAS"], @"SPRAS",
				  [item valueForKey:@"MTART"], @"MTART",
				  [item valueForKey:@"MTBEZ"], @"MTBEZ",
				  nil];	
		
		[array addObject:tmpDic];
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSArray*) getTiposTapa
{
	RHM_Comercial_TS_TIPOTAPAList *list = [RHM_Comercial_TS_TIPOTAPA findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_TIPOTAPA *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZZTIPOTAPA"], @"ZZTIPOTAPA",
				  [item valueForKey:@"DESCR"], @"DESCR",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSDictionary *)getTipoTapaByCode:(NSString *)zztipotapa
{
	NSArray* tiposTapa = [self getTiposTapa];
	NSDictionary* tipoTapa = nil;
	
	NSPredicate *predicate = [NSPredicate alloc];
	predicate = [NSPredicate predicateWithFormat:@"ZZTIPOTAPA == %@", zztipotapa];
	
	NSArray *array = [tiposTapa filteredArrayUsingPredicate:predicate];
	if([array count]>0) tipoTapa = [array objectAtIndex:0];
	
	return tipoTapa;
}

- (NSArray *)getEdades
{
	RHM_Comercial_TS_EDADESList *list = [RHM_Comercial_TS_EDADES findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_EDADES *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"ZZDATGE"], @"ZZDATGE",
				  [item valueForKey:@"ZZDATGET"], @"ZZDATGET",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

- (NSString*) getArtClients:(NSString*)artCode
{
	NSString* clients = @"";
	NSMutableDictionary* artsClients = [self getArtsClientsDic];
	
	if([artsClients valueForKey:artCode]==nil)
	{
		NSArray *list = [artsClients valueForKey:artCode];
		
		for(NSDictionary *item in list)
			clients = [NSString stringWithFormat:@"%@%@%@",clients,(NSString*)[item valueForKey:@"KUNNR"],@";"];
	}
	
	return clients;
}

- (NSMutableDictionary*) getArtsClientsDic
{
	if([self artsClientsDic]==nil)
	{
		RHM_Comercial_TS_CLI_MATList *list = [RHM_Comercial_TS_CLI_MAT findAll];
		
		NSMutableArray *tmpArray = nil;
		NSDictionary *tmpDic = nil;
		NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
		
		for(RHM_Comercial_TS_CLI_MAT *item in list)
		{
			tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
					  [item valueForKey:@"BUKRS"], @"BUKRS",
					  [item valueForKey:@"KUNNR"], @"KUNNR",
					  [item valueForKey:@"VKORG"], @"VKORG",
					  [item valueForKey:@"VTWEG"], @"VTWEG",
					  [item valueForKey:@"MATNR"], @"MATNR",
					  nil];	
					
			if([dic objectForKey:(NSString*)[item valueForKey:@"MATNR"]]==nil)
			{
				tmpArray = [[NSMutableArray alloc] initWithObjects:tmpDic, nil];			
				[dic setValue:tmpArray forKey:(NSString*)[item valueForKey:@"MATNR"]];
			}
			else 
			{
				[(NSMutableArray*)[dic objectForKey:(NSString*)[item valueForKey:@"MATNR"]] addObject:tmpDic];
			}	
		}
		
		[self setArtsClientsDic:dic];
	}
	
	return [self artsClientsDic];
}

#pragma mark - Autores

- (NSArray *)getAutores
{
	if([self autores]==nil)
	{
		RHM_Comercial_AutoresList *list = [RHM_Comercial_Autores findAll];
		
		NSDictionary *tmpDic;
		NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
		
		//Variables para el diccionario
		NSMutableArray *tmpArray = nil;
		NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
		
		for(RHM_Comercial_Autores *item in list)
		{
			tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
					  [item valueForKey:@"BUKRS"], @"BUKRS",
					  [item valueForKey:@"CODAUT"], @"CODAUT",
					  [item valueForKey:@"NOMAUT"], @"NOMAUT",
					  [item valueForKey:@"BIOGRAFIA_HTML"], @"BIOGRAFIA_HTML",
					  nil];	
			
			[array addObject:tmpDic];
			
			//Lo añadimos también al Diccionario
			if([dic objectForKey:(NSString*)[item valueForKey:@"CODAUT"]]==nil)
			{
				tmpArray = [[NSMutableArray alloc] initWithObjects:tmpDic, nil];			
				[dic setValue:tmpArray forKey:(NSString*)[item valueForKey:@"CODAUT"]];
			}
			else 
			{
				[(NSMutableArray*)[dic objectForKey:(NSString*)[item valueForKey:@"CODAUT"]] addObject:tmpDic];
			}
		}
		
		[self setAutores:[[NSArray alloc] initWithArray:array]];
		[self setAutoresDic:dic];
	}
	
	return [self autores];
}

- (NSDictionary *)getAutorByCode:(NSString *)codaut
{
	return [[self autoresDic] objectForKey:codaut];
}

- (NSArray *)getAutoresContenido
{
	RHM_Comercial_TS_AUTOR_CONTENIDOList *list = [RHM_Comercial_TS_AUTOR_CONTENIDO findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_TS_AUTOR_CONTENIDO *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"CODAUT"], @"CODAUT",
				  [item valueForKey:@"UOID"], @"UOID",
				  [item valueForKey:@"TIPO_CONT"], @"TIPO_CONT",
				  [item valueForKey:@"MIMETYPE"], @"MIMETYPE",
				  [item valueForKey:@"TAMA"], @"TAMA",
				  [item valueForKey:@"NOMBRE"], @"NOMBRE",
				  [item valueForKey:@"DESCRIPCION"], @"DESCRIPCION",
				  [item valueForKey:@"DESC_SUP"], @"DESC_SUP",				  
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

#pragma mark - Agentes

- (NSArray *)getAgentes
{
	RHM_Comercial_AgentesList *list = [RHM_Comercial_Agentes findAll];
	
	NSDictionary *tmpDic;
	NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
	
	for(RHM_Comercial_Agentes *item in list)
	{
		tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
				  [item valueForKey:@"BUKRS"], @"BUKRS",
				  [item valueForKey:@"AGENTE"], @"AGENTE",
				  [item valueForKey:@"VKORG"], @"VKORG",
				  [item valueForKey:@"VTWEG"], @"VTWEG",
				  [item valueForKey:@"NAME1"], @"NAME1",
				  [item valueForKey:@"ESDIRECTOR"], @"ESDIRECTOR",
				  [item valueForKey:@"DIRECTOR"], @"DIRECTOR",
				  [item valueForKey:@"EMAIL"], @"EMAIL",
				  [item valueForKey:@"TELEFONO"], @"TELEFONO",
				  [item valueForKey:@"STRAS"], @"STRAS",
				  [item valueForKey:@"ORT01"], @"ORT01",
				  [item valueForKey:@"CP"], @"CP",
				  [item valueForKey:@"REGIO"], @"REGIO",
				  [item valueForKey:@"USUARIO"], @"USUARIO",
				  nil];	
		
		[array addObject:tmpDic];		
	}
	
	return [[NSArray alloc] initWithArray:array];
}

#pragma mark - Clientes

- (NSArray *)getClientes
{
	if([self clientes]==nil)
	{
		RHM_Comercial_ClientesList *list = [RHM_Comercial_Clientes findAll];
		
		NSDictionary *tmpDic;
		NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:[list length]];
		
		//Variables para el diccionario
		NSMutableArray *tmpArray = nil;
		NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
		
		for(RHM_Comercial_Clientes *item in list)
		{
			tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:
					  [item valueForKey:@"BUKRS"], @"BUKRS",
					  [item valueForKey:@"VKORG"], @"VKORG",
					  [item valueForKey:@"VTWEG"], @"VTWEG",
					  [item valueForKey:@"SPART"], @"SPART",
					  [item valueForKey:@"KUNNR"], @"KUNNR",
					  [item valueForKey:@"KTOKD"], @"KTOKD",
					  [item valueForKey:@"NAME1"], @"NAME1",
					  [item valueForKey:@"AGENTE"], @"AGENTE",
					  [item valueForKey:@"CLIPRI"], @"CLIPRI",
					  [item valueForKey:@"ESCLIPRI"], @"ESCLIPRI",
					  [item valueForKey:@"LAND1"], @"LAND1",
					  [item valueForKey:@"REGIO"], @"REGIO",
					  [item valueForKey:@"PSTLZ"], @"PSTLZ",
					  [item valueForKey:@"ORT01"], @"ORT01",
					  [item valueForKey:@"STRAS"], @"STRAS",
					  [item valueForKey:@"BRSCH"], @"BRSCH",
					  [item valueForKey:@"BRAN1"], @"BRAN1",
					  [item valueForKey:@"ZZPEDOBL"], @"ZZPEDOBL",
					  [item valueForKey:@"ZZSERVNOV"], @"ZZSERVNOV",
					  [item valueForKey:@"BLOQENTREGA"], @"BLOQENTREGA",
					  [item valueForKey:@"ZTERM"], @"ZTERM",
					  [item valueForKey:@"EMAIL"], @"EMAIL",
					  [item valueForKey:@"AVISO"], @"AVISO",
					  nil];			
			
			[array addObject:tmpDic];
			
			//Lo añadimos también al Diccionario
			if([dic objectForKey:(NSString*)[item valueForKey:@"KUNNR"]]==nil)
			{
				tmpArray = [[NSMutableArray alloc] initWithObjects:tmpDic, nil];			
				[dic setValue:tmpArray forKey:(NSString*)[item valueForKey:@"KUNNR"]];
			}
			else 
			{
				[(NSMutableArray*)[dic objectForKey:(NSString*)[item valueForKey:@"KUNNR"]] addObject:tmpDic];
			}
		}
		
		[self setClientes:[[NSArray alloc] initWithArray:array]];
	}
	
	return [self clientes];
}

- (NSDictionary *)getClienteByCode:(NSString *)kunnr
{
	return [[self clientesDic] objectForKey:kunnr];
}

#pragma mark - Plantillas

#pragma mark - Otros

- (void) reiniciarCaches
{
	[self setArticulos:nil];
	[self setManuscritos:nil];
	[self setArticulosDic:nil];
	[self setArtsBICDic:nil];
	[self setArtsClientsDic:nil];
	
	[self setAutores:nil];
	[self setAutoresDic:nil];
	
	[self setClientes:nil];
}

@end

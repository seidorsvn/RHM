//
//  DataService.h
//  OrdesaFuerzaVentas
//
//  Created by Apple1 Seidor on 11/23/11.
//  Copyright (c) 2011 Seidor Consulting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Utils.h"

@interface DataService : NSObject
{
	NSString *_loggedUser;
	
	NSArray *_articulos;
	NSMutableDictionary* _articulosDic;
	NSArray *_manuscritos;
	NSMutableDictionary *_artsBICDic;
	NSMutableDictionary *_artsClientsDic;
	
	NSArray *_autores;
	NSMutableDictionary *_autoresDic;
	
	NSArray *_clientes;
	NSMutableDictionary *_clientesDic;
}

@property(nonatomic,retain) NSString *loggedUser;

#pragma mark - Articulos

@property(nonatomic,retain) NSArray *articulos;
@property(nonatomic,retain) NSMutableDictionary *articulosDic;
@property(nonatomic,retain) NSArray *manuscritos;
@property(nonatomic,retain) NSMutableDictionary *artsBICDic;
@property(nonatomic,retain) NSMutableDictionary *artsClientsDic;

- (NSArray*) getArticulos;
- (NSDictionary*) getArticuloByCode:(NSString*)matnr;
- (NSArray*) getTitulos;
- (NSArray*) getCodigos;
- (NSArray*) getAlmacenes;
- (NSArray*) getAmbitos;
- (NSString*) getArtBIC:(NSString*)matnr;
- (NSArray*) getArtContenido;
- (NSArray*) getArtStock;
- (NSArray*) getArtTexto;
- (NSArray*) getBICs;
- (NSArray*) getCatsMov;
- (NSArray*) getCentros;
- (NSArray*) getColecciones;
- (NSDictionary*) getColeccionByCode:(NSString*)zzcodcolec;
- (NSArray*) getDivisionesEditorial;
- (NSArray*) getEstados;
- (NSArray*) getFormatos;
- (NSArray*) getIdiomas;
- (NSArray*) getLineas;
- (NSArray*) getManuscritos;
- (NSArray*) getNegocios;
- (NSArray*) getPersonajes;
- (NSArray*) getSellos;
- (NSDictionary*) getSelloByCode:(NSString*)zcodsello;
- (NSArray*) getTematicas;
- (NSArray*) getTipoEnc;
- (NSArray*) getTiposMat;
- (NSArray*) getTiposTapa;
- (NSDictionary*) getTipoTapaByCode:(NSString*)zztipotapa;
- (NSArray*) getEdades;
- (NSString*) getArtClients:(NSString*)artCode;

#pragma mark - Autores

@property(nonatomic,retain) NSArray *autores;
@property(nonatomic,retain) NSMutableDictionary *autoresDic;

- (NSArray*) getAutores;
- (NSDictionary*) getAutorByCode:(NSString*)codaut;
- (NSArray *)getAutoresContenido;

#pragma mark - Agentes

- (NSArray *)getAgentes;

#pragma mark - Clientes

@property(nonatomic,retain) NSArray *clientes;
@property(nonatomic,retain) NSMutableDictionary *clientesDic;

- (NSArray*) getClientes;
- (NSDictionary*) getClienteByCode:(NSString*)kunnr;
- (NSArray*) getDescuentos;
- (NSArray*) getDestinatarios;
- (NSArray*) getMaterialesCli;
- (NSArray*) getDepositos;
- (NSArray*) getSociedades;
- (NSArray*) getOrgVentas;
- (NSArray*) getCanales;
- (NSArray*) getPaises;
- (NSArray*) getRegiones;
- (NSArray*) getRamos;
- (NSArray*) getRamos1;

#pragma mark - Otros

- (void) reiniciarCaches;

@end

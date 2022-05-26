
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "vivienda.h"
#include "censista.h"
/**
 * esta funcion inicializa todos los id a partir de 20000 incrementando en 1, y todos los isEmpty en 1
 * @param viviendas
 * @param
 *
 */
void inicializarViviendas(pVivienda viviendas[],int tam);
/**
 * esta funcion busca si hay algun lugar en el array de viviendas y si esta libre procede a cargar los datos en ese espacio
 * @param viviendas
 * @param tam
 * @param censistas
 * @param tamCensistas
 * @return 0 si funciono correctamente, -1 si no lo hizo
 */
int altaVivienda(pVivienda viviendas[],int tam,pCensista censistas[], int tamCensistas);
/**
 * esta funcion sirve para validar el ingreso del legajo del censista en la funcion alta vivienda para que solo se ingresen legajos validos
 * @param auxIdCensista
 * @param censistas
 * @param tamCensistas
 * @return 0 si funciono correctamente, -1 si no lo hizo
 */
int buscarCensista(int auxIdCensista,pCensista censistas[],int tamCensistas);
/**
 * esta funcion pide un id el cual lo compara con los id en las posiciones del array, si encuentra alguno igual te muestra un menu el cual te da 4 opciones para
 * modificar el array de vivienda en la posicion a la que pertenece ese id
 * @param viviendas
 * @param tam
 * @return 0 si funciono correctamente, -1 si no lo hizo
 */
int modificarVivienda(pVivienda viviendas[],int tam);
/**
 * esta funcion pide un id el cual lo compara con los id en las posiciones del array, si encuentra alguno igual procede a poner el isEmpty en 1 para que luego se
 * puedan cargar nuevos datos en esa posicion del array
 * @param viviendas
 * @param tam
 * @return 0 si funciono correctamente, -1 si no lo hizo
 */
int bajaVivienda(pVivienda viviendas[],int tam);
/**
 * esta funcion ordena las posiciones del array por calle y luego las muestra
 * @param viviendas
 * @param tam
 * @return
 */
int listarViviendas(pVivienda viviendas[],int tam);
/**
 * esta funcion muestra los censistas harcodeados anteriormente
 * @param censistas
 * @param tam
 * @return 0 si funciono correctamente, -1 si no lo hizo
 */
int listarCensistas(pCensista censistas[],int tam);

int listarCensisitasConViviendas(pVivienda viviendas[],pCensista censistas[],int tamViviendas,int tamCensistas);

int mostrasCensistasConMasCensos(pVivienda viviendas[],pCensista censistas[],int tamViviendas,int tamCensistas);


#endif /* FUNCIONES_H_ */

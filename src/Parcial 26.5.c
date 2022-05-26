#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vivienda.h"
#include "censista.h"
#include "validaciones.h"
#include "funciones.h"

#define TAM 5

int main(void)
{

	setbuf(stdout,NULL);

	pCensista censistas[3] =
			{
					{100, "Ana", 34, 12032345},
					{101, "Juan", 24, 430154678},
					{102, "Sol", 47, 590237487}
			};

	pVivienda viviendas[TAM];

	int opcion;
	int retorno;
	int flag = 0;


	inicializarViviendas(viviendas,TAM);

	do
	{
		retorno = getNumero(&opcion,"ingrese su opcion\n1. Ingresar una vivienda\n2. Modificar una vivienda\n3. Eliminar una vivienda\n4. listar viviendas\n5. listar censistas\n6. listar censistas con datos de las viviendas censadas\n7. mostra el o los censistas con mas censos realizados\n8. salir\n",8,1);
		if(retorno == 0)
		{
			switch(opcion)
			{

				case 1:
					altaVivienda(viviendas,TAM,censistas,3);
					flag = flag + 1;
					break;
				case 2:
					if(flag != 0)
					{
						modificarVivienda(viviendas,TAM);
					}
					else
					{
						printf("Primero debe ingresar al menos una vivienda\n");
					}
					break;
				case 3:
					if(flag != 0)
					{
						bajaVivienda(viviendas,TAM);
						flag = flag - 1;
					}
					else
					{
						printf("Primero debe ingresar al menos una vivienda\n");
					}
					break;
				case 4:
					if(flag != 0)
					{
						listarViviendas(viviendas,TAM);
					}
					else
					{
						printf("Primero debe ingresar al menos una vivienda\n");
					}
					break;
				case 5:
					listarCensistas(censistas,3);
					break;
				case 6:
					if(flag != 0)
					{
						listarCensisitasConViviendas(viviendas,censistas,TAM,3);
					}
					else
					{
						printf("Primero debe ingresar al menos una vivienda\n");
					}
					break;
				case 7:
					if(flag != 0)
					{
						mostrasCensistasConMasCensos(viviendas,censistas,TAM,3);
					}
					else
					{
						printf("Primero debe ingresar al menos una vivienda\n");
					}

			}
		}
		else
		{
			printf("error al ingresar su opcion\n");
		}

	}while(opcion != 8);









}


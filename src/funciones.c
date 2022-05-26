#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vivienda.h"
#include "censista.h"
#include "validaciones.h"

void inicializarViviendas(pVivienda viviendas[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		viviendas[i].isEmpty = 1;
		viviendas[i].idVivienda = 20000 + i;
	}

}

int buscarCensista(int auxIdCensista,pCensista censistas[],int tamCensistas)
{
	int retorno = -1;
	int i;

	if(auxIdCensista >= 100 && censistas != NULL && tamCensistas > 0)
	{
		for(i=0;i<tamCensistas;i++)
		{
			if(censistas[i].legajoCensista == auxIdCensista)
			{
				retorno = 0;
				break;
			}
		}

		if(retorno == -1)
		{
			printf("ningun censista tiene ese legajo\n");
		}
	}

	return retorno;
}

int altaVivienda(pVivienda viviendas[],int tamViviendas,pCensista censistas[],int tamCensistas)
{
	int retorno = -1;
	int i;
	int validacion = -1;
	int auxLegajo;

	if(viviendas != NULL && censistas != NULL && tamViviendas > 0 && tamCensistas > 0)
	{
		for(i=0;i<tamViviendas;i++)
		{
			if(viviendas[i].isEmpty == 1)
			{
				validacion = 0;
				break;
			}
		}

		if(validacion == 0)
		{
			getString(viviendas[i].calle,"Ingrese su calle\n",25);
			getNumero(&viviendas[i].cantidadDePersonas,"Ingrese la cantidad de personas\n",15,1);
			getNumero(&viviendas[i].cantidadDeHabitaciones,"Ingrese la cantidad de habitaciones\n",15,1);
			getNumero(&viviendas[i].tipoDeVivienda,"Ingrese su tipo de vivienda (1. CASA 2. DEPARTAMENTO 3. CASILLA 4. RANCHO)\n",4,1);
			getNumero(&auxLegajo,"Ingrese el id de su censista\n",102,100);

			validacion = buscarCensista(auxLegajo,censistas,3);
			if(validacion == 0)
			{
				viviendas[i].legajoCensista.legajoCensista = auxLegajo;
			}
			else
			{
				printf("error");
			}

			viviendas[i].isEmpty = 0;
			retorno = 0;
		}
		else
		{
			printf("no hay mas espacios libres\n");
		}


	}

	return retorno;
}

int modificarVivienda(pVivienda viviendas[],int tam)
{
	int i;
	int retorno = -1;
	int auxId;
	int opciones;
	int validacion = -1;

	if(viviendas != NULL && tam > 0)
	{
		getNumero(&auxId,"Ingrese el ID que quiere modificar\n",30000,20000);

		for(i=0;i<tam;i++)
		{
			if(viviendas[i].idVivienda == auxId && viviendas[i].isEmpty == 0)
			{
				validacion = 0;
				break;
			}
		}

		if(validacion == 0)
		{
			getNumero(&opciones,"Ingrese la opcion que desea editar\n1. calle\n2. cantidad de personas\n3. cantidad de habitaciones\n4. tipo de vivienda\n5. Salir\n",5,1);

			switch(opciones)
			{
				case 1:
					getString(viviendas[i].calle, "Ingrese la nueva calle\n", 25);
					break;
				case 2:
					getNumero(&viviendas[i].cantidadDePersonas, "Ingrese la nueva cantidad de personas\n",15,1);
					break;
				case 3:
					getNumero(&viviendas[i].cantidadDeHabitaciones, "Ingrese la nueva cantidad de habitaciones\n", 15, 1);
					break;
				case 4:
					getNumero(&viviendas[i].tipoDeVivienda, "Ingrese su nuevo tipo de vivienda (1. CASA 2. DEPARTAMENTO 3. CASILLA 4. RANCHO)\n",4,1);
					break;
				case 5:
					printf("Se salio correctamente\n");
			}

			retorno = 0;

			if(opciones != 5)
			{
				printf("Se edito correctamente la vivienda\n");
			}
		}
		else
		{
			printf("No hay ningun ID igual\n");
		}

	}
		return retorno;
}

int bajaVivienda(pVivienda viviendas[],int tam)
{

	int retorno = -1;
	int auxId;
	int i;
	int validacion = -1;

	if(viviendas != NULL && tam > 0)
	{
		getNumero(&auxId,"Ingrese el ID que quiere modificar",30000,20000);

		for(i=0;i<tam;i++)
		{
			if(viviendas[i].idVivienda == auxId && viviendas[i].isEmpty == 0)
			{
				validacion = 0;
				break;
			}
		}

		if(validacion == 0)
		{
			viviendas[i].isEmpty = 1;
			printf("Se elimino correctamente la vivienda\n");
			retorno = 0;
		}
		else
		{
			printf("No hay ningun ID igual\n");
		}
	}

	return retorno;
}

int listarViviendas(pVivienda viviendas[],int tam)
{
	int retorno = -1;
	int i;
	int j;
	pVivienda auxVivienda;

	if(viviendas != NULL && tam > 0)
	{
		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(strcmp(viviendas[i].calle, viviendas[j].calle) > 0)
				{
					auxVivienda = viviendas[i];
					viviendas[i] = viviendas[j];
					viviendas[j] = auxVivienda;

				}
				else if(strcmp(viviendas[i].calle, viviendas[j].calle) == 0)
				{
					if(viviendas[i].cantidadDePersonas < viviendas[j].cantidadDePersonas)
					{
						auxVivienda = viviendas[i];
						viviendas[i] = viviendas[j];
						viviendas[j] = auxVivienda;
					}
				}
			}
		}

		for(i=0;i<tam;i++)
		{
			if(viviendas[i].isEmpty == 0)
			{
				printf("id vivienda: %d\n", viviendas[i].idVivienda);
				printf("calle: %s\n", viviendas[i].calle);
				printf("cantidad de personas: %d\n", viviendas[i].cantidadDePersonas);
				printf("cantidad de habitaciones: %d\n", viviendas[i].cantidadDeHabitaciones);
				printf("tipo de vivienda: %d\n", viviendas[i].tipoDeVivienda);
				printf("----------------------------------------------------------------\n");
			}
		}

		retorno = 0;
	}
	else
	{
		printf("Error");
	}
	return retorno;
}

int listarCensistas(pCensista censistas[],int tam)
{
	int retorno = -1;
	int i;

	if(censistas != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			printf("Legajo: %d\n",censistas[i].legajoCensista);
			printf("Nombre: %s\n",censistas[i].nombre);
			printf("Edad: %d\n",censistas[i].edad);
			printf("Telefono: %d\n",censistas[i].telefono);
			printf("----------------------------------------------------------------\n");
		}
	}

	return retorno;
}

int listarCensisitasConViviendas(pVivienda viviendas[],pCensista censistas[],int tamViviendas,int tamCensistas)
{
	int retorno = -1;
	int i;
	int j;

	if(viviendas != NULL && censistas !=NULL && tamViviendas > 0 && tamCensistas > 0)
	{
		retorno = 0;
		for(i=0;i<tamCensistas;i++)
		{
			printf("LEGAJO       NOMBRE       EDAD           TELEFONO\n");
			printf(" %d            %s          %d                %d   \n",censistas[i].legajoCensista,censistas[i].nombre,censistas[i].edad,censistas[i].telefono);
			printf("-----------------------------------------------------------------------------\n");
			for(j=0;j<tamViviendas;j++)
			{
				if(viviendas[j].legajoCensista.legajoCensista == censistas[i].legajoCensista && viviendas[i].isEmpty == 0)
				{

					printf("ID           CALLE           CANTIDAD DE PERSONAS       CANTIDAD DE HABITACIONES        TIPO DE VIVIENDA\n");
					printf("%d          %s                  %d                           %d                             %d          \n",viviendas[i].idVivienda,viviendas[i].calle,viviendas[i].cantidadDePersonas,viviendas[i].cantidadDeHabitaciones,viviendas[i].tipoDeVivienda);

				}
			}
			printf("------------------------------------------------------------------------------\n");
		}
	}
	else
	{
		printf("Error\n");
	}

	return retorno;
}

int mostrasCensistasConMasCensos(pVivienda viviendas[],pCensista censistas[],int tamViviendas,int tamCensistas)
{
	int retorno = -1;
	int i;
	int j;
	int contador[tamCensistas];
	int maximo;
	int flag = 0;

	for(i=0;i<tamCensistas;i++)
	{
		contador[i]=0;
	}

	if(viviendas != NULL && censistas !=NULL && tamViviendas > 0 && tamCensistas > 0)
	{
		retorno = 0;

		for(i=0;i<tamCensistas;i++)
		{
			for(j=0;j<tamViviendas;j++)
			{
				if(viviendas[j].legajoCensista.legajoCensista == censistas[i].legajoCensista && viviendas[i].isEmpty == 0)
				{
					contador[i]=contador[i]+1;
				}
			}
		}

		for(i=0;i<tamCensistas;i++)
		{
			if(flag == 0 || contador[i]>maximo)
			{
				flag = 1;
				maximo = i;
			}
		}

		printf("el Censista con mas censos es: \n");
		printf(" %d            %s          %d                %d   \n",censistas[maximo].legajoCensista,censistas[maximo].nombre,censistas[maximo].edad,censistas[maximo].telefono);

	}
	else
	{
		printf("Error\n");
	}




	return retorno;
}












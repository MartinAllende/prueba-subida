
#ifndef VIVIENDA_H_
#define VIVIENDA_H_
#include "censista.h"

typedef struct
{
	int idVivienda;
	char calle[25];
	int cantidadDePersonas;
	int cantidadDeHabitaciones;
	int tipoDeVivienda;
	pCensista legajoCensista;
	int isEmpty;

}pVivienda;

#endif /* VIVIENDA_H_ */

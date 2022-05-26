#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
/**
 * esta funcion sirve para obtener un numero y que se valide que solo sea un numero y que esta dentro de un rango dado
 * @param destino
 * @param mensaje
 * @param maximo
 * @param minimo
 * @return 0 si funciono correctamente, -1 si no lo hizo
 */
int getNumero(int *destino,char *mensaje,int maximo,int minimo);
/**
 * esta funcion sirve para validar que lo ingresado sean solo letras, y que se valide que la cantidad que tengas sea menor o igual a un maximo dado
 * @param destino
 * @param mensaje
 * @param tam
 * @return 0 si funciono correctamente, -1 si no lo hizo
 */
int getString(char destino[],char *mensaje,int tam);

#endif /* VALIDACIONES_H_ */

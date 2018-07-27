#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "genericas.h"

//#define MASACARA_ARCHIVO "%[^,],%[^,],%[^,],%[^\n]\n"
#define MASACARA_ARCHIVO "%[^,],%[^,],%[^,],%[^\n],%[^\n]\n"
#define CANTIDAD_CAMPOS_ARCHIVO 5
#define TIENE_ENCABEZADO_ARCHIVO 1

typedef struct{
    //id,producto,direccion,localidad,recibe
    int id;
    char producto[30];
    char direccion[30];
    char localidad[30];
    char recibe[30];
}EMercaderia;


EMercaderia* nuevo(void);
int Muestra1Record(EMercaderia * record);
int compara_elementos_Estructura(void* pElementA,void* pElementB);




/*
int Alumno_setEdad(EAlumno* this, int dato);
int Alumno_setLegajo(EAlumno* this, int dato);
//int Alumno_setSexo(EAlumno* this, char dato);
int Alumno_setSexo(EAlumno* this,  char *dato);
int Alumno_setName(EAlumno* this, const char* name);
*/

int funcionQueFiltra(void* item);

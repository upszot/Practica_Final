#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Estructura.h"
#include "genericas.h"
#include "Complemento_ArrayList.h"




int E_setCampo1(EMercaderia* this, int dato)
{
    this->id = dato;
    return 0;
}

int E_setCampo2(EMercaderia* this, const char* dato)
{
    strcpy(this->producto, dato);
    return 0;
}

EAlumno* nuevoElementoParametrizado(datos* [])
{
    EMercaderia* record;
    record=nuevoElemento();
    if(record != NULL)
    {
        if( E_setCampo1(record, charToint(datos[0]) ) !=0)
        {
            break;
        }

        if( E_setCampo2(record, datos[1] ) !=0)
        {
            break;
        }

    }


}

EAlumno* nuevoElemento(void)
{
    EAlumno* returnAux;
    returnAux = (EAlumno*)malloc(sizeof(EAlumno));
    return returnAux;
}

int Muestra1Record(void * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf("id: %d \t",record->id);
        /*
        printf("Nombre: %s    \t\t",record->Nombre);
        printf("Edad: %d \t",record->Edad);
        printf("Legajo: %d \t",record->Legajo);
        printf("Sexo: %c \n",record->Sexo);
        */
    }
    return retorno;
}

int compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno;
    EAlumno *tmp_1;
    EAlumno *tmp_2;
    tmp_1=(EAlumno * ) pElementA;
    tmp_2=(EAlumno * ) pElementB;

    if(tmp_1->Edad > tmp_2->Edad)
    {
        retorno=1;
    }
    else
    {
        retorno=-1;
        if(tmp_1->Edad == tmp_2->Edad)
        {
            retorno=0;
        }

    }
    return retorno;
}


int funcionQueFiltra(void* item)
{
    int retorno=0;
    EAlumno *tmp_1;
    tmp_1=(EAlumno * ) item;

    if(get_Edad(tmp_1) > 30 )
    {
        retorno=1;
    }
    return retorno ;
}

int get_Edad(EAlumno * record)
{
    int retorno;
    retorno =record->Edad;
    return retorno;
}

int get_Legajo(void * record)
{
    EAlumno *tmp_1;
    tmp_1=(EAlumno * ) record;
    return tmp_1->Legajo;
}

char *get_Nombre(void * record)
{
    EAlumno *tmp_1;
    tmp_1=(EAlumno * ) record;

    return tmp_1->Nombre;
}

char get_Sexo(void * record)
{
    EAlumno *tmp_1;
    tmp_1=(EAlumno * ) record;

    return tmp_1->Sexo;
}




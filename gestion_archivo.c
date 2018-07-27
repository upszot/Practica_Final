#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Estructura.h"
#include "genericas.h"
#include "Complemento_ArrayList.h"
#include "gestion_archivo.h"

int cargarDesdeArchivo(const char* nombreArchivo, ArrayList* this)
{
    FILE* archivo;
    int retorno = -1;
    int parseoArchivo;
    int cerroArchivo;

    archivo = fopen(nombreArchivo, "r");
    if(archivo != NULL)
    {
        retorno = -2;
        if(parserEstructura(archivo, this)==0)
        {
            retorno = -3;
            if(fclose(archivo)==0)
            {
                retorno = 0;
            }
        }
    }//FIN if(archivo != NULL)

    return retorno;
}

int parserEstructura(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int cantidadDatosLeidos;
    int agregoRecord;
    char cabecera[80];
    int guardoDato;

    //EMercaderia* record;

    char campo[CANTIDAD_CAMPOS_ARCHIVO][30];

    if(pFile != NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO_ARCHIVO == 1)
        {
            //descarto la lectura del encabezado
            fgets(cabecera, 80, pFile);
        }

        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevoElemento();
            if(record != NULL)
            {
                cantidadDatosLeidos = fscanf(pFile,MASACARA_ARCHIVO,campo[0],campo[1],campo[2],campo[3],campo[4],campo[5]);
                if(cantidadDatosLeidos == CANTIDAD_CAMPOS_ARCHIVO)
                {

                    guardoDato = E_setCampo1(record, charToint(campo[0]) );
                    if(guardoDato !=0)
                    {
                        break;
                    }
/*
                    guardoDato = E_setCampo1(record,(char*) campo[0]);
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = Alumno_setEdad(record, charToint(Edad) );
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = Alumno_setLegajo(record,charToint(Legajo) );
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    //guardoDato = Alumno_setSexo(record,(char) Sexo[0] );
                    guardoDato = Alumno_setSexo(record,(char *) Sexo );
                    if(guardoDato !=0)
                    {
                        break;
                    }
*/

                    agregoRecord = al_add(this, record);
                    if(agregoRecord < 0) //Hubo error
                    {
                        break;
                    }

                    cantidadFilasLeidas++;
                }
                else //Fin de archivo u otro error
                {
                    break;
                }
            }
            else //Sin memoria
            {
                break;
            }
        }
    }

    return retorno;
}

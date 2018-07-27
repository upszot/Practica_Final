#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Estructura.h"
#include "genericas.h"


#define NOMBRE_ARCHIVO "mercaderia.csv"
#define PAGINADO 10

int main()
{
    ArrayList *ListMerca;
    ListMerca= al_newArrayList();

    ArrayList *ListTemp;
    ListTemp= al_newArrayList();

    char seguir='s';
    int opcion=0;
    int Error=-9;

    if(ListMerca!=NULL)
    {
        Error=0;
    }

    if(Error==0)
    {
        do
        {
            menu(   "\n 1. Parse del archivo CVS"
                    "\n 2. Lista Ordenados por Edad"
                    "\n 3. Lista Original"
                    "\n 4. LISTAR filtrado"
                    //"\n 5. INFORMAR:"
                );

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    Error = cargarDesdeArchivo(NOMBRE_ARCHIVO, ListMerca);
                    break;
                case 2:
                    /*
//                    ListAlumno->sort(compara_elementos_Estructura,1)
                    ListTemp= clonaOrdenado(ListAlumno,compara_elementos_Estructura,1);
                    if(ListTemp!=NULL)
                    {
                        Error=al_MuestraElemento_desde_hasta(ListTemp,"Alumnos Ordenados por Edad",Muestra1Record ,0,ListTemp->len(ListTemp),PAGINADO);
                    }
                    */
                    break;
                case 3://Muestra
                    Error=al_MuestraElemento_desde_hasta(ListMerca,"Mercaderia ",Muestra1Record ,0,ListMerca->len(ListMerca),PAGINADO);
                    break;
                case 4:
                    /*
                        ListTemp= al_filter(ListAlumno ,funcionQueFiltra);
                        Error=al_MuestraElemento_desde_hasta(ListTemp,"Alumnos Filtrado por Edad",Muestra1Record ,0,ListTemp->len(ListTemp),PAGINADO);
                        */
                    break;
                case 5:


                    break;
                case 0:
                    seguir = 'n';
                    Error=0;
                    break;
                default:
                    Error=-1;
                    opcion=-2;
                    break;
            }//FIN switch(opcion)
            if(Error!=0)
            {
                sms_error(opcion,Error);
                Error=0;
            }
        }while(seguir=='s');
    }
    else
    {
        sms_error(-1,Error);
    }//FIN if(Error==0)

    return Error;
}//int main()

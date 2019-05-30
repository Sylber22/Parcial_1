#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "Biblo_UTN.h"
#include "Validaciones.h"
#include "Orquesta.h"
#include "Tipo.h"


int generateIdOrq()
{
    static int id = 0;
    id ++;
    return id;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in 0 in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orq_Init(Orquestas* list, int len)
{
    int ret = -1;
     if ((list!=NULL) && (len>=0))
     {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty= 0;
            ret =0;
        }
     }
     return ret;
}

/** \brief This funcion look for the fist empty place in the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param pResult pointer type int* to the empty direccion
 * \return int Return (-1) if Error [Invalid length or NULL pointer] -
     (0) if Ok-1 if there is no empty place
 */
int orq_FindFree(Orquestas* list, int len, int* pResult)
{
    int ret=-1;
    int i;
    for(i=0;i<len;i++)
        {
            if(!list[i].isEmpty)
            {
                (*pResult)=i;
                ret=0;
                break;
            }
            ret =-1;
        }
    return ret;
}

/** \brief carga un empleado nuevo
* \param list employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or
NULL pointer or without free space] - (0) if Ok
*/
int orq_Add(Orquestas* list,int len, TiposDORQ* clase, int lenTip)
{
    int ret=-1;
    int idOrq;
    char name[51];
    char lugar[51];
    int tipoO;
    int index;


    if(!orq_FindFree(list, len, &index))
            {
               if((!getStringLetras(name,"Ingrese nombre de la orquesta: ", "\n-INGRESO MAL EL DATO-\n", 2))&&
                  (!getStringLetras(lugar,"Ingrese lugar de la orquesta: ", "\n-INGRESO MAL EL DATO-\n", 2)))
                  {
                                hardcodearTipoOrquesta(clase, lenTip);
                                printf("\n--TIPOS DE ORQUESTAS--\n");
                                for(int i=0; i<lenTip; i++)
                                     {
                                         printf("%d-%s \n", clase[i].idTip, clase[i].descripcion);
                                     }
                                tipoO= getValidInt("\nElija al tipo correspondiente: ","\n-INGRESO MAL EL DATO-\n", 1, 3);

                                if((tipoO>0 && tipoO<4) &&
                                    (!orq_IsValidAdd(list,len,name,lugar,tipoO,index)))
                                {
                                    printf("-ALTA EXITOSA- ID: %d\n", idOrq);

                                    ret=0;
                                }//ALTA
                    }//LUGAR Y NOMBRE
            }//FIND FREE
               else
                {
                    printf("No hay lugar para otra carga.");
                }
    return ret;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary char
* \param sector int
* \return int Return (-1) if Error [Invalid length or
NULL pointer or without free space] - (0) if Ok
*/
int orq_IsValidAdd(Orquestas* list, int len, char* name, char* lugar, int tipoO, int index)
{
    int ret=-1;
    Orquestas auxList;

   if ((index>=0) && (list !=NULL))
   {
       auxList.idOrq= generateIdOrq();
       strncpy(auxList.name, name,sizeof(auxList.name));
       strncpy(auxList.lugar, lugar,sizeof(auxList.lugar));
       auxList.tipoO= tipoO;
       auxList.isEmpty= 1;
       list[index] = auxList;
       ret=0;
   }
    return ret;
}

/** \brief Muestra un unico empleado
 * \param lista array de empleados
 * \param index int posicion del array a ser mostrada
 * \return int 0 si los datos se cargaron correctamente 1 si hubo un error
 */
int Orq_PrintOnly(Orquestas* list,int index,
                    TiposDORQ* clase, int lenTip)
{
    int ret=-1;
    int largo= 0;
    char *lugarChar= NULL;
    char *tipoChar= NULL;
    int lugarInt= 0;
    int tipoInt= 0;

    if(list!=NULL)
    {
        printf("ID   NOMBRE  LUGAR  TIPO\n");
        if(list[index].isEmpty == 1)
        {
            printf("%d  %d    %s\n  ",list[index].idOrq,
                                      list[index].name);
        lugarInt=list[index].tipo;
        tipoChar= retTipChar(clase, lenTip, tipoInt);
        printf("\t %s", tipoChar);
        largo=strlen(lugarChar);
        for(int i=0; i<10-largo; i++)
        {
            printf(" ");
        }

        lugarInt= list[index].lugar;
        tipoChar= retTipoChar(reparto, lenTip, lugarInt);
        printf("\t\t  %s", tipoChar);
            ret=0;
        }
    }
    return ret;
}

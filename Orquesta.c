#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "Biblo_UTN.h"
#include "Validaciones.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"

int generateIdOrq()
{
    static int id = 0;
    id ++;
    return id;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in 0 in all
* position of the array
* \param list * Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orq_Init(Orquestas* list, int len)
{
    int ret = -1;
     if ((list!=NULL) && (len>0))
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
 * \param list * Pointer to array of employees
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
            if(list[i].isEmpty==0)
            {
                (*pResult)=i;
                ret=0;
                break;
            }
            ret =-1;
        }
    return ret;
}

/** \brief carga una orquesta nueva
* \param list *
* \param len int
* \return int Return (-1) if Error [Invalid length or
NULL pointer or without free space] - (0) if Ok
*/
int orq_Add(Orquestas* list,int len)
{
    int ret=-1;
    char name[51];
    char lugar[51];
    int tipoO;
    int index;

    if(!orq_FindFree(list, len, &index))
            {
               if((!getStringLetras(name,"Ingrese nombre de la orquesta: ", "\n-INGRESO MAL EL DATO-\n", 2))&&
                  (!getStringLetras(lugar,"Ingrese lugar de la orquesta: ", "\n-INGRESO MAL EL DATO-\n", 2)))
                  {
                    tipoO= getValidInt("\n1)Filarmonica\n2)Sinfonica\n3)Camara\nElija el tipo correspondiente: ","\n-INGRESO MAL EL DATO-\n", 0, 3);
                    if((tipoO>0 && tipoO<4) &&
                    (!orq_IsValidAdd(list,len,name,lugar,tipoO,index)))
                    {
                        printf("-ALTA EXITOSA ID ASIGNADO: %d-\n", list[index].idOrq);
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

/** \brief add in a existing list of orquestas the values received as parameters
* in the first empty position
* \param list *
* \param len int
* \param tipo int
* \param name[] char
* \param index int
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

/** \brief Muestra una unica orquesta
 * \param lista array de orquestas
 * \param index int posicion del array a ser mostrada
 * \return int 0 si los datos se cargaron correctamente -1 si hubo un error
 */
int orq_PrintOnly(Orquestas* list, int index)
{
    int ret=-1;
    int tipoInt= 0;
    char pResult[51];

    if((list!=NULL)&& list[index].isEmpty==1)
    {
            printf("%d\t    %s\t   %s\t ",list[index].idOrq,
                                          list[index].name,
                                          list[index].lugar);
        tipoInt=list[index].tipoO;
        retTipChar(list, tipoInt ,pResult);
        printf("\t %s\n", pResult);
        ret=0;
    }
    return ret;
}

/** \brief print the content of array
*
* \param list *
* \param len int
* \return int 0 si los datos se cargaron correctamente -1 si hubo un error
*/
int orq_Print(Orquestas* list,int len)
{
    int ret=-1;
    int i;
    if(list!= NULL)
    {
        printf("ID\t   ORQUESTA\t     LUGAR\t      TIPO\n");
        for(i=0; i<len ; i ++)
        {
            if(list[i].isEmpty == 1)
            {
              orq_PrintOnly(list,i);
              ret=0;
            }
        }
    }
    else
        {
            printf("no hay datos cargados");
        }
    return ret;
}

/** \brief find an orquesta by Id en returns the index position in array.
** \param list *
* \param len int
* \param id int
* \return Return  index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*/
int orq_FindById(Orquestas* list, int len,int idOrq)
{
    int ret= -1;
    for (int i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1 && list[i].idOrq == idOrq)
            {
                ret = i;
                break;
            }
        }
    return ret;
}
/** \brief fuerza la carga de datos
 * \param array y tamaño
 * \return Return  (-1) if error 0 is ok
 *
 */

int hardcodearOrquesta(Orquestas* list, int len)
{
    int ret=-1;
    Orquestas bufferlist[]=
    {
        {1,generateIdOrq(), "Orquesta1", "Lugar1", 1},//"Sinfonica"},
        {1,generateIdOrq(), "Orquesta2", "Lugar1", 2},//"Camara"},
        {1,generateIdOrq(), "Orquesta3", "Lugar2", 3}, //"Filarmonica"},
        {1,generateIdOrq(), "Orquesta4", "Lugar3", 3},//"Filarmonica"},

    };
    for(int i=0; i<4; i++)
    {
        list[i] = bufferlist[i];
        system("cls");
        ret =0;
    }
    return ret;
}

/** \brief toma la informacion parasa y devuelve char
 * \param   lista de campos
 * \param largo de array
 * \param entero
 * \return char
 */

int retTipChar(Orquestas* list, int tipoInt, char* pResult)
{
    char ret=-1;
    char fil[]="Filarmonica";
    char sin[]="Sinfonica";
    char cam[]="Camara";
    if (list!= NULL)
    {
        switch(tipoInt)
        {
        case 1:
            strncpy(pResult,fil, sizeof(fil));
            ret=0;
         break;
        case 2:
            strncpy(pResult,sin, sizeof(sin));
            ret=0;
         break;
        case 3:
            strncpy(pResult,cam, sizeof(cam));
            ret=0;
         break;
        }//Swich
     }
    return ret;
}

/** \brief toma un valor int y devuelve char
 * \param estructura de orquestas
 * \param array de  orquestas y su tamaño
 * \return puntero a char
 */
char* orq_RetChar(Orquestas* list, int len, int idOrq)
{
    char* pOrquesta=NULL;

    if (list!= NULL && list >0 )
    {
        for (int i=0;i<len;i++)
        {
            if (idOrq==list[i].idOrq && list[i].isEmpty==1)
            {
               pOrquesta=list[i].name;
            }
        }
    }
    return pOrquesta;
}

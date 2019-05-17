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
                                for(int i=0; i<lenTip; i++)
                                     {
                                         printf("%d-%s \n", clase[i].idTip, clase[i].descripcion);
                                     }
                                tipoO= getValidInt("\nElija al tipo correspondiente: ","\n-INGRESO MAL EL DATO-\n", 0, 3);

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
int orq_PrintOnly(Orquestas* list,int index)
{
    int ret=-1;
    int largo= 0;
    char *tipoChar= NULL;
    int tipoInt= 0;

    if(list!=NULL)
    {
        printf("ID   NOMBRE  LUGAR  TIPO\n");
        if(list[index].isEmpty == 1)
        {
            printf("%d  %s    %s  ",list[index].idOrq,
                                    list[index].name,
                                    list[index].lugar);
        tipoInt=list[index].tipoO;
        tipoChar= retTipChar(clase, lenTip, tipoInt);
        printf("\t %s", tipoChar);
        largo=strlen(tipoChar);
        for(int i=0; i<10-largo; i++)
        {
            printf(" ");
        }
            ret=0;
        }
    }
    return ret;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param len int
* \return int 0 si los datos se cargaron correctamente 1 si hubo un error
*/
int orq_Print(Orquestas* list,int len)
{
    int ret=-1;
    int i;
    if(list!= NULL)
    {

        for( i=0; i<len ; i ++ )
        {
            if(list[i].isEmpty == 1)
            {
              orq_PrintOnly(list,i, clase);
              ret=0;
            }
        }
    }
    return ret;
}

/** \brief modifica datos existentes
 *
 * \param lista del array
 * \param tamaño del array
  * \param idPelis identidicacion del empleado a modificar
 * \return 0 si hubo alguna modificacion 1 si no se logro
 */

 /** \brief Remove a eEmployee  by Id (put isEmpty Flag in 1)
*
* \param eEmployee  *list: Pointer to Array of employees
* \param len int: length of the Array of employees
* \param id int: Unique identifier for each employee
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int orq_Delete(Orquestas* list, int len, TiposDORQ* clase, int lenTip)
{
    ret=-1;
    int idOrq;
    int confirmErase;
    int indexIs=-1;

    orq_Print(list, len, clase,lenTip);
    idOrq= getValidInt("\n Ingrese el ID de la Orquesta a eliminar:\n\n","ERROR", 0, 1000);
    indexIs= orq_FindById(list, len, idOrq);

    if (indexIs==-1)
    {
        printf("\nLa Orquesta no existe");
        system("pause");
    }
    else
    {
        system("cls");
        Orq_PrintOnly(list, indexIs);

        printf("\n\n\n Esta seguro que desea eliminar %s\n\n",list[indexIs].name);
        printf("\n\t 1-Si \t\t 2-No  \n\n? ");

        confirmErase=getche();

        while (confirmErase!=49&&confirmErase!=50)
        {
            printf("? ");
            confirmErase=getche();
        }

        if (confirmErase==49)
        {
            printf("\n\n %s ha sido eliminado!\n\n", lista[indexIs].name);
            peliculas[indexIs].isEmpty=0;
            ret=0;
            system("pause");
        }
    }//ELSE

    return ret;
}

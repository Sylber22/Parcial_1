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

int generateIdMus()
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
int mus_Init(Musico* reparto, int lenMus)
{
    int ret = -1;
     if ((reparto!=NULL) && (lenMus>0))
     {
        for(int i=0; i<lenMus; i++)
        {
            reparto[i].isEmpty= 0;
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
int mus_FindFree(Musico* reparto, int lenMus, int* pResult)
{
    int ret=-1;
    for(int i=0;i<lenMus;i++)
        {
            if(reparto[i].isEmpty==0)
            {
                (*pResult)=i;
                ret=0;
                break;
            }
            ret =-1;
        }
    return ret;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int mus_Add(Musico* reparto,int lenMus,
            Orquestas* list,int len,
            Instrumentos* clase, int lenIns)
{
    int ret=-1;
    char name[51];
    char lastName[51];
    int edad;
    int instrumento;
    int orquesta;
    int index;

    if(!mus_FindFree(reparto,lenMus, &index))
    {
        if((!getStringLetras(name,"Ingrese nombre del musico: ", "\n-INGRESO MAL EL DATO-\n", 2))&&
                  (!getStringLetras(lastName,"Ingrese apellido del musico: ", "\n-INGRESO MAL EL DATO-\n", 2)))
                  {
                    edad= getValidInt("\nIngrese edad del musico: ","\n-INGRESO MAL EL DATO-\n", 4, 100);
                    if(edad>4 && edad<100)
                       {
                            for (int i=0; i<lenIns; i++)
                            {
                                if(clase[i]. isEmpty==1)
                                {
                                   printf("\n%d-%s\t", clase[i].idIns, clase[i].name);
                                }
                            }
                            instrumento=getValidInt("\nIngrese el ID del instrumento que toca: ","\n-INGRESO MAL EL DATO-\n", 0, 21);
                            for (int i=0; i<len; i++)
                            {
                                if(list[i]. isEmpty==1)
                                {
                                    printf("\n%d-%s\t", list[i].idOrq, list[i].name);
                                }
                            }
                                orquesta=getValidInt("\nIngrese el ID de la orquesta a la que pertenece: ","\n-INGRESO MAL EL DATO-\n", 0, 51);
                            if(!mus_IsValidAdd(reparto,lenMus,name,lastName,edad,instrumento, orquesta,index))
                                {
                                    printf("-ALTA EXITOSA ID ASIGNADO: %d-\n", reparto[index].idMus);
                                    ret=0;
                                }//ALTA
                       }//ORQUESTA E INSTRUMENTO
                }//NOMBRE Y APELLIDO
            }//NULL
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
int mus_IsValidAdd(Musico* reparto,
                   int lenMus,
                   char* name,
                   char* lastName,
                   int edad,
                   int instrumento,
                   int orquesta,
                   int index)
{
    int ret=-1;
    Musico auxReparto;

   if ((index>=0) && (reparto !=NULL))
   {
       auxReparto.idMus= generateIdMus();
       strncpy(auxReparto.name, name,sizeof(auxReparto.name));
       strncpy(auxReparto.lastName, lastName,sizeof(auxReparto.lastName));
       auxReparto.edad= edad;
       auxReparto.instrumento= instrumento;
       auxReparto.orquesta= orquesta;
       auxReparto.isEmpty= 1;
       reparto[index] = auxReparto;
       ret=0;
   }
    return ret;
}

/** \brief Muestra un unico empleado
 * \param lista array de empleados
 * \param index int posicion del array a ser mostrada
 * \return int 0 si los datos se cargaron correctamente 1 si hubo un error
 */
int mus_PrintOnly(Musico* reparto, int index)
{
    int ret=-1;

    if((reparto!=NULL)&&(reparto[index].isEmpty == 1))
    {
        printf("%d\t    %s\t   %s\n ",reparto[index].idMus,
                                      reparto[index].name,
                                      reparto[index].lastName);
        ret=0;

    }
    return ret;
}

/** \brief print the content of array
*
* \param reparto *
* \param len int
* \return int 0 si los datos se cargaron correctamente -1 si hubo un error
*/
int mus_Print(Musico* reparto,int lenMus)
{
    int ret=-1;
    int i;
    if(reparto!= NULL)
    {
        printf("ID\t   NOMBRE\t    APELLIDO\n");
        for( i=0; i<lenMus ; i ++ )
        {
            if(reparto[i].isEmpty == 1)
            {
              mus_PrintOnly(reparto,i);
              ret=0;
            }
        }
    }
    return ret;
}
int mus_PrintOneAll(Musico* reparto, int index, Instrumentos* clase,int lenIns, Orquestas* list, int len)
{
    int ret=-1;
    int tipoIns= 0;
    int tipoOrq= 0;
    char* pOrquesta=NULL;
    char* pInstrumento=NULL;

     if((reparto!=NULL)&&(reparto[index].isEmpty == 1))
    {
        printf("%d\t    %s\t   %s\t  %d ",reparto[index].idMus,
                                          reparto[index].name,
                                          reparto[index].lastName,
                                          reparto[index].edad);
        tipoIns=reparto[index].instrumento;
        tipoOrq=reparto[index].orquesta;
        pInstrumento= ins_RetChar(clase, lenIns ,tipoIns);
        pOrquesta= orq_RetChar(list, tipoOrq, tipoOrq);
        printf("\t %s\t %s\n", pInstrumento, pOrquesta);

        ret=0;
    }
    return ret;
}
int mus_PrintAll(Musico* reparto,int lenMus, Instrumentos* clase,int lenIns, Orquestas* list, int len)
{
    int ret=-1;
    if(reparto!= NULL)
    {
        printf("ID\t   NOMBRE\t    APELLIDO     EDAD\t    INSTRUMENTO       ORQUESTA\n");
        for(int i=0; i<lenMus ; i ++ )
        {
            if(reparto[i].isEmpty == 1)
            {
              mus_PrintOneAll(reparto,i, clase, lenIns, list, len);
              ret=0;
            }
        }
    }
    return ret;
}
int mus_ModifyById(Musico* reparto, int lenMus, Instrumentos* clase, int lenIns, Orquestas* list, int len)
{
    int ret=-1;
    int IdAModificar;
    int campoAModificar;
    int index;

    mus_Print(reparto, lenMus);
    //mus_PrintAll(reparto, lenMus, clase, lenIns, list, len);
    IdAModificar=getValidInt("\nIngrese ID del musico que desea modificar: ","\n-INGRESO MAL EL DATO-\n", 0, 51);
    index= mus_FindById(reparto, lenMus, IdAModificar);
    if(index==-1)
    {
        printf("No existe el musico que quiere modificar");
    }
    else
    {
     mus_PrintOneAll(reparto, index, clase, lenIns, list, len);
    campoAModificar= getValidInt("\nIngrese '1' si desea modificar la edad o \n'2' si desea modificar la orquesta a la que pertenece: ", "\n-INGRESO MAL EL DATO-\n", 0,3);
    switch(campoAModificar)
    {
    case 1://EDAD
        reparto[index].edad =getValidInt("\nIngrese nueva edad del musico: ","\n-INGRESO MAL EL DATO-\n", 0,100);
        break;
    case 2://ORQUESTA
         orq_Print(list, len);
         reparto[index].orquesta =getValidInt("\nIngrese ID nuevo de la orquesta del musico: ","\n-INGRESO MAL EL DATO-\n", 0,1000);
        break;
    }//SWITCH
    printf("-Datos modificados con exito-\n");
    mus_PrintAll(reparto, lenMus, clase, lenIns, list, len);
    ret=0;
    }//ELSE
    return ret;
}

/** \brief encuentra un musico por su ID
 *
 * \param reparto, array
 * \param lenMus tamanio del array
 * \param id a buscar
 * \return direccion del ID encontrado
 */
int mus_FindById(Musico* reparto, int lenMus, int id)
{
    int ret=-1;
    for (int i=0; i<lenMus; i++)
    {
        if (reparto[i].idMus==id && reparto[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

 /** \brief Remove a musico  by Id (put isEmpty Flag in 1)
*
* \param musico  *list: Pointer to Array
* \param len int: length of the Array
* \param id int: Unique identifier for each musico
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a musico] - (0) if Ok
*
*/
int mus_Delete(Musico* reparto, int lenMus)
{
    int ret=-1;
    int idMus;
    int confirmErase;
    int index=-1;

    mus_Print(reparto, lenMus);
    idMus= getValidInt("\n Ingrese el ID del musico a eliminar:\n\n","ERROR", 0, 50);
    index= mus_FindById(reparto, lenMus, idMus);

    if (index==-1)
    {
        printf("\nEl musico no existe");
        system("pause");
    }
    else
    {
        system("cls");
        mus_PrintOnly(reparto, index);
        printf("\n\n\n Esta seguro que desea eliminar %s\n\n",reparto[index].name);
        printf("\n\t 1-Si \t\t 2-No  \n\n? ");
        confirmErase=getche();
        while (confirmErase!=49&&confirmErase!=50)
        {
            confirmErase=getche();
        }
        if (confirmErase==49)
        {
            printf("\n\n %s ha sido eliminado!\n\n", reparto[index].name);
            reparto[index].isEmpty=0;
            ret=0;
            system("pause");
        }
    }//ELSE
    return ret;
}

/** \brief fuerza la carga de datos
 * \param array y tamaño
 * \return Return  (-1) if error 0 is ok
 *
 */
int hardcodearMusicos(Musico* reparto,int lenMus)
{
    int ret=-1;

    Musico auxReparto[]=
    {
        {1,generateIdMus(),"Mus1", "Amus1", 30, 2,1},
        {1,generateIdMus(),"Mus2", "Amus2", 20, 4,2},
        {1,generateIdMus(),"Mus3", "Amus3", 25, 2,4},
        {1,generateIdMus(),"Mus4", "Amus4", 27, 1,4},
        {1,generateIdMus(),"Mus5", "Amus5", 22, 3,1},
        {1,generateIdMus(),"Mus6", "Amus6", 35, 4,3}
     //probar punto 4 y 1
          ,
        {1,generateIdMus(),"Mus7", "Poppo", 30, 1,3},
        {1,generateIdMus(),"Mus8", "Gokus", 20, 1,3},
        {1,generateIdMus(),"Mus9", "Trunks", 25, 1,3},
        {1,generateIdMus(),"Mus10", "Vegeta", 27, 1,3},
        {1,generateIdMus(),"Mus11", "Cadmio", 22, 1,3},
        {1,generateIdMus(),"Mus12", "Amus12", 30, 2,3},
        {1,generateIdMus(),"Mus13", "Amus13", 20, 3,3},
        {1,generateIdMus(),"Mus14", "Amus14", 25, 4,3}
    };
    for(int i=0; i<6; i++)//PARA PROBAR PUNTO 4 CAMBIAR A 14
    {
        reparto[i] = auxReparto[i];
        ret=0;
        system("cls");
    }
    return ret;
}

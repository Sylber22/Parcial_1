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

int generateIdIns()
{
    static int id = 0;
    id ++;
    return id;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in 0 in all
* position of the array
* \param clase * Pointer to array of clases
* \param lenIns int Array lenInsgth
* \return int Return (-1) if Error [Invalid lenInsgth or NULL pointer] - (0) if Ok
*
*/
int ins_Init(Instrumentos* clase, int lenIns)
{
    int ret = -1;
     if ((clase!=NULL) && (lenIns>0))
     {
        for(int i=0; i<lenIns; i++)
        {
            clase[i].isEmpty= 0;
            ret =0;
        }
     }
     return ret;
}
int hardcodearInstrumentos(Instrumentos* clase, int lenIns)
{
    int ret=-1;
    Instrumentos auxClase[]=
    {
        {1,generateIdIns(),"Inst1",1},
        {1,generateIdIns(),"Inst2",2},
        {1,generateIdIns(),"Inst3",3},
        {1,generateIdIns(),"Inst4",4},
    };

    for(int i=0; i<4; i++)
    {
        clase[i] = auxClase[i];
        system("cls");
        ret=0;
    }
    return ret;
}
/** \brief toma un valor int y devuelve char
 * \param estructura de instrumentos
 * \param array de  instrumentos y su tamaño
 * \return puntero a char
 */
char* ins_RetChar(Instrumentos* clase, int lenIns, int idIns)
{
    char* pInstrumento=NULL;

    if (clase!= NULL && clase >0 )
    {
        for (int i=0;i<lenIns;i++)
        {
            if (idIns==clase[i].idIns && clase[i].isEmpty==1)
            {
               pInstrumento=clase[i].name;
           ///    printf("\n%s\n", clase[i].name);
          ///     printf("\n%s\n", genreDescripcion);
            }
        }
    }
    return pInstrumento;
}

/** \brief This funcion look for the fist empty place in the array
 * \param clase Pointer to array of instruments
 * \param len int Array length
 * \param pResult pointer type int* to the empty direccion
 * \return int Return (-1) if Error [Invalid length or NULL pointer] -
     (0) if Ok-1 if there is no empty place
 */
int ins_FindFree(Instrumentos* clase, int lenIns, int* pResult)
{
    int ret=-1;
    for(int i=0;i<lenIns;i++)
        {
            if(clase[i].isEmpty==0)
            {
                (*pResult)=i;
                ret=0;
                break;
            }
        }
    return ret;
}

/** \brief carga un nuevo instrumento
* \param array de la estructura
* \param lenIns tamaño del array
* \return int Return (-1) if Error [Invalid length or
    NULL pointer or without free space] - (0) if Ok
*/
int ins_Add(Instrumentos* clase, int lenIns)
{
    int ret=-1;
    char name[51];
    int tipo;
    int index;

    if(!ins_FindFree(clase,lenIns, &index))
    {
        if(!getStringLetras(name,"Ingrese nombre del instrumento: ", "\n-INGRESO MAL EL DATO-\n", 2))
                {
                    tipo= getValidInt("\n1)Cuerdas\n2)Viento-Madera\n3)Viento-Metal\n4)Percusion\nIngrese tipo de instrumento: ","\n-INGRESO MAL EL DATO-\n", 0, 4);
                     if(!ins_IsValidAdd(clase,lenIns,name,tipo,index))
                        {
                            printf("-ALTA EXITOSA ID ASIGNADO: %d-\n", clase[index].idIns);
                            ret=0;
                        }//ALTA
                }//NOMBRE
    }//FREE
    else
    {
        printf("No hay lugar para otra carga.");
    }
    return ret;
}

/** \brief add in a existing list of instruments the values received as parameters
* in the first empty position
* \param clase*
* \param lenIns int
* \param name[] char
* \param tipo char
* \param index lugar
* \return int Return (-1) if Error [Invalid length or
NULL pointer or without free space] - (0) if Ok
*/
int ins_IsValidAdd(Instrumentos* clase,
                   int lenIns,
                    char* name,
                    int tipo,
                    int index)
{
    int ret=-1;
    Instrumentos auxClase;

   if ((index>=0) && (clase !=NULL))
   {
       auxClase.idIns= generateIdIns();
       strncpy(auxClase.name, name,sizeof(auxClase.name));
       auxClase.tipo= tipo;
       auxClase.isEmpty= 1;
       clase[index] = auxClase;
       ret=0;
   }
    return ret;
}
/** \brief imprime un instrumento
* \param clase
* \param len int
* \param index lugar
* \return int Return (-1) if Error [Invalid length or
NULL pointer or without free space] - (0) if Ok
*/
int ins_PrintOnly(Instrumentos* clase, int lenIns,int index)
{
    int ret=-1;
    int tipoInt=0;
    char pResult[51];

    if(clase!=NULL)
    {
        printf("%d\t  %s ",clase[index].idIns,
                           clase[index].name);
        tipoInt=clase[index].tipo;
        ins_RetTipChar(clase, tipoInt, pResult);
        printf("\t%s\n", pResult);
        ret=0;
    }
    return ret;
}

/** \brief print the content of array
*
* \param clase *
* \param len int
* \return int 0 si los datos se cargaron correctamente -1 si hubo un error
*/
int ins_Print(Instrumentos* clase, int lenIns)
{
    int ret=-1;
    if(clase!= NULL)
    {
        printf("ID\t   NOMBRE\t    TIPO\n");
        for(int i=0; i<lenIns ; i ++ )
        {
            if(clase[i].isEmpty == 1)
            {
              ins_PrintOnly(clase, lenIns, i);
              ret=0;
            }
        }
    }
    return ret;
}
/** \brief toma un valor int y devuelve char
 * \param estructura de instrumentos
 * \param array de  instrumentos
 * \param tipo int instrumentos
 * \return puntero a char con el numero elegido
 */
int ins_RetTipChar(Instrumentos* clase, int tipoInt, char* pResult)
{
    char ret=-1;
    char cue[]="Cuerdas";
    char viema[]="Viento-Madera";
    char vieme[]="Viento-Metal";
    char per[]="Percusion";
    if (clase!= NULL)
    {
        switch(tipoInt)
        {
        case 1:
            strncpy(pResult,cue, sizeof(cue));
            ret=0;
         break;
        case 2:
            strncpy(pResult,viema, sizeof(viema));
            ret=0;
         break;
        case 3:
            strncpy(pResult,vieme, sizeof(vieme));
            ret=0;
         break;
            case 4:
            strncpy(pResult,per, sizeof(per));
            ret=0;
         break;
        }//Swich
     }
    return ret;
}

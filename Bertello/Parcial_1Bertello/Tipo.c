#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "Biblo_UTN.h"
#include "Validaciones.h"
#include "Tipo.h"


int generateIdTip()
{
    static int id = 0;
    id ++;
    return id;
}
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in 0 in all
* position of the array
* \param clase Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int tip_Init(TiposDORQ* clase, int lenTip)
{
    int ret = -1;
     if ((clase!=NULL) && (lenTip>=0))
     {
        for(int i=0; i<lenTip; i++)
        {
            clase[i].isEmpty= 0;
            ret =0;
        }
     }
     return ret;
}


char* retTipChar(TiposDORQ* clase, int lenTip, int idTip)
{
    char *tipsDescripcion=NULL;

    if (clase!= NULL && clase >0 )
    {
        for (int i=0; i<lenTip; i++)
        {
            if (idTip== clase[i].idTip && clase[i].isEmpty==1)
            {
               tipsDescripcion=clase[i].descripcion;
           //    printf("\n%s\n", clase[i].descripcion);
          //    printf("\n%s\n", genreDescripcion);
            }
        }
    }
    return tipsDescripcion;
}

int hardcodearTipoOrquesta(TiposDORQ* clase, int lenTip)
{
    int ret=-1;
    printf("ID\t    TIPO DE ORQUESTA\n");
    TiposDORQ bufferclase[]=
    {
        {1,generateIdOrq(), "Sinfonica"},
        {1,generateIdOrq(), "Filarmonica"},
        {1,generateIdOrq(), "Camara"}
    };
    for(int i=0; i<lenTip; i++)
    {
        clase[i] = bufferclase[i];
        ret =0;
    }
    return ret;
}

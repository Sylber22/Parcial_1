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
#include "Informes.h"

/** \brief Imprime el menu de opciones
 * \param void
 * \return opcion elegida
 */
int menuInformes()
{
    int opcionElegida;
    printf("\n---------MENU DE INFORMES-----------\n");
    printf("1)Listar las orquestas con mas de 5 musicos, indicando ID de orquesta, \nnombre, tipo y lugar.\n\n");
    printf("2)Imprimir musicos mayores de 30 anios.\n\n");
    printf("3)Listar las orquestas de un lugar en particular ingresado por el usuario.\nImprimir ID de orquesta, nombre, tipo y lugar.\n\n");
    printf("4)Una orquesta se encuentra completa si, posee al menos\n 5 instrumentos de  cuerda, 3 de viento (cualquiera de los dos tipos) y \n 2 de percusion.Listar las orquestas completas.\n\n");
    printf("5)Listar los musicos de una orquesta determinada(ingresando su ID), \nindicando nombre, apellido, edad, nombre y tipo de instrumento.\n\n");
    printf("6)Imprimir la orquesta con mas musicos, indicando todos sus datos\n y la cantidad de musicos que posee.\n\n");
    printf("7)Listar los musicos que tocan instrumentos de cuerdas, imprimiendo nombre y \napellido, edad, nombre y tipo de instrumento que toca. Ordenado por apellido.\n\n");
    printf("8)Imprimir el promedio de musicos por orquesta.\n\n");
    getInt(&opcionElegida,"9)Salir\n\nOPCION: ", "\n-INGRESO MAL EL DATO-\n");
   return opcionElegida;
}

/** \brief Imprime lista de orquestas con mas musicos
 * \param estructura de musicos y orquestas
 * \param array de musicos y orquestas y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int orq_PrintMostMusic(Musico* reparto, int lenMus, Orquestas* list, int len)
{
    int ret=-1;
    int i;
    int j;
    int idOrq;
    int contadorMusicos=0;
    int tipoInt= 0;
    char pResult[51];


    if(len>0 && list!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                idOrq=list[i].idOrq;
                for(j=0; j<lenMus; j++)
                {
                    if(reparto[j].isEmpty==1 && reparto[j].orquesta==idOrq)
                    {
                        contadorMusicos++;
                    }
                }
                if(contadorMusicos>5)
                {
                    printf("\nID\t ORQUESTA\t  TIPO\t LUGAR\n");
                      printf("%d\t %s\t  ",list[i].idOrq,
                                                     list[i].name);
                      tipoInt=list[i].tipoO;
                      retTipChar(list, tipoInt ,pResult);
                      printf("%s\t  %s\n", pResult,list[i].lugar );
                    ret=0;
                }
            }
            contadorMusicos =0;
        }
    }
    return ret;

}

/** \brief Imprime lista de orquestas alfabeticamente
 * \param estructura de  orquestas
 * \param array de orquestas y su tamaño
 * \return -1 si hubo error y 0 si esta ok
 */
int orq_PrintByAlfabeticOrquesta(Orquestas* list, int len)
{
    int ret=-1;
    int i=0;
    int j=0;
    int largo=0;

    Orquestas auxList;
    Orquestas listCopia[len];

    for (int h=0; h<len; h++)
    {
        listCopia[h]=list[h];
    }
    printf ("\n\n");

    for (i=1; i < len; i++)
    {
        auxList= listCopia[i];
        j = i-1;
        while (strcmp(listCopia[j].name,auxList.name)>0 && j>=0)
        {
            listCopia[j+1] = listCopia[j];
            j--;
        }
        listCopia[j+1] = auxList;
    }
    printf("\nID\t ORQUESTA\t\t   LUGAR");

    for (int k=0; k<len; k++)
    {
        if (listCopia[k].isEmpty==1)
        {
            printf("\n%d\t",listCopia[k].idOrq);
            printf("%s ",listCopia[k].name);
            largo=strlen(listCopia[k].name);
            for(int l=0; l<25-largo; l++)
            {
                printf(" ");
            }
            printf("\t%s",listCopia[k].name);
            ret=0;
        }//IF
    }
    return ret;
}

/** \brief Imprime lista de orquestas de un lugar ingresado por el usuario
 * \param estructura de  orquestas
 * \param array de orquestas y su tamaño
 * \return -1 si hubo error y 0 si esta ok
 */
int orq_PrintByPlace(Orquestas* list, int len)
{
    char auxLugar[51];
    int i;
    int ret=-1;
    int tipoInt= 0;
    char pResult[51];

    if(!getStringAlpha(auxLugar,"Ingrese lugar de la orquesta: ", "\n-INGRESO MAL EL DATO-\n", 2))
    {
        for(i= 0; i <len; i++)
        {
            if(!strncmp(list[i].lugar, auxLugar, len) && list[i].isEmpty == 1)
            {
                printf("\nID\t    NOMBRE\t    TIPO\t    LUGAR\n");
                printf("%d\t  %s\t ", list[i].idOrq,
                                          list[i].name);
                tipoInt=list[i].tipoO;
                retTipChar(list, tipoInt ,pResult);
                printf("\t %s\t %s\n", pResult,list[i].lugar);
                ret=0;
            }

        }//FOR
    }
    return ret;
}

/** \brief Imprime lista de orquestas que estan completas
 * \param estructura de musicos y orquestas
 * \param array de musicos y orquestas y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int mus_CompleteOrquesta(Musico* reparto, int lenMus, Orquestas* list, int len)
{
    int ret=-1;
    int i;
    int j;
    int idOrq;
    int contadorInsCuerda=0;
    int contadorInsViento=0;
    int contadorInsPercu=0;

    if(len>0 && list!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                idOrq=list[i].idOrq;
                for(j=0; j<lenMus; j++)
                {
                    if(reparto[j].isEmpty==1 && reparto[j].orquesta==idOrq)// HASTA ACA Q MUSICOS PERTENECEN A LA MISMA ORQUESTA
                    {
                        switch(reparto[j].instrumento)
                        {
                            case 1: contadorInsCuerda++;
                            break;
                            case 2: contadorInsViento++;
                            break;
                            case 3: contadorInsViento++;
                            break;
                            case 4: contadorInsPercu++;

                        }
                    }//IF
                }
                if((contadorInsCuerda>=5)&&(contadorInsViento>=3)&&(contadorInsPercu>=2))
                {
                   // printf("ORQUESTA COMPLETA Cuerdas: %d -Viento: %d-Percusion: %d", contadorInsCuerda, contadorInsViento, contadorInsPercu);
                    printf("-ID: %d - NOMBRE: %s - TIPO: %d - LUGAR: %s \n ",list[i].idOrq,
                                                                                list[i].name,
                                                                                list[i].tipoO,
                                                                                list[i].lugar);
                         ret=0;
                }
            }//IF ISeMPTY
        contadorInsCuerda=0;
        contadorInsPercu=0;
        contadorInsViento=0;
        }
    }
    return ret;
}

/** \brief Imprime lista de musicos de mas de una edad, la orquesta a la que pertenece y su instrumento
 * \param estructura de instrumentos,musicos y orquestas
 * \param array de instrumentos, musicos, orquestas y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int mus_PrintByAge(Musico* reparto, int lenMus, Instrumentos* clase,int lenIns, Orquestas* list, int len)
{
    int ret=-1;
    int tipoIns= 0;
    int tipoOrq= 0;
    char* pOrquesta=NULL;
    char* pInstrumento=NULL;


     for(int i = 0; i < lenMus; i++)
    {
        if((reparto[i].edad)> 30 && reparto[i].isEmpty == 1)
        {
            printf("\nID\t  NOMBRE    APELLIDO\t  EDAD\t  INSTRUMENTO\t  ORQUESTA\n");
            printf("%d\t  %s\t  %s\t \t %d\t ", reparto[i].idMus,
                                               reparto[i].name,
                                               reparto[i].lastName,
                                               reparto[i].edad);
        tipoIns=reparto[i].instrumento;
        tipoOrq=reparto[i].orquesta;
        pInstrumento= ins_RetChar(clase, lenIns ,tipoIns);
        pOrquesta= orq_RetChar(list, tipoOrq, tipoOrq);
        printf("\t %s\t %s\n", pInstrumento, pOrquesta);
        ret=0;
        }
    }
    return ret;
}

/** \brief ordena por apellido
 * \param estructura de musicos
 * \param array de musicos y su tamaño
 * \return -1 si hubo error y 0 si esta ok
 */
int mus_OrderByLastName(Musico* reparto, int lenMus)
{
    int ret=-1;
    int i, j;
    Musico auxReparto;

    for (i = 1; i < lenMus; i++)
    {
        auxReparto = reparto[i];
        j = i - 1;
        while ((j >= 0) && strcmp(auxReparto.lastName, reparto[j].lastName)<0)
        {
            reparto[j + 1] = reparto[j];
            j--;
            ret=0;
        }
        reparto[j + 1] = auxReparto;
    }
    return ret;
}

/** \brief Imprime lista de musicos con su instrunebto
 * \param estructura de instrumentos y musicos
 * \param array de instrumentos y musicos y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int mus_PrintInsType(Musico* reparto, int i, Instrumentos* clase,int lenIns)
{
    int ret=-1;
    int tipoInt=0;
    int tipoIns=0;
    char* pInstrumento=NULL;
    char pResult[51];

        if(reparto!=NULL)
        {
                printf("%d\t    %s\t   %s\t  %d ",reparto[i].idMus,
                                                  reparto[i].name,
                                                  reparto[i].lastName,
                                                  reparto[i].edad);

        tipoInt=reparto[i].instrumento;
        tipoIns=reparto[i].instrumento;
        pInstrumento= ins_RetChar(clase, lenIns ,tipoIns);
        ins_RetTipChar(clase, tipoInt,pResult);
        printf("\t %s\t %s\n", pInstrumento, pResult );
        ret=0;
        }
        return ret;
}

/** \brief Imprime lista de musicos ordenado por apellido con su instrumento
 * \param estructura de instrumentos,musicos y orquestas
 * \param array de instrumentos, musicos, orquestas y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int mus_TypeOfInstrument(Musico* reparto, int lenMus, Orquestas* list, int len, Instrumentos* clase,int lenIns)
{
   int ret=-1;
   if(reparto!=NULL)
    {
        printf("\nID\t    NOMBRE\t   APELLIDO\t  EDAD\t INSTRUMENTO   TIPO\n");
        for(int i = 0; i < lenMus; i++)
        {
         mus_OrderByLastName(reparto, lenMus);
         if((reparto[i].instrumento== 1)&&(reparto[i].isEmpty == 1))
            {
              mus_PrintInsType(reparto,i, clase, lenIns);
              ret=0;
            }
        }
    }
    return ret;
}

/** \brief pone el isEmpty de la orquesta deseada con sus musicos en 1
 * \param estructura de musicos y orquestas
 * \param array de  musicos y orquestas y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int orq_Delete(Orquestas* list, int len, Musico* reparto,int lenMus)
{
    int ret=-1;
    int idOrq;
    int confirmErase;
    int index=-1;

    orq_Print(list, len);
    idOrq= getValidInt("\n Ingrese el ID de la Orquesta a eliminar:\n\n","ERROR", 0, 1000);
    index= orq_FindById(list, len, idOrq);

    if (index==-1)
    {
        printf("\nLa Orquesta no existe");
        system("pause");
    }
    else
    {
        system("cls");
        orq_PrintOnly(list,  index);

        printf("\n\n\n Esta seguro que desea eliminar %s\n\n",list[index].name);
        printf("\n\t 1-Si \t\t 2-No  \n\n? ");

        confirmErase=getche();

        while (confirmErase!=49&&confirmErase!=50)
        {
            printf("? ");
            confirmErase=getche();
        }

        if (confirmErase==49)
        {
            list[index].isEmpty=0;
            for(int i=0; i<lenMus; i++)
            {
                if((reparto[i].orquesta==idOrq )&& (reparto[index].isEmpty==1))
                {
                    reparto[i].isEmpty=0;
                    ret=0;
                }
            }
        printf("\n\n %s ha sido eliminado junto con los musicos que la componen!\n\n", list[index].name);
        system("pause");
        }
    }//ELSE
    return ret;
}

/** \brief imprime la orquesta con mas musicos
 * \param estructura de musicos y orquestas
 * \param array de  musicos y orquestas y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int mus_Must(Musico* reparto, int lenMus, Orquestas* list, int len)
{
    int ret=-1;
    int i;
    int j;
    int idOrq;
    int contadorMusicos=0;
    int tipoInt= 0;
    char pResult[51];

    if(len>0 && list!=NULL)
    {
        printf("ID\t   ORQUESTA\t     LUGAR\t   TIPO\t    CANT DE MUSICOS\n");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                idOrq=list[i].idOrq;
                for(j=0; j<lenMus; j++)
                {
                    if(reparto[j].isEmpty==1 && reparto[j].orquesta==idOrq)
                    {
                        contadorMusicos++;
                    }
                }
                if(contadorMusicos>0)
                {
                    printf("%d\t  %s\t  ",list[i].idOrq,
                                        list[i].name);
                    tipoInt=list[i].tipoO;
                    retTipChar(list, tipoInt ,pResult);
                    printf(" %s\t %s\t\t %d\n",list[i].lugar, pResult, contadorMusicos);
                    ret=0;
                }
            }
            contadorMusicos =0;
        }
    }
    return ret;
}

/** \brief imprime los musicos de una orquesta
 * \param estructura de instrumentos,musicos y orquestas
 * \param array de  instrumentos, musicos y orquestas y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int mus_PrintMusicByOrquesta(Orquestas* list, int len, Musico* reparto, int lenMus, Instrumentos* clase, int lenIns)
{
    int auxOrq;
    int i;
    int ret=-1;
    int tipoIns= 0;
    int tipoInt=0;
    char* pInstrumento=NULL;
    char pResult[51];

    auxOrq=getValidInt("Ingrese ID de la orquesta: ", "\n-INGRESO MAL EL DATO-\n",0 , 50);
    orq_FindById(list, len, auxOrq);

    if(list!=NULL && len>0)
    {
        printf("\nID\t   NOMBRE   APELLIDO\t EDAD\t  INSTRUMENTO\t  TIPO\n");
        for(i= 0; i <len; i++)
        {
            if(reparto[i].orquesta== auxOrq && reparto[i].isEmpty == 1)
            {
                printf("%d\t  %s\t  %s\t\t %d", reparto[i].idMus,
                                           reparto[i].name,
                                           reparto[i].lastName,
                                           reparto[i].edad);
            tipoIns=reparto[i].instrumento;
            pInstrumento= ins_RetChar(clase, lenIns ,tipoIns);
            tipoInt=clase[i].tipo;
            ins_RetTipChar(clase, tipoInt, pResult);
            printf("\t %s\t\t %s\n", pInstrumento, pResult);
            ret=0;
            }//IF
        }//FOR
    } else{
            printf("Esta orquesta no posee musicos aun.\n");
    }
    return ret;
}
/** \brief imprime promedio de musicos
 * \param estructura de musicos y orquestas
 * \param array de  musicos y orquestas y sus tamaños
 * \return -1 si hubo error y 0 si esta ok
 */
int mus_PrintAverage(Musico* reparto, int lenMus, Orquestas* list, int len)
{
    int ret=-1;
    int i;
    int j;
    int idOrq;
    int contadorMusicos=0;
    int contadorDeOrquestas=0;
    float promedio;

    if(len>0 && list!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
               contadorDeOrquestas++;
                idOrq=list[i].idOrq;
                for(j=0; j<lenMus; j++)
                {
                    if(reparto[j].isEmpty==1 && reparto[j].orquesta==idOrq)
                    {
                        contadorMusicos++;
                    }
                }
            }
        }//FOR
        promedio=(float)contadorMusicos/(float)contadorDeOrquestas;
        ret=0;
        printf("PROMEDIO DE MUSICOS POR ORQUESTAS: %.2f ", promedio);
    }
    return ret;
}

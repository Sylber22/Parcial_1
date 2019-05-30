#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "Biblo_UTN.h"
#include "Validaciones.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "Informes.h"


#define CANT_ORQ 50
#define CANT_INS 20
#define CANT_MUS 1000

int main()
{
    char seguir= 's';
    Orquestas listaDeOrquestas[CANT_ORQ];
    Instrumentos listaDeInstrumentos[CANT_INS];
    Musico listaDeMusicos[CANT_MUS];

    //------------------------------------
    orq_Init(listaDeOrquestas, CANT_ORQ);
    ins_Init(listaDeInstrumentos, CANT_INS);
    mus_Init (listaDeMusicos, CANT_MUS);

    //------------------------------------
      hardcodearMusicos( listaDeMusicos, CANT_MUS);
      hardcodearOrquesta( listaDeOrquestas, CANT_ORQ);
      hardcodearInstrumentos(listaDeInstrumentos, CANT_INS);



    do
    {
        switch(menu())
        {
        case 1://ALTA ORQUESTA
            if(orq_Add(listaDeOrquestas, CANT_ORQ)==-1)
            {
                printf("No se pudo completar el alta");
            }
            break;
        case 2://ELIMINAR ORQUESTA
            if(!orq_Delete(listaDeOrquestas, CANT_ORQ, listaDeMusicos, CANT_MUS))
            {
                printf("bien");
            }
            break;
        case 3://IMPRIMIR ORQUESTAS
                orq_Print(listaDeOrquestas, CANT_ORQ);
            break;
        case 4://AGREGAR MUSICO
                mus_Add(listaDeMusicos, CANT_MUS, listaDeOrquestas, CANT_ORQ, listaDeInstrumentos, CANT_INS);
            break;
        case 5://MODIFICAR MUSICO
                mus_ModifyById(listaDeMusicos, CANT_MUS, listaDeInstrumentos, CANT_INS, listaDeOrquestas, CANT_ORQ);
            break;
        case 6://ELIMINAR MUSICO
                mus_Delete(listaDeMusicos, CANT_MUS);
            break;
        case 7://IMPRIMIR MUSICO
               mus_PrintAll(listaDeMusicos, CANT_MUS,listaDeInstrumentos, CANT_INS, listaDeOrquestas, CANT_ORQ);
             // mus_Print(listaDeMusicos, CANT_MUS);
            break;
        case 8://AGREGAR INSTRUMENTO
              ins_Add(listaDeInstrumentos, CANT_INS);
            break;
        case 9://IMPRIMIR INSTRUMENTO
              ins_Print(listaDeInstrumentos, CANT_INS);
            break;
        case 10://INFORMES
            do
                {
                switch(menuInformes())
                {
                case 1://LISTAR ORQUESTA
                    if(orq_PrintMostMusic(listaDeMusicos, CANT_MUS, listaDeOrquestas, CANT_ORQ)==-1)
                    {
                        printf("No hay orquestas con mas de 5 musicos.\n");
                    }
                     system("pause");
                  break;
                case 2:
                     if(mus_PrintByAge(listaDeMusicos, CANT_MUS, listaDeInstrumentos, CANT_INS, listaDeOrquestas, CANT_ORQ)==-1)
                    {
                        printf("No hay musicos mayores de 30 anios\n");
                    }
                     system("pause");
                 break;
                   case 3:
                       if(orq_PrintByPlace(listaDeOrquestas, CANT_ORQ)==-1)
                         {
                            printf("No hay orquestas en este lugar.\n");
                        }
                         system("pause");
                  break;
                  case 4:
                        if(mus_CompleteOrquesta(listaDeMusicos, CANT_MUS, listaDeOrquestas, CANT_ORQ)==-1)
                        {
                            printf("No hay orquestas que esten completas\n");
                        }
                         system("pause");
                   break;
                    case 5://MUSICOS DE UNA ORQUESTA
                        mus_PrintMusicByOrquesta(listaDeOrquestas, CANT_ORQ, listaDeMusicos, CANT_MUS, listaDeInstrumentos, CANT_INS);
                    break;
                    case 6:
                        mus_Must(listaDeMusicos, CANT_MUS, listaDeOrquestas, CANT_ORQ);
                  break;
                       case 7://CUERDAS
                        mus_TypeOfInstrument(listaDeMusicos, CANT_MUS, listaDeOrquestas, CANT_ORQ, listaDeInstrumentos, CANT_INS);
                  break;
                       case 8:
                        mus_PrintAverage(listaDeMusicos, CANT_MUS, listaDeOrquestas, CANT_ORQ);
                        break;
                       case 9://EXIT
            seguir='n';
            printf("EXIT ==>");
              break;
                }//SWITCH MENU INFORMES
                }while(seguir == 's');
            break;
        case 11://SALIR
            seguir='n';
            printf("EXIT ==>");
            break;
        default :
            system("pause");
            system("cls");
        }//FINSWITCH
    }while(seguir == 's');











return 0;
}



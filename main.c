#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "Biblo_UTN.h"
#include "Validaciones.h"
#include "Orquesta.h"
#include "Tipo.h"

#define CANT_TIP 3
#define CANT_ORQ 50
#define CANT_INS 20
#define CANT_MUS 1000

int main()
{
    char seguir= 's';
    Orquestas listaDeOrquestas[CANT_ORQ];
    TiposDORQ tiposDeInstrumentos[CANT_TIP];
    //------------------------------------
    orq_Init(listaDeOrquestas, CANT_ORQ);

    do
    {
        switch(menu())
        {
        case 1://ALTA ORQUESTA
            if(!orq_Add(listaDeOrquestas, CANT_ORQ, tiposDeInstrumentos, CANT_TIP))
            {
                printf("No se pudo completar el alta");
            }
            break;
        case 2://ELIMINAR ORQUESTA
            if(!orq_Delete(listaDeOrquestas, CANT_ORQ);
            {
                printf("No se pudo completar la eliminacion");
            }
            break;
        case 3://IMPRIMIR
           orq_Print(listaDeOrquestas, CANT_ORQ))
            break;
        case 4://LISTAR
               printf("Listar");
            break;
            case 5://LISTAR
               printf("Listar");
            break;
            case 6://LISTAR
               printf("Listar");
            break;
            case 7://LISTAR
               printf("Listar");
            break;
            case 8://LISTAR
               printf("Listar");
            break;
            case 9://LISTAR
               printf("Listar");
            break;
        case 10://SALIR
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



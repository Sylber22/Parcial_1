#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
#include "Tipo.h"

typedef struct
{
    int isEmpty;
    int idOrq;
    char* name[51];
    char* lugar[51];
    int tipoO;
}Orquestas;
//--------------------------
int orq_FindFree(Orquestas* list, int len, int* pResult);
int orq_Init(Orquestas* list, int len);
int orq_Add(Orquestas* list,int len, TiposDORQ* clase, int lenTip);
int orq_IsValidAdd(Orquestas* list, int len, char* name, char* lugar, int tipo, int index);
int orq_Delete(Orquesta....)
//-------------------------
int generateIdOrq();

#endif // ORQUESTA_H_INCLUDED

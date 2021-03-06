#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int isEmpty;
    int idOrq;
    char name[51];
    char lugar[51];
    int tipoO;
}Orquestas;
//--------------------------
int orq_FindFree(Orquestas* list, int len, int* pResult);
int orq_Init(Orquestas* list, int len);
int orq_Add(Orquestas* list,int len);
int orq_IsValidAdd(Orquestas* list, int len, char* name, char* lugar, int tipo, int index);
int orq_PrintOnly(Orquestas* list,int index);
int orq_Print(Orquestas* list,int len);

int orq_FindById(Orquestas* list,int len,int idOrq);
int retTipChar(Orquestas* list,int tipoInt, char* pResult);
char* orq_RetChar(Orquestas* list, int len, int idOrq);
//-------------------------
int generateIdOrq();
int hardcodearOrquesta(Orquestas* list, int len);
#endif // ORQUESTA_H_INCLUDED

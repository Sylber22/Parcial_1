#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "Instrumento.h"

typedef struct
{
    int isEmpty;
    int idMus;
    char name[51];
    char lastName[51];
    int edad;
    int instrumento;
    int orquesta;
}Musico;
//--------------------------
int mus_Init(Musico* reparto, int lenMus);
int mus_FindFree(Musico* reparto, int lenMus, int* pResult);
int mus_Add(Musico* reparto,int lenMus,
            Orquestas* list,int len,
            Instrumentos* clase, int lenIns);
int mus_IsValidAdd(Musico* reparto,
                   int lenMus,
                   char* name,
                   char* lastName,
                   int edad,
                   int instrumento,
                   int orquesta,
                   int index);

int mus_PrintOnly(Musico* reparto,int index);
int mus_Print(Musico* reparto,int lenMus);
int mus_PrintOneAll(Musico* reparto,int index,
                    Instrumentos* clase,int lenIns,
                    Orquestas* list, int len);
int mus_PrintAll(Musico* reparto,int lenMus,
                 Instrumentos* clase, int lenIns,
                 Orquestas* list, int len);
int mus_PrintInsType(Musico* reparto, int i, Instrumentos* clase,int lenIns);
int mus_ModifyById(Musico* reparto, int lenMus,
                   Instrumentos* clase, int lenIns,
                   Orquestas* list, int len);
int mus_FindById(Musico* reparto, int lenMus, int id);
int mus_Delete(Musico* reparto, int lenMus);
//--------------------------
int hardcodearMusicos(Musico* reparto,int lenMus);
int generateIdMus();
#endif // MUSICO_H_INCLUDED

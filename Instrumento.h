#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    int isEmpty;
    int idIns;
    char name[51];
    int tipo;
  }Instrumentos;
//---------------------------
int ins_Init(Instrumentos* clase, int lenIns);
char* ins_RetChar(Instrumentos* clase, int lenIns, int idIns);
int ins_RetTipChar(Instrumentos* clase, int tipoInt, char* pResult);
int ins_FindFree(Instrumentos* clase, int lenIns, int* pResult);
int ins_Add(Instrumentos* clase, int lenIns);
int ins_IsValidAdd(Instrumentos* clase,
                    int lenIns,
                    char* name,
                    int tipo,
                    int index);
int ins_PrintOnly(Instrumentos* clase,int lenIns, int index);
int ins_Print(Instrumentos* clase,int lenIns);
//------------------------------
int generateIdIns();
int hardcodearInstrumentos(Instrumentos* clase, int lenIns);
#endif // INSTRUMENTO_H_INCLUDED

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

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

int menuInformes();
//-----------------------------------
int orq_PrintMostMusic(Musico* reparto, int lenMus, Orquestas* list, int len);
int orq_PrintByAlfabeticOrquesta(Orquestas* list, int len);
int orq_PrintByPlace(Orquestas* list, int len);
int orq_Delete(Orquestas* list,int len, Musico* reparto,int lenMus);
//------------------------------------
int mus_CompleteOrquesta(Musico* reparto, int lenMus, Orquestas* list, int len);
int mus_PrintByAge(Musico* reparto, int lenMus,Instrumentos* clase,
                   int lenIns, Orquestas* list, int len);
int mus_OrderByLastName(Musico* reparto, int lenMus);
int mus_TypeOfInstrument(Musico* reparto, int lenMus,
                         Orquestas* list, int len,
                         Instrumentos* clase,int lenIns);
int mus_Must(Musico* reparto, int lenMus, Orquestas* list, int len);
int mus_PrintMusicByOrquesta(Orquestas* list, int len,
                             Musico* reparto, int lenMus,
                             Instrumentos* clase, int lenIns);
int mus_PrintAverage(Musico* reparto, int lenMus, Orquestas* list, int len);

#endif // INFORMES_H_INCLUDED

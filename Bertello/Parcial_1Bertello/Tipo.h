#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int isEmpty;
    int idTip;
    char descripcion[51];
}TiposDORQ;

int generateIdTip();
int tip_Init(TiposDORQ* clase, int lenTip);
int hardcodearTipoOrquesta(TiposDORQ* clase, int lenTip);
//---------------------------------------------------
char* retTipChar(TiposDORQ* clase, int lenTip, int idTips);
#endif // TIPO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "Biblo_UTN.h"
#include "Validaciones.h"

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado donde se carga el resultado
 * \return '-1' si hubo un error y '0' si esta todo bien
 */
int getInt(int* pResultado, char* msg, char* msgError)
{
    int buffer;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%d",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado donde se carga el resultado
 * \return '-1' si hubo un error y '0' si esta todo bien
 */
int getFloat(float* pResultado, char* msg, char* msgError)
{
    float buffer;
    int ret=-1;

    printf("%s",msg);
    if(scanf("%f",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
    }
    return ret;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param buffer Se crea un auxiliar para cargar el dato
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \return El caracter ingresado por el usuario
 */
int getChar(char* pResultado,char* msg, char* msgError)
{
    char buffer;
    int ret=-1;

    printf("%s",msg);
    if(scanf("%c",&buffer)==1)
    {
        (*pResultado)=buffer;
        ret=0;
    }
    else
    {
        printf("%s",msgError);
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

/**
 * \brief Genera un n�mero aleatorio
 * \param desde N�mero aleatorio m�nimo
 * \param hasta N�mero aleatorio m�ximo
 * \param iniciar Indica si se trata del primer n�mero solicitado 1 indica que si
 * \return retorna el n�mero aleatorio generado
 */
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo espacios y letras y -1 si no lo es
 */
int esSoloLetras(char* str)
{
    int ret=-1;
    int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
         ret=0;
        }
        i++;
    }
   return ret;
}

/**
 * \brief Verifica si el valor recibido son numeros
 * \param str Array con la cadena a ser analizada
 * \return 0 si es n�merico y -1 si no lo es
 */
int esNumerico(char* str)
{
    int ret=-1;
    int i=0;
    while(str[i] != '\0')
   {
        if(str[i] < '0' || str[i] > '9')
       {
          ret=0;
       }
    i++;
   }
   return ret;
}


/**
 * \brief Verifica si el valor recibido contiene solo n�meros y guiones o espacios
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo numeros, espacios y un guion, -1 si no tiene
 */
int esTelefono(char* str)
{
    int i=0;
    int contadorGuion=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ')&&(str[i]!='-')&&(str[i]<'0' || str[i]>'9'))
        {
            return 0;
        }
        if(str[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return 1;
        }
    return 0;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo espacio o letras y n�meros, y -1 si no lo es
 */
int esAlfaNumerico(char* str)
{
    int ret=-1;
    int i=0;
    while(str[i] != '\0')
    {
       if((str[i] != ' ') &&
          (str[i] < 'a' || str[i] > 'z') &&
          (str[i] < 'A' || str[i] > 'Z') &&
          (str[i] < '0' || str[i] > '9'))
       {
           ret=0;
       }
       i++;
   }
   return ret;
}

/**
 * \brief Verifica si el valor recibido es un numero, entero o con coma
 * \param str Array con la cadena a ser analizada
 * \return 0 si es n�merico y 1 si no lo es
 */
int esNumericoFlotante(char* str)
{
    int i=0;
    int contadorPuntos=0;

    while(str[i]!='\0')
    {
            if((str[i]<'0' || str[i]>'9')&&(str[i]!='.'))
        {
            return 0;
        }
        if(str[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

/**
 * \brief Solicita un dato al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param msgError Es el mensaje a ser mostrado en caso de error
 * \param pResultado Array donde se cargar� el dato ingresado
 * \return 0
 */
int getString(char* pResultado, char* msg)
{
    char bufferStr[20];
    printf(msg);
    fflush(stdin);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pResultado!=NULL)
    {
        strncpy(pResultado,bufferStr,sizeof(bufferStr));
    }
      return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param msg Es el mensaje a ser mostrado
 * \param pResultado Array donde se cargar� el texto ingresado
 * \param magError mensaje a ser mostrado en caso de error
 * \param reintentos cantidad de reintentos habilitadas para ingresar un dato correcto
 * \return 0 si el texto contiene solo letras -1 si no
 */
int getTelefono(char* pResultado, char* msg, char* msgError,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getStringNumeros(bufferStr,msg,msgError, reintentos)&&(pResultado!=NULL)&&(esTelefono(bufferStr)))
        {
            strncpy(pResultado,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgError);
            reintentos--;
        }
    }
    return ret;
}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 */
void cleanStdin(void)
{
    int x;
    do {
        x = getchar();
    } while (x != '\n' && x != EOF);
}

/**
 * \brief Menu de opciones
 * \param imprime un menu de opciones para
    que el usuario elija mediante numeros
 * \return 0
 */
int menu()
{
    int opcionElegida;
    printf("\n---------MENU-----------\n1)Agregar Orquesta\n2)Eliminar Orquesta\n3)Imprimir Orquesta\n4)Agregar musico\n5)Modificar musico");
    getInt(&opcionElegida,"\n6)Eliminar musico\n7)Imprimir musico\n8)Agregar Instrumento\n9)Imprimir Instrumento\n10)Informes\n11)Salir\n\nOPCION: ", "\n-INGRESO MAL EL DATO-\n");
   return opcionElegida;
}

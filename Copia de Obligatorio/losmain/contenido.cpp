#include "../lospuntohache/contenido.h"
#include "../lospuntohache/definiciones.h"
#include <string.h>
#include <iostream>
using namespace std;


struct _contenido
{   
    Texto primero;
    Texto ultimo;
    int tam;
};

struct lista_textos{
    char dato[MAX_TAM_TEX];
    Texto sig;
    Texto ant;
};

TipoRet delete_contenido(Contenido contenido){
//Pre: contenido no esta vacia
//Borra el contenido del texto
    if (contenido != NULL) {
        Texto aux = contenido->primero;
        while (aux != NULL) {
            Texto temp = aux;
            aux = aux->sig;
            delete temp; 
        }
        contenido->primero = NULL;
        contenido->ultimo = NULL;
        contenido->tam = 0;
        delete contenido;
        contenido = NULL; 

        return OK;
    }
    return ERROR;
}

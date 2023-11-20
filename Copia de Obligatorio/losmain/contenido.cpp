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
    char c;
    Texto sig;
    Texto ant;
};

Contenido crear_cont(Contenido c){
    c= new (_contenido);
    c->primero = NULL;
    c->ultimo = NULL;
    c->tam = 0;
    return c;
}

Contenido insertar_Al_final(Cadena nombreArchivo,Contenido c, Cadena x){
// Inserta x al final del contenido
      for (int i = 0; i < strlen(x) ; i++){
        cout << "insertando " << x[i] << endl; 
        Texto aux = new(lista_textos);
        aux->c = x[i];
        c->tam++;
        if (c->ultimo == NULL){
            c->primero = aux;
            c->ultimo = aux;
        }else{
            c->ultimo->sig = aux;
            aux->sig = NULL;
            c->ultimo = aux;
            /*aux->ant = c->ultimo;
            aux->ant->sig = aux;
            aux->sig = NULL;
            c->ultimo = aux;
            */
        }
    }
    return c;
}

Contenido insertar_Al_principio(Cadena nombreArchivo, Contenido c, Cadena x) {
// Inserta x al principio del contenido
    for (int i = strlen(x) -1; i >= 0; i--){
        cout << "insertando " << x[i] << endl; 
        Texto aux = new(lista_textos);
        aux->c = x[i];
        c->tam++;
        if (c->primero == NULL){
            c->primero = aux;
            c->ultimo = aux;
        }else{
            aux->sig = c->primero;
            aux->ant = NULL;
            c->primero = aux;
        }
    }
    return c;
}


Texto delete_texto(Texto t){
    if (t != NULL){
        t->sig = delete_texto(t->sig);
        delete t;
    }
}

TipoRet delete_contenido(Contenido & contenido){
//Pre: contenido no esta vacia
//Borra el contenido del texto
        contenido->primero = delete_texto(contenido->primero);
        delete contenido;
        return OK;
}

void Imprimir_texto(Texto t) {
//Pre:Contenido no está vacío.
//Imprime el texto del contenido.
    if (t != NULL){
        cout << t->c;
        Imprimir_texto(t->sig);
    }
}

void Imprimir_cont(Contenido c) {
    cout << "IMPRIMIENDO.....\n";
    Imprimir_texto(c->primero);

}

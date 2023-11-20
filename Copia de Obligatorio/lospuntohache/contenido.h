#ifndef CONTENIDO_H
#define CONTENIDO_H
#include "./definiciones.h"

typedef struct _contenido * Contenido;
typedef struct lista_textos * Texto;

Contenido crear_cont(Contenido c);
//Pide memoria para el archivo

TipoRet delete_contenido(Contenido & contenido);
//Pre: Contenido NO está vacía
//Borra texto del contenido

Contenido insertar_Al_final(Cadena nombreArchivo,Contenido c, Cadena x);
//Inserta texto al final del contenido

Contenido insertar_Al_principio(Cadena nombreArchivo ,Contenido c, Cadena x);
//Inserta texto al principio del contenido

void Imprimir_cont(Contenido c);
//Imprime el texto del contenido
#endif 
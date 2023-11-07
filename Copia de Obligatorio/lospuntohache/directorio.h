#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include "./definiciones.h"

typedef struct nodo_directorio * directorio;
// typedef struct lista_directorios * listaDirectorios;

// directorio crear_lista_directorios_vacia();
// //Crea una lista de directorios vacia.

directorio crear_directorio_raiz(Cadena nombre, directorio &dirPadre);
// Crea un directorio vacio de nombre "raiz".

directorio crear_directorio(Cadena nombre, directorio &d);
// Crea un directorio vacio de nombre "nombre".

bool pertenece_dir_a_lista_hijos(Cadena nombre, directorio lista);
//Devuelve true si el directorio pertenece a la lista de directorios hijos.

directorio destruir_directorio(directorio d);
// Destruye el directorio pasado como parametro.

TipoRet ins_arch_dir(directorio &d, Cadena nombreArchivo);
//Insterta un nuevo archivo en el directorio actual.

TipoRet borrar_arch_dir(directorio &d, Cadena nombreArchivo);

void imprimir_ruta(directorio d);

void imprimir_lista_dir(directorio lista);
//Imprime los nombres de una lista de directorios dada.

TipoRet imprimir_dir_actual(directorio d, Cadena parametro);
//Imprime en pantalla todo el contenido de un directorio.

#endif
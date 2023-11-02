#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include "./definiciones.h"

typedef struct nodo_directorio * directorio;
typedef struct lista_directorios * listaDirectorios;

listaDirectorios crear_lista_directorios_vacia();
//Crea una lista de directorios vacia.

directorio crear_directorio(Cadena nombre);
// Crea un directorio vacio de nombre "nombre".

directorio destruir_directorio(directorio d);
// Destruye el directorio pasado como parametro.

TipoRet ins_arch_dir(directorio &d, Cadena nombreArchivo);
//Insterta un nuevo archivo en el directorio actual.

TipoRet borrar_arch_dir(directorio &d, Cadena nombreArchivo);

void imprimir_lista_dir(listaDirectorios lista);
//Imprime los nombres de una lista de directorios dada.

TipoRet imprimir_dir_actual(directorio d, Cadena parametro);
//Imprime en pantalla todo el contenido de un directorio.

#endif
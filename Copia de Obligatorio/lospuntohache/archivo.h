#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "./definiciones.h"


typedef struct lista_archivos * listaArchivos;

typedef struct _archivo * Archivo;

listaArchivos crear_lista_archivos_vacia();
//Crea una lista vacia.

bool pertenece_archi_a_lista(listaArchivos arch, Cadena nombreArchivo);
//retorna true si el nombre pertenece a la lista.

TipoRet insertar_archivo_lista(listaArchivos &lista, Cadena nombreArchivo, Cadena ext);
//Inserta un nuevo archivo a la lista de archivos.

TipoRet Borrar_arch_lista(listaArchivos &lista, Cadena nombreArchivo);

void imprimir_archs(listaArchivos archivos);
//imprime todos los archivos de un directorio.

#endif
#ifndef DIRECTORIO_H
#define DIRECTORIO_H
#include "./definiciones.h"

typedef struct nodo_directorio * directorio;
// typedef struct lista_directorios * listaDirectorios;

// directorio crear_lista_directorios_vacia();
// //Crea una lista de directorios vacia.

directorio crear_directorio_raiz(Cadena nombre);
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

bool tiene_padre(directorio d);
//Retorna true si tiene padre, falsi en cc.

directorio dir_padre(directorio d);
//Retorna el padre de un directorio dado.

directorio lista_de_hijos(directorio d);
//Retorna la lista de hijos de un directorio dado.

directorio buscar_dir(directorio d, Cadena nombreDado);
//Busca el directorio de nombre "nombreDado" en la lista de hijos "d" y lo retorna.

void imprimir_un_dir(directorio d);
//Imprime el directorio dado.

directorio dir_sigiente(directorio d);
//Retorna el directorio siguente.

TipoRet eliminar_dir(directorio actual, Cadena nombreDirectorio);
//Elimina el directorio de nombre "nombreDirectorio".


#endif
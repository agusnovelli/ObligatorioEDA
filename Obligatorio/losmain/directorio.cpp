#include <string.h>
#include <iostream>
#include "../lospuntohache/definiciones.h"
#include "../lospuntohache/directorio.h"
#include "../lospuntohache/archivo.h"
using namespace std;

struct lista_directorios{
	listaDirectorios ant;
	listaDirectorios sig;
	directorio dir;
};

struct nodo_directorio{
	Cadena nombre;
	listaArchivos archivos;
	listaDirectorios padre;
	listaDirectorios listaHijos;
};

listaDirectorios crear_lista_directorios_vacia(){
//Crea una lista de directorios vacia.
	return NULL;
}

directorio crear_directorio(Cadena nombre){
// Crea un directorio vacio de nombre "nombre".
	directorio d = new(nodo_directorio);
	d->nombre = new char[MAX_NOM_DIR];
	strcpy(d->nombre, nombre);
	d->listaHijos = crear_lista_directorios_vacia();
	d->archivos = crear_lista_archivos_vacia();
	return d;
}

directorio destruir_directorio(directorio d){
// Destruye el directorio pasado como parametro.
	// Destruir estructura de archivos
	delete [] d->nombre;
	delete d;
	return d;
}

TipoRet ins_arch_dir(directorio &d, Cadena nombreArchivo){
	if(pertenece_archi_a_lista(d->archivos, nombreArchivo))
		return ERROR;
	else
		return insertar_archivo_lista(d->archivos, nombreArchivo);
}

TipoRet borrar_arch_dir(directorio &d, Cadena nombreArchivo){
	if(pertenece_archi_a_lista(d->archivos, nombreArchivo)){
		Borrar_arch_lista(d->archivos, nombreArchivo);
		return OK;
	}
	else
		return ERROR;
}

void imprimir_lista_dir(listaDirectorios lista){
//Imprime los nombres de una lista de directorios dada.
	if(lista == NULL){
	}
	else{
		cout << lista->dir->nombre;
		imprimir_lista_dir(lista->sig);
	}
}

TipoRet imprimir_dir_actual(directorio d, Cadena parametro){//FALTA EL PARAMETRO
//Imprime en pantalla todo el contenido de un directorio.
	if (parametro == NULL){
		if((d->archivos == NULL) && (d->listaHijos == NULL))
			cout << "El directorio esta vacio\n";
		else{
			if(d->archivos != NULL)
				imprimir_archs(d->archivos);
			if(d->listaHijos != NULL){
				imprimir_lista_dir(d->listaHijos);
			}
		}
	}
	return OK;
}





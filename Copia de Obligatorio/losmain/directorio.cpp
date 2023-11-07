#include <string.h>
#include <iostream>
#include "../lospuntohache/definiciones.h"
#include "../lospuntohache/directorio.h"
#include "../lospuntohache/archivo.h"
using namespace std;

struct nodo_directorio{
	directorio padre;
	directorio listaHijos;
	directorio sig;
	Cadena nombre;
	listaArchivos archivos;
};

directorio crear_directorio_raiz(Cadena nombre, directorio &dirPadre){
// Crea un directorio vacio de nombre "nombre".
	directorio d = new(nodo_directorio);
	d->nombre = new char[MAX_NOM_DIR];
	strcpy(d->nombre, nombre);
	d->listaHijos = NULL;
	d->archivos = crear_lista_archivos_vacia();
	if(strcasecmp(nombre, "raiz") != 0){
		d->padre = dirPadre;
		dirPadre->listaHijos = d;
	}
	return d;
}

directorio crear_directorio(Cadena nombre, directorio &dirPadre){
// Crea un directorio vacio de nombre "nombre".
	if(pertenece_dir_a_lista_hijos(nombre, dirPadre->listaHijos)){
		cout << "El nombre ya existe\n";
		return NULL;
	}
	else{
		directorio d = new(nodo_directorio);
		d->nombre = new char[MAX_NOM_DIR];
		strcpy(d->nombre, nombre);
		d->padre = dirPadre;
		d->listaHijos = NULL;
		d->archivos = crear_lista_archivos_vacia();
		if(dirPadre->listaHijos == NULL){
			d->sig = NULL;
			dirPadre->listaHijos = d;
			return d;
		}
		else{
			d->sig = dirPadre->listaHijos;
			dirPadre->listaHijos = d;
			return d;
		}

	}
}

directorio destruir_directorio(directorio d){
// Destruye el directorio pasado como parametro.
	// Destruir estructura de archivos
	delete [] d->nombre;
	delete d;
	return d;
}

bool pertenece_dir_a_lista_hijos(Cadena nombre, directorio lista){
	if(lista == NULL)
		return false;
	else if(strcmp(lista->nombre, nombre) == 0)
		return true;
	else 
		pertenece_dir_a_lista_hijos(nombre, lista->sig);
}

TipoRet ins_arch_dir(directorio &d, Cadena nombreArchivo){
	Cadena nombre = strtok(nombreArchivo, ".");
	Cadena ext = strtok(NULL, ".");
	if(pertenece_archi_a_lista(d->archivos, nombre))
		return ERROR;
	else{
		if(ext == NULL){
			cout << "Debe ingresar la extension\n";
			return ERROR;
		}
		else
			return insertar_archivo_lista(d->archivos, nombre, ext);
	}
}

TipoRet borrar_arch_dir(directorio &d, Cadena nombreArchivo){
	if(pertenece_archi_a_lista(d->archivos, nombreArchivo)){
		Borrar_arch_lista(d->archivos, nombreArchivo);
		return OK;
	}
	else
		return ERROR;
}


void imprimir_ruta(directorio d){
	if(strcasecmp(d->nombre, "RAIZ") == 0)
		cout << d->nombre;
	else{
		imprimir_ruta(d->padre);
		cout << "/" << d->nombre;
	}
	cout << "\n";
}

void imprimir_lista_dir(directorio lista){
//Imprime los nombres de una lista de directorios dada.
	if(lista == NULL){
	}
	else{
		cout << lista->nombre << "\n";
		imprimir_lista_dir(lista->sig);
	}
}

TipoRet imprimir_dir_actual(directorio d, Cadena parametro){//FALTA EL PARAMETRO
//Imprime en pantalla todo el contenido de un directorio.
	if (parametro == NULL){
		imprimir_ruta(d);
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




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

directorio crear_directorio_raiz(Cadena nombre){
// Crea un directorio vacio de nombre "nombre".
	directorio d = new(nodo_directorio);
	d->nombre = new char[MAX_NOM_DIR];
	strcpy(d->nombre, nombre);
	d->listaHijos = NULL;
	d->archivos = crear_lista_archivos_vacia();
	d->padre = NULL;
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
		if(dirPadre->listaHijos == NULL){//Es el primero
			d->sig = NULL;
			dirPadre->listaHijos = d;
			return d;
		}
		else{
			directorio aux = dirPadre->listaHijos;
			if(strcmp (aux->nombre, nombre) > 0){//Comparo con el primero
				d->sig = dirPadre->listaHijos;
				dirPadre->listaHijos = d;
			}
			else{
				while((aux->sig != NULL) and (strcmp (aux->sig->nombre, nombre) < 0))
					aux = aux->sig;
				d->sig = aux->sig;
				aux->sig = d;
			}
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
		return pertenece_dir_a_lista_hijos(nombre, lista->sig);
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
		cout << "\n";
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
	else {
		if(strcasecmp(parametro, "/s") == 0){
			imprimir_ruta(d);
			cout << "\n";
			if((d->archivos == NULL) && (d->listaHijos == NULL))
				cout << "El directorio esta vacio\n";
			else{
				if(d->archivos != NULL){
					listaArchivos aux = d->archivos;
					while(aux != NULL){
						imprimir_ruta(d);
						cout << "/";
						imprimir_un_arch(aux);
						aux = arch_sigiente(aux);
						cout << "\n";
					}
				}
				if(d->listaHijos != NULL){
					directorio aux = d->listaHijos;
					while(aux != NULL){
						imprimir_ruta(d);
						cout << "/";
						imprimir_un_dir(aux);
						aux = dir_sigiente(aux);
						cout << "\n";
					}
				}
			}
		}
		else
			cout << "Parametro incorrecto.\n";
	}
	return OK;
}

void imprimir_un_dir(directorio d){
//Imprime el directorio dado.
	cout << d->nombre;
}

directorio dir_sigiente(directorio d){
//Retorna el directorio siguente.
	return d->sig;
}


bool tiene_padre(directorio d){
//Retorna true si tiene padre, falsi en cc.
	if(d->padre != NULL)
		return true;
	else
		return false;
}

directorio dir_padre(directorio d){
//Retorna el padre de un directorio dado.
	return d->padre;
}

directorio lista_de_hijos(directorio d){
//Retorna la lista de hijos de un directorio dado.
	return d->listaHijos;
}

directorio buscar_dir(directorio d, Cadena nombreDado){
//Busca el directorio de nombre "nombreDado" en la lista de hijos "d".
	if(d == NULL){
		return NULL;
	}
	else if(strcasecmp(d->nombre, nombreDado) == 0){
		return d;
	}
	else
		return buscar_dir(d->sig, nombreDado);
}
// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// sistema.c
// Modulo de Implementacion del File System.

#include "../lospuntohache/sistema.h"
#include "../lospuntohache/directorio.h"
#include "../lospuntohache/definiciones.h"
#include "../lospuntohache/archivo.h"
#include <string.h>

#include <iostream>

using namespace std;

struct _sistema{
	directorio raiz;
	directorio actual;
	
	// aquí deben figurar los campos que usted considere necesarios para manipular el sistema de directorios
	// Se deberan crear nuevos modulos
};

TipoRet CREARSISTEMA(Sistema &s){
// Inicializa el sistema para que contenga únicamente al directorio RAIZ, sin subdirectorios ni archivos.
// Para mas detalles ver letra.
	s = new(_sistema);
	Cadena nombre = new char[MAX_NOM_DIR];
	strcpy(nombre, "RAIZ");
	s->raiz = crear_directorio_raiz(nombre);
	delete [] nombre;
	s->actual = s->raiz;
	return OK;
}

TipoRet DESTRUIRSISTEMA(Sistema &s){
// Destruye el sistema, liberando la memoria asignada a las estructuras que datos que constituyen el file system.
// Para mas detalles ver letra.
	s->raiz = destruir_directorio(s->raiz);
	delete s;
	return OK;
}

TipoRet CD (Sistema &s, Cadena nombreDirectorio){
// Cambia directorio. 
// Para mas detalles ver letra.
	if(strcasecmp(nombreDirectorio, "Raiz") == 0){
		s->actual = s->raiz;
	}
	else if(strcasecmp(nombreDirectorio, "..") == 0){
		if(tiene_padre(s->actual) == true){
			s->actual= dir_padre(s->actual);
		}
		else{
			cout << "Este directorio no tiene padre.\n";
		}
	}
	else{
		directorio aux = buscar_dir(lista_de_hijos(s->actual), nombreDirectorio);
		if(aux != NULL){
			s->actual = aux;
		}
		else{
			cout << nombreDirectorio << " no existe.\n";
		}
	}
	return OK;
}
	
TipoRet MKDIR (Sistema &s, Cadena nombreDirectorio){
// Crea un nuevo directorio. 
// Para mas detalles ver letra.
	directorio aux = crear_directorio(nombreDirectorio, s->actual);
	return OK;
}

TipoRet RMDIR (Sistema &s, Cadena nombreDirectorio){
// Elimina un directorio.
// Para mas detalles ver letra.
	return eliminar_dir(s->actual, nombreDirectorio);
}

TipoRet MOVE (Sistema &s, Cadena nombre, Cadena directorioDestino/*, directorio raiz*/){
// mueve un directorio o archivo desde su directorio origen hacia un nuevo directorio destino.
// Para mas detalles ver letra.
	// return mover_dir_o_arch(s->actual, nombre, directorioDestino, raiz);
	return NO_IMPLEMENTADA;
}

TipoRet DIR (Sistema &s, Cadena parametro){
// Muestra el contenido del directorio actual.
// Para mas detalles ver letra.
	return imprimir_dir_actual(s->actual, parametro);
}

TipoRet CREATEFILE (Sistema &s, Cadena nombreArchivo){
// Crea un nuevo archivo en el directorio actual.
// Para mas detalles ver letra.
	return ins_arch_dir(s->actual, nombreArchivo);
}

TipoRet DELETE (Sistema &s, Cadena nombreArchivo){
// Elimina un archivo del directorio actual, siempre y cuando no sea de sólo lectura.
// Para mas detalles ver letra.
	return borrar_arch_dir(s->actual, nombreArchivo);
}

TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro){
// Agrega un texto al comienzo del archivo NombreArchivo.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet IC (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Agrega un texto al final del archivo NombreArchivo.
// Para mas detalles ver letra.
	return ins_cont_princ(s->actual, nombreArchivo, texto);
}

TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Agrega un texto al final del archivo NombreArchivo.
// Para mas detalles ver letra.
	return ins_cont_fin(s->actual,nombreArchivo,texto);
}

TipoRet DC (Sistema &s, Cadena nombreArchivo, int k){
// Elimina los a lo sumo K primeros caracteres del archivo parámetro.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet DF (Sistema &s, Cadena nombreArchivo, int k){
// Elimina los a lo sumo K últimos caracteres del archivo parámetro.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet TYPE (Sistema &s, Cadena nombreArchivo){
// Imprime el contenido del archivo parámetro.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet SEARCH (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Busca dentro del archivo la existencia del texto.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet REPLACE (Sistema &s, Cadena nombreArchivo, Cadena texto1, Cadena texto2){
// Busca y reemplaza dentro del archivo la existencia del texto1 por el texto2. 
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}



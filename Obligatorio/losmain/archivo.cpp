#include <stdio.h>
#include <string.h>
#include <iostream>
#include "../lospuntohache/archivo.h"
#include "../lospuntohache/definiciones.h"
#include "../lospuntohache/contenido.h"
using namespace std;



struct lista_archivos{
    listaArchivos sig;
    listaArchivos ant;
    Archivo arch;
};

struct _archivo{
    Cadena nombre;
    Cadena extension;
    bool escritura;
    Contenido cont;
};

listaArchivos crear_lista_archivos_vacia(){
//Crea una lista vacia.
    return NULL;
}

bool pertenece_archi_a_lista(listaArchivos lista, Cadena nombreArchivo){
//retorna true si el nombre pertenece a la lista.
     cout << "entre\n";
    if(lista == NULL){
        cout << "esta vacia\n";
        return false;
    }
    else if(strcmp(lista->arch->nombre,nombreArchivo) == 0){
        cout << "encontre\n";
        return true;
    }
    else
        return pertenece_archi_a_lista(lista->sig, nombreArchivo);
}

TipoRet insertar_archivo_lista(listaArchivos &lista, Cadena nombreArchivo){
//Inserta un nuevo archivo a la lista de archivos.
    if ((lista == NULL) || (strcmp (lista->arch->nombre, nombreArchivo) > 0)){
        listaArchivos aux = new(lista_archivos);
        aux->sig = lista;
        aux->arch = new(_archivo);
        aux->arch->nombre = new(char[MAX_NOM_ARCH]);
        strcpy(aux->arch->nombre, nombreArchivo);
        aux->arch->extension = new(char[MAX_EXT_ARCH]);
        strcpy(aux->arch->extension, "");
        // cout << "lo que me pinte\n";
        // aux->arch->extension = ext;
        // cout << "lo que me pinte\n";
        aux->arch->escritura = true;
        aux->arch->cont = NULL;
        aux->ant = NULL;
        lista = aux;
    }else{
        insertar_archivo_lista(lista->sig, nombreArchivo);
    }
    return OK;
}

TipoRet Borrar_arch_lista(listaArchivos lista, Cadena nombreArchivo){
//Elimina un archivo de la lista de archivos.
    if(pertenece_archi_a_lista(lista, nombreArchivo)){
        delete lista->arch->cont;
        delete lista->arch->extension;
        delete lista->arch->nombre;
        delete lista;
        return OK;
    }
    else
        return ERROR;
}

void imprimir_archs(listaArchivos archivos){
    if(archivos == NULL){
    }
    else{
        cout << archivos->arch->nombre << "." << archivos->arch->extension;
        imprimir_archs(archivos->sig);
    }
}

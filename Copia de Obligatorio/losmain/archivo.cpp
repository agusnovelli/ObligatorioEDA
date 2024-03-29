#include <stdio.h>
#include <string.h>
#include <iostream>
#include "../lospuntohache/archivo.h"
#include "../lospuntohache/definiciones.h"
#include "../lospuntohache/contenido.h"
using namespace std;

struct lista_archivos{
    listaArchivos sig;
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
    if(lista == NULL){
        return false;
    }
    else if(strcmp(lista->arch->nombre, nombreArchivo) == 0){
        return true;
    }
    else
        return pertenece_archi_a_lista(lista->sig, nombreArchivo);
}

TipoRet insertar_archivo_lista(listaArchivos &lista, Cadena nombreArchivo, Cadena ext){
//Inserta un nuevo archivo a la lista de archivos.
    if ((lista == NULL) || (strcmp (lista->arch->nombre, nombreArchivo) > 0)){
        listaArchivos aux = new(lista_archivos);
        aux->sig = lista;
        aux->arch = new(_archivo);
        aux->arch->nombre = new(char[MAX_NOM_ARCH]);
        strcpy(aux->arch->nombre, nombreArchivo);
        aux->arch->extension = new(char[MAX_EXT_ARCH]);
        strcpy(aux->arch->extension, ext);
        aux->arch->escritura = true;
        aux->arch->cont = NULL;
        lista = aux;
    }else{
        insertar_archivo_lista(lista->sig, nombreArchivo, ext);
    }
    return OK;
}

TipoRet Borrar_arch_lista(listaArchivos &lista, Cadena nombreArchivo){
//Pre: existe un archivo de nombre "NombreArchivo" en la lista.
//pre2: No escribir su extension. 
//Elimina el archivo de la lista
    listaArchivos aux = lista;
    if(strcasecmp(nombreArchivo, aux->arch->nombre) != 0){ //No soy el primero.
        while(strcasecmp(nombreArchivo, aux->sig->arch->nombre) != 0)
            aux = aux->sig;
        listaArchivos aux2 = aux;
        aux2 = aux->sig->sig;
        delete[] aux->sig->arch->nombre;  // Liberar memoria de nombre
        delete[] aux->sig->arch->extension;  // Liberar memoria de extension
        if(aux->sig->arch->cont !=NULL)
            delete_contenido(aux->sig->arch->cont);
        aux->sig = aux2;
    }else{ //Soy el primero.
        lista = aux->sig;
        delete[] aux->arch->nombre;  // Liberar memoria de nombre
        delete[] aux->arch->extension;  // Liberar memoria de extension
        if(aux->arch->cont !=NULL)
            delete_contenido(aux->arch->cont);
    }
    return OK;
}

void imprimir_archs(listaArchivos archivos){
//imprime todos los archivos de un directorio.
    if(archivos == NULL){
    }
    else{
        cout << archivos->arch->nombre << "." << archivos->arch->extension << "\n";
        imprimir_archs(archivos->sig);
    }
}

void imprimir_un_arch(listaArchivos lista){
    cout << lista->arch->nombre << "." << lista->arch->extension;
}

listaArchivos arch_sigiente(listaArchivos lista){
//Devuelve el archivo siguiente.
    return lista->sig;
}

TipoRet insertar_Al_principio_deCont(listaArchivos l, Cadena nombreArchivo, Cadena texto){

        insertar_Al_principio(nombreArchivo,l->arch->cont, texto);
        return OK;
}

TipoRet insertar_Al_final_deCont(listaArchivos l, Cadena nombreArchivo, Cadena texto){
    
        insertar_Al_final(nombreArchivo,l->arch->cont, texto);
        return OK;
}

TipoRet Imprimir_cont_delArch(listaArchivos l, Cadena nombreArchivo) {
//Pre: el archivo pertenece a la lista. 

    if (l->arch->cont!= NULL) {
        cout<<"entre al if \n";
        if (strcmp(l->arch->nombre, nombreArchivo) == 0) {
            cout<<"compare el nombre \n";
            // Encontramos el archivo, imprimir su contenido
            Imprimir_cont(l->arch->cont);
            return OK;
        } 
        else{
            cout << "El archivo " << nombreArchivo << " no se encuentra en la lista.";
            return ERROR;
        }

        l = l->sig;
    }
    return OK;
}

TipoRet Cambia_permisos(listaArchivos l, Cadena nombreArchivo, Cadena parametro) {
    // Cambia los permisos del archivo según el parámetro
    if (pertenece_archi_a_lista(l, nombreArchivo)) {
        if (strcasecmp(parametro, "+W") == 0) {
            l->arch->escritura = true;
            cout << "Lectura/Escritura";
        } else if (strcasecmp(parametro, "-W") == 0) {
            l->arch->escritura = false;
            cout << "Lectura";
        } else {
            cout << "Parámetro Incorrecto";
            return ERROR;
        }
        return OK;
    } else {
        cout << "No existe el archivo en la lista";
        return ERROR;
    }
}

#ifndef CONTENIDO_H
#define CONTENIDO_H
#include "./definiciones.h"

typedef struct _contenido * Contenido;
typedef struct lista_textos * Texto;

TipoRet delete_contenido(Contenido contenido);

#endif
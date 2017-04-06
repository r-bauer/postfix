//***************************************************************************//
//                                                                           //
//  Titulo:                                                                  //
//  Arquivo: MAIN.H                                                          //
//  Autor: Roberto Bauer                                                     //
//  Observacoes: Cabecalho principal p/ concentrar os demais cabecalhos      //
//                                                                           //
//***************************************************************************//

#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __MAIN_C__
#define EXTERN
#else
#define EXTERN      extern
#endif

#define LOCAL       static

typedef enum tagBOOL { FALSE, TRUE }     BOOL;
typedef unsigned char       BYTE;
typedef unsigned short int  WORD;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stackgen.h"
#include "stackapp.h"
#include "stackdrv.h"

#endif /* #ifndef __MAIN_H__ */

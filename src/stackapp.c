//***********************************************************//
//  Arquivo: STACKAPP.C                                      //
//  Autor: Roberto Bauer                                     //
//  Observacoes:                                             //
//              Dados especificos para aplicacoes de pilhas. //
//***********************************************************//

#define __STACKAPP_C__

#include "main.h"

SDATA *
appViewData (SSTACK * pStk, int iPos)
{
  return ((SDATA *) ViewData (pStk, iPos));
}

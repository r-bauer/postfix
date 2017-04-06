//***********************************************************//
//  Arquivo: STACKAPP.H                                      //
//  Autor: Roberto Bauer                                     //
//  Observacoes:                                             //
//              Dados especificos para aplicacoes de pilhas. //
//***********************************************************//

#ifndef __STACKAPP_H__
#define __STACKAPP_H__

#undef EXTERN
#ifdef __STACKAPP_C__
#define EXTERN
#else
#define EXTERN  extern
#endif


typedef struct tagDATA
{
  float fVal;

} SDATA;

#define appCreateStack(x)       CreateStack((x), sizeof(SDATA))
#define appPopData(x, y)        PopData((x), ((void *)(y)))
#define appPushData(x, y)       PushData((x), ((void *)(y)))

EXTERN SDATA *appViewData (SSTACK *, int);


#endif // #define __STACKAPP_H__

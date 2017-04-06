//***************************************************************************//
//                                                                           //
//  Titulo:                                                                  //
//  Arquivo: STACKGEN.H                                                      //
//  Data: 18/09/2008                                                         //
//  Versao: 1.0                                                              //
//  Autor: Roberto Bauer                                                     //
//  Observacoes:                                                             //
//              Primitivas genericas para operacoes de pilhas.               //
//                                                                           //
//  Historico de evolucao:                                                   //
//              18/09/2008 -> adaptacaoh dos algoritimos apresentados no     //
//                          livro 'Pratical Algorithms for programmers' de   //
//                          John Rex e Andrew Binstok                        //
//                                                                           //
//***************************************************************************//

#ifndef __STACKGEN_H__
#define __STACKGEN_H__

#undef EXTERN
#ifdef __STACKGEN_C__
#define EXTERN
#else
#define EXTERN  extern
#endif


typedef struct tagSSTACK
{
  void *pBase;                  // aponta para a base da pilha
  int iStackSize;               // numero de dados
  int iDataSize;                // tamanho do dado
  int iMaxStack;                // ultimo posicao possivel do dado
  int iTop;                     // posicaoh atual

} SSTACK;

EXTERN void ClearStack (SSTACK *);
EXTERN SSTACK *CreateStack (int, int);
EXTERN BOOL PopData (SSTACK *, void *);
EXTERN BOOL PushData (SSTACK *, void *);
EXTERN void *ViewData (SSTACK *, int);


#endif // #define __STACKGEN_H__

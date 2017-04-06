//**************************************************************//
//  Arquivo: STACKDRV.C                                         //
//  Autor: Roberto Bauer                                        //
//  Observacoes:                                                //
//              Controlador da aplicacaoh de exemplo de pilhas. //
//**************************************************************//


#define __STACKDRV_C__

#include "main.h"

LOCAL BOOL IsDigit (char);
LOCAL BOOL IsNumber (char *);
LOCAL int Atoi (char *);
LOCAL BOOL IsOperator (char);
LOCAL float Expon (float, int);

int
StackDriver (int argc, char *argv[])
{
  SDATA sdEl;                   // dado temporario,
  SSTACK *stk;                  // a pilha que serah usada
  int iCnt;                     // para ser usado como contador de loop
  float fRes;

  if (argc == 1)
    {
      fprintf (stderr, "Uso: posfixa <expressaoh>\n");
      return (EXIT_FAILURE);
    }

  stk = appCreateStack (argc);  // cria e inicializa a pilha
  if (stk == NULL)
    {
      fprintf (stderr, "Memoria Insuficiente\n");
      return (EXIT_FAILURE);
    }

  for (iCnt = 1; iCnt < argc; ++iCnt)
    {
        fprintf (stderr, "argv[%i] = %s\n", iCnt, argv[iCnt]);
      if (IsNumber (argv[iCnt]))
        {
          sdEl.fVal = (float) Atoi (argv[iCnt]);
          if (!appPushData (stk, &sdEl))
            {
              fprintf (stderr, "Acabou espacoh na pilha\n");
              return (EXIT_FAILURE);
            }
          printf ("%.f\n", sdEl.fVal);
        }
      else if (IsOperator (argv[iCnt][0]))
        {
          float fVal1, fVal2;

          appPopData (stk, &fVal2);
          appPopData (stk, &fVal1);

          switch (argv[iCnt][0])
            {
            case '+':
              sdEl.fVal = fVal1 + fVal2;
              printf ("%.f + %.f = %.f\n", fVal1, fVal2, sdEl.fVal);
              break;

            case '-':
              sdEl.fVal = fVal1 - fVal2;
              printf ("%.f - %.f = %.f\n", fVal1, fVal2, sdEl.fVal);
              break;

            case '/':
              sdEl.fVal = fVal1 / fVal2;
              printf ("%.f / %.f = %.f\n", fVal1, fVal2, sdEl.fVal);
              break;

            case '*':
              sdEl.fVal = fVal1 * fVal2;
              printf ("%.f * %.f = %.f\n", fVal1, fVal2, sdEl.fVal);
              break;

            case '$':
              sdEl.fVal = Expon (fVal1, (int) fVal2);
              printf ("%.f $ %.f = %.f\n", fVal1, fVal2, sdEl.fVal);
              break;
            }

          // salva o resultado na pilha
          appPushData (stk, &sdEl);
        }
      else
        {
          fprintf (stderr, "operacaoh invalidah\n");
        }
    }

  appPopData (stk, &fRes);
  printf ("%.f\n", fRes);

  return (EXIT_SUCCESS);
}

LOCAL BOOL
IsDigit (char c)
{
  return (c >= '0' && c <= '9');
}

LOCAL BOOL
IsNumber (char *pStr)
{
  while (*pStr)
    {
      if (!IsDigit (*pStr))
        {
          return FALSE;
        }
      pStr++;
    }
  return TRUE;
}

LOCAL int
Atoi (char *pStr)
{
  int iRet = 0;

  while (*pStr)
    {
      iRet *= 10;
      iRet += (*pStr++ & 0xF);
    }
  return (iRet);
}

LOCAL BOOL
IsOperator (char c)
{
//  char cOp[] = { "+-/*$" };
  char cOp[] = { '+', '-', '/', '*', '$', '\0' };
  char *ptr;

  ptr = cOp;
  while (*ptr)
    {
      if (*ptr++ == c)
        return TRUE;
    }
  return FALSE;
}

LOCAL float
Expon (float fBas, int iExp)
{
  float fRes;

  fRes = fBas;
  while (--iExp)
    fRes *= fBas;

  return fRes;
}

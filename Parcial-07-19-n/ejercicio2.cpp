int mochila(int i, int N, int *E, int *W, int *D, int *P, int *Cant, int EMax, int WMax, int DMax)
{
  if (i == N)
  {
    return 0;
  }

  // vamos a probar con todas las mochilas, aca el "agregar y quitar" esta medio escondido
  // directamente cuando hacemos la llamada recursiva estamos "agregando" la solucion
  // como las variables originales no las modificamos, "quitar" de la solucion no requiere que hagamos nada
  int max = 0;
  for (int count = 0; count <= Cant[i]; count++)
  {
    int Eaux = E[i] * count;
    int Waux = W[i] * count;
    int Daux = D[i] * count;
    if (Eaux <= EMax && Waux <= WMax && Daux <= DMax)
    {
      int aux = mochila(i + 1, N, E, W, D, P, Cant, Eaux, Waux, Daux);
      if (aux > max)
      {
        max = aux;
      }
    }
    else
    {
      // si no podemos meter count elementos, entonces no podemos meter mas de count, salimos del while
      break;
    }
  }
  return max;
}

// no hay ninguna poda trivial
#include <iostream>

int max(int a, int b)
{
  return a > b ? a : b;
}

int mochila(int PesoMax, int *pesos, int *valores, int n)
{
  int **M = new int *[n + 1];
  for (int i = 0; i <= n; i++)
  {
    M[i] = new int[PesoMax + 1];
  }

  for (int i = 0; i <= n; i++)
  {
    for (int p = 0; p <= PesoMax; p++)
    {
      if (i == 0 || p == 0)
      {
        M[i][p] = 0;
      }
      else if (pesos[i - 1] <= p)
        M[i][p] = max(valores[i - 1] + M[i - 1][p - pesos[i - 1]], M[i - 1][p]);
      else
        M[i][p] = M[i - 1][p];
    }
  }

  return M[n][PesoMax];
}

int main()
{
  int pesos[] = {1, 2, 3, 4, 5, 6};
  int valores[] = {1, 3, 4, 5, 6, 7};
  int pesoMax = 10;
  int largo = sizeof(pesos) / sizeof(int);
  std::cout << mochila(pesoMax, pesos, valores, largo) << std::endl;
}
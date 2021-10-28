#include <iostream>

int max(int a, int b)
{
  return a > b ? a : b;
}

int mochilaMemo(int pesoMax, int *pesos, int *valores, int i, int **memo)
{
  if (i < 0)
    return 0;
  if (memo[i][pesoMax] != -1)
    return memo[i][pesoMax];
  if (pesos[i] > pesoMax)
  {
    memo[i][pesoMax] = mochilaMemo(pesoMax, pesos, valores, i - 1, memo);
    return memo[i][pesoMax];
  }
  else
  {
    memo[i][pesoMax] = max(valores[i] + mochilaMemo(pesoMax - pesos[i], pesos, valores, i - 1, memo),
                           mochilaMemo(pesoMax, pesos, valores, i - 1, memo));
    return memo[i][pesoMax];
  }
}

int mochila(int pesoMax, int *pesos, int *valores, int largo)
{
  int **memo = new int *[largo + 1];
  for (int i = 0; i <= largo; i++)
  {
    memo[i] = new int[pesoMax + 1];
    for (int j = 0; j <= pesoMax; j++)
    {
      memo[i][j] = -1;
    }
  }

  return mochilaMemo(pesoMax, pesos, valores, largo, memo);
}

int main()
{
  int pesos[] = {1, 2, 3, 4, 5, 6};
  int valores[] = {1, 3, 4, 5, 6, 7};
  int pesoMax = 10;
  int largo = sizeof(pesos) / sizeof(int);
  std::cout << mochila(pesoMax, pesos, valores, largo) << std::endl;
}
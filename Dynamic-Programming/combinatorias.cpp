#include <iostream>

using namespace std;

int combinatoria(int n, int k)
{
  int **C = new int *[n + 1];
  for (int i = 0; i <= n; i++)
  {
    C[i] = new int[k + 1];
  }

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= min(i, k); j++)
    {
      if (i == 0 || j == 0)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; // nunca volvemos a j-2
    }
  }
  return C[n][k];
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int combinatoriaSinMatriz(int n, int k)
{
  int *C = new int[k + 1];
  C[0] = 1;

  for (int i = 1; i <= n; i++)
  {
    // vamos a calcular los pisos del triangulo de tartaglia, pero solo hasta la posicion k
    for (int j = min(i, k); j >= 1; j--)
    {
      C[j] = C[j] + C[j - 1];
    }
  }

  return C[k];
}

int main()
{
  int n, k;
  cin >> n >> k;
  cout << combinatoria(n, k) << endl;
  cout << combinatoriaSinMatriz(n, k) << endl;
  return 0;
}
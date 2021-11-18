#include <iostream>

int sumaMultiplos(int *v, int desde, int hasta, int k)
{
  if (desde == hasta)
  {
    if (v[desde] % k == 0)
      return v[desde];
    else
      return 0;
  }
  int mid = (desde + hasta) / 2;
  int suma1 = sumaMultiplos(v, desde, mid, k);
  int suma2 = sumaMultiplos(v, mid + 1, hasta, k);
  return suma1 + suma2;
}

int main()
{
  int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 3;
  int suma = sumaMultiplos(v, 0, 9, k);
  std::cout << suma << std::endl;
  return 0;
}
#include <iostream>
#include <string>

bool todosTienenPrefijo(std::string *arr, int n, int ini, int fin)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = ini; j <= fin; j++)
    {
      if (arr[i][j] != arr[0][j])
      {
        return false;
      }
    }
  }
  return true;
}

int shortestStringLength(std::string *arr, int n)
{
  int min = arr[0].length();
  for (int i = 1; i < n; i++)
  {
    if (arr[i].length() < min)
      min = arr[i].length();
  }
  return min;
}

std::string longestPrefix(std::string *arr, int n)
{
  // buscamos largo del string mas chico
  int len = shortestStringLength(arr, n);
  std::string prefix;
  int ini = 0, fin = len;

  while (ini < fin)
  {
    int mid = (ini + fin) / 2;

    if (todosTienenPrefijo(arr, n, ini, mid))
    {
      prefix = prefix + arr[0].substr(ini, mid - ini + 1);

      //nos fijamos en el substring de la derecha
      ini = mid + 1;
    }
    else
    {
      fin = mid - 1;
    }
  }

  return prefix;
}

int main()
{
  std::string arr[] = {"abc", "abcd", "abce", "abcf"};
  int n = sizeof(arr) / sizeof(arr[0]);
  std::cout << longestPrefix(arr, n) << std::endl;
}
#include <iostream>
#include <list>

bool sePuedeColocar(int fila, int col, int N, bool **solucion)
{
  // misma columna
  for (int i = 0; i < fila; i++)
  {
    if (solucion[i][col])
      return false;
  }
  for (int i = fila, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if (solucion[i][j])
      return false;
  }

  for (int i = fila, j = col; i >= 0 && j < N; i--, j++)
  {
    if (solucion[i][j])
      return false;
  }

  return true;
}

bool encontrarSolucion(int fila, int N, bool **solucion)
{
  if (fila == N)
    return true;

  for (int col = 0; col < N; col++)
  {
    if (sePuedeColocar(fila, col, N, solucion))
    {
      solucion[fila][col] = true;
      if (encontrarSolucion(fila + 1, N, solucion))
      {
        return true;
      }
      solucion[fila][col] = false;
    }
  }

  return false;
}

std::list<int *> solucionesNReinas(int fila, int N, bool **solucion)
{
  std::list<int *> soluciones;
  if (fila == N)
  {
    int *sol = new int[N];
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (solucion[i][j])
        {
          sol[i] = j;
        }
      }
    }
    soluciones.push_back(sol);
    return soluciones;
  }
  for (int col = 0; col < N; col++)
  {
    if (sePuedeColocar(fila, col, N, solucion))
    {
      solucion[fila][col] = true;
      soluciones.merge(solucionesNReinas(fila + 1, N, solucion));
      solucion[fila][col] = false;
    }
  }
  return soluciones;
}

int main()
{
  int N = 8;
  bool **solucion = new bool *[N];
  for (int i = 0; i < N; i++)
  {
    solucion[i] = new bool[N];
    for (int j = 0; j < N; j++)
    {
      solucion[i][j] = false;
    }
  }
  bool existe = encontrarSolucion(0, N, solucion);
  std::cout << "Existe solucion: " << (existe ? "true" : "false") << std::endl;
  if (existe)
  {
    std::cout << "Primer solucion encontrada" << std::endl;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        std::cout << solucion[i][j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << "-----------" << std::endl;

    for (int i = 0; i < N; i++)
    {
      solucion[i] = new bool[N];
      for (int j = 0; j < N; j++)
      {
        solucion[i][j] = false;
      }
    }
    std::list<int *> soluciones = solucionesNReinas(0, N, solucion);
    std::cout << "Todas las soluciones: " << soluciones.size() << std::endl;
    for (auto sol : soluciones)
    {
      for (int i = 0; i < N; i++)
      {
        for (int j = 0; j < N; j++)
        {
          std::cout << (sol[i] == j ? 1 : 0) << " ";
        }
        std::cout << std::endl;
      }
      std::cout << "-----------" << std::endl;
    }
  }
  else
  {
    std::cout << "No existe solucion" << std::endl;
  }
}
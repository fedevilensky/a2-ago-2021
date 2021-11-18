#include <list>
#include <iostream>

template <class T, class U>
struct Pair
{
  T key;
  U value;
};

class Grafo
{
  std::list<Pair<int, int>> **matrix;
  int size;

public:
  Grafo(int size)
  {
    this->size = size;
    matrix = new std::list<Pair<int, int>> *[size];
    for (int i = 0; i < size; i++)
    {
      matrix[i] = new std::list<Pair<int, int>>;
    }
  }

  void addEdge(int source, int destination, int weight = 1)
  {
    Pair<int, int> pair;
    pair.key = destination;
    pair.value = weight;
    matrix[source]->push_back(pair);
  }

  std::list<Pair<int, int>> *adyacentes(int v)
  {
    return matrix[v];
  }
};

Pair<std::list<std::list<int> *> *, int> seleccionarMejorSolucion(std::list<int> *solucionActual, int distanciaActual, Pair<std::list<std::list<int> *> *, int> mejoresSoluciones)
{
  if (mejoresSoluciones.value > distanciaActual)
  {
    Pair<std::list<std::list<int> *> *, int> p;
    p.value = distanciaActual;
    p.key = new std::list<std::list<int> *>;
    p.key->push_back(new std::list<int>(*solucionActual));
    return p;
  }
  if (mejoresSoluciones.value == distanciaActual)
  {
    if (solucionActual->size() < mejoresSoluciones.key->front()->size())
    {
      Pair<std::list<std::list<int> *> *, int> p;
      p.value = distanciaActual;
      p.key = new std::list<std::list<int> *>;
      p.key->push_back(new std::list<int>(*solucionActual));
      return p;
    }
    if (solucionActual->size() == mejoresSoluciones.key->front()->size())
    {
      mejoresSoluciones.key->push_back(new std::list<int>(*solucionActual));
      return mejoresSoluciones;
    }
  }
  return mejoresSoluciones;
}

Pair<std::list<std::list<int> *> *, int> seleccionarMejoresSoluciones(Pair<std::list<std::list<int> *> *, int> sols, Pair<std::list<std::list<int> *> *, int> mejoresSoluciones)
{
  if (sols.value > mejoresSoluciones.value)
    return mejoresSoluciones;
  if (sols.value < mejoresSoluciones.value)
    return sols;
  if (sols.key->front()->size() < mejoresSoluciones.key->front()->size())
    return sols;
  if (sols.key->front()->size() > mejoresSoluciones.key->front()->size())
    return mejoresSoluciones;
  if (sols.key->front()->size() == mejoresSoluciones.key->front()->size())
  {
    // agrego todo a sols
    sols.key->insert(sols.key->begin(), mejoresSoluciones.key->begin(), mejoresSoluciones.key->end());
    return sols;
  }
}

Pair<std::list<std::list<int> *> *, int> caminosMasCortosBT(int ciudadOrigen, int ciudadDestino, int numeroDeCiudades, Grafo *g, std::list<int> *solActual, int distanciaActual, bool *visitados, Pair<std::list<std::list<int> *> *, int> mejoresSoluciones)
{
  if (ciudadOrigen == ciudadDestino)
  {
    return seleccionarMejorSolucion(solActual, distanciaActual, mejoresSoluciones);
  }
  // poda
  if (distanciaActual > mejoresSoluciones.value)
  {
    return mejoresSoluciones;
  }

  solActual->push_back(ciudadOrigen);
  visitados[ciudadOrigen] = true;
  std::list<Pair<int, int>> *adyacentes = g->adyacentes(ciudadOrigen);
  for (auto it = adyacentes->begin(); it != adyacentes->end(); it++)
  {
    if (visitados[it->key])
      continue;
    Pair<int, int> pair = *it;
    auto sols = caminosMasCortosBT(pair.key, ciudadDestino, numeroDeCiudades, g, solActual, distanciaActual + pair.value, visitados, mejoresSoluciones);
    mejoresSoluciones = seleccionarMejoresSoluciones(sols, mejoresSoluciones);
  }
  solActual->pop_back();
  visitados[ciudadOrigen] = false;
  return mejoresSoluciones;
}

std::list<std::list<int> *> *caminosMasCortos(int ciudadOrigen, int ciudadDestino, int numeroDeCiudades, Grafo *g)
{
  Pair<std::list<std::list<int> *> *, int> mS;
  mS.key = new std::list<std::list<int> *>;
  mS.value = INT32_MAX;
  bool *visitados = new bool[numeroDeCiudades + 1];
  Pair<std::list<std::list<int> *> *, int> p = caminosMasCortosBT(ciudadOrigen, ciudadDestino, numeroDeCiudades, g, new std::list<int>(), 0, visitados, mS);
  return p.key;
}

int main()
{
  Grafo *g = new Grafo(5);
  g->addEdge(0, 1, 1);
  g->addEdge(0, 2, 2);
  g->addEdge(1, 3, 3);
  g->addEdge(2, 4, 4);
  g->addEdge(3, 4, 5);
  std::list<std::list<int> *> *caminos = caminosMasCortos(0, 4, 5, g);
  for (auto it = caminos->begin(); it != caminos->end(); it++)
  {
    std::list<int> *c = *it;
    for (auto it2 = c->begin(); it2 != c->end(); it2++)
    {
      std::cout << *it2 << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
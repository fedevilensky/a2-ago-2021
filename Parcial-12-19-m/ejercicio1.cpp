// a) haria un dijkstra, donde el camino mas corto es el que tiene menos
// pasos y mas vida

// b)
#include <list>
using namespace std;

#define Health int

template <class T, class U>
struct par
{
  T fst;
  U snd;
  par(T a, U b) : fst(a), snd(b) {}
  bool operator==(const par<T, U> &p) const { return fst == p.fst && snd == p.snd; }
  par<T, U> operator+(const par<T, U> &p) const { return par<T, U>(fst + p.fst, snd + p.snd); }
};

par<int, int> direcciones[] = {
    par<int, int>(0, 1),
    par<int, int>(1, 0),
    par<int, int>(0, -1),
    par<int, int>(-1, 0)};

bool esImposible(char **lab, par<int, int> orig, int N, int M, Health H)
{
  return H == 0 || orig.fst == -1 || orig.fst == N || orig.snd == -1 || orig.snd == M || lab[orig.fst][orig.snd] == 'N';
}

par<list<list<par<int, int>> *> *, Health> *seleccionearSoluciones(
    par<list<list<par<int, int>> *> *, Health> *soluciones,
    par<list<list<par<int, int>> *> *, Health> *sol)
{
  if (soluciones->fst->size() == 0 && sol->fst->size() == 0)
    return soluciones;
  else if (soluciones->fst->front()->size() < sol->fst->front()->size())
    return soluciones;
  else if (soluciones->fst->front()->size() > sol->fst->front()->size())
    return sol;
  else if (soluciones->snd < sol->snd)
    return sol;
  else if (soluciones->snd > sol->snd)
    return soluciones;
  else
  {
    // mergeamos las soluciones
    for (auto it = sol->fst->begin(); it != sol->fst->end(); ++it)
    {
      soluciones->fst->push_back(*it);
    }
  }
}

par<list<list<par<int, int>> *> *, Health> *labBT(
    char **lab, par<int, int> orig, int N, int M, par<int, int> dest, Health H, list<par<int, int>> *solActual, par<list<list<par<int, int>> *> *, Health> *mejoresSoluciones)
{
  // solucion no es posible, retornamos una solucion vacia
  if (esImposible(lab, orig, N, M, H))
  {
    return new par<list<list<par<int, int>> *> *, Health>(new list<list<par<int, int>> *>, H);
  }
  if (orig == dest)
  {
    return new par<list<list<par<int, int>> *> *, Health>(
        new list<list<par<int, int>> *>{new list<par<int, int>>{*solActual}}, H);
  }

  par<list<list<par<int, int>> *> *, Health> *soluciones = mejoresSoluciones;
  // agregamos solucion
  solActual->push_back(orig);
  // poda por largo del camino
  if (soluciones->fst->size() > 0 && soluciones->fst->front()->size() < solActual->size())
    return soluciones;
  for (int i = 0; i < 4; i++)
  {
    auto sig = orig + direcciones[i];
    if (lab[sig.fst][sig.snd] == 'H')
      H--;
    // poda por vida
    if (H < mejoresSoluciones->snd)
      continue;
    par<list<list<par<int, int>> *> *, Health> *sol = labBT(lab, sig, N, M, dest, H, solActual, mejoresSoluciones);
    soluciones = seleccionearSoluciones(soluciones, sol);
    if (lab[sig.fst][sig.snd] == 'H')
      H++;
  }
  // quitamos solucion
  solActual->pop_back();
  // solucion es posible, retornamos una solucion con la posicion actual
}

list<list<par<int, int>> *> *lab(char **laberinto, int N, int M, Health H, par<int, int> orig, par<int, int> dest)
{
  list<par<int, int>> *solActual = new list<par<int, int>>();
  par<list<list<par<int, int>> *> *, Health> *mejoresSoluciones = new par<list<list<par<int, int>> *> *, Health>(new list<list<par<int, int>> *>, 0);
  auto res = labBT(laberinto, orig, N, M, dest, H, solActual, mejoresSoluciones);
  return res->fst;
}

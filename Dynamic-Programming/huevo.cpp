/*
Tenemos dos huevos y un edificio de 36 pisos (para que Fiorella no se queje, son huevos de avestruz, asi que son bien gruesos y aguantan las caidas)
Nos pidieron que averiguemos cual es el piso mas alto desde el que podemos tirar los huevos sin que se rompan
Tenemos los siguientes supuestos
  1. Un huevo que sobrevive la caida, podemos volver a usarlo
  2. Un huevo que se rompa, no podemos volver a usarlo
  3. El efecto de la caida es el mismo para todos los huevos
  4. Si un huevo se rompe, entonces se rompe desde todos los pisos mas altos
  5. Si un huevo sobrevive, entonces sobrevive desde todos los pisos mas bajos
  6. No sabemos que pasa en el piso 1 ni el piso 36

Antes de aceptar el trabajo, queremos saber cuantas veces vamos a tener que ir a buscar el huevo en el peor caso,
porque no queremos subir y bajar las escaleras
*/

// Veamos que pasa con un solo huevo:
// Solo podemos de una manera, ir tirando el huevo piso por piso
// o sea, que tenemos que ir a buscarlo 36 veces en el peor caso
//---------------------------------------------------------------
// Veamos que pasa con dos huevos:
// Queremos calcular el maximo de tirados mas chico que podemos hacer
// O sea, llegar al piso 36, tirando la menor cantidad de veces

// Si el huevo se rompe desde el piso p, entonces solo tenemos que chequear los pisos
// mas bajos a p, asi que el problema se reduce cuantas veces tenemos que tirar un solo
// huevo con p-1 pisos
// Si el huevo NO se rompe desde el piso p, entonces tenemos que chequear los pisos
// mayores a p, o sea 36 - p, con 2 huevos

#include <stdlib.h>
#include <iostream>

using namespace std;

int max(int a, int b)
{
  return a > b ? a : b;
}

int dosHuevos(int pisos = 36)
{
  int min = INT32_MAX;

  if (pisos == 1 || pisos == 0)
    return pisos;
  for (int x = 1; x <= pisos; x++)
  {
    int res = 1 + max(x - 1,                 // se rompe el huevo en el piso x
                      dosHuevos(pisos - x)); // NO se rompe el huevo
    if (res < min)
      min = res;
  }
  return min;
}

// pero no nos da para calcular, entonces se nos ocurre que podemos ir guardando los resultados
int dosHuevosDP(int pisos = 36)
{
  int *pisoHuevo = new int[pisos + 1];
  pisoHuevo[0] = 0;
  pisoHuevo[1] = 1;
  for (int i = 2; i <= pisos; i++)
  {
    pisoHuevo[i] = INT32_MAX;
    for (int x = 1; x <= i; x++)
    {
      int res = 1 + max(x - 1,             // se rompe el huevo en el piso x
                        pisoHuevo[i - x]); // NO se rompe el huevo
      if (res < pisoHuevo[i])
        pisoHuevo[i] = res;
    }
  }

  return pisoHuevo[pisos];
}

int nHuevos(int huevos, int pisos)
{

  int pisoHuevos[huevos + 1][pisos + 1];

  // We need one trial for one floor and 0
  // trials for 0 floors
  for (int i = 1; i <= huevos; i++)
  {
    pisoHuevos[i][1] = 1;
    pisoHuevos[i][0] = 0;
  }

  // We always need j trials for one egg
  // and j floors.
  for (int j = 1; j <= pisos; j++)
    pisoHuevos[1][j] = j;

  // Fill rest of the entries in table using
  // optimal substructure property
  for (int i = 2; i <= huevos; i++)
  {
    for (int j = 2; j <= pisos; j++)
    {
      pisoHuevos[i][j] = INT32_MAX;
      for (int x = 1; x <= j; x++)
      {
        int res = 1 + max(
                          pisoHuevos[i - 1][x - 1],
                          pisoHuevos[i][j - x]);
        if (res < pisoHuevos[i][j])
          pisoHuevos[i][j] = res;
      }
    }
  }

  return pisoHuevos[huevos][pisos];
}

int main()
{
  cout << dosHuevos(12) << endl;
  cout << dosHuevosDP() << endl;
  cout << nHuevos(2, 36) << endl;
  cout << dosHuevos() << endl;
}

int f(int n)
{
  if (n < 4)
  {
    return n;
  }
  else if (n % 2 == 0)
  {
    return f(n - 1) + f(n - 2) + f(n - 3) - f(n - 4);
  }
  else
  {
    return f(n - 2) + f(n - 3) - f(n - 4);
  }
}

// a) el mismo problema que teniamos con fibonacci, pero peor todavia
//  vamos a tener que repetir una cantidad de casos monstruosa
//  O(4^ n)
//  si no repetimos tantos casos entonces va a ser evidentemente mucho mas rapido

// b) memo
int fM(int n)
{
  int memo[n + 1];
  for (int i = 0; i <= n; i++)
  {
    memo[i] = -1;
  }
  return fMemo(n, memo);
}
int fMemo(int n, int *memo)
{
  if (n < 4)
  {
    return n;
  }
  else if (n % 2 == 0)
  {
    if (memo[n] == -1)
    {
      memo[n] = fMemo(n - 1, memo) + fMemo(n - 2, memo) + fMemo(n - 3, memo) - fMemo(n - 4, memo);
    }
    // return memo[n];
  }
  else
  {
    if (memo[n] == -1)
    {
      memo[n] = fMemo(n - 2, memo) + fMemo(n - 3, memo) - fMemo(n - 4, memo);
    }
    // return memo[n];
  }
  return memo[n];
}

// c) tab
int fT(int n)
{
  int tab[n + 1];
  for (int i = 0; i <= n; i++)
  {
    if (n < 4)
      tab[n] = n;
    else if (n % 2 == 0)
    {
      tab[n] = tab[n - 1] + tab[n - 2] + tab[n - 3] - tab[n - 4];
    }
    else
    {
      tab[n] = tab[n - 2] + tab[n - 3] - tab[n - 4];
    }
  }
  return tab[n];
}

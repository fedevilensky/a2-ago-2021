long f(int n)
{
  if (n < 4)
  {
    return n + 1;
  }
  else
  {
    return ((f(n - 1) * f(n - 2)) + f(n - 3)) / f(n - 4);
  }
}

// a) D&C

// b)

long fMemo(int n, long *memo)
{
  if (n < 4)
  {
    memo[n] = n + 1;
    return memo[n];
  }
  else
  {
    memo[n] = ((fMemo(n - 1, memo) * fMemo(n - 2, memo)) + fMemo(n - 3, memo)) / fMemo(n - 4, memo);
    return memo[n];
  }
}

long fM(int n)
{
  long memo[n + 1];
  return fMemo(n, memo);
}

// c)
long fTab(int n)
{
  long tab[n + 1];
  for (int i = 4; i <= n; i++)
  {
    if (i < 4)
      tab[n] = n + 1;
    else
      tab[i] = ((tab[i - 1] * tab[i - 2]) + tab[i - 3]) / tab[i - 4];
  }
  return tab[n];
}
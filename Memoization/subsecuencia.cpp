#include <iostream>
#include <string>

int max(int a, int b)
{
    return a > b ? a : b;
}

int scmMemo(std::string X, std::string Y, int largoX, int largoY, int **memo)
{
    if (largoX == 0 || largoY == 0)
        return 0;
    if (memo[largoX][largoY] != -1)
        return memo[largoX][largoY];
    if (X[largoX - 1] == Y[largoY - 1])
    {
        memo[largoX][largoY] = 1 + scmMemo(X, Y, largoX - 1, largoY - 1, memo);
        return memo[largoX][largoY];
    }
    else
    {
        memo[largoX][largoY] = max(scmMemo(X, Y, largoX - 1, largoY, memo),
                                   scmMemo(X, Y, largoX, largoY - 1, memo));
        return memo[largoX][largoY];
    }
}

// subsecuencia comun minima
// dados dos strings X e Y, encontrar la subsecuencia comun minima de X y Y
// la subsecuencia no tiene que estar contigua, pero los caracteres tienen que aparecer en el mismo orden
// X="AGGTAB" Y = "GXTXAYB" => "GTAB" => 4
int scm(std::string X, std::string Y, int largoX, int largoY)
{
    int **memo = new int *[largoX + 1];
    for (int i = 0; i < largoX + 1; i++)
    {
        memo[i] = new int[largoY + 1];
        for (int j = 0; j < largoY + 1; j++)
        {
            memo[i][j] = -1;
        }
    }
    return scmMemo(X, Y, largoX, largoY, memo);
}

int main()
{
    std::string X = "AGGTAB";
    std::string Y = "GXTXAYB";

    int m = X.size();
    int n = Y.size();

    std::cout << "Length of LCS is " << scm(X, Y, m, n) << std::endl;

    return 0;
}
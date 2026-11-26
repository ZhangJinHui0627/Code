//2026-11-24
#include <iostream>
using namespace std;

int CommonOrder(char x[], int m, char y[], int n, char z[]);

int main()
{
    const int m = 6, n = 9;
    int i, k;
    char x[m + 1] = {'0', 'a', 'b', 'c', 'b', 'd', 'b'},
         y[n + 1] = {'0', 'a', 'c', 'b', 'b', 'a', 'b', 'd', 'b', 'b'},
         z[m + 1];
    k = CommonOrder(x, m, y, n, z);
    cout << "最长公共子序列的长度是: " << k << endl;
    cout << "最长公共子序列是: ";
    for (i = 0; i < k; i++)
        cout << z[i];
    cout << endl;
    return 0;
}

int CommonOrder(char x[], int m, char y[], int n, char z[])
{
    int i, j, k;
    int L[m + 1][n + 1], S[m + 1][n + 1];
    for (j = 0; j <= n; j++)
        L[0][j] = 0;
    for (i = 0; i <= m; i++)
        L[i][0] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 1;
            }
            else if (L[i][j - 1] >= L[i - 1][j])
            {
                L[i][j] = L[i][j - 1];
                S[i][j] = 2;
            }
            else
            {
                L[i][j] = L[i - 1][j];
                S[i][j] = 3;
            }
        }
    }
    i = m; j = n; k = L[m][n];
    while (i > 0 && j > 0)
    {
        if (S[i][j] == 1)
        {
            z[--k] = x[i];
            --i;
            --j;
        }
        else if (S[i][j] == 2)
            --j;
        else
            --i;
    }
    return L[m][n];
}

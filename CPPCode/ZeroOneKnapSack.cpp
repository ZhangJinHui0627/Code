//2026-11-27
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int KnapSack(int w[], int v[], int n, int C, int x[]);

int main()
{
    const int n = 5, C = 10;
    int i;
    int w[n + 1] = {0, 2, 2, 6, 5, 4};
    int v[n + 1] = {0, 6, 3, 5, 4, 6};
    int x[n + 1] = {0};

    cout << "背包获得的最大价值是：" << KnapSack(w, v, n, C, x) << endl;
    cout << "装入背包的物品编号是：";
    for (i = 1; i <= n; i++)
        if (x[i] == 1)
            cout << i << " ";
    cout << endl;

    return 0;
}

int KnapSack(int w[], int v[], int n, int C, int x[])
{
    int i, j;
    vector<vector<int>> V(n + 1, vector<int>(C + 1, 0));

    for (j = 0; j <= C; j++)
        V[0][j] = 0;
    for (i = 0; i <= n; i++)
        V[i][0] = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= C; j++)
        {
            if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
        }
    }

    for (i = n, j = C; i > 0; i--)
    {
        if (V[i][j] > V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
        {
            x[i] = 0;
        }
    }

    return V[n][C];
}

//2026-11-13
#include <iostream>
#include <climits>
using namespace std;

const int n = 5;
int arc[n][n] = {
    {0,  3,  8,  6,  9},
    {3,  0,  5, 11,  7},
    {8,  5,  0,  4, 10},
    {6, 11,  4,  0,  2},
    {9,  7, 10,  2,  0}
};

int TSP(int start, int path[])
{
    int S[n] = {0}, k, v, i, min, sum = 0;
    k = start;
    S[k] = 1;
    path[0] = k;
    for (int t = 1; t < n; t++)
    {
        min = INT_MAX;
        v = -1;
        for (i = 0; i < n; i++)
            if (S[i] == 0 && arc[k][i] > 0 && arc[k][i] < min)
            {
                v = i;
                min = arc[k][i];
            }
        if (v == -1) return -1;
        S[v] = 1;
        path[t] = v;
        sum += min;
        k = v;
    }
    sum += arc[k][start];
    return sum;
}

int main()
{
    int path[n];
    for (int start = 0; start <= 1; start++)
    {
        int sum = TSP(start, path);
        cout << "从城市" << start << "出发: ";
        for (int i = 0; i < n; i++)
            cout << path[i] << " -> ";
        cout << path[0] << "  路径总长: " << sum << endl;
    }
    return 0;
}

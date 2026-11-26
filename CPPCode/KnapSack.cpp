//2026-11-13
#include <iostream>
#include <vector>
using namespace std;

double KnapSack(int w[], int v[], int n, int C);

int main()
{
    const int n = 3;
    int w[n] = {10, 30, 20}, v[n] = {50, 120, 60}, C = 50;
    cout << "背包获得的最大价值是: " << KnapSack(w, v, n, C) << endl;
    return 0;
}

double KnapSack(int w[], int v[], int n, int C)
{
    vector<double> x(n, 0.0);
    double maxValue = 0;
    int i;
    for (i = 0; i < n && w[i] <= C; i++)
    {
        x[i] = 1;
        maxValue += v[i];
        C = C - w[i];
    }
    if (i < n)
    {
        x[i] = (double)C / w[i];
        maxValue += x[i] * v[i];
    }
    return maxValue;
}

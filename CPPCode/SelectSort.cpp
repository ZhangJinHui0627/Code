//2026-10-16
#include <iostream>
using namespace std;

void SelectSort(int r[], int n);

int main()
{
    int i, n = 5, r[5] = {49, 27, 65, 38, 13};
    for (i = 0; i < n; i++)
        cout << r[i] << " ";
    cout << endl;
    SelectSort(r, n);
    for (i = 0; i < n; i++)
        cout << r[i] << " ";
    cout << endl;
    return 0;
}

void SelectSort(int r[], int n)
{
    int i, j, k, temp;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (r[j] < r[k])
                k = j;
        }
        if (k != i)
        {
            temp = r[i];
            r[i] = r[k];
            r[k] = temp;
        }
    }
}

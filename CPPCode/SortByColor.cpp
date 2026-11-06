//2026-9-18
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void ColorSort(int a[], int n)
{
    int n1 = 0, n2 = 0, n3 = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] == 1)
            n1++;
        if(a[i] == 2)
            n2++;
        if(a[i] == 3)
            n3++;
    }
    for(i = 0; i < n1; i++)
        a[i] = 1;
    for(; i < n1 + n2; i++)
        a[i] = 2;
    for(; i < n1 + n2 + n3; i++)
        a[i] = 3;
}

int main()
{
    srand(time(0));
    const int n = 15;
    int a[n];
    cout << "排序前数组：";
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 3 + 1;
        cout << a[i] << " ";
    }
    cout << endl;
    ColorSort(a, n);
    cout << "排序后数组：";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

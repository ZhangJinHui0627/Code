//2026-9-18
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void CountSort(int A[], int n, int k, int B[])
{
    int* num = new int[k+1]{0};
    for(int i = 0; i < n; i++)
    {
        num[A[i]]++;
    }
    for(int i = 1; i <= k; i++)
    {
        num[i] += num[i-1];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        B[ --num[A[i]] ] = A[i];
    }
    delete[] num;
}

int main()
{
    srand(time(0));
    const int n = 10;
    const int k = 9;
    int A[n];
    int B[n];
    cout << "排序前数组：";
    for(int i = 0; i < n; i++)
    {
        A[i] = rand() % 10;
        cout << A[i] << " ";
    }
    cout << endl;
    CountSort(A, n, k, B);
    cout << "排序后数组：";
    for(int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}

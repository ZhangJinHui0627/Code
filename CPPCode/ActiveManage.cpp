//2026-11-10
#include <iostream>
using namespace std;

int ActiveManage(int s[], int f[], int B[], int n);

int main()
{
    const int n = 11;
    int s[n] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12},
        f[n] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int i, k = 0, B[n] = {0};
    k = ActiveManage(s, f, B, n);
    cout << "最多安排的活动个数是: " << k << endl;
    cout << "安排的活动是: ";
    for (i = 0; i < n; i++)
        if (B[i] == 1) cout << i + 1 << " ";
    cout << endl;
    return 0;
}

int ActiveManage(int s[], int f[], int B[], int n)
{
    int i, j, count;
    B[0] = 1; j = 0; count = 1;
    for (i = 1; i < n; i++)
    {
        if (s[i] >= f[j])
        {
            B[i] = 1; count++;
            j = i;
        }
        else B[i] = 0;
    }
    return count;
}

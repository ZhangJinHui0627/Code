//2026-10-23
#include <iostream>
#include <algorithm>
using namespace std;

int MaxSum(int a[], int left, int right);

int main()
{
    int max, n = 6, r[6] = {-20, 11, -4, 13, -5, -2};
    max = MaxSum(r, 0, n-1);
    cout<<"最大子段和是："<<max<<endl;
    return 0;
}

int MaxSum(int a[], int left, int right) {
    if (left == right) {
        return a[left] > 0 ? a[left] : 0;
    }

    int center = (left + right) / 2;
    int leftSum = MaxSum(a, left, center);
    int rightSum = MaxSum(a, center + 1, right);

    int s1 = 0, lefts = 0;
    for (int i = center; i >= left; i--) {
        lefts += a[i];
        if (lefts > s1) s1 = lefts;
    }

    int s2 = 0, rights = 0;
    for (int i = center + 1; i <= right; i++) {
        rights += a[i];
        if (rights > s2) s2 = rights;
    }

    int midSum = s1 + s2;

    int sum = max(leftSum, rightSum);
    return max(sum, midSum);
}

//2026-10-9
#include <iostream>
using namespace std;

int MonkeyPeach(int n)
{
    int peaches = 1;
    for (int day = n - 1; day >= 1; day--)
    {
        peaches = (peaches + 1) * 2;
    }
    return peaches;
}

int main()
{
    int n = 10;
    cout << MonkeyPeach(n) << endl;
    return 0;
}

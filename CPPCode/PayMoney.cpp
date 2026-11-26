//2026-11-10
#include <iostream>
using namespace std;

int PayMoney(double sum)
{
    int money[6] = {50, 20, 10, 5, 2, 1};
    int i, count = 0, n = sum * 10;
    while (n > 0)
    {
        for (i = 0; i < 6; i++)
        {
            if (n >= money[i])
            {
                count++;
                n = n - money[i];
                break;
            }
        }
    }
    return count;
}

int main()
{
    double sum;
    cout << "请输入要找零的金额(元): ";
    cin >> sum;
    cout << "最少张数: " << PayMoney(sum) << endl;
    return 0;
}

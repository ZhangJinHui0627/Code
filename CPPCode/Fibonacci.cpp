//2026-10-9
#include <iostream>
using namespace std;

int Fibonacci(int n);

int main()
{
    int n;
    cout << "请输入月份：";
    cin >> n;
    cout << Fibonacci(n) << endl;
    return 0;
}

int Fibonacci(int n)
{
    int f, f1 = 1, f2 = 1;
    for (int i = 3; i <= n; i++)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f2;
}

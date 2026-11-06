//2026-10-10
#include <iostream>
using namespace std;

int Bernoulli(int n);

int main()
{
    int n;
    cout<<"请输入一个大于2的正整数：";
    cin>>n;
    cout<<Bernoulli(n)<<endl;
    return 0;
}

int Bernoulli(int n)
{
    int i, b, b1 = 1, b2 = 0;
    for(i = 3; i <= n; i++)
    {
        b = (i - 1) * (b1 + b2);
        b2 = b1;
        b1 = b;
    }
    return b;
}

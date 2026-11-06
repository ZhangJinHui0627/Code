#include <iostream>
using namespace std;

int Coin(int a[], int low, int high, int n);

int main()
{
    int i, t;
    const int n = 8;
    int a[n] = {1,1,0,1,1,1,1,1};
    for (i = 0; i < n; i++)
        cout<<a[i]<<"\t";
    cout<<endl;
    t = Coin(a, 0, n - 1, n);
    cout<<"第"<<t<<"个硬币是假币"<<endl;
    return 0;
}

int Coin(int a[], int low, int high, int n)
{
    int i, num1, num2, num3;
    int add1 = 0, add2 = 0;
    if (n == 1)
        return low + 1;                    //返回序号
    if (n % 3 == 0)                       //3组硬币的个数相同
        num1 = num2 = n / 3;
    else                                  //前两组有较多硬币
        num1 = num2 = n / 3 + 1;
    num3 = n - num1 - num2;
    for (i = 0; i < num1; i++)            //计算第1组硬币的重量和
        add1 = add1 + a[low + i];
    for (; i < num1 + num2; i++)          //计算第2组硬币的重量和
        add2 = add2 + a[low + i];
    if (add1 < add2)                      //在第1组查找
        return Coin(a, low, low + num1 - 1, num1);
    else if (add1 > add2)                 //在第2组查找
        return Coin(a, low + num1, low + num1 + num2 - 1, num2);
    else                                  //在第3组查找
        return Coin(a, low + num1 + num2, high, num3);
}

//2026-9-22
#include<iostream>
using namespace std;

int Packing(int k1, int k2, int k3, int k4, int k5, int k6)
{
    int ans = k6 + k5 + k4 + (k3 + 3) / 4;

    int empty2_for_k3[4] = {0, 5, 3, 1};

    int empty_2 = k4 * 5 + empty2_for_k3[k3 % 4];

    if (k2 > empty_2)
    {
        ans += (k2 - empty_2 + 8) / 9;
    }

    int empty_1 = ans * 36 - (k6 * 36 + k5 * 25 + k4 * 16 + k3 * 9 + k2 * 4);
    if (k1 > empty_1)
    {
        ans += (k1 - empty_1 + 35) / 36;
    }

    return ans;
}

int main()
{
    int k1,k2,k3,k4,k5,k6,n;
    cout<<"请输入6种型号产品的数量：";
    cin>>k1>>k2>>k3>>k4>>k5>>k6;
    n=Packing(k1,k2,k3,k4,k5,k6);
    cout<<n<<endl;
    return 0;
}

#include <iostream>
using namespace std;

void Chicken();

int main()
{
    Chicken();
    return 0;
}

void Chicken()
{
    int x, y, z, count = 0;
    for (x = 0; x <= 20; x++)
    {
        for (y = 0; y <= 33; y++)
        {
            z = 100 - x - y; //满足共100只
            if ((z % 3 == 0) && (5 * x + 3 * y + z/3 == 100)) //满足总价100元
            {
                count++; //解的个数加1
                cout << "公鸡：" << x << "母鸡：" << y << "小鸡：" << z << endl;
            }
        }
    }
    if (count == 0)
        cout << "问题无解" << endl;
}

//2026-9-15
#include <iostream>
#include <vector>

int Joseph(int n, int m)
{
    if (n <= 0 || m <= 0)
    {
        return -1;
    }

    std::vector<int> r(n, 0);

    int count = 0;
    int i = -1;
    int num = 0;

    while (num < n - 1)
    {
        while (count < m)
        {
            i = (i + 1) % n;
            if (r[i] == 0)
            {
                count++;
            }
        }
        r[i] = 1;
        num++;
        count = 0;
    }

    for (int k = 0; k < n; k++)
    {
        if (r[k] == 0)
        {
            return k + 1;
        }
    }

    return -1;
}

int main()
{
    int n, m;
    std::cout << "请输入参与人数 n 和密码 m: ";
    while (std::cin >> n >> m)
    {
        int survivor = Joseph(n, m);
        if (survivor != -1)
        {
            std::cout << "幸存者编号: " << survivor << std::endl;
        } else
        {
            std::cout << "输入参数无效" << std::endl;
        }

        std::cout << "请输入参与人数 n 和密码 m: ";
    }

    return 0;
}

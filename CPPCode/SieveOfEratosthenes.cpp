//2026-9-15
#include <iostream>
#include <vector>

void EratoSieve(int n, int A[])
{
    if (n >= 0) A[0] = 1;
    if (n >= 1) A[1] = 1;

    for (int i = 2; i <= n / 2; i++)
    {
        if (A[i] != 0)
        {
            continue;
        }

        for (int j = 2 * i; j <= n; j += i)
        {
            A[j] = 1;
        }

    }

    std::cout << "区间 [1, " << n << "] 之间的所有素数如下：" << std::endl;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (A[i] == 0)
        {
            std::cout << i << " ";
            count++;
            if (count % 10 == 0)
            {
                std::cout << std::endl;
            }
        }
    }
    if (count % 10 != 0)
    {
        std::cout << std::endl;
    }
    std::cout << "素数总个数: " << count << std::endl;
}

int main()
{
    int n;
    std::cout << "请输入待确定素数的范围 n (例如 100): ";
    if (std::cin >> n)
    {
        if (n < 2)
        {
            std::cout << "区间 [1, " << n << "] 内没有素数。" << std::endl;
            return 0;
        }

        std::vector<int> A(n + 1, 0);
        EratoSieve(n, A.data());
    }

    return 0;
}

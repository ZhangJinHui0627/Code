//2026-9-15
#include <iostream>

void Feets(int n, int &maxNum, int &minNum)
{
    if (n <= 0 || n % 2 != 0)
    {
        maxNum = 0;
        minNum = 0;
    }
    else if (n % 4 == 0)
    {
        maxNum = n / 2;
        minNum = n / 4;
    }
    else
    {
        maxNum = n / 2;
        minNum = (n - 2) / 4 + 1;
    }
}

int main()
{
    int n;
    std::cout << "请输入脚数 n: ";
    while (std::cin >> n)
    {
        int maxNum = 0;
        int minNum = 0;

        Feets(n, maxNum, minNum);

        if (maxNum == 0 && minNum == 0)
        {
            std::cout << "无解" << std::endl;
        }
        else
        {
            std::cout << maxNum << " " << minNum << std::endl;
        }

        std::cout << "请输入脚数 n: ";
    }

    return 0;
}

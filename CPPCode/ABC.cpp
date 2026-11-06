#include <iostream>

int main() {
    int count = 0;

    std::cout << "序号\t1元\t2元\t5元\n";

    for (int x = 1; x <= 23; ++x) {
        for (int y = 1; y <= 23; ++y) {
            int z = 25 - x - y;

            if (z >= 1 && x + 2 * y + 5 * z == 50) {
                ++count;
                std::cout << count << '\t'
                          << x << '\t'
                          << y << '\t'
                          << z << '\n';
            }
        }
    }

    std::cout << "共有 " << count << " 种兑换方案" << std::endl;
    return 0;
}

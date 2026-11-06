#include <iostream>
using namespace std;
int GetFish(int fish[], int n);
int main()
{
	int i, n = 5, fish[100];
	GetFish(fish, n);
	cout << "至少捕到的鱼数是：" << fish[0] << endl;
	for (i = 0; i < n; i++)
		cout << "第" << i + 1 << "个人看到的鱼数是：" << fish[i] << endl;
	return 0;
}
int GetFish(int fish[], int n)
{
	int i, flag = 0;
	fish[0] = 1;
	while (flag == 0)
	{
		flag = 1;
		for (i = 0; i < n - 1; i++)
		{
			if (fish[i] % 5 != 1)
			{
				flag = 0;
				break;
			}
			fish[i + 1] = (fish[i] - 1) / 5 * 4;
		}
		if (flag == 1 && fish[n - 1] % 5 != 1)
			flag = 0;
		if (flag == 0)
			fish[0]++;
	}
	return 0;
}

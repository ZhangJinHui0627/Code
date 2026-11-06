/**
 * @file HelloWorld.c
 * @brief 经典的 HelloWorld 死循环测试程序
 * @details 用于在控制台中死循环测试 C 语言打印输出，检测环境是否能流畅运行并测试终端占用。
 */
#include <stdio.h>
int main()
{
  while(1)
  {
    printf("你好，世界");
  }
  return 0;
}

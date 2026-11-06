# Code

个人编程练习与课程代码归档仓库：C 语言、C++ 算法与数据结构、Java 面向对象课程练习。

## 目录结构

```
Code/
├── CCode/      C 语言练习与数据结构实现（按日期命名，19 个文件）
├── CPPCode/    C++ 算法与数据结构练习（19 个文件）
├── JavaCode/   Java 课程练习（IntelliJ IDEA 工程 demo1）
└── README.md
```

## CCode

C 语言练习与数据结构，文件名按"月-日"命名；带 `_fixed` 后缀的是修正版，原始版本保留作为 Debug 对照。

| 文件 | 内容 |
| :--- | :--- |
| 04-27.c | 稀疏矩阵的快速转置（三元组顺序表、`num`/`cpot` 辅助数组） |
| 05-06.cpp | 二叉树的先序/后序非递归遍历与层次遍历（辅助栈、循环队列） |
| 05-22.c | 邻接矩阵求顶点度（Bug 历史版本，度数计数器未重置） |
| 05-22_fixed.c | 邻接矩阵求顶点度（修复版） |
| 05-25.c | 邻接表存储与建立（数组越界 Bug 版本） |
| 05-25_fixed.c | 邻接表存储、邻接点查询与顶点度计算（修复版） |
| 05-27.c | 邻接矩阵建图、求度与非递归 DFS（编译报错版） |
| 05-27_fixed.c | 邻接矩阵建图、求度与非递归 DFS（修复版） |
| 06-01.c | 图存储结构练习（原始版） |
| 06-01_fixed.c | 图存储结构练习（修正版） |
| 06-30(1).c | 住宿档案管理（结构体 + 定长数组版） |
| 06-30.c | 住宿档案管理（结构体数组实现） |
| 06-30_fixed.c | 住宿档案管理（修正版） |
| 07-02.c | 住宿档案管理（后续迭代） |
| 07-04.c | 住宿档案管理（后续迭代） |
| helloWorld.c | 环境测试：控制台循环打印问候语 |
| map.cpp | 沙漠掘金：多阶段路径决策规划（DFS 状态树遍历） |
| qualityRoutePlanner.cpp | 沙漠掘金路径规划（重构、补充注释版） |
| student.c | 学生信息管理（结构体、菜单交互） |

## CPPCode

C++ 算法与数据结构练习，多数文件开头标注了练习日期。

| 文件 | 内容 |
| :--- | :--- |
| InsertSort.cpp | 直接插入排序 |
| SelectSort.cpp | 选择排序 |
| CountSort.cpp | 计数排序（含随机数据生成） |
| SortByColor.cpp | 三色排序（按颜色分组） |
| Fibonacci.cpp | 斐波那契数列 |
| Bernoulli.cpp | 伯努利数 |
| Catalan.cpp | 卡特兰数 |
| MonkeyPeach.cpp | 猴子吃桃（逆推递推） |
| PackingProblem.cpp | 装箱问题 |
| CoinProblem.cpp | 假币问题（分治） |
| JosephusProblem.cpp | 约瑟夫环 |
| SieveOfEratosthenes.cpp | 埃拉托斯特尼筛法求素数 |
| ChessBoard.cpp | 棋盘覆盖（分治） |
| MaxSum.cpp | 最大子段和（分治） |
| GetFish.cpp | 分鱼问题（递推） |
| Game.cpp | 猜拳/对弈小游戏 |
| chicken.cpp | 鸡兔同笼 |
| TheChickenAndRabbitCageProblem.cpp | 鸡兔同笼（脚数约束，求最大/最小只数） |
| ABC.cpp | 组合计数（1/2/5 元凑数） |

## JavaCode

`demo1` 为 IntelliJ IDEA 工程（`demo1.iml`），源码位于 `demo1/src`，以 `c<章>_<节>_<序号>` 命名对应课程章节的课堂练习。

| 包 | 内容 |
| :--- | :--- |
| `com.demo1`、`com.demo1.basic` | Java 基础：数组、二维数组、类与对象、类方法 |
| `com.demo1.ser` | 对象与序列化相关示例 |
| `c2_1_2` | 类与对象：Employee/Person 定义、构造方法、封装（private + getter/setter）、方法调用 |
| `c2_2_1`、`c2_2_2` | 继承与多态：父类 Animal 与子类方法重写、父类引用指向子类对象 |
| `c2_3_1`、`c2_3_2` | 抽象类与接口：abstract 方法、接口实现、default 方法 |
| `c2_3_4`、`c2_3_5` | 内部类：成员内部类、静态内部类、匿名内部类与 Lambda 表达式 |
| `c2_4_1/String`、`c2_4_1/StringBuffer` | 字符串 API：String 常用方法、StringBuffer/StringBuilder 的追加/插入/删除/替换/反转与容量 |

## 编译与运行

**C / C++（GCC / G++）**

```bash
gcc CCode/05-22_fixed.c -o graph_matrix
./graph_matrix

g++ CPPCode/InsertSort.cpp -o insert_sort
./insert_sort
```

**Java（JDK 8+）**

```bash
cd JavaCode/demo1/src
javac c2_1_2/c1/Main.java
java c2_1_2.c1.Main
```

或直接用 IntelliJ IDEA 打开 `JavaCode/demo1` 工程运行。

## 约定

- 构建产物（`*.exe`、`*.o`、`*.class`、`out/`、`bin/`、`build/`）不入库。
- 早期 C 代码曾维护在独立仓库 `ZhangJinHui0627/C`，已整体迁入本仓库的 `CCode/` 目录，历史提交仍保留在旧仓库。

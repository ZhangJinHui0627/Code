/**
 * @file 4-27.c
 * @brief 稀疏矩阵的快速转置算法
 * @details 稀疏矩阵使用三元组顺序表（Triple Sequence List）存储，快速转置
 *          算法通过两个辅助数组 num（统计每列非零元个数）和 cpot（存储每列首个非零元的目标位置），
 *          从而在时间复杂度 O(列数 + 非零元个数) 内实现快速转置。
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20        // 三元组的最大容量

// 三元组结构定义
typedef struct {
    int i;   // 行下标 (1..mu)
    int j;   // 列下标 (1..nu)
    int v;   // 非零元的值
} Triple;

// 三元组顺序表结构定义
typedef struct {
    int mu;              // 矩阵的行数
    int nu;              // 矩阵的列数
    int tu;              // 矩阵的非零元个数
    Triple data[MAXSIZE + 1]; // 三元组一维数组，从下标1开始存储，data[0]未用
} Matrix;

// 对三元组顺序表进行按行优先和列优先排序
void SortTriple(Matrix *M) {
    int i, j;
    Triple t;
    for (i = 1; i < M->tu; i++) {
        for (j = i + 1; j <= M->tu; j++) {
            if ((M->data[i].i > M->data[j].i) ||
                (M->data[i].i == M->data[j].i && M->data[i].j > M->data[j].j)) {
                t = M->data[i];
                M->data[i] = M->data[j];
                M->data[j] = t;
            }
        }
    }
}

// 打印输出三元组格式数据
void ShowTriple(Matrix M) {
    int p;
    printf("行  列  值\n");
    for (p = 1; p <= M.tu; p++) {
        printf("%-4d%-4d%d\n", M.data[p].i, M.data[p].j, M.data[p].v);
    }
}

// 还原并打印出完整的稠密稀疏矩阵
void ShowMatrix(Matrix M) {
    int p, i, j;
    printf("当前稀疏矩阵 (%d行 乘 %d列, 非零元个数:%d):\n", M.mu, M.nu, M.tu);
    p = 1;
    for (i = 1; i <= M.mu; i++) {
        for (j = 1; j <= M.nu; j++) {
            if (p <= M.tu && M.data[p].i == i && M.data[p].j == j) {
                printf("%4d", M.data[p].v);
                p++;
            } else {
                printf("%4d", 0);
            }
        }
        printf("\n");
    }
}

// 快速转置核心算法
void FastTran(Matrix *X, Matrix *Y) {
    int col, p, q;
    int num[MAXSIZE + 1];   // 统计原矩阵 X 中每一列（转置后为 Y 的行）非零元素的个数
    int cpot[MAXSIZE + 1];  // 存放转置后每一行首个非零元素在 Y.data[] 中的起始存储位置

    Y->mu = X->nu;
    Y->nu = X->mu;
    Y->tu = X->tu;

    if (Y->tu == 0)
        return;

    // 初始化 num 数组
    for (col = 1; col <= X->nu; col++)
        num[col] = 0;

    // 遍历 X 统计各列的非零元个数
    for (p = 1; p <= X->tu; p++)
        num[X->data[p].j]++;

    // 计算各列的 cpot 数组值
    cpot[1] = 1;
    for (col = 2; col <= X->nu; col++)
        cpot[col] = cpot[col - 1] + num[col - 1];

    // 执行快速转置
    for (p = 1; p <= X->tu; p++) {
        col = X->data[p].j;
        q = cpot[col];
        Y->data[q].i = X->data[p].j;
        Y->data[q].j = X->data[p].i;
        Y->data[q].v = X->data[p].v;
        cpot[col]++;
    }
}

int main() {
    Matrix M, T;

    // 设置本地编码，这里可作为环境注释
    // setlocale(LC_ALL, ".65001");

    printf("请输入矩阵的行数、列数以及非零元个数：");
    if (scanf("%d %d %d", &M.mu, &M.nu, &M.tu) != 3) {
        printf("输入格式错误\n");
        return 1;
    }

    // 参数合法性校验
    if (M.mu <= 0 || M.nu <= 0 || M.tu < 0 || M.tu > MAXSIZE) {
        printf("非零元个数必须为 0 ~ %d 之间\n", MAXSIZE);
        return 1;
    }

    if (M.tu > 0) {
        printf("请输入这 %d 个非零元的三元组（输入格式：行号 列号 元素值）：\n", M.tu);
        for (int p = 1; p <= M.tu; p++) {
            printf("元素序号 %d: ", p);
            if (scanf("%d %d %d", &M.data[p].i, &M.data[p].j, &M.data[p].v) != 3) {
                printf("输入数据错误\n");
                return 1;
            }
            // 数据边界值检查
            if (M.data[p].i < 1 || M.data[p].i > M.mu ||
                M.data[p].j < 1 || M.data[p].j > M.nu) {
                printf("输入元素的行列下标超出了矩阵的大小范围\n");
                return 1;
            }
        }

        // 对录入的三元组进行行优先和列优先排序
        SortTriple(&M);
    }

    printf("\n========== 原始矩阵 ==========\n");
    ShowTriple(M);
    ShowMatrix(M);

    FastTran(&M, &T);

    printf("\n========== 快速转置后的矩阵 ==========\n");
    ShowTriple(T);
    ShowMatrix(T);

    return 0;
}

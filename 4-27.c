#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20        // 最多支持的非零元个数

// 三元组
typedef struct {
    int i;   // 行号 (1..mu)
    int j;   // 列号 (1..nu)
    int v;   // 非零元的值
} Triple;

// 稀疏矩阵
typedef struct {
    int mu;              // 行数
    int nu;              // 列数
    int tu;              // 非零元个数
    Triple data[MAXSIZE + 1]; // 从下标1开始存储，data[0]闲置
} Matrix;

// 对三元组按行序为主序排序（行相同时按列序）
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

// 以三元组形式输出稀疏矩阵
void ShowTriple(Matrix M) {
    int p;
    printf("行  列  值\n");
    for (p = 1; p <= M.tu; p++) {
        printf("%-4d%-4d%d\n", M.data[p].i, M.data[p].j, M.data[p].v);
    }
}

// 以二维表格形式输出稀疏矩阵（便于直观查看）
void ShowMatrix(Matrix M) {
    int p, i, j;
    printf("稀疏矩阵 (%d行 × %d列, 非零元:%d):\n", M.mu, M.nu, M.tu);
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

// 快速转置
void FastTran(Matrix *X, Matrix *Y) {
    int col, p, q;
    int num[MAXSIZE + 1];   // 统计每列非零元个数，索引 1..nu
    int cpot[MAXSIZE + 1];  // 每列第一个非零元在转置矩阵 data[] 中的位置

    Y->mu = X->nu;
    Y->nu = X->mu;
    Y->tu = X->tu;

    if (Y->tu == 0)
        return;

    // 初始化 num
    for (col = 1; col <= X->nu; col++)
        num[col] = 0;

    // 统计每一列的非零元个数
    for (p = 1; p <= X->tu; p++)
        num[X->data[p].j]++;

    // 计算 cpot
    cpot[1] = 1;
    for (col = 2; col <= X->nu; col++)
        cpot[col] = cpot[col - 1] + num[col - 1];

    // 执行转置
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

    // 若终端输出中文乱码，请取消下面一行的注释，并在文件头部包含 <locale.h>
    // setlocale(LC_ALL, ".65001");

    printf("请输入矩阵的行数、列数和非零元个数（空格分隔）：");
    if (scanf("%d %d %d", &M.mu, &M.nu, &M.tu) != 3) {
        printf("输入格式错误！\n");
        return 1;
    }

    // 合法性检查
    if (M.mu <= 0 || M.nu <= 0 || M.tu < 0 || M.tu > MAXSIZE) {
        printf("输入参数无效：行列数必须为正，非零元个数应在 0 ~ %d 之间。\n", MAXSIZE);
        return 1;
    }

    if (M.tu > 0) {
        printf("请输入 %d 个三元组，每行格式：行号 列号 值（行/列从1开始）\n", M.tu);
        for (int p = 1; p <= M.tu; p++) {
            printf("三元组 %d: ", p);
            if (scanf("%d %d %d", &M.data[p].i, &M.data[p].j, &M.data[p].v) != 3) {
                printf("输入格式错误！\n");
                return 1;
            }
            // 检查行列范围
            if (M.data[p].i < 1 || M.data[p].i > M.mu ||
                M.data[p].j < 1 || M.data[p].j > M.nu) {
                printf("错误：三元组的行号或列号超出矩阵范围！\n");
                return 1;
            }
        }

        // 排序，使三元组按行序有序（便于后续操作）
        SortTriple(&M);
    }

    printf("\n========== 转置前 ==========\n");
    ShowTriple(M);
    ShowMatrix(M);

    FastTran(&M, &T);

    printf("\n========== 快速转置后 ==========\n");
    ShowTriple(T);
    ShowMatrix(T);

    return 0;
}

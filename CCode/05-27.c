/**
 * @file 5-27.c
 * @brief 无向图的建立、求顶点度及非递归DFS遍历（编译 Bug 版）
 * @details 用于建立无向邻接矩阵存储的图，但在第 54-55 行对 vexs 数组使用了不存在的 .data 
 *          和 flag 属性，用于展示和测试 C 语言编译时的 Debug 报错。
 */
#include<stdio.h>
#include<stdlib.h>
#define N 10

// 邻接矩阵存储图的结构体定义
typedef struct
{
    int vexnum; // 图的顶点个数
    int arcnum; // 图的边数（弧数）
    char vexs[N]; // 顶点信息一维数组
    int adj[N][N]; // 存储邻接关系的二维矩阵
}Graph;

// 辅助栈结构体定义
typedef struct
{
    int a[N];// 存储栈中元素的数组
    int top;// 栈顶指针
}stack;

// 定位顶点在顶点数组中的下标，未找到则返回 -1
int locate(char ch, Graph g)
{
    int i;
    for(i=0;i<g.vexnum;i++)
    {
        if(ch==g.vexs[i])
        {
            return i;
        }
    }
    return -1; // 未找到该顶点
}

int main()
{
    Graph G;
    int i,j,m,n;
    char ch1,ch2;

    printf("\n请输入图的顶点个数和边数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);

    printf("\n请输入这 %d 个顶点的信息：", G.vexnum);
    fflush(stdin);
    for(i=0;i<G.vexnum;i++)
    {
        scanf(" %c",&G.vexs[i].data); // 此处 vexs[i] 是 char，没有 .data 属性，为编译 Bug 演示点
        G.vex[i].flag=0; // 此处结构体中无 vex[i] 与 flag 成员，为编译 Bug 演示点
    }

    printf("\n图的顶点信息为：");
    for(i=0;i<G.vexnum;i++)
    {
        printf(" %c", G.vexs[i].data);
    }

    // 邻接矩阵初始化
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            G.adj[i][j] = 0;
        }
    }

    // 读入各条边信息
    printf("\n\n请输入这 %d 条边（每条边输入两个相邻顶点）：", G.arcnum);
    fflush(stdin);
    for(i=0;i<G.arcnum;i++)
    {
        scanf(" %c %c",&ch1,&ch2);
        m=locate(ch1, G);
        n=locate(ch2, G);

        G.adj[m][n]=G.adj[n][m]=1;
    }

    // 打印无向图的邻接矩阵
    printf("\n图的邻接矩阵为：\n");
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            printf("%-4d", G.adj[i][j]);
        }
        printf("\n");
    }

    // 计算并输出每个顶点的度
    for(i=0;i<G.vexnum;i++)
    {
        n=0; // 顶点的度计数初始化为 0
        for(j=0;j<G.vexnum;j++)
        {
            if(G.adj[i][j]==1)
            {
                n++;
            }
        }
        printf("顶点%c的度为：%d\n", G.vexs[i], n);
    }

    printf("请输入要查询邻接点的顶点：");
    fflush(stdin);
    scanf(" %c", &ch1);
    m=locate(ch1, G);
    printf("与顶点%c相邻接的顶点有：", G.vexs[m]);
    for(j=0;j<G.vexnum;j++)
    {
        if(G.adj[m][j]==1)
        {
            printf("%c ", G.vexs[j]);
        }
    }

    return 0;
}

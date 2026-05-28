/**
 * @file 5-27_fixed.c
 * @brief 无向图的建立、求顶点度及非递归深度优先搜索（DFS）遍历
 * @details 使用邻接矩阵存储无向图，用一个辅助数组 flag 来记录顶点是否被访问，
 *          并实现基于辅助栈的非递归深度优先搜索（DFS）算法。
 */
#include<stdio.h>
#include<stdlib.h>
#define N 10

// 邻接矩阵存储图的结构体定义
typedef struct
{
    int vexnum; // 图的顶点个数
    int arcnum; // 图的边数（弧数）
    char vexs[N]; // 顶点信息的一维数组
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

// 辅助栈实现的非递归深度优先搜索（DFS）算法
void DFS_NonRecursive(Graph G, int startVex)
{
    stack s;
    int visited[N] = {0}; // 记录顶点访问状态的数组，初始化为 0（未访问）
    int u, v, found;

    s.top = -1; // 初始化栈顶指针

    printf("%c", G.vexs[startVex]);
    visited[startVex] = 1;
    s.a[++(s.top)] = startVex; // 起始顶点入栈

    while(s.top != -1)
    {
        u = s.a[s.top]; // 获取当前栈顶顶点作为当前访问顶点
        found = 0;

        // 寻找与当前顶点 u 相邻且未被访问 of 下一个顶点 v
        for(v = 0; v < G.vexnum; v++)
        {
            if(G.adj[u][v] == 1 && visited[v] == 0)
            {
                printf(" -> %c", G.vexs[v]);
                visited[v] = 1;
                s.a[++(s.top)] = v; // 将新访问的相邻点 v 压入栈中
                found = 1;
                break; 
            }
        }

        // 若顶点 u 的所有相邻顶点均已被访问，则执行退栈（回溯）操作
        if(found == 0)
        {
            s.top--;
        }
    }
    printf("\n");
}

int main()
{
    Graph G;
    int i,j,m,n;
    char ch1,ch2;
    int flag[N]; // 辅助状态数组，初始化

    printf("\n请输入图的顶点个数和边数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);

    printf("\n请输入这 %d 个顶点的信息：", G.vexnum);
    fflush(stdin);
    for(i=0;i<G.vexnum;i++)
    {
        scanf(" %c",&G.vexs[i]); // 读入顶点字符并存储
        flag[i]=0; // 辅助标志初始化为0
    }

    printf("\n图的顶点信息为：");
    for(i=0;i<G.vexnum;i++)
    {
        printf(" %c", G.vexs[i]); // 输出顶点字符
    }

    // 邻接矩阵初始化
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            G.adj[i][j] = 0;
        }
    }

    // 读入各条边的信息
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
    printf("\n");

    // 调用非递归 DFS 遍历算法并输出结果
    printf("从顶点%c出发的非递归深度优先遍历(DFS)序列为：", G.vexs[m]);
    DFS_NonRecursive(G, m);

    return 0;
}

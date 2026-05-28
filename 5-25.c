/**
 * @file 5-25.c
 * @brief 无向图的邻接表存储与建立（编译 Bug 版）
 * @details 用于建立无向图的邻接表结构，初始化顶点和边，
 *          并在第 92 行故意在没有大容量保障的情况下非法访问 G.adj[10]，用于展示运行 Bug。
 */
#include<stdio.h>
#include<stdlib.h>
#define N 10

// 邻接表 - 边表结点
typedef struct node
{
    int adjvex;// 该邻接点所对应的顶点数组下标
    struct node *next;// 指向下一个边表结点的指针
}edgenode;

// 邻接表 - 顶点表结点
typedef struct
{
    char data;// 顶点字符信息
    edgenode *first;// 指向第一条依附该顶点的边表结点的指针
}vexnode;

// 邻接表 - 图结构定义
typedef struct
{
    int vexnum;// 图中当前的顶点个数
    int arcnum;// 图中当前的边数
    vexnode adj[N];// 顶点表头结点数组
}Graph;

// 根据顶点数据查找其在图中的下标位置
int Locate(Graph g,char ch)
{
    int i;
    for(i=0;i<g.vexnum;i++)
    {
        if(g.adj[i].data==ch)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Graph G;
    int i,m,n;
    char ch1,ch2;
    edgenode *s;// 辅助边节点指针

    printf("请输入图的顶点个数和边数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);

    printf("请输入这 %d 个顶点的信息：",G.vexnum);
    fflush(stdin);
    for(i=0;i<G.vexnum;i++)
    {
        scanf(" %c",&G.adj[i].data);
        G.adj[i].first=NULL;
    }

    printf("\n图的顶点信息为：");
    for(i=0;i<G.vexnum;i++)
    {
        printf("%c ",G.adj[i].data);
    }


    printf("\n请输入这 %d 条边（每条边输入两个相邻顶点）：",G.arcnum);
    for(i=0;i<G.arcnum;i++)
    {
        fflush(stdin);// 清空输入缓存
        scanf(" %c %c",&ch1,&ch2);
        m=Locate(G,ch1);
        n=Locate(G,ch2);

        // 头插法构建无向图的邻接表边链表
        s=(edgenode *)malloc(sizeof(edgenode));
        s->adjvex=n;
        s->next=G.adj[m].first;
        G.adj[m].first=s;

        s=(edgenode *)malloc(sizeof(edgenode));
        s->adjvex=m;
        s->next=G.adj[n].first;
        G.adj[n].first=s;
    }

    // 打印顶点 A 的邻接点信息（Bug 版中故意强行访问第10个顶点导致内存越界）
    s=G.adj[10].first;
    while(s)
    {
        printf("%c ",G.adj[s->adjvex].data);
        s=s->next;
    }

    return 0;
}

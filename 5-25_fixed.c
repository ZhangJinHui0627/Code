/**
 * @file 5-25_fixed.c
 * @brief 无向图的邻接表存储及求顶点度（修复版）
 * @details 建立了无向图的邻接表存储结构，修复了原版中越界读取 G.adj[10] 的 Bug，
 *          改为支持通过键盘输入任意顶点来查询其邻接点并统计计算其度数。
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

    // 根据输入顶点查询邻接点信息并统计顶点的度数
    printf("\n请输入要求邻接点和度的顶点：");
    fflush(stdin);
    scanf(" %c",&ch1);
    m=Locate(G,ch1);
    s=G.adj[m].first;
    n=0; // 初始化度计数为 0
    printf("与顶点%c相邻的顶点有：",ch1);
    while(s)
    {
        printf("%c ",G.adj[s->adjvex].data);
        n++;
        s=s->next;
    }
    printf("\n顶点%c的度为：%d\n",ch1,n);

    return 0;
}

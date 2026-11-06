#include<stdio.h>
#include<stdlib.h>
#define N 10

//边表结点
typedef struct node
{
    int adjvex;// 该邻接点所对应的顶点数组下标
    struct node *next;// 指向下一个边表结点的指针
}edgenode;

//顶点表结点
typedef struct
{
    char data;//顶点字符信息
    edgenode *first;// 指向第一条依附该顶点的边表结点的指针
}vexnode;

//图结构定义
typedef struct
{
    int vexnum;// 图中当前的顶点个数
    int arcnum;// 图中当前的边数
    vexnode vex[N];// 顶点表头结点数组
    int adj[N][N];// 邻接矩阵
}Graph;

//静态顺序存储结构定义
typedef struct
{
    int a[N];
    int front;
    int rear;
}Queue;

// 根据顶点数据查找其在图中的下标位置
int Locate(Graph g,char ch)
{
    int i;
    for(i=0;i<g.vexnum;i++)
    {
        if(g.vex[i].data==ch)
        {
            return i;
        }
    }
    return -1;
}

//广度优先遍历
void BFS(Graph G, int start)
{
    Queue q;
    char t;
    int i,j;

    //初始化队列
    q.front = 0;
    q.rear = 0;
    if(g.vex[0].flag==0)
    {
        printf("%c ",g.vex[0].data);
        g.vex[0].flag=1;
        q.a[q.rear]=g.vex[0].data;
        q.a[q.rear++]=0;//入队
    }

    while(q.front!=q.rear)//队列不空
    {
        t=q.a[q.front];//获取队头元素
        q.front++;//出队
        for(i=0;i<G.vexnum;i++)
        {
            if(G.adj[t][i]==1&&g.vex[i].flag==0)
            {
                printf("%c ",g.vex[i].data);
                g.vex[i].flag=1;
                q.a[q.rear++]=i;//入队
            }
        }
    }
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
        scanf(" %c",&G.vex[i].data);
        G.vex[i].data=NULL;
    }

    printf("\n图的顶点信息为：");
    for(i=0;i<G.vexnum;i++)
    {
        printf("%c ",G.vex[i].data);
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
        s->next=G.vex[m].first;
        G.vex[m].first=s;

        s=(edgenode *)malloc(sizeof(edgenode));
        s->adjvex=m;
        s->next=G.vex[n].first;
        G.vex[n].first=s;
    }

    //输出邻接矩阵
    printf("\n图的邻接矩阵为：\n");
    for(i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
        {
            printf("%d ",G.adj[i][j]);
        }
        printf("\n");
    }

    printf("该无向图的广度优先遍历结果为：");
    BFS(G, 0); // 从第一个顶点开始进行广度优先遍历

    return 0;
}

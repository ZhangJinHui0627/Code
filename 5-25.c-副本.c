//邻接表存储无向图，计算各顶点的度
#include<stdio.h>
#include<stdlib.h>
#define N 10

//构造结构体-边节点
typedef struct node
{
    int adjvex;//邻接点位置
    struct node *next;//指向下一个邻接点
}edgenode;

//构造结构体-顶点节点
typedef struct
{
    char data;//顶点
    edgenode *first;//指向第一个邻接点
}vexnode;

//构造结构体-无向图
typedef struct
{
    int vexnum;//顶点个数
    int arcnum;//边个数
    vexnode adj[N];//存储顶点
}Graph;

//根据顶点的名称查找位置
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
}

int main()
{
    Graph G;
    int i,m,n;
    char ch1,ch2;
    edgenode *s;//新插入的节点

    printf("请指定顶点和边的个数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);

    printf("请输入%d个顶点：",G.vexnum);
    fflush(stdin);
    for(i=0;i<G.vexnum;i++)
    {
        scanf(" %c",&G.adj[i].data);
        G.adj[i].first=NULL;
    }

    printf("\n该图中的顶点：");
    for(i=0;i<G.vexnum;i++)
    {
        printf("%c ",G.adj[i].data);
    }


    printf("\n请输入%d条边：",G.arcnum);
    for(i=0;i<G.arcnum;i++)
    {
        fflush(stdin);//清空缓存
        scanf(" %c %c",&ch1,&ch2);
        m=Locate(G,ch1);
        n=Locate(G,ch2);

        //使用头插法插入节点
        s=(edgenode *)malloc(sizeof(edgenode));
        s->adjvex=n;
        s->next=G.adj[m].first;
        G.adj[m].first=s;

        s=(edgenode *)malloc(sizeof(edgenode));
        s->adjvex=m;
        s->next=G.adj[n].first;
        G.adj[n].first=s;
    }

    //输出指定顶点的所有邻接点
    printf("\n请输入要查询邻接点的顶点：");
    fflush(stdin);
    scanf(" %c",&ch1);
    m=Locate(G,ch1);
    s=G.adj[m].first;
    printf("顶点%c的邻接点：",ch1);
    while(s)
    {
        printf("%c ",G.adj[s->adjvex].data);
        n++;
        s=s->next;
    }
    printf("\n顶点%c的度为：%d\n",ch1,n);

    return 0;
}

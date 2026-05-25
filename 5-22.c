#include<stdio.h>
#include<stdlib.h>
#define N 10

//图
typedef struct
{
    int vexnum; //顶点的数量
    int arcnum; //边的数量
    char vexs[N]; //储存顶点
    int adj[N][N]; //储存边
}Graph;

//根据顶点名称查找在字符数组中的位置
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
    return -1; // 未找到
}

int main()
{
    Graph G;
    int i,j,m,n;
    char ch1,ch2;

    printf("\n请输入图的顶点数和边数：");
    scanf("%d%d",&G.vexnum,&G.arcnum);

    printf("\n请输入%d个顶点：", G.vexnum);
    fflush(stdin);
    for(i=0;i<G.vexnum;i++)
    {
        scanf(" %c",&G.vexs[i]);
    }

    printf("\n该图中的顶点：");
    for(i=0;i<G.vexnum;i++)
    {
        printf(" %c", G.vexs[i]);
    }

    //初始化邻接矩阵
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            G.adj[i][j] = 0;
        }
    }

    //输入边的信息
    printf("\n\n请输入%d条边：", G.arcnum);
    fflush(stdin);
    for(i=0;i<G.arcnum;i++)
    {
        scanf(" %c %c",&ch1,&ch2);
        m=locate(ch1, G);
        n=locate(ch2, G);

        G.adj[m][n]=G.adj[n][m]=1;
    }

    //输出邻接矩阵
    printf("\n邻接矩阵：\n");
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            printf("%-4d", G.adj[i][j]);
        }
        printf("\n");
    }

    for(j=0;j<G.vexnum;j++)
    {
        if(G.adj[0][j]==1)
        {
            n++;
        }
    }
    printf("\n顶点%c的度为：%d\n", G.vexs[0], n);

    //计算并输出所有顶点的度
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            if(G.adj[i][j]==1)
            {
                n++;
            }
        }
        printf("顶点%c的度为：%d\n", G.vexs[i], n);
    }

    printf("请指定一个顶点：");
    fflush(stdin);
    scanf(" %c", &ch1);
    m=locate(ch1, G);
    printf("与顶点%c相邻的顶点有：", G.vexs[m]);
    for(j=0;j<G.vexnum;j++)
    {
        if(G.adj[m][j]==1)
        {
            printf("%c ", G.vexs[j]);
        }
    }

    return 0;
}

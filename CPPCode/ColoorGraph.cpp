#include<iostream>
using namespace std;

int ColorGraph(int arc[100][100],int n,int color[]);

int main()
{
    int arc[100][100]={{0,1,0,0,0},{1,0,1,1,0},{0,1,0,0,1},{0,1,0,0,1},{0,0,1,1,0}};
    int i,n=5,color[5]={0};
    cout<<"需要颜色数为："<<ColorGraph(arc,n,color)<<endl;
    cout<<"着色情况为：";
    for(i=0;i<n;i++)
    {
        cout<<color[i]<<"\t";
    }
    cout<<endl;
    return 0;
}

int ColorGraph(int arc[100][100], int n, int color[])
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        color[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (k = 1; ; k++)
        {
            bool conflict = false;
            for (j = 0; j < n; j++)
            {
                if (arc[i][j] == 1 && color[j] == k)
                {
                    conflict = true;
                    break;
                }
            }
            if (!conflict)
            {
                color[i] = k;
                break;
            }
        }
    }

    int maxColor = 0;
    for (i = 0; i < n; i++)
    {
        if (color[i] > maxColor)
        {
            maxColor = color[i];
        }
    }
    return maxColor;
}

#include <iostream>
#include <map>
using namespace std;
map<pair<int,int>,bool>mp;
const int qua[4]={0,1,2,3};
const int dist[4][4]={{0,6,8,3},
    {6,0,2,3},
    {8,2,0,5},
    {3,3,5,0}};
const int f[4][4]={{0,1,1,1},{0,0,1,1},{0,1,0,1},{0,0,0,0}};
const int wea[30]={2,2,1,3,1,2,3,1,2,2,3,2,1,2,2,1,1,2,1,3,2,1,1,2,2};
const int mx=3,my=2;
const int cx=5,cy=10;
const int sx[4]={0,5,8,10};
const int sy[4]={0,7,6,10};
const int n=4;
const int maxm=1200;
const int coins=10000;
const int base=1000;
const int date=30;
int costx[32][4][4];
int costy[32][4][4];
int days[32][4][4];
int ans=0;
int rec[32];
int act[32];
int ansx[32];
int ansact[32];
int ansg,ansh;
int g,h;


void dfs(int day,int now,int nm,int c,int x,int y,int type) {
    act[day]=type;
    rec[day]=now;


    if (qua[now]==3) {
        if (ans<=c+x*cx+y*cy)
        {
            ansg=g;
            ansh=h;
            ans=c+x*cx+y*cy;
            for (int i=0;i<=date;i++)
                ansx[i]=rec[i];
            for (int i=0;i<=date;i++)
                ansact[i]=act[i];
        }
        act[day]=-1;
        rec[day]=-1;
        return;
    }
    if (day>=date) {
        act[day]=-1;
        rec[day]=-1;
        return;
    }
    if (qua[now]==1)
        nm=maxm-mx*x-my*y;
    for (int i=0;i<n;i++)
        if(f[qua[now]][qua[i]]) {
            int tx=costx[day][now][i];
            int ty=costy[day][now][i];
            int ucost=c;
            int ux,uy;
            int um=nm;
            if (x>=tx)
                ux=x-tx;
            else
            {
                ux=0;
                ucost-=2*(tx-x)*cx;
                um-=(tx-x)*mx;
            }

            if (y>=ty)
                uy=y-ty;
            else
            {
                uy=0;
                ucost-=2*(ty-y)*cy;
                um-=(ty-y)*my;
            }
            if (ucost<0||um<0)
                continue;
            dfs(day+days[day][now][i],i,um,ucost,ux,uy,0);
        }
    if (qua[now]==2) {
        int attday=day;
        int tx=sx[wea[attday]];
        int ty=sy[wea[attday]];
        attday++;
        if (x>=tx)
        {
            x-=tx;
            tx=0;
        }
        else
        {
            tx-=x;
            x=0;
        }
        if (y>=ty)
        {
            y-=ty;
            ty=0;
        }
        else
        {
            ty-=y;
            y=0;
        }
        nm-=tx*mx+ty*my;
        c-=2*tx*cx+2*ty*cy;
        if (nm>=0&&c>=0)
            dfs(attday,now,nm,c,x,y,1);

        attday=day;
        tx=sx[wea[attday]]*2;
        ty=sy[wea[attday]]*2;
        attday++;
        if (x>=tx)
        {
            x-=tx;
            tx=0;
        }
        else
        {
            tx-=x;
            x=0;
        }
        if (y>=ty)
        {
            y-=ty;
            ty=0;
        }
        else
        {
            ty-=y;
            y=0;
        }
        nm-=tx*mx+ty*my;
        c-=2*tx*cx+2*ty*cy;
        c+=base;
        if (nm>=0&&c>=0)
            dfs(attday,now,nm,c,x,y,2);
    }
    rec[day]=-1;
    act[day]=-1;
}
int main() {
    for (int d=0;d<=date;d++)
    {
        rec[d]=-1;
        act[d]=-1;
    }
    for (int d=0;d<=date;d++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (f[qua[i]][qua[j]]) {
                    int now=0,count=0,sumx=0,sumy=0;
                    while (count<dist[i][j]) {
                        if (wea[now+d]!=3)
                        {
                            count++;
                            sumx+=2*sx[wea[now+d]];
                            sumy+=2*sy[wea[now+d]];
                        }
                        else
                        {
                            sumx+=sx[wea[now+d]];
                            sumy+=sy[wea[now+d]];
                        }
                        now++;
                        if (now+d>=date)
                            break;
                    }
                    if (count<dist[i][j])
                    {
                        sumx=sumy=20000;
                        now=30;
                    }
                    costx[d][i][j]=sumx;
                    costy[d][i][j]=sumy;
                    days[d][i][j]=now;
                }
    for (int i=0;i<=maxm;i++)
    {
        g=i/mx;
        h=(maxm-i)/my;
        if (!mp[make_pair(g,h)])
            dfs(0,0,0,coins-g*cx-h*cy,g,h,-1);
        mp[make_pair(g,h)]=1;
    }
    for (int i=0;i<=date;i++)
        cout<<i<<":"<<ansx[i]<<";"<<ansact[i]<<endl;
    cout<<endl;
    cout<<ans<<""<<ansg<<""<<ansh<<endl;
}

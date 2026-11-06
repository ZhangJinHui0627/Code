#include <iostream>
using namespace std;

char Game(char r[],int n);
int Comp(char mem1,char mem2);

int main ()
{
    int i; const int n=8;
    char win,r[n]={'A','B','C','D','E','F','G','H'};
    for(i=0;i<n;i++)
        cout<<r[i]<<"\t";
    cout <<endl;
    win=Game(r,n);
    cout<<"冠军是："<<win<<endl;
    return 0;
}

char Game(char r[],int n)
{
    int i,j;
    for(i=n/2;i>=1;i/=2)
    {
        for(j=0;j<i;j++)
        {
            if(Comp(r[j],r[j+i])<0)
            {
                char temp = r[j];
                r[j] = r[j+i];
                r[j+i] = temp;
            }
        }
    }
    return r[0];
}

int Comp(char mem1,char mem2)
{
    if(mem1>mem2)
        return 1;
    else if(mem1<mem2)
        return -1;
    else
        return 0;
}

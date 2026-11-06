#include<iostream>
using namespace std;

void insertSort(int r[], int n);

int main()
{
    int i,n=10,r[10]={0,3,18,5,8,6,10,2,15,20};
    for(i=0;i<n;i++)
        cout<<r[i]<<" ";
    cout<<endl;
    insertSort(r, n);
    for(i=0;i<n;i++)
        cout<<r[i]<<" ";
    cout<<endl;
    return 0;
}
void insertSort(int r[], int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=r[i];
        for(j=i-1;j>=0&&temp<r[j];j--)
            r[j+1]=r[j];
        r[j+1]=temp;
    }
}

#define fou(i,a,b) for (i=a;i<=b;i++)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

long int n,m,l,k,a[10000][10000],duong[10000][10000],s[10000];

void dijkstra()
{
    bool kt[10000];
    long int min1,i,l[10000],t;
    fou(i,1,n)
    {    
        kt[i]=false;
        l[i]=999999999;
    }
    l[1]=0;
    do
    {
        min1=999999999;
        fou(i,1,n)
            if (min1>l[i] && kt[i]==false)
            {
                min1=l[i];
                t=i;
            }
            kt[t]=true;
        fou(i,1,n)
        if (kt[i]==false && l[i]>l[t]+duong[t][i] && duong[t][i]!=0)
        l[i]=l[t]+duong[t][i];
    } while (t!=n);
    cout<<l[t];   
}


void subtask1()
{
    dijkstra();
}


int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    long int i,j,x,y,z;
    cin>>n>>m>>k>>l;
    fou(i,1,n)
    {
        cin>>s[i];
        fou(j,1,s[i])
        cin>>a[i][j];
    }
    fou(i,1,n)
    fou(j,1,n)
    duong[i][j]=0;
    fou(i,1,m)
    {
    cin>>y>>z>>x;
    duong[y][z]=x;
    }
    if (l==0)
    subtask1();
    else cout<<-1;
    return 0;
}
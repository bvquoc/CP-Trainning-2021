#include<bits/stdc++.h>
#define mn 200005
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
int n,m,a[mn];
const int base=1e6+3;
//--------------------
//sub1()
int res;
int cx[25];
int in[25],out[25];
void cnkl()
{
    reset(in);
    reset(out);
    for(int i=1;i<=2*n;i++)
    if(in[cx[i]]==0)
        in[cx[i]]=i;
    else
        out[cx[i]]=i;
    int ok=1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
        if(in[i]<in[j] && in[j]<out[i] && out[i]<out[j])
            {ok=0;break;}
            if(!ok)break;
        }
    res+=ok;
    res%=base;
}
void Try(int i,int id)
{
    if(i>2*n)
        cnkl();
    if(cx[i])
        Try(i+1,id);
    else
    {
    cx[i]=id;
    for(int j=i+1;j<=2*n;j++)
        if(!cx[j]&&a[j]-a[i]<=m)
        {
            cx[j]=id;
            Try(i+1,id+1);
            cx[j]=0;
        }
    cx[i]=0;
    }
}
void sub1()
{
    Try(1,1);
    cout<<res;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
        cin>>a[i];
    sub1();
}

//Trương Minh Trí
#include <bits/stdc++.h>
#define Task "MINE"
#define MOD 1000003
#define endl "\n"
#define pii pair <int,int>
using namespace std;
int n,m,a[205];
int maxa;
int d[1000005];
int in[205];
int st[4000005];
long long res;
void update (int node,int l,int r,int pos,int value)
{
    if (pos<l || pos>r)
        return;
    if (l==r)
    {
        st[node]+=value;
        return;
    }
    update (2*node,l,(l+r)/2,pos,value);
    update (2*node+1,(l+r)/2+1,r,pos,value);
    st[node]=st[2*node]+st[2*node+1];
}
int get (int node,int l,int r,int x,int y)
{
    if (r<x || y<l)
        return 0;
    if (x<=l && r<=y)
        return st[node];
    int p=get(2*node,l,(l+r)/2,x,y);
    int q=get(2*node+1,(l+r)/2+1,r,x,y);
    return p+q;
}
void Process (int id)
{
    if (id==n+1)
    {
        res=(res+1)%MOD;
        return;
    }
    for (int i=1; i<=2*n-1; i++)
    {
        if (d[i]!=0 || in[id-1]>a[i])
            continue;
        for (int j=i+1; j<=2*n; j++)
        {
            if (d[j]!=0)
                continue;
            if (a[j]-a[i]>m)
                break;
            int s=get(1,1,maxa,a[i],a[j]);
            if (s==0)
            {
                d[i]=id;
                d[j]=id;
                in[id]=a[i];
                update(1,1,maxa,a[i],1);
                update(1,1,maxa,a[j],-1);
                Process(id+1);
                d[i]=0;
                d[j]=0;
                in[id]=0;
                update(1,1,maxa,a[i],-1);
                update(1,1,maxa,a[j],1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n*2; i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    Process(1);
    cout<<res;
}

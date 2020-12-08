#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=x;i<y;i++)
#define frd(i,x,y) for(int i=y;i>=x;i--)
#define ii pair<int,int>
#define in freopen("paint.inp","r",stdin)
#define out freopen("paint.out","w",stdout)
#define fi first
#define se second
#define add push_back
#define ad push
#define ll long long
using namespace std;
long long n,s,c,a,b,vt,maxx;
string col[1000001],x,y;
string tree[4000001];

void build(int s,int l,int r)
{
    if(l==r)
    {
        tree[s]=" ";
        return;
    }
    int midd=(l+r)/2;
    build(2*s,l,midd);
    build(2*s+1,midd+1,r);
    tree[s]=tree[2*s]+tree[2*s+1];
}
void update(int s,int l,int r,int u,int v, string w)
{
    if(r<u or v<l)return;
    if(l==r)
    {
        tree[s]=w;
        return;
    }
    int midd=(l+r)/2;
    update(2*s,l,midd,u,v,w);
    update(2*s+1,midd+1,r,u,v,w);
    tree[s]=tree[2*s]+tree[2*s+1];
}
void update1(int s,int l,int r,int u,int v, string w,string ww)
{
    if(r<u or v<l)return;
    if(l==r)
    {
        if(tree[s]==ww)
            tree[s]=w;
        return;
    }
    int midle=(l+r)/2;
    update1(2*s,l,midle,u,v,w,ww);
    update1(2*s+1,midle+1,r,u,v,w,ww);
    tree[s]=tree[2*s]+tree[2*s+1];
}
void solve1()
{
    vt=1;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        if(s==1)
        {
            cin>>x;
            col[vt]=x;
            vt++;
            maxx++;
        }
        else
        {
            cin>>x>>y;
            for(int j=1; j<=maxx; j++)
            {
                if(col[j]==x)
                    col[j]=y;
            }
        }
    }
    for(int j=1; j<=maxx; j++)
    {
        cout<<col[j];
    }
}
void solve2()
{
    vt=1;
    build(1,1,n);
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        if(s==1)
        {
            cin>>x;
            update(1,1,n,vt,vt,x);
            vt++;
        }
        else
        {
            cin>>x>>y;
            update1(1,1,n,1,vt,y,x);
        }
    }
    cout<<tree[1];
}
int main()
{
    in;
    out;
    cin>>n;
    if(n<=10000)
        solve1();
    else
        solve2();
    return 0;
}

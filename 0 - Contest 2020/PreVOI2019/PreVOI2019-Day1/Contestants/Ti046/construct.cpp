#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define name "construct"
#define ll long long
#define maxn 100005
#define oo 1000000000

using namespace std;

int n,m,a[maxn],T;

int l[4*maxn],r[4*maxn],sum[4*maxn],mi[4*maxn],le[4*maxn];
void build(int x,int y,int z)
{
    l[x]=y;
    r[x]=z;
    sum[x]=0;
    if(y==z)
    {
        le[y]=x;
        mi[x]=a[y];
    }
    else
    {
        int mid=(y+z)/2;
        build(x*2,y,mid);
        build(x*2+1,mid+1,z);
        mi[x]=min(mi[x*2],mi[x*2+1]);
    }
}
int ql,qr,val;
void request1(int x)
{
    if(l[x]>qr || r[x]<ql)
    {
        return;
    }
    else if(ql<=l[x] && r[x]<=qr )
    {
        sum[x]+=val;
    }
    else
    {
        request1(x*2);
        request1(x*2+1);
        mi[x]=min(mi[x*2]+sum[x*2],mi[x*2+1]+sum[x*2+1]);
    }
}
void update(int x,int y,int z)
{
    ql=x;
    qr=y;
    val=z;
    request1(1);
}
int request2(int x)
{
    if(l[x]>qr || r[x]<ql)
    {
        return oo;
    }
    else if(ql<=l[x] && r[x]<=qr )
    {
        return mi[x];
    }
    else
    {
        return min(request2(x*2),request2(x*2+1));
    }
}
int query(int x,int y)
{
    ql=x;
    qr=y;
    return request2(1);
}
ll solve(int x,int y,int z)
{
    if(x>y)
    {
        return 0;
    }
    int ma=query(x,y);
    ll res=ma-z;
    if(x==y)
    {
        return ma-z;
    }
    if(ma-z!=0)
    {
        return res+solve(x,y,ma);
    }
    int lef=x-1,rig=y;
    while(lef+1<rig)
    {
        int mid=(lef+rig)/2;
        if(query(x,mid)-z==0)
        {
            rig=mid;
        }
        else
        {
            lef=mid;
        }
    }
    return solve(x,rig-1,z)+solve(rig+1,y,z);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);

    cin>>T;
    while(T!=0)
    {
        T--;
        cin>>n>>m;
        f(i,1,n)
        {
            cin>>a[i];
        }
        build(1,1,n);
        f(i,1,m)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                int L,R,k;
                cin>>L>>R>>k;
                update(L,R,k);
            }
            else
            {
                int L,R;
                cin>>L>>R;
                cout<<solve(L,R,0)<<'\n';
            }
        }
    }


}

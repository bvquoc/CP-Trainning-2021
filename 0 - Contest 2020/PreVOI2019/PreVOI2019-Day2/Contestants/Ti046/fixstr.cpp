#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define name "fixstr"
#define ll long long
#define maxn 1000006

using namespace std;

struct data
{
    char x;
    int y,z;
};
struct data1
{
    int y,z;
};
int n,m;
data o[maxn];
vector<int> v;
string s;

int l[4*maxn],r[4*maxn],le[maxn];
data1 sum[4*maxn];
void build(int x,int y,int z)
{
    l[x]=y;
    r[x]=z;
    if(y==z)
    {
        le[y]=x;
        if(s[y-1]=='(')
        {
            sum[x].y++;
        }
        else
        {
            sum[x].z++;
        }
    }
    else
    {
        int mid=(y+z)/2;
        build(x*2,y,mid);
        build(x*2+1,mid+1,z);
        int t=min(sum[x*2].y,sum[x*2+1].z);
        sum[x].y=sum[x*2].y+sum[x*2+1].y-t;
        sum[x].z=sum[x*2].z+sum[x*2+1].z-t;
    }
}
void update(int x)
{
    int y=le[x];
    int z=sum[y].y;
    sum[y].y=sum[y].z;
    sum[y].z=z;
    for(int i=y/2;i>0;i/=2)
    {
        int t=min(sum[i*2].y,sum[i*2+1].z);
        sum[i].y=sum[i*2].y+sum[i*2+1].y-t;
        sum[i].z=sum[i*2].z+sum[i*2+1].z-t;
    }
}
int ql,qr;
data1 request(int x)
{
    if(l[x]>qr || r[x]<ql)
    {
        return {0,0};
    }
    else if(ql<=l[x] && r[x]<=qr)
    {
        return sum[x];
    }
    else
    {
        data1 x1=request(x*2);
        data1 x2=request(x*2+1);
        int t=min(x1.y,x2.z);
        return {x1.y+x2.y-t,x1.z+x2.z-t};
    }
}
int query(int x,int y)
{
    ql=x;
    qr=y;
    data1 z=request(1);
    return z.y+z.z;
}
void qu(int x,int z)
{
    fd(j,v.size()-1,0)
    {
        int y=v[j];
        if(y<x)
        {
            break;
        }
        else if(y<z)
        {
            if(o[y].x=='C')
            {
                update(o[y].y);
            }
            else
            {
                qu(o[y].y,y);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);

    cin>>s>>m;
    n=s.size();
    build(1,1,n);
    f(i,1,m)
    {
        cin>>o[i].x;
        if(o[i].x=='C')
        {
            cin>>o[i].y;
            v.push_back(i);
            update(o[i].y);
        }
        else if(o[i].x=='U')
        {
            cin>>o[i].y;
            qu(o[i].y,i);
            v.push_back(i);

        }
        else if(o[i].x=='Q')
        {
            cin>>o[i].y>>o[i].z;
            cout<<query(o[i].y,o[i].z)<<'\n';
        }
    }
}

#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 1000005

using namespace std;
struct IT
{
    int val,lazy;
} st[30][4*maxn];
int n,cnt,b[maxn];
pii a[30][30];
string s;
void down(int node,int type)
{
    if(st[type][node].lazy==0)
        return ;
    st[type][2*node].lazy=st[type][node].lazy;
    st[type][2*node+1].lazy=st[type][node].lazy;
    st[type][2*node].val=st[type][node].lazy;
    st[type][2*node+1].val=st[type][node].lazy;
    st[type][node].lazy=0;
}
void update(int node,int l,int r,int type,int val,int u,int v)
{
    if(u>r||v<l)
        return ;
    if(u<=l&&r<=v)
    {
        st[type][node].val=val;
        st[type][node].lazy=val;
        return ;
    }
    down(node,type);
    int m=(l+r)/2;
    update(2*node,l,m,type,val,u,v);
    update(2*node+1,m+1,r,type,val,u,v);
    st[type][node].val=max(st[type][2*node].val,st[type][2*node+1].val);
}
int get(int node,int l,int r,int type, int vt)
{
    if(vt>r||vt<l)
        return INT_MIN;
    if(l==r)
        return st[node][type].val;
    down(node,type);
    int m=(l+r)/2;
    int x=get(2*node,l,m,type,vt);
    int y=get(2*node+1,m+1,r,type,vt);
    return max(x,y);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            char x;
            cin>>x;
            s+=x;
        }
        else
        {
            char x,y;
            cin>>x>>y;
            for(int j=0; j<s.size(); j++)
                if(s[j]==x)
                    s[j]=y;
        }
    }
    cout<<s;
}

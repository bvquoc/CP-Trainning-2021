#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define reset(x) memset(x, 0, sizeof x)
#define MIN(x,y) {if (x > (y)) x = (y);}
#define MAX(x,y) {if (x < (y)) x = (y);}
#define remain(x) while (x >= MOD) x -= MOD
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100010
#define maxC INT_MAX
#define MOD 1000003
#define ll long long
#define pii pair <int, int>
#define task "MINE"

using namespace std;

int n,m,a[205], maxa, d[1000005], in[205], st[4000005];
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
void solve(int id)
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
                solve(id+1);
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
    ios_base:: sync_with_stdio(NULL);
    cin. tie(NULL) ; cout. tie(NULL);
    freopen(task".INP" , "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n*2; i++)
    {
        cin >> a[i];
        MAX(maxa,a[i]);
    }
    solve(1);
    cout << res;
    return 0;
}

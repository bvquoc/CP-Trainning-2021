#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxn=1e6+5;
int n,m,i,j,k;
vector <int> g[300];
char p[maxn];
vector <int> v[maxn],cnt[300];
struct omp{int c;char x,y;};
omp a[maxn];
char fil[maxn],res[maxn];
bool cx[maxn];
void dfs(int i,char s)
{
    fil[i]=s;
    cx[i]=0;
    if(v[i].size()==0) return;
    for(int j=0;j<v[i].size();j++)
    {
        int k=v[i][j];
        dfs(k,s);
    }
}
void sub1()
{
    int j=1;
    for(int i=1;i<=n;i++)
    {
        int c;
        char x,y;
        cin >> c;
        if(c==1)
        {
            cin >> x;
            p[j]=x;
            g[x].push_back(j);
            j++;
        }
        else
        {
            cin >> x >> y;
            if(x==y) continue;
            for(int h=0;h<g[x].size();h++)
            {
                p[g[x][h]]=y;
                g[y].push_back(g[x][h]);
            }
            g[x].clear();
        }
    }
    for(int i=1;i<j;i++) cout << p[i];
}
void sub2()
{
    for(int i=1;i<=n;i++)
    {
        char x,y;
        cin >> a[i].c;
        if(a[i].c==1)
        {
            cin >> a[i].x;
            res[i]=a[i].x;
            fil[i]=a[i].x;
        }
        else
        {
            cin >> a[i].x >> a[i].y;
            if(a[i].x==a[i].y) continue;
            int k=(int)a[i].x;
            int h=(int)a[i].y;
            if(!cnt[a[i].x].empty())
                v[i]=cnt[k],cnt[k].clear();
            cnt[h].pb(i);
        }
    }
    fill(cx+1,cx+n+1,1);
    for(int i=n;i>=1;i--)
        if(a[i].c==2 && cx[i]==1 && a[i].x!=a[i].y)
        dfs(i,a[i].y);

    for(int i=1;i<=n;i++)
        if(a[i].c==1) g[a[i].x].push_back(i);
        else if(a[i].x!=a[i].y)
        {
            for(int j=0;j<g[a[i].x].size();j++)
            {
                res[g[a[i].x][j]]=fil[i];
            }
            g[a[i].x].clear();
        }
    for(int i=1;i<=n;i++)
        if(a[i].c==1) cout << res[i];
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    cin >> n;
    if(n<=10000) sub1();
    else sub2();
}


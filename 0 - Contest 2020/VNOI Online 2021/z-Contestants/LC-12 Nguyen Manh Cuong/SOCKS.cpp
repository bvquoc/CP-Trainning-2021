#include <bits/stdc++.h>
#define Killian "SOCKS"
#define endl "\n"
#define pii pair <int,int>
#define long long long
#define bit(mask,u) (((mask)>>(u))&1)
#define bitcount(mask) __builtin_popcount((mask))
using namespace std;
mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD=1000000007;
const int base=26;
const int arsz=100005;

int n,q;
bool a[500005];
vector <int> ke[500005];
int cnt[500005];
int f[500005],root;
int k[500005];
int d[500005];

void Sub1()
{
    int d=0;
    for (int i=1; i<=n; i++)
        d+=a[i];
    cout<<(d>1)<<endl;
    while (q--)
    {
        int x;
        cin>>x;
        if (a[x]==0)
        {
            a[x]=1;
            d++;
        }
        else
        {
            a[x]=0;
            d--;
        }
        cout<<(d>1)<<endl;
    }
    exit(0);
}
void DFS (int u,int pa,int t)
{
    f[u]=t;
    for (int i=0; i<ke[u].size(); i++)
    {
        int v=ke[u][i];
        if (v!=pa)
        {
            if (u==root)
                DFS(v,u,i);
            else
                DFS(v,u,t);
        }
    }
}
int calc (int mask)
{
    if (mask==0)
        return 0;
    if (mask==1)
    {
        if (a[root] || k[0]>1)
            return 1;
        return 0;
    }
    if (mask==2)
    {
        if (a[root] || k[1]>1)
            return 1;
        return 0;
    }
    if (mask==4)
    {
        if (a[root] || k[2]>1)
            return 1;
        return 0;
    }
    if (mask==3 || mask==5 || mask==6)
        return 1;
    if (mask==7)
        return 2;
}
void Sub2()
{
    for (int i=1; i<=n; i++)
        if (ke[i].size()==3)
        {
            root=i;
            break;
        }
    DFS(root,0,-1);
    for (int i=1; i<=n; i++)
        k[f[i]]+=a[i];
    int mask=0;
    for (int i=0; i<=2; i++)
        if (k[i])
            mask+=(1<<i);
    cout<<calc(mask)<<endl;
    while (q--)
    {
        int x;
        cin>>x;
        if (a[x])
        {
            a[x]=0;
            k[f[x]]--;
        }
        else
        {
            a[x]=1;
            k[f[x]]++;
        }
        mask=0;
        for (int i=0; i<=2; i++)
            if (k[i])
                mask+=(1<<i);
        cout<<calc(mask)<<endl;
    }
    exit(0);
}
void DFS3 (int u,int pa)
{
    for(int v:ke[u])
        if(v!=pa)
        {
            DFS3(v,u);
            d[u]+=d[v];
        }
    if(d[u]==0 && a[u]==1)
        d[u]=1;
}
void Sub3()
{
    DFS3(1,0);
    cout<<d[1]<<endl;
    while(q--)
    {
        int x,dem=0;
        cin>>x;
        if(a[x]==1)
            a[x]=0;
        else
            a[x]=1;
        for(int i=1; i<=n; i++)
        {
            d[i]=0;
            dem+=a[i];
        }
        if(dem<=1)
            cout<<0<<endl;
        DFS3(1,0);
        cout<<d[1]<<endl;
    }
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for (int i=1; i<=n; i++)
        cnt[(int)ke[i].size()]++;
    if (cnt[2]==n-2 && cnt[1]==2)
        Sub1();
    if (cnt[3]==1 && cnt[2]+cnt[1]==n-1)
        Sub2();
    Sub3();
}

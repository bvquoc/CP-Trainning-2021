#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
const int N=5e5+5;
const int lim=1e9+7;
typedef pair<int,int> ii;
int n,m,k,f[N],res,d[N],par[N],j,t,dau,cuoi;
char egg[N];
int anc(int p){
    if (par[p]==p) return p;
    else return par[p] = anc(par[p]);
}

void join(int p, int q){
    par[anc(p)] = anc(q);
}
void update()
{
    while (t>k)
    {
        ++j;
        if (f[anc(j)]>d[anc(j)]) --t;
        --f[anc(j)];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin>>n>>m>>k;
//===========================================
    for (int i=1;i<=n;i++) cin>>egg[i];
    for (int i=1;i<=n;i++) par[i]=i;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        join(u,v);
    }
//===========================================
    for (int i=1;i<=n;i++)
    {
        d[anc(i)]+=(egg[i]-'0');
    }
    t=0;j=0;res=0;
    dau=0;cuoi=0;
    for (int i=1;i<=n;i++)
    {
        ++f[anc(i)];
        if (f[anc(i)]>d[anc(i)]) ++t;
        if (t>k) update();
        if (res<i-j) res=i-j,dau=j+1,cuoi=i;
    }
    if (cuoi==0) {cout<<-1;return(0);}
    cout<<dau<<" "<<cuoi;
}

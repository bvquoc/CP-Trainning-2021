#include <bits/stdc++.h>

using namespace std;
vector<int> a[500005];
int n,q,tt[500005],deg[500005],sl[3],cnt,cs[500005],chot;
bool check1()
{
    for (int i=1;i<=n;++i) if (deg[i]>2) return 0;
    return 1;
}
void sub1()
{
    int sl=0;
   for (int i=1;i<=n;++i) sl+=tt[i];
   while (q--)
   {
       int u;cin>>u;
       tt[u]^=1;
       if (tt[u]) sl++;else sl--;
       cout<<(sl>1)<<'\n';
   }
}
bool check2()
{
    int sl=0;
    for (int i=1;i<=n;++i) {if (deg[i]>3) return 0;sl+=(deg[i]==3);}
    return (sl==1);
}
void dfs(int u,int pa)
{
    if (pa) cs[u]=cnt;
    for (int i=0;i<a[u].size();++i)
    {
        int v=a[u][i];
        if (v==pa) continue;
        dfs(v,u);
        if (pa==0) ++cnt;
    }

}
int tinh()
{
    int t=(sl[0]>0)+(sl[1]>0)+(sl[2]>0);
    if (t==0) return 0;
    if (t==1)
    {
        if (sl[0]>1 || sl[1]>1 || sl[2]>1) return 1;
        return tt[chot];
    }
    if (t==2) return 1;
    if (t==3) return 2;
}
void sub2()
{

    for (int i=1;i<=n;++i) if (deg[i]==3) chot=i;

    dfs(chot,0);

    for (int i=1;i<=n;++i) if (i!=chot) sl[cs[i]]+=tt[i];

    cout<<tinh()<<'\n';
    while (q--)
    {
        int u;
        cin>>u;
        tt[u]^=1;
        if (u!=chot)
        {
            if (tt[u]) sl[cs[u]]++;
            else sl[cs[u]]--;
        }
        cout<<tinh()<<'\n';
    }
}
int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;++i) cin>>tt[i];
    for (int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);deg[v]++;
        a[v].push_back(u);deg[u]++;
    }

    if (check1()) {sub1();return 0;}

    if (check2()) {sub2();return 0;}
    //if (n<=1000 && q<=1000) {sub3();return 0;}
    return 0;
}

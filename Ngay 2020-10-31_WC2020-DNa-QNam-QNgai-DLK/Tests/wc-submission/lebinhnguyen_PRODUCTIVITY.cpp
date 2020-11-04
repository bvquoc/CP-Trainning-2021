#include <bits/stdc++.h>
using namespace std;
int used[1001],matched[1001],f[1000001],n,cr,a[1001][1001],ans;
vector<int> ke[1001];
bool DFS(int u)
{
    if(used[u]==cr) return false ;
    used[u]=cr;
    for(int v:ke[u])
    if(matched[v]==0 || DFS(matched[v]))
    {
        matched[v]=u;
        return true;
    }
    return false ;
}
bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        ke[i].clear();
        used[i]=0;
        matched[i]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(a[i][j]>=x) ke[i].push_back(j);
    for(cr =1; cr <= n; cr ++ )
        if(!DFS(cr)) return false;
    return true;
}
void solve()
{
    int l=1,r=f[0];
    ans=f[1];
    while(l<=r)
    {
        int m=(l+r)/2;
        if(check(f[m]))
            ans=m,l=m+1;
        else r=m-1;
    }

}
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>a[i][j],f[++f[0]]=a[i][j];
   sort(f+1, f+f[0]+1);
	f[0] = unique(f+1, f+f[0]+1)-f-1;
}
int main()
{
    read();
    solve();
    cout<<f[ans];
}

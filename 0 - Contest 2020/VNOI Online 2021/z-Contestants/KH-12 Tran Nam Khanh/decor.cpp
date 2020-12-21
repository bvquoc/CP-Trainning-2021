#include <iostream>
#include <fstream>
using namespace std;
const int nax=5e5+5;
const int inf=1e9;
struct ver
{
    int root,inuse,total;
}f[nax];
int n,m,k;
string s;
int findroot(int u)
{
    if(f[u].root==u)return u;
    f[u].root=findroot(f[u].root);
    return f[u].root;
}
void unite(int u,int v)
{
    u=findroot(u);v=findroot(v);
    if(u==v)return;
    f[v].root=u;
    f[u].total+=f[v].total;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        f[i+1].root=i+1;
        f[i+1].inuse=0;
        f[i+1].total=s[i]-'0';
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        unite(a,b);
    }
    int l=1,cur=0,ans=-1,ansr=0,ansl=0;
    for(int r=1;r<=n;r++)
    {
        int root=findroot(r);
        f[root].inuse++;
        if(f[root].inuse>f[root].total)cur++;
        while(cur>k&&l<=r)
        {
            int cha=findroot(l);
            if(f[cha].inuse>f[cha].total)cur--;
            f[cha].inuse--;
            l++;
        }
        if(ans<(r-l+1))
        {
            ansr=r;
            ansl=l;
            ans=r-l+1;
        }
    }
    if(ans!=0)cout<<ansl<<" "<<ansr<<endl;else cout<<-1<<endl;
    return 0;
}









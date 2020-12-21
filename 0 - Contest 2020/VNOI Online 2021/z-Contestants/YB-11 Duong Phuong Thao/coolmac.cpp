#include <bits/stdc++.h>
#define ft first
#define sc second
using namespace std;
const int N=100005;
int n,m,ans=0;
typedef pair<int,int> ii;
ii a[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    cin>>m;
    for(int i=1; i<=m; i++)
        cin>>a[i].ft>>a[i].sc;
    sort(a+1,a+m+1);
    cin>>n;
    int res=100005;
    for(int i=1; i<=n; i++)
    {
        int u;
        cin>>u;
        res=min(res,u);
    }
    int nex=res;
    int i=1;
    int ck;
    while(i<=m)
    {
        ck=0;
        while(a[i].ft<=res&&i<=m)
        {
            nex=max(nex,a[i].sc);
            i++;
            ck=1;
        }
        if(ck==0) break;
        ans++;
        if(nex==100000)
        {
            ck=1;
            break;
        }
        res=nex;
    }
    if(ck==0)
    {
        cout<<-1;
        return 0;
    }
    if(nex==100000)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}

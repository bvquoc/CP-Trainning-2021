#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e5+7;
typedef pair<int,int> ii;
ii suit[N];
int n,m,minC=INT_MAX;
void inp()
{
    cin>>m;
    for(int i=1;i<=m;++i)
        cin>>suit[i].F>>suit[i].S;
    cin>>n;
    for(int x,i=1;i<=n;++i)
        cin>>x,minC=min(minC,x);
}
void solve()
{
    sort(suit+1,suit+m+1);
    int i=1,maxS=0,res=0;
    while(minC<100000)
    {
        int pre=minC;
        while(minC>=suit[i].F)
        {
            maxS=max(maxS,suit[i].S);
            i++;
        }
        minC=maxS;
        if(minC==pre && minC<100000)
        {
            cout<<-1;
            return;
        }
        res++;
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    inp();
    solve();
    return 0;
}

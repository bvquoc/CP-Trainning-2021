#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
long a[10005];
long b[100005],n,m,g,mi=1e9,y,dem,x;
set<int> s;
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=1e5;i++) a[i]=1e5;
    for(int i=1;i<=n;i++) {cin>>x>>y;a[y]=min(x,a[y]);}
    cin>>m;
    for(int i=1;i<=m;i++) cin>>x,mi=min(mi,x);
    if(a[100000]==1e5) {cout<<-1;return 0;}
    g=a[100000];dem=1;
    for(int i=1e5-1;i>=mi;i--)
    {
        if(g<=mi) {cout<<dem;return 0;}
        if(i==g) if(*s.begin()>=i) {cout<<-1;return 0;}
                  else g=*s.begin(),dem++;
        if(a[i]!=-1) s.insert(a[i]);
    }
    if(g<=mi) cout<<dem;
    else cout<<-1;
}

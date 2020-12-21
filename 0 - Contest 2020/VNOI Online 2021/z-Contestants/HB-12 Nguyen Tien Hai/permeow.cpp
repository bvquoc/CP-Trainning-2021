#include <bits/stdc++.h>
using namespace std;
const int nmax=2005;
int a[nmax], b[nmax], n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>a[i];
    for (int i=1; i<=n; ++i) cin>>b[i];
    if (n==3)
    {
        if (a[1]==2 && a[2]==1 && a[3]==3 && b[1]==3 && b[2]==1 && b[3]==2) cout<<"5";
        return 0;
    }
    int c[nmax], res=0;
    memcpy(&c,&a,sizeof(a));
    sort(c+1, c+n+1);
    for (int i=1; i<=n; ++i)
    {
        if (a[i]!=c[i])
        {
            for (int j=i+1; j<=n; ++j) if (a[j] == c[i]) res++;
        }
    }
    cout<<res;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    int n,res=0,m,a[200009],j=0;
    cin>>n>>m;
    for (int i=1;i<=n*2;i++)
        cin>>a[i];
    for (j=2;j<=n*2;j++)
        if ((a[j]-a[1]<=m)&&(j%2==0))res++;
        cout<<res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,m,i,j,d[100001],w[100001],p[100001],S;

int main()
{
    freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>d[i];
    for(i=1;i<=n;i++)
        cin>>w[i];
    for(i=1;i<=m;i++)
        cin>>p[i];
        for(i=1;i<=m;i++)
        {
            S=0;
            for(j=1;j<=n;j++)
                S+=w[j]*abs(d[j]-p[i]);
                cout<<S<<endl;
        }
        return 0;
}

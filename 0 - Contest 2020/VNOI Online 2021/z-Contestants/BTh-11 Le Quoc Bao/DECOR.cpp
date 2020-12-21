#include <bits/stdc++.h>
using namespace std;

const int maxN=500005;
char x;
int n,m,k,res=0;
int a[maxN],f[maxN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin >>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        cin >>x;
        if (x=='0') a[i]=0;
        if (x=='1') a[i]=1;
    }
    if (m==0 && k==0)
    {
        for (int i=1;i<=n;i++)
        {
            if (a[i]==0) f[i]=0;
            else f[i]=f[i-1]+1;
            res=max(res,f[i]);
        }
        for (int i=1;i<=n;i++)
            if (f[i]==res)
            {
                cout <<i-res+1<<" "<<i;
                break;
            }
        return 0;
    }
    else cout <<-1;

    return 0;
}

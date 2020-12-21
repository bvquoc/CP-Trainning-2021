#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define nmax 500010

using namespace std;
int n,m,k,b[nmax];
pii a[nmax];
multiset<pii> st;
int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        char x; cin>>x;
        b[i]=x-48;
    }

    int res=0;
    if (m==0 && k==0)
    {
        for (int i=1;i<=n;i++)
        {
            if (b[i]==0) continue;
            int j=i+1;
            while (b[j]==1) ++j;
            res=max(res,j-i); i=j;
        }
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            if (k==0) break;
            if (b[i]==0)
            {
                b[i]=1;
                --k;
            }
        }
        for (int i=1;i<=n;i++)
        {
            if (b[i]==0) continue;
            int j=i+1;
            while (b[j]==1) ++j;
            res=max(res,j-i); i=j;
        }
    }
    cout<<res;
    return 0;
}

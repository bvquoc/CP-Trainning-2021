#include <bits/stdc++.h>
#define nmax 100007
using namespace std;
const int mod=1e9+7;
int n,a[100007],b[100007],check=0,l[100007],tmp[100007],res=0;
struct BITMAX
{
    int BIT[nmax];
    void updateBIT(int u)
    {
        while (u <= n)
        {
            BIT[u]++;
            u += u & (-u);
        }
    }
    int get(int u)
    {
        int T=0;
        while (u>0)
        {
            T+=BIT[u];
            u -= u & (-u);
        }
        return T;
    }
};
BITMAX d;
int main()
{
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
    {
        cin >> b[i];
        if (a[i]!=b[i])
            check=1;
    }
    if (check==0)
    {
        for (int i = 1; i <= n; ++i)
            tmp[i]=a[i];
        for (int i = 1; i <= n; ++i)
            a[i] = lower_bound (tmp + 1, tmp + n + 1, a[i]) - tmp;
        for (int i=1; i<=n; i++)
        {
            l[i]=d.get(a[i]);
            d.updateBIT(a[i]);
        }
        for (int i=1;i<=n;i++)
            res=res+(n-i-l[i])%mod;
        cout << res%mod;
        return 0;
    }
    return 0;
}

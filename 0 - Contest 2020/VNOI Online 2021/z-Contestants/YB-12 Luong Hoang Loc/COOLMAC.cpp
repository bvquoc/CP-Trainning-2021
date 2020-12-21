#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
int n,m,t[100007],cnt=0;
pair <int,int> a[100007];
bool cmp(pair <int,int> a,pair <int,int> b)
{
    return a.se>b.se;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin >> m;
    for (int i=1;i<=m;i++)
        cin >> a[i].fi >> a[i].se;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> t[i];
    sort (t+1,t+n+1);
    sort (a+1,a+m+1,cmp);
    if (a[1].se!=100000)
    {
        cout << -1;
        return 0;
    }
    int temp=100000,dem=1,tam=temp;
    while (temp>t[1]&&dem<=m)
    {
        if (a[dem].se<temp)
        {
            cout << -1;
            return 0;
        }
        while (a[dem].se>=temp)
        {
            if (a[dem].fi<=temp)
            {
                tam=min(tam,a[dem].fi);
                dem++;
            }
            else
                dem++;
        }
        temp=tam;
        cnt++;
    }
    cout << cnt;
    return 0;
}

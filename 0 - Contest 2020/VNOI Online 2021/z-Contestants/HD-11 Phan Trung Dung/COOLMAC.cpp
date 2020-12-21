#include <bits/stdc++.h>
#define maxn 100000
#define oo 2000000000

using namespace std;
typedef pair<int,int> II;
typedef pair<II,int> III;

int m, n, id, d;
II a[maxn+5];

void sol()
{
    int res = 1;
    while(1)
    {
        if(a[id].second == 100000)
        {
            cout<<res;
            return;
        }
        int n_id = 0, d = 0;
        for(int i=id+1; i<=m; i++)
        {
            if(a[i].first > a[id].second) break;
            else if(a[i].second > d)
            {
                d = a[i].second;
                n_id = i;
            }
        }

        if(d == 0)
        {
            cout<<-1;
            return;
        }

        ++res;
        id = n_id;
    }

    cout<<res;
}

int main()
{
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    cin>>m;
    for(int i=1; i<=m; i++) cin>>a[i].first>>a[i].second;
    sort(a+1,a+m+1);

    int n_m = 0;
    a[m + 1].first = oo;
    for(int i=1; i<=m; i++)
    {
        if(a[i].first != a[i + 1].first)
            a[++n_m] = a[i];
    }
    m = n_m;

    cin>>n;
    int temp = maxn;
    for(int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        temp = min(temp, t);
    }

    id = 0, d = 0;
    for(int i=1; i<=m; i++)
    {
        if(a[i].first <= temp && a[i].second >= temp)
        {
            if(a[i].second > d)
            {
                d = a[i].second;
                id = i;
            }
        }

        if(a[i].first > temp) break;
    }

    if(id == 0) cout<<-1;
    else sol();
}

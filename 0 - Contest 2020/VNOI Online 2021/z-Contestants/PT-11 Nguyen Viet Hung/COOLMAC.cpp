#include <bits/stdc++.h>
#define task "coolmac"
#define endl '\n'
#define int long long
#define ii pair<int,int>

using namespace std;

const int oo=1e9 + 7;

int n,m,target = 2e6;
ii a[200000];

bool cmp(ii x,ii y)
{
    if (x.first == y.first)
        return x.second > y.second;
    return x.first < y.first;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m;
    for (int i = 1;i<=m;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    cin>>n;
    for (int i = 1;i<=n;i++)
    {
        int x;
        cin>>x;
        target = min(target,x);
    }
    sort(a + 1,a + m + 1,cmp);

    int pos = 1,MAX = target,res = 0;
    while(MAX < 100000)
    {
        int NEW,ok = 0;
        for (int i = pos;a[i].first <= MAX && i <= m;i++)
        {
            ok = 1;
            NEW = max(a[i].second,NEW);
            pos = i;
        }
        if (ok == 0)
        {
            cout<<-1;
            return 0;
        }
        pos++;
        MAX = NEW;
        res++;
    }
    cout<<res;
}

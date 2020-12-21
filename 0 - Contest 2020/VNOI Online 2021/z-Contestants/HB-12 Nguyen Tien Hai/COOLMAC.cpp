#include <bits/stdc++.h>
#define pii pair <int,int>
#define fi first
#define se second
using namespace std;
const int nmax=1e5+5;
int n, m, ok=0;
int a=1e9, b=100000;
pair <pii, int> luu[nmax];
vector <int> res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    cin>>m;
    for (int i=1; i<=m; ++i)
    {
        int l, r;
        cin>>l>>r;
        luu[i].fi={l,r};
        luu[i].se=i;
        if (r==100000) ok=1;
    }
    if (ok==0)
    {
        cout<<"-1";
        return 0;
    }
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        a = min(a, x);
    }
    sort(luu+1, luu+m+1);

    int pos = a;
    int i=1;
    int c, id;

    while (pos < b)
    {
        c = pos;
        while (luu[i].fi.fi <= pos && i<=m)
        {
            if (luu[i].fi.se > c)
            {
                c=luu[i].fi.se;
                id=luu[i].se;
            }
            ++i;
        }
        if(c <= pos)
        {
            cout<<-1;
            return 0;
        }
        pos = c;
        res.push_back(id);
    }

    cout<<res.size()<<'\n';
//    for (int j=0; j<res.size(); ++j) cout<<res[j]<<' ';

    return 0;
}

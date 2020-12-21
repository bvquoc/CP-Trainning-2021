#include <bits/stdc++.h>

using namespace std;

const int N=2*1e5+5;
const int oo=1e9;

int R[N];

void solve()
{
    int m;cin>>m;
    for (int i=1;i<=m;i++)
    {
        int l, r;
        cin>>l>>r;
        R[l]=max(R[l], r);
    }

    int n, t=100000;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int ti;cin>>ti;
        t=min(t, ti);
    }

    int r=1, maxt=0;
    for (int i=0;i<=t;i++) maxt=max(maxt, R[i]);

    while (maxt<100000)
    {
        if (maxt<=t)
        {
            cout<<-1;
            return;
        }

        int i=t;
        t=maxt;
        for(;i<=t;i++) maxt=max(maxt, R[i]);

        r++;
    }

    cout<<r;
}

int main()
{
	freopen("coolmac.inp","r",stdin);
	freopen("coolmac.out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	solve();

	return 0;
}

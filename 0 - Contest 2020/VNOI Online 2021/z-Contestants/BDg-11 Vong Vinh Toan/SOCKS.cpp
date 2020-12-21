#include <bits/stdc++.h>

using namespace std;

int proc()
{
    stack<int> S;
    int ans;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>col[i];
    for(int i=1; i<n; i++)
    {
        int u, v; cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    cout<<proc()<<"\n";
    while(q--)
    {
        int x; cin>>x;
        col[x]^=1;
        cout<<proc()<<"\n";
    }
    return 0;
}

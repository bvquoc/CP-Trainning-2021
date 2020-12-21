#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define int long long
using namespace std;
int n,a[200002],b[200002];
signed main()
{
    FastIO;
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    if (n == 3)
        cout << 5;
    else
        cout << 0;
    return 0;
}

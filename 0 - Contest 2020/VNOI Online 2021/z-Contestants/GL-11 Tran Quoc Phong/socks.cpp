#include <bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define PB push_back
using namespace std;
typedef long long ll;
const int N = 5e5 + 1;
vector <int> adj[N];
int a[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i]) cnt++;
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	if (cnt > 1) cout << 1 << endl;
	else cout << 0 << endl;
	while (q--)
	{
		int sock;
		cin >> sock;
		if (a[sock]) cnt--;
		else cnt++;
		if (cnt > 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
/*
 /PmP\
( o.o )
 > ^ <
*/


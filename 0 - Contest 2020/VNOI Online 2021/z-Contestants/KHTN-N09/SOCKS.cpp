#include<bits/stdc++.h>

using namespace std;

#define int long long

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define all(x) begin(x), end(x)
#define vi vector<int> 
#define eb emplace_back
#define ii pair<int, int> 
#define fi first
#define se second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define bitCnt __builtin_popcountll

const int maxN = 5e5 + 5;

int N, Q, start[maxN], cnt;
signed main()
{
	freopen("SOCKS.inp", "r", stdin);
	freopen("SOCKS.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	loop(i, 1, N) 
	{
		cin >> start[i];
		cnt += start[i];
	}
	loop(i, 1, N - 1)
	{
		int u, v;
		cin >> u >> v;
	}
	loop(q, 1, Q)
	{
		int u;
		cin >> u;
		cnt -= start[u];
		start[u] ^= 1;
		cnt += start[u];
		if(cnt == 1) 
		{
			cout << 0 << endl;
		}
		else cout << 1 << endl;
	}
}
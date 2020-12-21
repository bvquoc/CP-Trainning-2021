#include<bits/stdc++.h>
using namespace std;

//Variables
const int mxN = 5e5 + 5;
const int MOD = 1e9 + 7;
const long long oo = 1e18;
const int d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const int d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

int TestCase , SubTask;
int n , q , red , white;
int light[mxN];
vector<int> adj[mxN];

void Solve() {
//	cin >> SubTask;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> light[i];
		red += (light[i] == 1);
		white += (light[i] == 0);
	}
	for (int i = 2; i <= n; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << 1 << "\n";
	
	for (int __ = 1; __ <= q; __++) {
		int node;
		cin >> node;
		if (light[node]) {
			red--;
			white++;
			light[node] = 0;
		}
		else {
			red++;
			white--;
			light[node] = 1;
		}
		if (red > 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("SOCKS.INP" , "r" , stdin);
	freopen("SOCKS.OUT" , "w" , stdout);
//	cin >> TestCase;
	TestCase = 1;
	while(TestCase--)
		Solve();
	return 0;
}




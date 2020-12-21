#include<bits/stdc++.h>
using namespace std;

//Variables
const int mxN = 1e5 + 5;
const int mxB = (2 << 5);
const int MOD = 1e9 + 7;
const long long oo = 1e18;
const int d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const int d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

int TestCase , SubTask;
int n , m , l , k;
long long answer = oo;
long long cost[mxN][mxB] , s[10] , a[10][10];
vector<pair<long long , long long>> adj[mxN];

long long getbit(long long a , long long b) {
	return (a & (1 << b));	
}

long long onbit(long long a , long long b) {
	return (a | (1 << b));	
}

struct Data {
	long long u , w , melon;
	Data(long long a = 0 , long long b = 0, long long c = 0) {
		w = a;
		u = b;
		melon = c;
	}
	bool operator < (Data temp) const {
		return w > temp.w;
	}
};

bool check(int bit) {
	int cnt = 0;
	for (int i = 0; i <= 4; i++) if	(getbit(bit , i)) cnt++;
	return (cnt >= l);
}

void dijkstra(int start) {
	priority_queue<Data> pq;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= mxB; j++) cost[i][j] = oo;
	}
	int newbit = 0;
	for (int i = 1; i <= s[1]; i++) newbit = onbit(newbit , a[1][i]);
	cost[1][newbit] = 0;
	pq.push(Data(0 , 1 , newbit));
	long long w , u , v , melon;
	
	while (!pq.empty()) {
		Data e = pq.top(); 
		pq.pop();
		w = e.w;
		u = e.u;
		melon = e.melon;
		if (cost[u][melon] != w) continue;
		
		for (auto it : adj[u]) {
			long long v = it.first , cp = it.second , premelon = melon , newmelon = melon;
			for (int e = 1; e <= s[v]; e++) if (!getbit(newmelon , a[v][e])) newmelon = onbit(newmelon , a[v][e]);
			
			if (cost[v][newmelon] > cost[u][premelon] + cp) {
				cost[v][newmelon] = cost[u][premelon] + cp;
				if (v == 6) if (check(newmelon)) answer = min(answer , cost[v][newmelon]);
				pq.push(Data(cost[v][newmelon] , v , newmelon));
			}
		}
	}
}

void Solve() {
//	cin >> SubTask;
	cin >> n >> m >> l >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].push_back({v , w});
		adj[v].push_back({u , w});
	}
	dijkstra(1);
	if (answer == oo) cout << -1;
	else cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("DHAKA.INP" , "r" , stdin);
	freopen("DHAKA.OUT" , "w" , stdout);
//	cin >> TestCase;
	TestCase = 1;
	while(TestCase--)
		Solve();
	return 0;
}




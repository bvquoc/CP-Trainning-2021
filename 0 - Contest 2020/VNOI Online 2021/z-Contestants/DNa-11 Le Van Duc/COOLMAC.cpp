#include<bits/stdc++.h>
using namespace std;

//Variables
const int mxN = 1e4 + 5;
const int MOD = 1e9 + 7;
const long long oo = 1e18;
const int d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const int d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

int TestCase , SubTask;
int n , m , answer , temp = mxN , t;
int dp[mxN][mxN];
bool mark[mxN][mxN];
pair<int , int> a[mxN * 10];

int cal(int idx , int pre) {
	int &ans = dp[idx][pre];
	bool &tie = mark[idx][pre];
	
	if (a[idx].first > temp && a[pre].second < temp) return 1e9;
	if (a[idx].first > a[pre].second + 1 && a[pre].second >= temp) return 1e9;
	
	if (idx > m) {
		if (a[pre].second < 1e5) return 1e9;
		return 0;
	}
	if (tie) return ans;
	tie = true;
	
	ans = 1e9;
	ans = min({ans , cal(idx + 1 , pre) , cal(idx + 1 , idx) + 1});
	return ans;
}

void Solve() {
//	cin >> SubTask;
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		temp = min(temp , t);
	}
	sort(a + 1 , a + m + 1);
	if (m <= 1e4) {
		cal(1 , 0);
		if (dp[1][0] == 1e9) cout << -1;
		else cout << dp[1][0];
		exit(0);
	}
	else cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("COOLMAC.INP" , "r" , stdin);
	freopen("COOLMAC.OUT" , "w" , stdout);
//	cin >> TestCase;
	TestCase = 1;
	while(TestCase--)
		Solve();
	return 0;
}




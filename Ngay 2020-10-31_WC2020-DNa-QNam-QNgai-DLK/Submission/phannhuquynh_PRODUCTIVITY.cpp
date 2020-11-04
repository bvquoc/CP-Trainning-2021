#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000 + 10;
int n, m, cur, c[N][N], b[N * N], used[N], match[N], del[N][N];
vector <int> a[N];

int dfs(int u){
		if (used[u] == cur) return 0;
		used[u] = cur;
		for(int v : a[u]){
				if (del[u][v]) continue;
				if (!match[v] || dfs(match[v])){
						match[v] = u;
						return 1;
				}
		}
		return 0;
} 
int check(int x){
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
				del[i][j] = 0;
		for(int i = 1; i <= n; i++) used[i] = 0, match[i] = 0;
		
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
				if (c[i][j] < x) del[i][j] = 1;
		
		int cnt = 0;
		for(cur = n; cur >= 1; cur--)
				cnt += dfs(cur);
				
		if (cnt == n) return 1;
		return 0;  
}
int main(){
		ios_base :: sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
//		freopen("productivity.inp", "r", stdin);
//		freopen("productivity.out", "w", stdout);
		
		cin >> n;
		m = 0;
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
				cin >> c[i][j];
				a[i].push_back(j);
		}

		int d = 0, c = 1e9 + 1, res;
		while (d <= c){
				int mid = (d + c) / 2;
				if (check(mid)) res = mid, d = mid + 1;
				else c = mid - 1; 
		}
		cout << res;
}




#include<bits/stdc++.h>
using namespace std;
const long long maxN = 2e3;
vector<long long> a[maxN];
long long chosen[maxN];
long long v[maxN][maxN];
long long visited[maxN];
bool BFS(long long now, long long r) {
	if(visited[now] == r) return 0;
	visited[now] = r;
	for(int i = 0; i <= (int)a[now].size() - 1; i++) {
		if(chosen[a[now][i]] == 0 || (BFS(chosen[a[now][i]], r) == true)) {
			chosen[a[now][i]] = now;
			return 1;
		}
    }
    return 0;
}
bool Solve(long long n, long long x) {
	for(int i = 1; i <= n; i++) a[i].clear();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) if(v[i][j] >= x) a[i].push_back(j);
	}
	long long r = 0,ans = 0;
	memset(visited, 0, sizeof(visited));
	memset(chosen, 0, sizeof(chosen));
	for(int i = 1; i <= n; i++) {
		r++;
		if(BFS(i, r)) ans++;
		else return false;
	}
	return (ans >= n);
}
int main()
{
	long long n,l,r,mid,ans;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}
	l = 0; r = 1e9;
	while(l <= r) {
		mid = (l + r) / 2;
		if(Solve(n, mid)) {
			ans =  mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	cout << ans << endl;
}

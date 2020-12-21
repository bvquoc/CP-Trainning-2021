#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAX = 2e5+6;
const int MX = 1e5;

int a[MAX], n, m, res, bad;
ii c[MAX], b[MAX];
int f[MAX], Out[MAX], MinMin;

void Init(){
	for(int i =0; i<=MX; i++){
		f[i] = MAX;
	}
	sort(b+1, b+m+1, greater<ii>());
	sort(c+1, c+m+1, greater<ii>());
	sort(a+1, a+n+1, greater<int>());
}

void Solve(){
	priority_queue<ii> pq;
	int j = 1, k = 1;
	for(int i = MX; i >=MinMin; i--){
		while (j<=m && b[j].fi >= i) {
			pq.push(ii(b[j].fi, b[j].se));
			j++;
		}  
		while (!pq.empty()){
			int Mx = pq.top().fi, idMx = pq.top().se;
			if (Out[idMx]) pq.pop();
			else {
				f[i] = f[Mx+1] + 1;
				break;
			}
		}
		if (pq.empty()) bad = true;
		while (k<=m && c[k].fi >= i){
			Out[c[k].se] = true;
			k++;
		}
	}
}

void Print(){
	if (bad) cout << -1;
	else{
		a[0] = MX+1;
		for(int i=1; i<=n; i++){
			res+= f[a[i]] - f[a[i-1]];
		}
		cout << res;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("COOLMAC.INP","r",stdin);
	    freopen("COOLMAC.OUT","w",stdout);
	#endif
	
	
	
	cin >> m;
	for(int i=1; i<=m; i++){
		cin >> c[i].fi >> b[i].fi;
		b[i].se = c[i].se = i;
	}
	cin >> n;

	MinMin = INT_MAX;
	for(int i =1; i<=n; i++) {
		cin >> a[i];
		MinMin = min(MinMin, a[i]);
	}

	Init();
	Solve();
	Print();
	// cout << "\n" << f[100001] << "\n";
	// cout << "\n" << f[200] << " " << f[1000] << "\n";
	// cout << f[249] << "\n";
	return 0;
}
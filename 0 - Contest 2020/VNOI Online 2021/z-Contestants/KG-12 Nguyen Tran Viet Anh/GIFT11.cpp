#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAX = 2e5+6;

int n, a[MAX], res, dem1, q;
std::vector<int> g[MAX];

int DFS(int u, int par){
	int ret = 0;
	for(int i =0; i< (int)g[u].size(); i++){
		int v= g[u][i];
		if (v==par) continue;
		int x = DFS(v, u);
		ret+= x;
		if (u==1) if (x) dem1++;
	}
	if (ret) return ret;
	if (a[u]) ret++;
	return ret;
}

void Sub1(){
	int dem =0;
	for(int i=1; i<=n; i++) if (a[i]) dem++;
	for(int i =1; i<=q; i++){
		int x;
		cin >> x;
		if (x==1) dem--;
		else dem++;
		if (dem > 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	    freopen("GIFT11.INP","r",stdin);
	    freopen("GIFT11.OUT","w",stdout);
	
	
	
	cin >> n >> q;
	for(int i=1; i<= n; i++) cin >> a[i];
	for(int i=1; i<n; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (n>=3000 && q>= 3000){
		Sub1();
		return 0;
	}

	dem1=0;
	int res = DFS(1,1);
	// cout << dem1 << "\n";
	if (dem1 == 1 && a[1]) res++;
	cout << res - res/2<< "\n";

	for(int i=1; i<=q; i++){
		int x;
		cin >> x;
		dem1= 0;
		a[x] = 1-a[x];
		res = DFS(1,1);
		if (dem1 == 1 && a[1]) res++;
		// cout << "F " << res << "\n";
		cout << res - res/2 << "\n";
	}
	return 0;
}
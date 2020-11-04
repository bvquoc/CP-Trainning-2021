#include <bits/stdc++.h>
#define ll long long 
using namespace std;
struct graph{
		int x;
		ll ts;
};
struct cmp{
	bool operator()(graph a, graph b){
			return a.ts > b.ts;
	}
};
const int N = 2e5 + 10, oo = 2e9 + 10;
int n, m, p, l, k, dd[N];
ll d[N];
vector <graph> a[N];

void dijkstra1(){
		for(int i = 1; i <= n; i++){
				d[i] = oo;
				dd[i] = 0;
		}
		priority_queue <graph,vector <graph>, cmp> q;
		d[1] = 0; q.push({1, 0});
		while (!q.empty()){
				int u = q.top().x; q.pop();
				if (u == n) return;
				dd[u] = 1;
				for(int j = 0; j < a[u].size(); j++){
						int v = a[u][j].x, cost = a[u][j].ts;
						if (!dd[v] && d[v] > d[u] + cost){
								d[v] = d[u] + cost;
								q.push({v, d[v]});
						}
				}
		}
}

void sub1(){
		dijkstra1();
		cout << d[n];	
}	

/*void dijkstra2(){
		for(int i = 1; i <= n; i++){
				for(int j = 0; j <= k; j++) f[i][j] = oo;
				dd[i] = 0;
		}
		priority_queue <bg,vector <bg>, cmp> q;
		for(int i = 1; i <= n; i++) f[i][0] = 0; 
		q.push({1, 0, 0});
		while (!q.empty()){
				int u = q.top().x; q.pop();
				int cnt = q.top().d;
				if (u == n) return;
				dd[u] = 1;
				for(int j = 0; j < a[u].size(); j++){
						int v = a[u][j].x, cost = a[u][j].ts;
						if (!dd[v] && L[v][cnt] > L[u][cnt] + cost){
								L[v][cnt] = L[u][cnt] + cost;
						 		q.push({v, L[v][cnt], cnt});
						}
						for(int i = 1; i <= n; i++)
							if (kenh[i][v] <= l)
							L[v][j] = min(L[v][j], L[v][j - 1] + p);	
				}
		}
}*/

void sub2(){
		//dijkstra2();
		//cout << f[n][k];
}

int main(){
		ios_base :: sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
//		freopen("telmov.inp", "r", stdin);
//		freopen("telmov.out", "w", stdout);
		
		cin >> n >> m >> p >> l >> k;
		for(int i = 1; i <= m; i++){
				int u, v, t;
				cin >> u >> v >> t;
				a[u].push_back({v, t});
				a[v].push_back({u, t});
		}
		//if (k == 0) 
		sub1();
		//else sub2();
}

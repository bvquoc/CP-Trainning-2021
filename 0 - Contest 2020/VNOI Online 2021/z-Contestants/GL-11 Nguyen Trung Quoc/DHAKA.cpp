#include <bits/stdc++.h>
using namespace std;

#define int long long 
typedef pair<int ,int > ii;
#define TASK "DHAKA"
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi first
#define se second
const int N = 1e6 + 7; 

int n, m , k ,l;
vector<int> wa[N];
vector<ii> adj[N];


void sub2(){

	priority_queue<ii , vector<ii> , greater<ii>> heap;
	vector<int> d;
	d.assign(n+7, 1e9);
	d[1] = 0;
	heap.push({0 , 1});
	while(!heap.empty()){
		int u = heap.top().se;
		int du = heap.top().fi;
		heap.pop();

		if(du != d[u]) continue;

		for(auto i : adj[u]){
			int v = i.se;
			int uv = i.fi;

			if(d[v] > du + uv ){
				d[v] = du + uv;
				heap.push({d[v] , v});
			}
		}
	}
	cout << d[n];
}

signed main(){
	IOS;	
	freopen(TASK".inp", "r" , stdin);
	freopen(TASK".out", "w" , stdout);

	cin >> n >> m >> k >> l;

	for(int i = 1 ; i <= n ; i++){
		int s;
		cin >> s;
		for(int j = 1; j <= s ; j++){
			int x;
			cin >> x;
			wa[i].push_back(x);
		}
	}
	for(int i = 1 ; i <= m ;i++){
		int u , v ,w ;
		cin >> u >> v >> w;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}

	if(l == 0) sub2();

	return 0;
}
/*
	      __
	  w c(..)o   (
	  \__(-)    __)
	      /\   (
	     /(_)___)
	    w  /|
	      | \
CouQyn   m  m
*/
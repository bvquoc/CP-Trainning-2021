#include <bits/stdc++.h>
using namespace std;

typedef pair<int ,int > ii;
#define TASK "SOCKS"
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi first
#define se second
const int N = 1e6 + 7; 

int n, q;
int bac[N];
int a[N];
vector<int> adj[N];
int mask = 0;
int cnt = 0;

void sub1(){
	if(cnt <= 1) cout << 0 << "\n";
	else cout << 1 << "\n";

	for(int i = 1; i <= q ;i++){
		int pos;
		cin >> pos;
		cnt -= (a[pos] == 1 ? 1 : -1);
		a[pos] = 1 - a[pos];
		if(cnt <= 1) cout << 0 << "\n";
		else cout << 1 << "\n" ;
	}
}

int main(){
	IOS;	
	freopen(TASK".inp", "r" , stdin);
	freopen(TASK".out", "w" , stdout);

	cin >> n >> q;

	for(int i = 1; i <= n ; i++){
		cin >> a[i];
		cnt += (a[i] == 1);
	}
	bool oksub1 = 1;
	for(int i = 1; i < n ; i++){
		int u , v;
		cin >> u >> v;
		bac[u]++;
		bac[v]++;
		if(bac[u] > 2 || bac[v] > 2) oksub1 = 0;
	}


	if(oksub1) sub1();

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
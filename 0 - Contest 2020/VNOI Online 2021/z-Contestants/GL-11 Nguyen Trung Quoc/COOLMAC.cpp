#include <bits/stdc++.h>
using namespace std;


#define TASK "COOLMAC"
#define int long long
typedef pair<int ,int > ii;
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi first
#define se second
const int N = 1e6 + 7; 

int m , n;
ii a[N];
int f[N];
int t;

bool cmp(ii a ,ii b){
	return a.fi != b.fi ? a.fi < b.fi : a.se < b.se;
}

void sub1(){
	sort(a+1 , a+1+m , cmp);
	if(a[1].fi > t){
		cout << -1;
		return; 
	} 
	int ans = 1e9;
	for(int mask = 1 ; mask < (1 << m) ; mask++){
		vector<ii> res;
		for(int j = 1; j <= m ; j++){
			if(((mask >> (j-1)) & 1) == 1) {
				res.push_back(a[j]);
			}
		}
		bool ok = 1;
		ii tmp = res[0];

		if(tmp.fi > t) continue; 
		for(int j = 1 ; j <(int) res.size() ; j++){
			if(tmp.se < res[j].fi){
				ok = 0;
				break;
			} 
			else{
				tmp = res[j];
			}
		}
		// cout << tmp.fi << " " << tmp.se << endl;
		if(ok && tmp.se == 100000){
			// for(auto x : res) cout << x.fi << " " << x.se << endl;
			ans = min(ans ,(long long) __builtin_popcountll(mask));
		}
			 
		// cout << ans <<endl;
		// cout << endl;
	}
	cout << (ans == 1e9 ?  -1 : ans);
}


signed main(){
	IOS;	
	freopen(TASK".inp", "r" , stdin);
	freopen(TASK".out", "w" , stdout);

	cin >> m;
	for(int i = 1 ; i <= m ; i++){
		cin >> a[i].fi >> a[i].se;
	}
	cin >> n;
	t = INT_MAX;
	for(int i = 1 ; i <= n ;i++){
		int x;
		cin >> x;
		t = min(t , x);
	}

	if( n <= 10 && m <= 16) sub1(); 
	else {
		cout << -1;
	}
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
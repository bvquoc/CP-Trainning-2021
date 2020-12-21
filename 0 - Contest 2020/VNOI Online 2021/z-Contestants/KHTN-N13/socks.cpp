#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7;

const int N = 5e5 + 5;

int n, q;
bool arr[N];

signed main(){
	ios_base::sync_with_stdio(0);
	freopen("socks.inp", "r", stdin);
	freopen("socks.out", "w", stdout);
	cin >> n >> q;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		if(arr[i]) cnt++;
	}
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
	}
	while(q--){
		int pos;
		cin >> pos;
		if(!arr[pos]){
			arr[pos] = 1;
			cnt++;
		}
		else{
			arr[pos] = 0;
			cnt--;
		}
		if(cnt >= 2) cout << 1;
		else cout << 0;
		cout << "\n";
	}
}



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;

ll t, x;
ll c[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};

ll greedy(ll rem){
	ll ans = 0;
	for(int i = 14; i >= 0; i--){
		ans += (rem / c[i]);
		rem %= c[i];
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("ODDCOIN.INP", "r", stdin);
	freopen("ODDCOIN.OUT", "w", stdout);
	
	int nTest;	cin >> nTest;

	while(nTest--){
		cin >> x >> t;
		ll fRes = INF;

		for(ll i = 0; i <= 50001; i++){
			if(t - i * x >= 0){
				fRes = min(fRes, greedy(t - i * x) + i);
			}
		}

		cout << fRes << '\n';
	}

	return 0;
}
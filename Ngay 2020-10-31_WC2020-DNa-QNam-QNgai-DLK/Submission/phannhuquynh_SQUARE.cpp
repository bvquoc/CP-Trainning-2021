#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000000;
ll k, sum[N + 1];

int scp(ll x){
		if (x < 0) return 0;
		ll t = sqrt(x);
		if (t * t == x) return 1;
		return 0;
}

int tknp(ll x){
		int d = 1, c = N, res = -1;
		while (d <= c){
				int mid = (d + c) / 2;
				if (sum[mid] >= x) res = mid, c = mid - 1;
				else d = mid + 1;
		}
		if (res == -1) return 0;
		if (sum[res] == x) return res;
		return res - 1;
}

int main(){
		ios_base :: sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
//		freopen("square.inp", "r", stdin);
//		freopen("square.out", "w", stdout);
		
		cin >> k;
		
		ll t = 1;
		sum[0] = 0;
		for(int i = 1; i <= N; i++){
				sum[i] = sum[i - 1] + t;
				t += 2; 
		}
		ll s = k, i = 1, q = 0;
		if (k < 0){
				int j = tknp(-k);
				s = k + sum[j];
				i = q = sum[j] - sum[j - 1] + 2;
		}
		if (scp(s)){
				cout << sqrt(s);
				return 0;
		}
		while (1){
				s += i;
				if (scp(s)){
						cout << sqrt(s);
						return 0;
				}	
				i += 2;
				if (i - q +1 >= 1e7){
						cout << "none";
						return 0;
				}
		}
		
}

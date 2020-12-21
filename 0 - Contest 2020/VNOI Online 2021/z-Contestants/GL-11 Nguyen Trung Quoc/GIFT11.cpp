#include <bits/stdc++.h>
using namespace std;

typedef pair<int ,int > ii;
#define TASK "GIFT11"
#define int long long
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi first
#define se second
const int N = 1e6 + 7; 
const int MOD = 998244353;
int n;
int a[N];
int chan, le;

int digit(int n){
	int cnt = 0;
	while(n){
		cnt++;
		n /= 10;
	}
	return pow(10,cnt);
}



void sub1(){
	int res = 0;
	vector<int> per(n , 1);

	iota(per.begin() , per.end() , 1);
	do{
		int cnt = 0;
		for(int i = 0; i < n ;i++){
			cnt = cnt*digit(a[per[i]]) + a[per[i]];
		}
		// cout << cnt << endl;
		if (cnt % 11 == 0) res++; 
		if (res > MOD) res-= MOD;
	}while(next_permutation(per.begin() , per.end()));

	cout << res << endl;

}

void cntoe(int a){
	int cnt = 1;
	while(a){
		if(cnt&1) chan += a%10;
		else le += a%10;
		a/=10;
		cnt++;
	}
}

void sub2(){
	int gt = 1;
	for(int i = 2 ; i <= n ; i++){
		gt = gt * i % MOD;
	}
	le = 0 , chan = 0;
	for(int i = 1 ; i <= n ; i++){
		// cout << a[i] <<" ";
		cntoe(a[i]);
	}
	// cout << le << " " << chan  <<endl;
	int k = le - chan;
	while(k < 11) k += 11;
	if(k % 11 == 0) cout << gt << "\n";
	else cout << 0 << "\n";
}

signed main(){
	IOS;	
	freopen(TASK".inp", "r" , stdin);
	freopen(TASK".out", "w" , stdout);

	int tc;
	cin >> tc;
	while(tc--){
		bool oksub2 = 1;
		cin >> n;
		for(int i = 1; i <= n ;i ++){
			cin >> a[i];
			if(digit(a[i]) % 2 != 0) oksub2 = 0;
		}
		// if(n <= 11) sub1();
		if(oksub2) sub2();
		else sub1();
		// sub1();
		// sub2();
		// cout << endl;
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
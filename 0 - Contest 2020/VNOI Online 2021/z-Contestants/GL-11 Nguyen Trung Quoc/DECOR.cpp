#include <bits/stdc++.h>
using namespace std;

typedef pair<int ,int > ii;
#define TASK "DECOR"
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi first
#define se second
const int N = 1e6 + 7; 

int n, m , k;
ii sw[N];
int a[N];

void sub1(){
	int res = 0;
	int pos = 0;
	vector<int> f;
	f.assign(n+7 , 0);
	for(int i = 2; i <= n ;i++){
		if(a[i] == a[i-1] && a[i] == 1) f[i] = f[i-1]+1;
		else if(a[i] == 0) f[i] = 0;
		else if(a[i] == 1) f[i] = 1;
		if(res < f[i]){
			res = f[i];
			pos = i;
		}
	}

	cout << pos - res + 1 << " " << pos;
}

int main(){
	IOS;	
	freopen(TASK".inp", "r" , stdin);
	freopen(TASK".out", "w" , stdout);

	cin >> n >> m >> k;

	for(int i = 1; i <= n ; i++){
		char x;
		cin >> x;
		a[i] = (x == '1');
	}
	for(int i = 1; i <= m ; i++){
		cin >> sw[i].fi >> sw[i].se;
	}

	if(m == 0 && k == 0){
		sub1();
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
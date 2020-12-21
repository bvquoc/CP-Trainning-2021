#include <bits/stdc++.h>
using namespace std;

typedef pair<int ,int > ii;
#define TASK "PERMEOW"
#define IOS ios_base :: sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi first
#define se second
const int N = 1e6 + 7;
const int MOD = 1e9+7; 

int n;
vector<int> a, b;
int res = 0;
int fin[N];
int f[N];
void sub1(){
	int cnt = 0;
	for(int i = 0; i < n-1 ;i++){
		for(int j = i+1; j < n ;j++){
			if(a[j] < a[i]) {
				swap(a[i], a[j]);
				cnt++;
			}
		}
	}
	cout << cnt;
}

void count(vector<int>a){
	int cnt = 0;
	for(int i = 0; i < n ;i++){
		for(int j = i+1; j < n ;j++){
			if(a[j] < a[i]) {
				swap(a[i], a[j]);
				cnt++;
			}
		}
	}
	res += cnt;
}

int main(){
	IOS;	
	freopen(TASK".inp", "r" , stdin);
	freopen(TASK".out", "w" , stdout);
	cin >> n;
	a.assign(n , 0);
	b.assign(n , 0);
	for(int i = 0; i < n ; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n ; i++){
		cin >> b[i]; 
	}

	bool oksub1 = 1,oksub2 = 1;
	for(int i = 1; i <= n ; i++){
		if(a[i] != b[i]){
			oksub1 = 0;
			break;
		} 
	}
	for(int i = 0 ; i < n ;i++){
		if(a[i] != i+1){
			oksub2 = 0;
		} 
		if(b[i] != n-i){
			oksub2 = 0;
		}

	}
	if(oksub1) sub1();
	else if(oksub2){
		fin[0] = 1;
		for(int i = 1; i <= n ;i++){
			fin[i] = fin[i-1]*i%MOD;
			// cout << fin[i] << " ";
		} 
		f[1] = 0;
		f[2] = 1;
 		for(int i = 3; i <= n ; i++){
			f[i] = f[i-1]*i%MOD + fin[i-1]*i*(i-1)/2%MOD;
			f[i]%=MOD;
		}
		cout << f[n];
	}
	else{
		vector<int> per(a.begin() , a.end());
		do{
			count(per);
			if(per == b) break;
		}while(next_permutation(per.begin() , per.end()));
		cout << res;
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
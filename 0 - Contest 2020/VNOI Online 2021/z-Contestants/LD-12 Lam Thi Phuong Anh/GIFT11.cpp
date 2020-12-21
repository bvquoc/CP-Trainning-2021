#include<bits/stdc++.h>
#define int long long
using namespace std;
int res = 0;
int a[2010];
int cnt[2010];
int Pow[2010];
bool check[2010];
int Test, n;
int Sz = 0;
void dfs(int m){
	if(Sz == n && m == 0) res++;
	for(int i = 1; i <= n; i++){
		if(check[i]) continue;
		
		check[i] = true;
		Sz++;
		
		dfs((m * Pow[cnt[i]] + a[i]) % 11);

		check[i] = false;
		Sz--;
	}
}
int32_t main(){
	
	cin >> Test;

	Pow[0] = 1;
	for(int i = 1; i <= 2001; i++) Pow[i] = Pow[i - 1] * 10 % 11;

	while(Test--){
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			int x = a[i];
			cnt[i] = 0;
			while(x > 0){
				cnt[i]++;
				x /= 10;
			}
		}
		res = 0;
		dfs(0);
		cout << res << "\n";
	}	
	
	return 0;
}
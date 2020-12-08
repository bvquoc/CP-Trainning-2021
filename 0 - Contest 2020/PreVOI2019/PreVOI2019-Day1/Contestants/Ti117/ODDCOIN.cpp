#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long q,n,dp[N],x,cost,val[20];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("ODDCOIN.inp","r",stdin);
	freopen("ODDCOIN.out","w",stdout);
	cin >> q;
	n = 2e5;
	//init
	val[1] = 1; val[4] = 10; val[7] = 100; val[10] = 1000; val[13] = 10000;
	val[2] = 3; val[5] = 30; val[8] = 300; val[11] = 3000; val[14] = 30000;
	val[3] = 5; val[6] = 50; val[9] = 500; val[12] = 5000; val[15] = 50000;
	while(q--){ 
		cin >> x >> cost;
		dp[0] = 0;
		val[16] = x;
		for(int i=1;i<=n;i++){
			dp[i] = 2e9;
			for(int j=1;j<=16;j++){
				if(val[j] <= i){
					dp[i] = min(dp[i], dp[i-val[j]] + 1);
				}
			}
		}
		if(cost > n){
			int maxx = 0, tmp = 1;
			for(int i=1;i<=16;i++){
				if(val[i] > maxx && val[i] <= cost){
					maxx = val[i];
				}
			}
			while(cost - tmp*maxx > n){
				tmp++;
			}
			tmp--;
			cost -= tmp * maxx;
			long long ans = 2e9;
			for(int i=1;i<=16;i++){
				if(val[i] <= cost && cost - val[i] <= n){
					ans = min(ans, dp[cost - val[i]] + tmp + 1);
				}
			}
			cout << ans << "\n";
		}else{
			cout << dp[cost] << "\n";
		}
	}
}

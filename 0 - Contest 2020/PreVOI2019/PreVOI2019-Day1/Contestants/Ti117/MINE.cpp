#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
const int mod = 1e6 + 3;
int n,m,a[N],dp[N];
long long cata[N],fac[N],rev[N];
long long add(long long a,long long b){
    return (a + b >= mod ? a + b - mod : a + b);
}
long long power(long long x,long long y,long long mod){
	if(y == 0){
		return 1;
	}else{
		long long dm=power(x, y/2, mod);
		if(y & 1){
			return ((dm * dm) % mod * x) % mod;
		}else{
			return (dm * dm) % mod;
		}
	}
}
long long inverse_mod(long long a,long long mod){
	return power(a, mod-2, mod);
}
long long C(int k,int n){
	return ((fac[n] * rev[k] % mod) * rev[n-k]) % mod;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("MINE.inp","r",stdin);
	freopen("MINE.out","w",stdout);
	cin >> n >> m;
	n = 2*n;
	for(int i=1;i<=n;i++) cin >> a[i];
	fac[0] = 1;
	rev[0] = inverse_mod(fac[0], mod);
	for(int i=1;i<=n;i++){
		fac[i] = (fac[i-1] * i) % mod;
		rev[i] = inverse_mod(fac[i], mod);
	}
	cata[0] = 1;
	for(int i=1;i<=n/2;i++){
		cata[i] = (1LL * inverse_mod(i+1, mod) * C(i, 2*i)) % mod;
	}
	if(n <= 4000){
		dp[0] = 1;
		for(int i=2;i<=n;i+=2){
			for(int j=i-1;j>=0;j-=2){
				if(a[i] - a[j] > m) break;
				dp[i] = add(dp[i], (1LL * dp[j-1] * cata[(i-j-1)/2]) % mod);
			}
		}
		cout << dp[n];
		return 0;
	}else{
		cout << cata[n/2];
		return 0;
	}
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
const int M=2e3+2;
const int mod=1e6+3;
int n,m,fact[2*N],rev_fact[2*N],ar[2*N],rev_num[2*N],suf[2*N];
int binpow(int x,int y){
	int tich=1;
	while(y){
		if(y&1){
			tich*=x;
			tich%=mod;
		}
		x*=x;
		x%=mod;
		y>>=1;
	}
	return tich;
}
int C(int x,int y){
	return (fact[y]*rev_fact[y-x]*rev_fact[x])%mod;
}
int Catalan(int x){
	if(x==0){
		return 1;
	}
	return (C(x,2*x)*rev_num[x+1])%mod;
}
signed main(){
	freopen("MINE.inp","r",stdin);
	freopen("MINE.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i,j,k,l;
	cin>>n>>m;
	fact[0]=1;
	for(i=1;i<=2*n;i++){
		cin>>ar[i];
		fact[i]=(fact[i-1]*i)%mod;
	}
	rev_fact[2*n]=binpow(fact[2*n],mod-2);
	for(i=2*n;i>0;i--){
		rev_fact[i-1]=(rev_fact[i]*i)%mod;
		rev_num[i]=binpow(i,mod-2);
	}
	if(m>=ar[2*n]-ar[1]){
		cout<<Catalan(n);
		return 0;
	}
	suf[2*n+1]=1;
	for(i=2*n-1;i>=1;i-=2){
		if(ar[2*n]-ar[i]<=m){
			suf[i]=Catalan((2*n-i+1)/2);
			continue;
		}
		for(j=i+1;j<=2*n;j+=2){
			if(ar[j]-ar[i]<=m){
				suf[i]+=suf[j+1]*Catalan((j-i-1)/2);
				suf[i]%=mod;
			}
			else{
				break;
			}
		}
	}
	int ans=0;
	for(i=2;i<=2*n;i+=2){
		if(ar[i]-ar[1]<=m){
			ans+=Catalan((i-2)/2)*suf[i+1];
			ans%=mod;
		}
		else{
			break;
		}
	}
	cout<<ans;
}
/*
3 6
1 2 3 7 9 10
*/

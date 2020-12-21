#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
const int mod=1e9+7;
void add(int &x,int y){
	x+=y;
	if(x>=mod){
		x-=mod;
	}
}
void sub(int &x,int y){
	x-=y;
	if(x<0){
		x+=mod;
	}
}
int mul(int x,int y){
	return (1ll*x*y)%mod;
}
int bit[N],fact[N],inv4,inv2;
vector<int> a,b;
void upd(int x,int y){
	while(x<N){
		bit[x]+=y;
		x+=(x&-x);
	}
}
int getsum(int x){
	int sum=0;
	while(x){
		sum+=bit[x];
		x-=(x&-x);
	}
	return sum;
}
int binpow(int x,int y){
	int tich=1;
	while(y){
		if(y&1){
			tich=mul(tich,x);
		}
		x=mul(x,x);
		y>>=1;
	}
	return tich;
}
int solve(vector<int> x){	//nho hon bang
	int n=x.size(),i,j,k,l,ans=0;
	vector<int> order;
	order.resize(n+1);
	for(i=0;i<n;i++){
		order[i]=x[i]-1-getsum(x[i]-1);
		add(ans,mul(mul(mul(order[i]-1,order[i]),inv2),fact[n-1-i]));
//		ans+=order*thutucuapermtui+1denn+1
//		cout<<ans<<endl;
//		if(i<n-2){
			add(ans,mul(mul(order[i],mul(mul(n-i-1,n-i-2),inv4)),fact[n-1-i]));
//		}
		upd(x[i],1);
//		cout<<i<<' '<<order<<' '<<ans<<endl;
	}
	for(i=n-1;i>-1;i--){
		add(ans,mul(order[i],order[i+1]));
		add(order[i+1],mul(order[i],fact[n-1-i]));
		swap(order[i],order[i+1]);
	}
//	cout<<ans<<endl;
	for(i=1;i<=n;i++){
		bit[i]=0;
	}
	for(i=0;i<n;i++){
		upd(x[i],1);
		add(ans,x[i]-getsum(x[i]));
	}
//	cout<<ans<<endl;
	for(i=1;i<=n;i++){
		bit[i]=0;
	}
//	cout<<ans<<endl;
	return ans;
	/*
	1 2 3 : 0
	1 3 2 : 1
	2 1 3 : 1
	2 3 1 : 2
	3 1 2 : 2 -> 6
	3 2 1 : 3
	*/
}
int solve1(vector<int> x){	//nho hon
	int n=x.size(),i,j,k,l,ans=0;
	vector<int> order;
	order.resize(n+1);
	for(i=0;i<n;i++){
		order[i]=x[i]-1-getsum(x[i]-1);
		add(ans,mul(mul(mul(order[i]-1,order[i]),inv2),fact[n-1-i]));
//		ans+=order*thutucuapermtui+1denn+1
//		cout<<ans<<endl;
//		if(i<n-2){
			add(ans,mul(mul(order[i],mul(mul(n-i-1,n-i-2),inv4)),fact[n-1-i]));
//		}
		upd(x[i],1);
//		cout<<i<<' '<<order<<' '<<ans<<endl;
	}
	for(i=n-1;i>-1;i--){
		add(ans,mul(order[i],order[i+1]));
		add(order[i+1],mul(order[i],fact[n-1-i]));
		swap(order[i],order[i+1]);
	}
//	cout<<ans<<endl;
	for(i=1;i<=n;i++){
		bit[i]=0;
	}
	return ans;
}
signed main(){
	freopen("PERMEOW.inp","r",stdin);
	freopen("PERMEOW.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,j,k,l,ans;
	cin>>n;
	a.resize(n);
	b.resize(n);
	inv2=binpow(2,mod-2);
	inv4=binpow(4,mod-2);
	fact[0]=1;
	for(i=1;i<=n;i++){
		fact[i]=mul(fact[i-1],i);
		cin>>a[i-1];
	}
	for(i=1;i<=n;i++){
		cin>>b[i-1];
	}
	ans=solve(b);
//	cout<<solve(b)<<endl;
	sub(ans,solve1(a));
//	cout<<solve1(a)<<endl;
	cout<<ans;
}
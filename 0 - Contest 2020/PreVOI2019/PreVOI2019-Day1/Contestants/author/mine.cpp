#ifndef LOCAL
#define NDEBUG
#endif
#include<iostream>
#include<vector>
#include<cassert>

int const MOD=1000003;

int invmod(int x,int y=MOD){
	int a=x,b=y,ax=1,bx=0;
	while(b){
		int q=a/b;
		a%=b;
		ax-=q*bx;
		std::swap(a,b);
		std::swap(ax,bx);
	}
	assert(a==1);
	if(ax<MOD)ax+=MOD;
	return ax;
}

std::vector<int> fact;

int binom(int a,int b){
	if(b<0 or b>a)return 0;
	return fact[a]*(int64_t)invmod(fact[b]*(int64_t)fact[a-b]%MOD, MOD)%MOD;
}

int cat(int n){
	return (binom(2*n,n)+MOD-binom(2*n,n-1))%MOD;
}

int main(){
	freopen ("mine.inp","r",stdin);
	freopen ("mine.out","w",stdout);
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int npair,maxspan;std::cin>>npair>>maxspan;
	std::vector<int> a(npair*2);for(int& x:a)std::cin>>x;

	fact.resize(npair*2+1); // TODO 
	fact[0]=1;
	for(unsigned i=1;i<fact.size();++i) // complexity: npair log npair
		fact[i]=i*(int64_t)fact[i-1]%MOD;

	std::vector<int> dp(npair+1);
	dp[0]=1;
	for(int i=1,j=0;i<=npair;++i){
		while(j<i and a[2*i-1]-a[2*j]>maxspan)
			++j;
		int dpi=0;
		//std::cerr <<i<<' '<<j<<'\n';
		if(j==0){
			dpi=cat(i);
		}else{
			for(int k=j;k<i;++k)
				dpi=(dpi+dp[k]*(int64_t)cat(i-k-1))%MOD;
		}
		dp[i]=dpi;
	} // complexity: min(npair,maxspan) * npair
	std::cout<<dp.back()<<'\n';
}

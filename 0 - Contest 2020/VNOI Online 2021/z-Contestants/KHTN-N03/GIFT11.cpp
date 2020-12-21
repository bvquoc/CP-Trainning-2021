#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=2e3+2;
void add(int &x,int y){
	x+=y;
	if(x>=mod){
		x-=mod;
	}
}
int mul(int x,int y){
	return (1ll*x*y)%mod;
}
int add11(int x,int y){
	x+=y;
	if(x>=11){
		x-=11;
	}
	return x;
}
int sub11(int x,int y){
	x-=y;
	if(x<0){
		x+=11;
	}
	return x;
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
int fact[N],ifact[N];
int C(int a,int b){
	if(a>b){
		return 0;
	}
	if(a<0){
		return 0;
	}
	return mul(fact[b],mul(ifact[b-a],ifact[a]));
}
vector<int> val[2];
int dpodd[2][N][11],dpeven[2][N][11];
signed main(){
	freopen("GIFT11.inp","r",stdin);
	freopen("GIFT11.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m,i,j,k,l;
	cin>>t;
	fact[0]=1;
	for(i=1;i<N;i++){
		fact[i]=mul(fact[i-1],i);
	}
	ifact[N-1]=binpow(fact[N-1],mod-2);
	for(i=N-1;i>0;i--){
		ifact[i-1]=mul(ifact[i],i);
	}
	string s;
	while(t--){
		cin>>n;
		val[0].clear();
		val[1].clear();
		for(i=1;i<=n;i++){
			cin>>s;
			k=0;
			for(j=0;j<s.size();j++){
				if(j&1){
					k-=(int)(s[j]-'0');
				}
				else{
					k+=(int)(s[j]-'0');
				}
			}
			if(s.size()&1){
				k=-k;
			}
			k%=11;
			k+=11;
			if(k>=11){
				k-=11;
			}
			val[(s.size()&1)].push_back(k);
		}
		for(i=0;i<N;i++){
			for(j=0;j<11;j++){
				dpodd[0][i][j]=dpodd[1][i][j]=dpeven[0][i][j]=dpeven[1][i][j]=0;
			}
		}
		int ans=0,cur=0,rev=1;
		dpodd[0][0][0]=dpeven[0][0][0]=1;
		for(i=0;i<val[1].size();i++){
			cur^=1; rev^=1;
			for(j=0;j<=i;j++){
				for(k=0;k<11;k++){
					add(dpodd[cur][j+1][add11(k,val[1][i])],dpodd[rev][j][k]);	
					add(dpodd[cur][j][sub11(k,val[1][i])],dpodd[rev][j][k]);
				}
			}
			for(j=0;j<N;j++){
				for(k=0;k<11;k++){
					dpodd[rev][j][k]=0;
				}
			}
		}
		cur=0,rev=1;
		for(i=0;i<val[0].size();i++){
			cur^=1; rev^=1;
			for(j=0;j<=i;j++){
				for(k=0;k<11;k++){
					add(dpeven[cur][j+1][add11(k,val[0][i])],dpeven[rev][j][k]);
					add(dpeven[cur][j][sub11(k,val[0][i])],dpeven[rev][j][k]);
				}
			}
			for(j=0;j<N;j++){
				for(k=0;k<11;k++){
					dpeven[rev][j][k]=0;
				}
			}
		}
		int idxodd=(val[1].size()&1),cntodd=(val[1].size()+1)/2,idxeven=(val[0].size()&1);
		int grpam=cntodd,grpduong=val[1].size()+1-grpam;
		if(!grpam){
			add(ans,mul(dpeven[idxeven][n][0],fact[n]));
		}
		else{
			for(i=0;i<=n;i++){
				for(j=0;j<11;j++){
					k=mul(mul(dpodd[idxodd][cntodd][j],fact[cntodd]),fact[val[1].size()-cntodd]);
					k=mul(k,mul(mul(dpeven[idxeven][i][sub11(0,j)],fact[i]),C(i,i+grpduong-1)));
					k=mul(k,mul(fact[val[0].size()-i],C(val[0].size()-i,val[0].size()-i+grpam-1)));
					add(ans,k);
				}
			}
		}
		cout<<ans<<'\n';
	}
}
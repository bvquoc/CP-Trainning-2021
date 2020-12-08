#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e9+7;
vector<int> lis;
int x,t,ans=inf,x1,y1;
void get_coof(int a,int b){
	if(b==0){
		x1=1;
		y1=0;
		return;
	}
	get_coof(b,a%b);
	int x2=x1;
	x1=y1;
	y1=x2-(a/b)*y1;
}
int ceil(int x,int y){
	return (x+y-1)/y;
}
void check(int val,int cnt){
	int gc=__gcd(50000ll,x);
	if(val%gc!=0){
		return;
	}
	get_coof(50000ll,x);
	//x1*50000 , y1*x
	x1*=val/gc;
	y1*=val/gc;
	int mul1=x/gc,mul2=50000ll/gc;
	if(x1<0){
		int num=ceil(-x1,mul1);
		x1+=num*mul1;
		y1-=num*mul2;
	}
	if(y1<0){
		int num=ceil(-y1,mul2);
		x1-=num*mul1;
		y1+=num*mul2;
	}
	if(x1<0||y1<0){
		return;
	}
	if(mul1<mul2){		//y1 min , x1 max
		int num=y1/mul2;
		y1-=num*mul2;
		x1+=num*mul1;
	}
	else{				//x1 min , y1 max
		int num=x1/mul1;
		x1-=num*mul1;
		y1-=num*mul2;
	}
	ans=min(ans,x1+y1+cnt);
}
void back(int pos,int lim,int sum,int cnt){
	if(sum>t){
		return;
	}
	if(pos==lim){
		check(t-sum,cnt);
		return;
	}
	if(pos%3==0){
		for(int i=0;i<=2;i++){
			back(pos+1,lim,sum+i*lis[pos],cnt+i);
		}
	}
	else{
		for(int i=0;i<2;i++){
			back(pos+1,lim,sum+i*lis[pos],cnt+i);
		}
	}
}
signed main(){
	freopen("ODDCOIN.inp","r",stdin);
	freopen("ODDCOIN.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q,n,i,j,k,l;
	for(i=1,j=1;j<=5;j++,i*=10){
		lis.push_back(i);
		lis.push_back(3*i);
		if(j!=5){
			lis.push_back(5*i);
		}
	}
	cin>>q;
	while(q--){
		cin>>x>>t;
		ans=2e9+7;
		back(0,lis.size(),0,0);
		cout<<ans<<'\n';
	}
}
/*
4
4700 53
4700 9400
4700 9401
4700 30000
*/

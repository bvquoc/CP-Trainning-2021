//Rochy'.'
#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define fl(i,a,b) for(int i=a;i<b;++i)
#define fa(i,a) for(auto (i):(a))
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define vi vector <int>
#define ii pair <int,int>
#define pb push_back
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));
if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
template <typename R, typename D> inline void Min(R &a, D b){if(a>b) a=b;}
template <typename D, typename R> inline void Max(D &a, R b){if(a<b) a=b;}
const int N=0000;
int am[]={0,1,2,1,2,1,2,3,2,3},Q,t,x,cnt,ans;
ii Ans;
int handle(int x){
	int res=0;
	for(;x;x/=10){
		res+=am[x%10];
	}
	return res;
}
void check(){
	if(Ans.F+Ans.S>handle(x)+cnt){
		Ans.F=handle(x);
		Ans.S=cnt;
	}
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin. tie(NULL); cout. tie(NULL);
	freopen("Oddcoin.inp" , "r", stdin);
	freopen("Oddcoin.out", "w", stdout);
	cin>>Q;while(Q--){
		ans=2e9;cnt=0;
		Ans={2e9,0};
		cin>>t>>x;
		check();
		fo(times,1,30)if(x>=t){
			++cnt;
//			Min(ans,handle(x-t)+cnt+1);
			x-=t;
			check();
		}
		cout<<Ans.F+Ans.S<<'\n';
//		cout<<ans<<'\n';
	}
	return 0;
}
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
const int N=100004;
int n,m,T,ty,a[N],q[N],top;
void handle(){
	top=0;
	int res=0;
	fo(i,1,n){
		while(a[q[top]]>a[i]&&top)--top;
		res+=a[i]-a[q[top]];
		q[++top]=i;
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin. tie(NULL); cout. tie(NULL);
	freopen("Construct.inp" , "r", stdin);
	freopen("Construct.out", "w", stdout);
	cin>>T;while(T--){
		cin>>n>>m;
		fo(i,1,n) cin>>a[i];
		while(m--){
			cin>>ty;
			if(ty==1){
				int l,r,w;cin>>l>>r>>w;
				fo(i,l,r) a[i]+=w;
				continue;
			}
			int l,r;cin>>l>>r;
			fo(i,1,l-1){
				a[i]=0;
			}
			fo(i,r+1,n){
				a[i]=0;
			}
			handle();
		}
	}
	return 0;
}
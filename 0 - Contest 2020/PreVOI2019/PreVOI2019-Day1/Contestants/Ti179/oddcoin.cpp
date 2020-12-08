#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b;a<=c;++a)
#define fordec(a,b,c) for(int a=b;a>=c;--a)
#define forv(a,b) for(auto &a:b)
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define task "oddcoin"
#define int long long
int n;
int a[] = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	cin>>n;
	while(n--){
		int x,t;
		cin>>x>>t;
		vector<int> c;
		forinc(i,0,14) c.pb(a[i]);
		c.pb(x);
		sort(all(c));
		int cnt=1e9;
		fordec(i,c.size()-1,0){
			int u=0,val=t;
			fordec(j,i,0){
				if(val==0) break;
				u+=val/c[j];
				val=val%c[j];
			}
			cnt=min(cnt,u);
		}
		//cerr<<'\n';
		cout<<cnt<<'\n';
	}
}

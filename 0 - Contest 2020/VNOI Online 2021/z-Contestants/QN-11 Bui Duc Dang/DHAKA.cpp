#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> ii;
typedef pair<long long,ii> i3;
priority_queue<i3,vector<i3>,greater<i3> > q;
const int M=1e5+1;
const long long InF=3e18;
int n,m,k,l,tp[M];
vector<ii> a[M];
long long d[M][32],ans;
int main()
{
	freopen("DHAKA.INP","r",stdin);
	freopen("DHAKA.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k>>l;
	for(int i=1;i<=n;++i)
	{
		int sz,aij; cin>>sz;
		while(sz--) {cin>>aij; tp[i]|=1<<(aij-1);}
	}
	for(int i=1;i<=m;++i)
	{
		int u,v,w; cin>>u>>v>>w;
		a[u].push_back({w,v});
		a[v].push_back({w,u});
	}
	int lmk=1<<k;
	for(int i=1;i<=n;++i)
		for(int j=0;j<lmk;++j) d[i][j]=InF;
	d[1][tp[1]]=0;
	q.push({0,{1,tp[1]}});
	while(!q.empty())
	{
		i3 tmp=q.top(); q.pop();
		long long du=tmp.fi; int u=tmp.se.fi;
		int msk=tmp.se.se;
		if(du==d[u][msk])
			for(auto e:a[u])
			{
				int v=e.se,w=e.fi,mk2=msk|tp[v];
				if(d[v][mk2]>du+w){
					d[v][mk2]=du+w;
					q.push({du+w,{v,mk2}});
				}
			}
	}
	ans=InF;
	for(int i=0;i<lmk;++i)
	{
		int i2=i,ct=0;
		while(i2) {if(i2&1) ++ct; i2>>=1;}
		if(ct>=l) ans=min(ans,d[n][i]);
	}
	cout<<((ans==InF) ? -1: ans);
	return 0;
}

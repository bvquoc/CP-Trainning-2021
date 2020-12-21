#include<bits/stdc++.h>
using namespace std;
const int M=5e5+1;
bool red[M];
vector<int> a[M];
int n,q,x,y;
int cnt;
int sum[M];
void dfs(int u,int p)
{
	if(red[u]) sum[u]=1;
	else sum[u]=0;
	for(auto v:a[u])
		if(v!=p){
			dfs(v,u);
			sum[u]+=sum[v];
		}
	if(red[u]&&sum[u]==1) ++cnt;
}
int main()
{
	freopen("SOCKS.INP","r",stdin);
	freopen("SOCKS.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>x;
		if(x==1) red[i]=true;
	}
	for(int i=1;i<n;++i)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,1); cout<<cnt;
	for(int i=1;i<=q;++i)
	{
		cnt=0;
		cin>>x; red[x]=!red[x];
		dfs(1,1);
		cout<<"\n"<<cnt;
	}
	return 0;
}

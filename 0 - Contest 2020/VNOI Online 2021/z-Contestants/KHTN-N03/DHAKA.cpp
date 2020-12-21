#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
const int NUM=5;
const long long inf=1e15+2;
vector<pair<int,int> > adj[N];
int n,mask[N];
long long dp[1<<NUM][N];
priority_queue<pair<long long,int> > pq;
int convert(int x,int y){
	return x*n+y;
}
pair<int,int> rev(int a){
	if(a%n==0){
		return {a/n-1,n};
	}
	return {a/n,a%n};
}
signed main(){
	freopen("DHAKA.inp","r",stdin);
	freopen("DHAKA.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,i,j,k,l,num,cnt;
	cin>>n>>m>>num>>cnt;
	for(i=0;i<(1<<NUM);i++){
		for(j=1;j<=n;j++){
			dp[i][j]=inf;
		}
	}
	for(i=1;i<=n;i++){
		cin>>j;
		for(k=0;k<j;k++){
			cin>>l;
			l--;
			mask[i]|=(1<<l);
		}
	}
	for(i=1;i<=m;i++){
		cin>>j>>k>>l;
		adj[j].push_back({k,l});
		adj[k].push_back({j,l});
	}
	dp[mask[1]][1]=0;
	pq.push({-dp[mask[1]][1],convert(mask[1],1)});
	while(pq.size()){
		pair<int,int> cac=rev(pq.top().second);
		j=cac.first,k=cac.second,i=-pq.top().first;
		pq.pop();
		if(i!=dp[j][k]){
			continue;
		}
		if(__builtin_popcount(j)>=cnt&&k==n){
			cout<<dp[j][k];
			return 0;
		}
		for(l=0;l<adj[k].size();l++){
			if(dp[j|mask[adj[k][l].first]][adj[k][l].first]>dp[j][k]+adj[k][l].second){
				dp[j|mask[adj[k][l].first]][adj[k][l].first]=dp[j][k]+adj[k][l].second;
				pq.push({-dp[j|mask[adj[k][l].first]][adj[k][l].first],convert(j|mask[adj[k][l].first],adj[k][l].first)});
			}
		}
	}
	cout<<-1;
}
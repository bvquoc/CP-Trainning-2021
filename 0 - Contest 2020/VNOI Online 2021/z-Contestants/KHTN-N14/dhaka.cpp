#include<bits/stdc++.h>
using namespace std;
vector <pair<long long,long long> > v[3333333];
pair <long long,long long> p,P;
priority_queue <pair<long long,long long> >q;
bool c[3333333];
long long n,j,k,l,u,w,g,M,m,i,a[101010],b[101010],d[3333333];
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("DHAKA.inp","r",stdin);
	freopen("DHAKA.out","w",stdout);
	cin>>n>>m>>k>>l;
	for(i=1;i<=n;i++){
		cin>>u;
		while(u--){
			cin>>w;
			a[i]+=(1<<w);
		}
	}
	for(i=1;i<=n;i++) b[i]=31^a[i];
	for(i=1;i<=m;i++){
		cin>>u>>w>>g;p.second=g;
		for(j=0;j<32;j++) if(j|b[u]==31){
			p.first=(w-1)*32+(j|a[w]);
			v[(u-1)*32+j].push_back(p);
		}
		for(j=0;j<32;j++) if(j|b[w]==31){
			p.first=(u-1)*32+(j|a[u]);
			v[(w-1)*32+j].push_back(p);
		}
	}
	for(i=1;i<=n*32;i++){
		d[i]=1e18;
		c[i]=false;
	}
	p.first=0;
	p.second=a[1];
	d[a[1]]=0;
	q.push(p);
	while(!q.empty()){
		p=q.top();
		q.pop();
		if(c[p.second]==true) continue;
		c[p.second]=true;
		for(i=0;i<v[p.second].size();i++){
			d[v[p.second][i].first]=min(d[v[p.second][i].first],d[p.second]+v[p.second][i].second);
			P.first=-d[v[p.second][i].first];
			P.second=v[p.second][i].first;
			q.push(P);
		}
	}
	M=1e18;
	for(i=0;i<32;i++) if(i|b[n]==31 && __builtin_popcount(i)>=l) M=min(M,d[32*(n-1)+i]);
	if(M==1e18) cout<<"-1";
	else cout<<M;
}
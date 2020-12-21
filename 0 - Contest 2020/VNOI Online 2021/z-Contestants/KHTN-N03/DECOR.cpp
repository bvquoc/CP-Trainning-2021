#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int totgrp[N],grp[N],cnt=0,cntgrp[N];
vector<int> adj[N];
string s;
void dfs(int x){
	grp[x]=cnt;
	for(int i=0;i<adj[x].size();i++){
		if(!grp[adj[x][i]]){
			dfs(adj[x][i]);
		}
	}
}
signed main(){
	freopen("DECOR.inp","r",stdin);
	freopen("DECOR.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,j,k,l,lef=1,rig=0,anslef=0,ansrig=0,dem=0,num;
	cin>>n>>m>>num>>s;
	for(i=1;i<=m;i++){
		cin>>j>>k;
		adj[j].push_back(k);
		adj[k].push_back(j);
	}
	for(i=1;i<=n;i++){
		if(!grp[i]){
			cnt++;
			dfs(i);
		}
	}
	for(i=0;i<n;i++){
		if(s[i]=='1'){
			totgrp[grp[i+1]]++;
		}
	}
	for(lef=1;lef<=n;lef++){
		if(lef>1){
			cntgrp[grp[lef-1]]--;
			if(cntgrp[grp[lef-1]]>=totgrp[grp[lef-1]]){
				dem--;
			}
		}
		while(rig<n&&dem<=num){
			rig++;
			cntgrp[grp[rig]]++;
			if(cntgrp[grp[rig]]>totgrp[grp[rig]]){
				dem++;
			}
		}
		if(dem<=num){
			if(rig-lef+1>ansrig-anslef+1){
				anslef=lef;
				ansrig=rig;
			}
		}
		else{
			if(rig-lef>ansrig-anslef+1){
				anslef=lef;
				ansrig=rig-1;
			}
		}
//		cout<<lef<<' '<<rig<<' '<<dem<<endl;
	}
	if(anslef==0&&ansrig==0){
		cout<<-1;
	}
	else{
		cout<<anslef<<' '<<ansrig;
	}
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
const int inf=1e9+7;
int mini[N];
signed main(){
	freopen("COOLMAC.inp","r",stdin);
	freopen("COOLMAC.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,j,k,l,now=N-1,cac=inf,cnt=0,tempnow=N-1;
	for(i=1;i<N;i++){
		mini[i]=inf;
	}
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>j>>k;
		mini[k+1]=min(mini[k+1],j);
	}
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j;
		cac=min(cac,j);
	}
	while(now>cac){
		cnt++;
		k=now;
		while(tempnow>=now){
			k=min(k,mini[tempnow]);
			tempnow--;
		}
		if(k==now){
			cout<<-1;
			return 0;
		}
		now=k;
	}
	cout<<cnt;
}
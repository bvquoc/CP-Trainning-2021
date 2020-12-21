#include<bits/stdc++.h>
using namespace std;
int n,q,s=0,a[1010101],i,u,v;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("SOCKS.inp","r",stdin);
	freopen("SOCKS.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>a[i];
		s=s+a[i];
	}
	for(i=1;i<n;i++) cin>>u>>v;
	if(s>1) cout<<"1";else cout<<"0";
	while(q--){
		cin>>u;
		if(a[u]==1) s--;else s++;
		a[u]=1-a[u];
		if(s>1) cout<<"\n1";else cout<<"\n0";
	}
}
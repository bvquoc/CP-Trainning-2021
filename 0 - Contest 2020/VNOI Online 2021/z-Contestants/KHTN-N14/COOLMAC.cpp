#include<bits/stdc++.h>
using namespace std;
pair <int,int> p[404040];
int m,l[404040],r[404040],L[404040],R[404040],N,n=404040,x,y,z,i;
void b(int u,int v,int w){
	if(u==v){
		l[w]=p[u].second;
		r[w]=p[v].first;
		return;
	}
	b(u,(u+v)/2,2*w);
	b((u+v)/2+1,v,2*w+1);
	l[w]=min(l[2*w],l[2*w+1]);
	r[w]=r[2*w];
}
void a(int u,int v,int w){
	if(u==v){
		if(r[w]>=z) x=min(x,l[w]);
		return;
	}
	if(r[2*w+1]<z) a((u+v)/2+1,v,2*w+1);
	else{
		x=min(x,l[2*w+1]);
		a(u,(u+v)/2,2*w);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("COOLMAC.inp","r",stdin);
	freopen("COOLMAC.out","w",stdout);
	cin>>m;
	for(i=1;i<=m;i++) cin>>p[i].second>>p[i].first;
	sort(p+1,p+m+1);
	b(1,m,1);
	cin>>z;
	for(i=1;i<=z;i++){
		cin>>N;
		n=min(n,N);
	}
	z=100000;
	y=0;
	while(69==69){
		x=z;
		a(1,m,1);
		y++;
		if(x==z){
			cout<<"-1";
			exit(0);
		}
		if(x<=n){
			cout<<y;
			exit(0);
		}
		z=x;
	}
}
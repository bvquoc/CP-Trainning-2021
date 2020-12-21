#include<bits/stdc++.h>
using namespace std;
long long n,h,o,u,i,t,a[2020],b[2020],c[2020],d[2020],g,ans=0,p=998244353,I[2020];
void back(long long v){
	if(v==n+1){
		g=0;h=0;
		for(I[v]=1;I[v]<=n;I[v]++){
			h=h+(1-2*(g%2))*a[c[I[v]]];
			g=g+b[c[I[v]]];
		}
		if(h>=0 && h%11==0) ans++;
		if(h<0 && (-h)%11==0) ans++;
		if(ans>=p) ans-=p;
		return;
	}
	for(I[v]=1;I[v]<=n;I[v]++) if(d[I[v]]==0){
		d[I[v]]=1;
		c[v]=I[v];
		back(v+1);
		d[I[v]]=0;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("GIFT11.inp","r",stdin);
	freopen("GIFT11.out","w",stdout);
	cin>>t;
	for(o=1;o<=t;o++){
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			u=a[i];
			b[i]=0;
			c[i]=0;
			d[i]=0;
			while(u>0){
				u=u/10;
				b[i]++;
			}
		}
		if(n+t<=9){
			back(1);
			cout<<ans<<"\n";
			continue;
		}
			ans=0;
			for(i=1;i<=n;i++) ans=ans+a[i];
			if(ans%11!=0){
				cout<<"0\n";
				continue;
			}
			ans=1;
			for(i=2;i<=n;i++) ans=(ans*i)%p;
			cout<<ans<<"\n";
			continue;
	}
}
#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
vector<int> a[500001];
string s;
int main()
{
	freopen("DECOR.INP","r",stdin);
	freopen("DECOR.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	cin>>s;
	for(int i=1;i<=m;++i){
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if(m==0)
	{
		int ans=0,pt=0,dl=0,ps;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='0') ++dl;
			while(dl>k&&pt<=i){
				if(s[pt]=='0') --dl;
				++pt;
			}
			if(i-pt>=ans) {ps=i; ans=i-pt+1;}
		}
		if(ans==0) cout<<-1;
		else cout<<ps-ans+2<<" "<<ps+1;
	}
	else cout<<-1;
	return 0;
}

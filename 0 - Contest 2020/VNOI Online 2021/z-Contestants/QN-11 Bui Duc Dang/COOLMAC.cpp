#include<bits/stdc++.h>
using namespace std;
const int M=1e5+1;
int st[4*M];
int n,m,il,ir;
int bg,ed,val;
int dp[M],start[M];
void build(int id,int l,int r)
{
	if(l>ed) st[id]=m;
	else st[id]=0;
	if(l<r){
		int mid=l+r>>1;
		build(2*id,l,mid);
		build(2*id+1,mid+1,r);
	}
}
void update(int id,int l,int r)
{
	if(l==r) st[id]=min(st[id],val);
	else
	{
		int mid=l+r>>1;
		if(mid<ed) update(2*id+1,mid+1,r);
		else update(2*id,l,mid);
		st[id]=min(st[2*id],st[2*id+1]);
	}
}
int query(int id,int l,int r)
{
	if(l>ed||r<bg) return m+1;
	if(l>=bg&&r<=ed) return st[id];
	int mid=l+r>>1;
	return min(query(2*id,l,mid),query(2*id+1,mid+1,r));
}
int main()
{
	freopen("COOLMAC.INP","r",stdin);
	freopen("COOLMAC.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>m;
	for(int i=0;i<M;++i) start[i]=M;
	for(int i=1;i<=m;++i){
		cin>>il>>ir;
		start[ir]=min(start[ir],il);
	}
	cin>>n; ed=M;
	for(int i=1;i<=n;++i) {cin>>il; ed=min(ed,il);}
	build(1,0,M-1);
	for(int i=1;i<M;++i)
		if(start[i]<i)
		{
			bg=start[i], ed=i-1;
			dp[i]=query(1,0,M-1)+1;
			if(dp[i]<=m){
				++ed; val=dp[i];
				update(1,0,M-1);
			}
		}
	if(start[M-1]==M||dp[M-1]>m) cout<<-1;
	else cout<<dp[M-1];
	return 0;
}

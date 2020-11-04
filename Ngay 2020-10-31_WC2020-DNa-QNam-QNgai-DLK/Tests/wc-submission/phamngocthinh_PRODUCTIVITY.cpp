#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define pb push_back
const int N=2e3+5;
int n;
vector <int> Ke[N];
int C[N][N],tr[N],Minn,dd[N],de;
void read()
{
	cin>>n;
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{	int x;
			cin>>x;
			Ke[i].pb(j+n);
		//	Ke[j+n].pb(i);
			C[i][j+n]=x;
		}
	}
}
int DFS(int u)
{
	if(dd[u]==de) return 0;
	dd[u]=de;//if(Minn==3) cout<<u<<endl;
	for(int i=0;i<Ke[u].size();i++)
	{	
		int v=Ke[u][i]; if(C[u][v]<Minn) continue;
//		if(Minn==3) cout<<u<<" "<<v<<" "<<tr[v]<<endl;
		if(tr[v]==0 || DFS(tr[v]))
		{
			tr[v]=u;
			return 1;
		}
	}
	return 0;
}
bool check(int gt)
{
	FOR(i,1,2*n) dd[i]=0;
	FOR(i,1,2*n) tr[i]=0;
	Minn=gt;
	for(de=1;de<=n;de++)
	{
		if(!DFS(de)) 
		{//	if(Minn==3) cout<<de<<endl;
			return false;
		}
	}
	return true;
}
void solve()
{
	int l=1,r=1e9+3,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
//		cout<<mid<<endl;
		if(check(mid)) 
		{
			ans=mid;	
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}
int main()
{
//	freopen("PRODUCTIVITY.inp","r",stdin);
	read();
	solve();
	return 0;
}


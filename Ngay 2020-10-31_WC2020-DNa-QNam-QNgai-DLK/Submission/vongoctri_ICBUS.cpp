#include <bits/stdc++.h>
#define fi "ICBUS.INP"
#define fo "ICBUS.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
const int N=5000+11,	vc=1e9;
int n,m;
int c[N],d[N],L[N],h[N],f[N][N],aa[N][N];
vector <int> a[N];
bool dd[N];
struct cmp
{
	bool operator() (int x, int y)	
	{
		return(x>y);
	}
};
void dijkstra()
{
	For(i,1,n) dd[i]=false;
	For(i,1,n) L[i]=vc;
	L[1]=c[1];
	priority_queue <int, vector<int>, cmp> h;
	h.push(1);
	while(!h.empty())
	{
		int u=h.top(); h.pop();
		if(!dd[u])
		{
			dd[u]=true;
			For(i,0,a[u].size()-1)
			{
				int v=a[u][i];
				if(!dd[v] && L[v]>L[u]+c[u])
				{
					L[v]=L[u]+c[u];
					h.push(v);
				}
			}
		}
	}
}
void DFS(int goc, int u, int x)
{
	if(x==0) return;
	dd[u]=true;
	For(i,0,a[u].size()-1)
	{
		int v=a[u][i];
		if(!dd[v])
		{
			if(aa[goc][v]==0)
			{
				a[goc].push_back(v);	a[v].push_back(goc);	
				aa[goc][v]=1;			aa[v][goc]=1;
			}
			DFS(goc, v, x-1);
		}
	}
}
void build()
{
	For(i,1,n)
	{
		For(j,1,n) dd[j]=false;
		DFS(i,i,d[i]);
	}
	/*
	For(i,1,n)
	{
		cout<<i<<": ";
		For(j,0,a[i].size()-1) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	*/
}
void solve()
{
	build();
	dijkstra();
	cout<<L[n];
}

int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	For(i,1,n) cin>>c[i]>>d[i];
	int u,v;
	For(i,1,m)
	{
		cin>>u>>v;
		a[u].push_back(v);	aa[u][v]=1;
		a[v].push_back(u);	aa[v][u]=1;
	}
	solve();
}

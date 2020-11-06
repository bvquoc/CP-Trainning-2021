#include <bits/stdc++.h>
#define fi "TELMOV.INP"
#define fo "TELMOV.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
const int N=1e6, vc=1e9;
int n,m,p,L,k;
struct tt{int id,ts;};
struct cmp
{
	bool operator() (tt a, tt b)
	{
		return(a.ts>b.ts);
	}
};
vector <tt> a[N];
int d[N];
bool dd[N];
tt w;

void dijkstra()
{
	For(i,1,n) d[i]=vc;
	For(i,1,n) dd[i]=false;
	d[1]=0;
	priority_queue <tt, vector<tt>, cmp> h;
	w.id=1; w.ts=0;	h.push(w);
	while(!h.empty())
	{
		int u=h.top().id; h.pop();
		if(!dd[u])
		{
			dd[u]=true;
			For(i,0,a[u].size()-1)
			{
				int v=a[u][i].id; 
				int cost=a[u][i].ts;
				if(!dd[v] && d[v]>d[u]+cost)
				{
					d[v]=d[u]+cost;
					w.id=v;	w.ts=d[v];
					h.push(w);
				}
			}
		}
		
	}
}

void sub1()
{
	dijkstra();
	cout<<d[n];
}

int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>p>>L>>k;
	int u,v;
	For(i,1,m)
	{
		cin>>u>>v>>w.ts;
		w.id=v; a[u].push_back(w);
		w.id=u; a[v].push_back(w);
	}
	sub1(); //k=0;
}

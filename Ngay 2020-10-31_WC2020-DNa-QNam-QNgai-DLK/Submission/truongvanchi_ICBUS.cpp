#include <bits/stdc++.h>
#define fi "ICBUS.INP"
#define fo "ICBUS.OUT"
#define loop(i,l,r) for(int i=(int)l ; i<=(int)r ; i++)
using namespace std;

struct bg{
	long x,y,value;
};

struct cmp{
	bool operator() (bg a,bg b)
	{
		return a.value>b.value;
	}
};

const int N=5e3+1;

long n,m,dem;
long dd[N],hi[N];
long long d[N];
long ke[N][N];
bg b[N];
vector <bg> g[N];
vector <long> a[N];
priority_queue <bg,vector<bg>,cmp> h;

void doc()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	cin>>n>>m;
	loop(i,1,n) cin>>b[i].x>>b[i].y;
	loop(i,1,m)
	{
		long u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}

void BFS(long s)
{
	queue <long> q;
	q.push(s);
	hi[s]=0;
	
	while (!q.empty())
	{
		long u=q.front();  q.pop();
		dd[u]=1;
		if (!a[u].empty())
			for (int i=0;i<a[u].size();i++)
			{
				long v=a[u][i];
				if (dd[v]==0)
				{
					hi[v]=hi[u]+1;
					q.push(v);
				}
			}
	}
}

void dijkstra(long s)
{
	loop(i,1,n)
	{
		dd[i]=0;
		d[i]=1e9;
	}
	d[s]=0;
	bg w;
	w.x=s; w.value=d[s]; h.push(w);
	while (!h.empty())
	{
		long u=h.top().x; h.pop();
		dd[u]=1;
		if (!g[u].empty())
			for (int i=0;i<g[u].size();i++)
			{
				long v=g[u][i].x;
				long long cost=g[u][i].value;
				if (dd[v]==0)
					if (d[v]>d[u]+cost)
					{
						d[v]=d[u]+cost;
						w.x=v; w.value=d[v]; h.push(w);
					}
			}
	}
}

void xdung()
{
	bg w;
	
	loop(i,1,n)
		loop(j,1,n) ke[i][j]=0;
		
		
	loop(i,1,n)
	{
		dem=0;
		loop(j,1,n)
		{
			dd[j]=0;
			hi[j]=0;
		}
		
		BFS(i);
		
		loop(j,1,n)
		{
			if (j!=i && ke[i][j]==0 && hi[j]<=b[i].y) 
			{
				ke[i][j]=1;
				w.x=j;  w.value=b[i].x;  g[i].push_back(w);
			}
		}
	}
}

void xuly()
{
	xdung();
	dijkstra(1);
	cout<<d[n];
}

int main()
{
	doc();
	xuly();
	return 0;
}

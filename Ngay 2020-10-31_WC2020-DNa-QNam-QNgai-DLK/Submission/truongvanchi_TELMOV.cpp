#include <bits/stdc++.h>
#define fi "TELMOV.INP"
#define fo "TELMOV.OUT"
#define loop(i,l,r) for(int i=(int)l ; i<=(int)r ; i++)
using namespace std;

struct bg{
	long long x,y,value;
};

struct cmp{
	bool operator() (bg a,bg b)
	{
		return a.value>b.value;
	}
};

const int N=1e5;

long n,m,p,l,k;
long long dd[N],d[N];
vector <bg> a[N];
priority_queue <bg,vector<bg>,cmp> h;

void doc()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	cin>>n>>m>>p>>l>>k;
	loop(i,1,m)
	{
		long u,v,gt;
		cin>>u>>v>>gt;
		bg w;
		w.x=v; w.value=gt; a[u].push_back(w);
		w.x=u; w.value=gt; a[v].push_back(w);
	}
}

void dijkstra(long s)
{
	loop(i,1,n)
	{
		d[i]=1e15;
		dd[i]=0;
	}
	d[s]=0;
	bg w;
	w.x=s; w.value=d[s]; h.push(w);
	while (!h.empty())
	{
		long u=h.top().x; h.pop();
		dd[u]=1;
		if (!a[u].empty())
			for (int i=0;i<a[u].size();i++)
			{
				long v=a[u][i].x;
				long long cost=a[u][i].value;
				if (dd[v]==0 && d[v]>d[u]+cost)
				{
					d[v]=d[u]+cost;
					w.x=v; w.value=d[v]; h.push(w);
				}
			}
	}
}

void xuly()
{
	dijkstra(1);
	cout<<d[n];
}

int main()
{
	doc();
	xuly();
	return 0;
}

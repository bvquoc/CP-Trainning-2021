#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int N=1e5+5;
const int vc=2e9;
vector <int> Ke[N],TS[N];
int d[N],k,n,m,p,l,tr[N][15];
bool dd[N];
void read()
{
	cin>>n>>m>>p>>l>>k;// cout<<l<<" "<<p<<endl;
	FOR(i,1,m)
	{	int u,v,c;
		cin>>u>>v>>c;
		Ke[u].push_back(v);Ke[v].push_back(u);
		TS[u].push_back(c);TS[v].push_back(c);
	}
}
void Dijkstra()
{
	FOR(i,1,n) { d[i]=vc; dd[i]=true; }
	d[1]=0;
	priority_queue <ii,vector<ii>,greater<ii> > PQ;
	PQ.push(mp(0,1));
	while(!PQ.empty())
	{
		int u=PQ.top().se; PQ.pop();
		dd[u]=false;
		for(int i=0;i<Ke[u].size();i++)
		{
			int v=Ke[u][i],c=TS[u][i];
			if(dd[v] && d[v]>d[u]+c)
			{
				d[v]=d[u]+c;
				PQ.push(mp(d[v],v));
			}
		}
	}
	cout<<d[n];
}
int main()
{
//	freopen("TELMOV.inp","r",stdin);
	read();
	Dijkstra();
	return 0;
}

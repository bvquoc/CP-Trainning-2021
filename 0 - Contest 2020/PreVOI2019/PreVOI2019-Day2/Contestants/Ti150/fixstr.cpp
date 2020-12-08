#include <bits/stdc++.h>
#define node pair<int, int>

using namespace std;

string s;
vector<int> ln, rn;
vector<node> it;
int root[1000005], m;
int cntupdate=0;
int nodecnt=0;
char type[1000005];
int x[1000005], y[1000005];

pair<int, int> merge(pair<int, int> g, pair<int, int> l)
{
	int ok=min(g.second, l.first);
	return{g.first+l.first-ok, g.second+l.second-ok};
}

void build_tree(int id, int l, int r)
{
	if(l==r)
	{
		if(s[l]==')') it[id]={1, 0};
		else it[id]={0, 1};
		return;
	}
	int mid=(l+r)>>1;
	{
		ln[id]=++nodecnt;
		it[nodecnt]={0, 0};
		ln[nodecnt]=0;
		rn[nodecnt]=0;
		build_tree(ln[id], l, mid);
	}
	{
		rn[id]=++nodecnt;
		it[nodecnt]={0, 0};
		ln[nodecnt]=0;
		rn[nodecnt]=0;
		build_tree(rn[id], mid+1, r);
	}
	it[id]=merge(it[ln[id]], it[rn[id]]);
}

int update(int id, int l, int r, int pos)
{
	if(l==r)
	{
		int newnode=++nodecnt;
		it[newnode]=it[id];
		ln[newnode]=0;
		rn[newnode]=0;
		swap(it[newnode].first, it[newnode].second);
		return newnode;
	}
	int mid=(l+r)>>1, newnode=++nodecnt;
	if(pos>mid)
	{
		ln[newnode]=ln[id];
		rn[newnode]=update(rn[id], mid+1, r, pos);
	}
	else
	{
		ln[newnode]=update(ln[id], l, mid, pos);
		rn[newnode]=rn[id];
	}
	it[newnode]=merge(it[ln[newnode]], it[rn[newnode]]);
	return newnode;
}

pair<int, int> get(int id, int l, int r, int u, int v)
{
	if(l>v||r<u) return {0, 0};
	if(l>=u&&r<=v) return it[id];
	int mid=(l+r)>>1;
	return merge(get(ln[id], l, mid, u, v), get(rn[id], mid+1, r, u, v));
}

signed main()
{
	ios::sync_with_stdio(false);
	freopen("fixstr.inp", "r", stdin);
	freopen("fixstr.out", "w", stdout);
	cin>>s;
	int n=s.size();
	s='!'+s;
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>type[i];
		if(type[i]=='Q')
		{
			cin>>x[i]>>y[i];
		}
		else
		{
			cin>>x[i];
			cntupdate++;
		}
	}
	it.reserve(cntupdate*log2(n)+10*n);
	ln.reserve(cntupdate*log2(n)+10*n);
	rn.reserve(cntupdate*log2(n)+10*n);
	build_tree(0, 1, n);
	// cout<<"works here"<<endl;
	// return 0;
	for(int i=1; i<=m; i++)
	{
		if(type[i]=='C')
		{
			root[i]=update(root[i-1], 1, n, x[i]);
		}
		else if(type[i]=='Q')
		{
			root[i]=root[i-1];
			pair<int, int> doradangyeu=get(root[i], 1, n, x[i], y[i]);
			cout<<doradangyeu.first+doradangyeu.second<<'\n';
		}
		else
		{
			root[i]=root[x[i]-1];
		}
	}
	return 0;
}
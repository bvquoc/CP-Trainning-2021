#include <bits/stdc++.h>

using namespace std;
const string filename = "FIXSTR";

struct Query
{
	char type;
	int x,y;
	Query(){}
}Q[1000001];

string s;
string z[1000001];
int m;

int p[1000001];
int Tree[4000001];
int lazy[4000001];
int inc[1000001];

void build(int node,int l,int r)
{
	if (l == r)
	{
		Tree[node] = p[l];
		return;
	}
	int mi = (l+r)/2;
	build(node*2,l,mi);
	build(node*2+1,mi+1,r);
	Tree[node] = min(Tree[node*2],Tree[node*2+1]);
}

void diffuse(int node,int l,int r)
{
	if (lazy[node])
	{
		Tree[node] += lazy[node];
		if (l != r)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node,int l,int r,int ll,int rr,int val)
{
	diffuse(node,l,r);
	if (r < ll || rr < l)
		return;
	if (ll <= l && r <= rr)
	{
		Tree[node] += val;
		if (l != r)
		{
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return;
	}	
	int mi = (l+r)/2;
	update(node*2,l,mi,ll,rr,val);
	update(node*2+1,mi+1,r,ll,rr,val);
	Tree[node] = min(Tree[node*2],Tree[node*2+1]);
}

int query(int node,int l,int r,int ll,int rr)
{
	diffuse(node,l,r);
	if (r < ll || rr < l)
		return 1e9;
	if (ll <= l && r <= rr)
		return Tree[node];
	int mi = (l+r)/2;
	int a = query(node*2,l,mi,ll,rr);
	int b = query(node*2+1,mi+1,r,ll,rr);
	return min(a,b);
}

void update2(int x,int val)
{
	for(;x<=1000000;x+=x&(-x))
		inc[x] += val;		
}

int query2(int x)
{
	int ans = 0;
	for(;x>0;x-=x&(-x))
		ans += inc[x];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> s;
	int n = s.size();
	s = '*' + s;

	bool sub2 = true;

	cin >> m;
	for (int i=1;i<=m;i++)
	{
		cin >> Q[i].type;
		if (Q[i].type == 'C') cin >> Q[i].x;
		else if (Q[i].type == 'U') 
		{
			sub2 = false;
			cin >> Q[i].x;
		}
		else cin >> Q[i].x >> Q[i].y;
	}	

	if (n <= 1000 && m <= 1000) // Sub 1
	{
      	z[0] = s;
      	for (int i=1;i<=m;i++)
      	{
      		if (Q[i].type == 'C')
      		{
      			if (s[Q[i].x] == '(') s[Q[i].x] = ')';
      			else s[Q[i].x] = '(';
      		}
      		else if (Q[i].type == 'U')
      			s = z[Q[i].x - 1];
      		else
      		{
      			int cur = 0;
      			int ans = 0;
      			for (int j=Q[i].x;j<=Q[i].y;j++)
      			{
      				if (s[j] == '(') cur++;
      				else cur--;
      				if (cur < 0)
      				{
      					cur = 0;
      					ans++;
      				}	
      			}
      			ans += cur;
      			cout << ans << '\n';
      		}
      		z[i] = s;
      	}
	}
	else if (sub2) // Sub 2
	{
     	for (int i=1;i<=n;i++)
     	{
     		p[i] = p[i-1];
     		if (s[i] == '(') p[i]++;
     		else p[i]--;
     	}

     	for (int i=1;i<=4*n;i++)
     		Tree[i] = 1e9;
     	build(1,1,n);
		for (int i=1;i<=m;i++)
     	{
     		char type = Q[i].type;
     		if (type == 'C')
     		{
     			int x = Q[i].x;
     			if (s[x] == '(') 
     			{
     				s[x] = ')';
     				update(1,1,n,x,n,-2);
     				update2(x,-2);
     			}
     			else
     			{
     				s[x] = '(';
     				update(1,1,n,x,n,2);
     				update2(x,2);
     			}					
     		}
     		else
     		{
     			int l = Q[i].x, r = Q[i].y;
     			int pl_1 = p[l-1] + query2(l-1);
     			int z = query(1,1,n,l,r) - pl_1;
     			int pr = p[r] + query2(r);
     			int sum = pr - pl_1;
     			if (z < 0)
     				cout << -z + (sum - z) << '\n';
     			else
     				cout << sum << '\n';					
     		}
     	}
	}
	else // Rip
	{
      	z[0] = s;
      	for (int i=1;i<=m;i++)
      	{
      		if (Q[i].type == 'C')
      		{
      			if (s[Q[i].x] == '(') s[Q[i].x] = ')';
      			else s[Q[i].x] = '(';
      		}
      		else if (Q[i].type == 'U')
      			s = z[Q[i].x - 1];
      		else
      		{
      			int cur = 0;
      			int ans = 0;
      			for (int j=Q[i].x;j<=Q[i].y;j++)
      			{
      				if (s[j] == '(') cur++;
      				else cur--;
      				if (cur < 0)
      				{
      					cur = 0;
      					ans++;
      				}	
      			}
      			ans += cur;
      			cout << ans << '\n';
      		}
      		z[i] = s;
      	}
	}
}
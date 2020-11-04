#include<bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e3+3;
int n, s[N][N];
vector <int> T;
vector<int> a[N];
int p;
int Visited[N];
int Assigned[N];
bool cmp(int a, int b)
{
	return a<b;
}
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
	cin>>s[i][j];
	T.push_back(s[i][j]);
	}
	sort(T.begin(),T.end(),cmp);
}
bool visit(int u,int x)
{
	if(Visited[u]==p)return false;
    Visited[u] = p;
    for (int v=1;v<=n;v++) if(s[u][v]>=x)
	{
        if ((!Assigned[v] || visit(Assigned[v], x))) 
		{
            Assigned[v] = u;
            return true;
        }
    }
    return false;
}

bool check(int x)
{
	int dem=0;
	p=1;
	for(int i=1;i<=n;i++)
	{
		Visited[i]=0;
		Assigned[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		p++;
		dem+=visit(i,x);
	}
	if(dem==n)return true;
	else return false;
}
void xuly()
{
	int l=0,r=n*n-1;
	int ans=0;
	while(l<=r)
	{
		int g=(l+r)/2;
		if(check(T[g]))
		{
			ans=max(ans,T[g]);
			l=g+1;
		}
		else r=g-1;
	}
	cout<<ans;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("PRODUCTIVITY.INP","r",stdin);
//	freopen("PRODUCTIVITY.OUT","w",stdout);
	doc();
	xuly();
	return 0;
}

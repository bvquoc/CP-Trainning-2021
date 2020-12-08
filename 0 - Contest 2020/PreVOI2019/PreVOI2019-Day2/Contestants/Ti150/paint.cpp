#include <bits/stdc++.h>

using namespace std;

int now[30];

vector<int> adj[1000005];
int carry[1000005];
int nodecnt=0;
int painted=0;
int type;
int n;
char ans[1000005];
char ok, ok1;

void dfs(int node, char ch)
{
	ans[carry[node]]=ch;
	for(auto i:adj[node])
	{
		dfs(i, ch);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	freopen("paint.inp", "r", stdin);
	freopen("paint.out", "w", stdout);
	cin>>n;
	for(int i='a'; i<='z'; i++)
	{
		nodecnt++;
		now[i-'a']=nodecnt;
	}
	for(int i=1; i<=n; i++)
	{
		cin>>type;
		if(type==1)
		{
			// cout<<type<<endl;
			painted++;
			cin>>ok;
			if(carry[now[ok-'a']]==0)
			{
				carry[now[ok-'a']]=painted;
			}
			else
			{
				nodecnt++;
				carry[nodecnt]=painted;
				adj[now[ok-'a']].push_back(nodecnt);
			}
		}
		else
		{
			cin>>ok>>ok1;
			adj[now[ok1-'a']].push_back(now[ok-'a']);
			nodecnt++;
			now[ok-'a']=nodecnt;
		}
	}
	// cout<<painted<<endl;
	for(int i='a'; i<='z'; i++)
	{
		dfs(now[i-'a'], (char)(i));
	}
	for(int i=1; i<=painted; i++)
	{
		cout<<ans[i];
	}
	cout<<endl;
}
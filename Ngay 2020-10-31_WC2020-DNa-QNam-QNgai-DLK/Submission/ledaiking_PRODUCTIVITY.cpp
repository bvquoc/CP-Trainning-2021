#include<bits/stdc++.h>
using namespace std;
int w,n;
vector<int> a[1001];
int dd[1001],cha[1001],s[1001][1001];
int dfs (int u)
{
	if (w==dd[u]) return 0;
	dd[u]=w;
	for (auto v:a[u])
	 if (cha[v]==0|| dfs(cha[v]))
	 {
	 	   cha[v]=u;
	 	   return 1;
	 }
	 return 0;
}
bool check(int x)
{
	for (int i=1;i<=n;i++) {
		a[i].clear();
		 dd[i]=0;
		 cha[i]=0;
	}
	 for (int i=1;i<=n;i++) for (int e=1;e<=n;e++) if (s[i][e]>=x) a[i].push_back(e);
	 int m=0; w=1;  
	 for (int i=1;i<=n;i++)
	 {
	 	 m+=dfs(i); w++;
	 }
	 return (m==n);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int i,j,l,r,mid;
	 cin>>n;
	 for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) cin>>s[i][j];
	  l=1; r=1e9; 
	  while (l<=r)
	  {
	  	 mid=(l+r)/2;
	  	 if (check(mid)) l=mid+1; else r=mid-1;
	  }
	  cout<<r;
 } 

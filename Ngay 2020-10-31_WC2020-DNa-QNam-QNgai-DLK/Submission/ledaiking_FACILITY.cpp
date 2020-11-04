#include<bits/stdc++.h>
using namespace std;
long long dp[1000005];
struct luvVy
{
	long long f,s,t;
	bool operator < ( luvVy other)
	{
	 return s<other.s; }
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,k,i,x,y,z,l,r,mid; vector<luvVy> kv;
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
    	cin>>x>>y>>z;
    	 kv.push_back({x,y+k+x,z});
	}
	 sort(kv.begin(),kv.end());
	 dp[1]=kv[0].t;
	 for (i=2;i<=n;i++)
	 {
	 	l=1; r=i;
	 	while (l<=r)
	 	{
	 		mid=(l+r)/2;
	 		if (kv[mid-1].s<=kv[i-1].f) l=mid+1; else r=mid-1;
		 }
		 dp[i]=max(dp[i-1],dp[r]+kv[i-1].t);
	 }
	 cout<<dp[n];
}

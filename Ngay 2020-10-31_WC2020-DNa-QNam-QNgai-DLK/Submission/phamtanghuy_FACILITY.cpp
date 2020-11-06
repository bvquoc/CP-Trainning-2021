#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
long long dp[N];
struct times
{
    int s,e,r;
};
times a[N];
bool cmp(times g,times h)
{
    return g.e<h.e;
}
int findpos(int L, int R, int x)
{
	int ans = 0;
	while (L <= R) {
		int mid = (L+R)/2;
		if (a[mid].e <= x) {
			ans = mid;
			L = mid+1;
		} else
			R = mid-1;
	}
	return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>a[i].s>>x>>a[i].r;
        a[i].e=a[i].s+x;
    }
    sort(a+1,a+n+1,cmp);
   /* for (int i=1;i<=n;i++)
    {
       cout<<a[i].s<<" "<<a[i].e<<" "<<a[i].r<<endl;
    }*/
    dp[1]=a[1].r;
    for (int i=2;i<=n;i++)
    {
        int j=findpos(1,i-1,a[i].s-k);
      //  if (j==-1) continue;
        dp[i]=max(dp[i-1],dp[j]+a[i].r);
    }
    cout<<dp[n];
}

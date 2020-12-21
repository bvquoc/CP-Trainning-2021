#include <bits/stdc++.h>
#define Killian "DECOR"
#define endl "\n"
#define pii pair <int,int>
#define long long long
#define bit(mask,u) (((mask)>>(u))&1)
#define bitcount(mask) __builtin_popcount((mask))
using namespace std;
mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD=1000000007;
const int base=26;
const int arsz=100005;

int n,m,k;
string str;
int s[500005];
int p[500005],d[500005];
pii ans;

void Sub12()
{
    int l=1,r=n,ans=-1;
    int u,v;
    while (l<=r)
    {
        int mid=(l+r)/2;
        bool ok=0;
        for (int i=mid; i<=n; i++)
        {
            int j=i-mid+1;
            int cnt=s[i]-s[j-1];
            if (i-j+1-cnt<=k)
            {
                ok=1;
                u=j,v=i;
                break;
            }
        }
        if (ok)
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    if (ans==-1)
        cout<<-1;
    else
        cout<<u<<" "<<v;
    exit(0);
}
int Find(int u)
{
	if (p[u]==0)
		return u;
	return p[u]=Find(p[u]);
}
void Group(int u, int v)
{
	int x=Find(u);
	int y=Find(v);
	if (x == y)
		return;
	p[x]=y;
}
bool check(int mid)
{
	for (int i=1; i<=n-mid+1; i++)
	{
		int t1=s[i+mid-1]-s[i-1];
		int t[500005];
		int t2=0;
		for (int j=i; j<=i+mid-1; j++)
		{
			int k=Find(j);
			t[k]++;
			if (t[k]==1)
				t2+=d[k];
			if (str[j]=='1')
				t2--;
		}
		if (t1+k+t2>=mid)
		{
			ans.first=i;
			ans.second=i+mid-1;
			return 1;
		}
	}
	return 0;
}
void Sub3()
{
	int l=1,r=n,res;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid))
        {
            res=mid;
			l=mid+1;
        }
		else
			r=mid-1;
	}
	cout<<ans.first<<" "<<ans.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>n>>m>>k;
    cin>>str;
    str=' '+str;
    for (int i=1; i<=n; i++)
        s[i]=s[i-1]+(str[i]=='1');
    for (int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        Group(x,y);
    }
	for (int i = 1; i <= n; i++)
		if (str[i]=='1')
			d[Find(i)]++;
    if (m==0)
        Sub12();
    Sub3();
}

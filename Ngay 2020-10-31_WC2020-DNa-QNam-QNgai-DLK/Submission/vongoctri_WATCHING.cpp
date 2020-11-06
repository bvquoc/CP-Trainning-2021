#include <bits/stdc++.h>
#define fi "WATCHING.INP"
#define fo "WATCHING.OUT"
#define For(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
const int N=1e6;
int n,m,k,t;
struct tt{int gt; char c;};
tt a[N];

bool dk(tt x, tt y)
{
	return(x.gt<y.gt);
}
void solve()
{
	sort(a,a+n+1,dk);
	long long resa=0;
	long long resb=0;
	char c='A';
	int i=0;
	while(a[i].gt < t && i<=n)
	{
		if(c=='A')
		{
			if(a[i+1].c == 'A') 
			{
				c='B'; resa+=a[i+1].gt-a[i].gt; i++;
			}
			else i++;
		}
		else
		{
			if(a[i+1].c == 'B') 
			{
				c='A'; resb+=a[i+1].gt-a[i].gt; i++;
			}
			else i++;
		}
	}
	cout<<resa<<" "<<resb;
}
int main()
{
//	freopen(fi,"r",stdin);
//	freopen(fo,"w",stdout);
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>t>>k;
	For(i,1,n)
	{
		cin>>a[i].gt;			a[i].c='A';
		a[n+i].gt=a[i].gt+k; 	a[n+i].c='B';
	}
	n=n+n;
	For(i,1,m)
	{
		cin>>a[i+n].gt;				a[i+n].c='B';
		a[n+m+i].gt=a[i+n].gt+k;	a[n+m+i].c='A';
	}
	n=n+m+m;
	a[0].gt=0; 		a[0].c='A';
	solve();	
}

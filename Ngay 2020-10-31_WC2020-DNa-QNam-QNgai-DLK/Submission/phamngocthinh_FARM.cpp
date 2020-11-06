#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)

int n,k,q,p,r,cnt=0;
int F[10005][10005],a[10005],C[10005];
bool dd[10005];
void read()
{
	cin>>n>>k>>q>>p;
	FOR(i,1,n) cin>>a[i];
}
void TV(int i,int j)
{
//	cout<<i<<" "<<j<<endl;
	if(i==1 && F[i][j]!=F[i][j-1])
	{
		dd[j]=true;
		return;
	}
	if(F[i][j]==F[i-1][j-k]+a[j]) 
	{
		dd[j]=true;
		TV(i-1,j-k);
	}
	else TV(i,j-1);
}
bool cmp(int aa,int bb)
{
	return aa>bb;
}
void solve()
{
	FOR(i,1,n) dd[i]=false;
	vector <int> g;
	int res=0,vt,ans=-1e9,cur;
	r=(q/p)+1;
	if(q%p==0) r--;
	FOR(i,1,n) 
	{
		F[1][i]=max(F[1][i-1],a[i]);
	}
	FOR(i,2,r)
	{	
		FOR(j,1,n)
		{	F[i][j]=F[i][j-1];
			if(j-k>0) F[i][j]=max(F[i-1][j-k]+a[j],F[i][j-1]);
//			cout<<i<<" : "<<j<<"  "<<F[i][j]<<endl;
		}
	//	cout<<F[i][n]<<endl;	
		if(ans<F[i][n]) 
		{
			ans=F[i][n]; vt=i;
		}
	}
//	cout<<F[vt][n]<<" ";
	TV(vt,n);
	FOR(i,1,n) if(dd[i]) g.push_back(a[i]);
	sort(g.begin(),g.end(),cmp);
//	for(int i=0;i<g.size();i++) cout<<g[i]<<" ";
//	cout<<q<<" "<<p<<endl;
	for(cur=0;cur<min(q/p,vt);cur++) res=res+g[cur]*p;
//	cout<<res<<endl;
	if(q%p!=0) res=res+g[cur]*(q-(q/p)*p);
	cout<<res;
}
int main()
{
//	freopen("FARM.inp","r",stdin);
	read();
	solve();
	return 0;
}

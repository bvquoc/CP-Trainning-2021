#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
struct edge
{
	int next,other;
}e[N];
int n,q,tot,head[N],x,y,f[20][N],dfn[N],cnt,fr[N],dep[N],L[N],size,sola=0;
set<int> A;
bool vis[N];
void add(int x,int y)
{
	e[++tot].next=head[x];head[x]=tot;e[tot].other=y;
}
void dfs(int u)
{
	vis[u]=1;dfn[++cnt]=u;fr[u]=cnt;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].other;
		if (!vis[v])
		{
			dep[v]=dep[u]+1;
			dfs(v);dfn[++cnt]=u;
		}
	}
}
int Get(int x){int ans=0;while (x>>1){x>>=1;ans++;}return ans;}
int cmp(int x,int y){
	if(dep[x]<dep[y]){
		return x;
	}
	return y;
}
int cmp1(int x,int y){
	if(dep[x]<dep[y]){
		return y;
	}
	return x;
}
void prepare()
{
	int t=L[cnt];
	for(int i=1;i<=cnt;i++) f[0][i]=dfn[i];
	for(int i=1;i<=t;i++)
		for(int j=1;j+(1<<i)-1<=cnt;j++) f[i][j]=cmp(f[i-1][j],f[i-1][j+(1<<(i-1))]);
}
int Getlca(int x,int y){
	x=fr[x],y=fr[y];if (x>y) swap(x,y);
	int t=L[y-x+1];
	return cmp(f[t][x],f[t][y-(1<<t)+1]);
}
int Getdistlca(int x,int y)
{
	x=fr[x],y=fr[y];if (x>y) swap(x,y);
	int t=L[y-x+1];
	return min(dep[f[t][x]],dep[f[t][y-(1<<t)+1]]);
}
int Dis(int x,int y)
{
	return dep[x]+dep[y]-Getdistlca(x,y)*2;
}
pair<int,int> Count(int x)
{
	set<int>::iterator nxt=A.upper_bound(fr[x]);
	int a,b;
	pair<int,int> ans;
	if (nxt==A.end())
	{
		a=dfn[*A.begin()];nxt--;
		b=dfn[*nxt];
		ans.first=(Dis(x,a)+Dis(x,b)-Dis(a,b))/2;
	}
	else if (nxt==A.begin())
	{
		a=dfn[*nxt];
		b=dfn[*(--A.end())];
		ans.first=(Dis(x,a)+Dis(x,b)-Dis(a,b))/2;
	}
	else
	{
		a=dfn[*nxt];nxt--;
		b=dfn[*nxt];
		ans.first=(Dis(x,a)+Dis(x,b)-Dis(a,b))/2;
	}
	ans.second=cmp1(cmp1(Getlca(a,b),Getlca(a,x)),Getlca(x,b));
	return ans;
}
int VirtualDelete(int x){
	if(!A.count(fr[x])){
		return 0;
	}
	int nowsize=size,nowsola=sola;
	A.erase(fr[x]);
	if(A.size()<=1){
		sola=A.size();
		size=0;
	}
	else{
		pair<int,int> ahaha=Count(x);
		int val=ahaha.first,ver=ahaha.second;
		size-=val;
	}
	int ans;
	if(size!=nowsize){
		ans=1;
	}
	else{
		ans=0;
	}
	sola=nowsola,size=nowsize;	
	return ans;
}
void Add(int x)
{
	if(A.size()<=1){
		sola++;
		size=0;
		if(!A.size()){
			A.insert(fr[x]);
		}
		else{
			int ver=dfn[*A.begin()];
			size+=Dis(ver,x);
			A.insert(fr[x]);
		}
		return;
	}
	pair<int,int> ahaha=Count(x);
	int val=ahaha.first,ver=ahaha.second;
	size+=val;
	if(val){
		sola++;
		sola-=VirtualDelete(ver);
	}
	A.insert(fr[x]);
}
void Delete(int x)
{
	A.erase(fr[x]);
	if(A.size()<=1){
		sola=A.size();
		size=0;
		return;
	}
	pair<int,int> ahaha=Count(x);
	int val=ahaha.first,ver=ahaha.second;
	size-=val;
	if(val){
		sola--;
		sola+=VirtualDelete(ver);
	}
}
bool mark[N];
int main(){
	freopen("SOCKS.inp","r",stdin);
	freopen("SOCKS.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int col;
		cin>>col;
		mark[i]=col;
	}
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n*2;i++) L[i]=Get(i);
	dfs(1);
	prepare();
	for(int i=1;i<=n;i++) if(mark[i]) Add(i);
	cout<<(sola==1?0:(sola+1)/2)<<'\n';
	for(int i=1;i<=q;i++){
		int j;
		cin>>j;
		if(mark[j]){
			Delete(j);
			mark[j]=false;
		}
		else{
			Add(j);
			mark[j]=true;
		}
		cout<<(sola==1?0:(sola+1)/2)<<'\n';
	}
}
/*
7 14
0 0 0 0 0 0 0 
1 2
2 3
2 4
2 5
2 6
2 7
1 2 3 4 5 6 7 6 2 4 5 7 1 3
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
#define forinc(a,b,c) for(int a=b;a<=c;++a)
#define fordec(a,b,c) for(int a=b;a>=c;--a)
#define forv(a,b) for(auto &a:b)
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define task "construct"
const int N=1e5+5;
int n,m,a[N];
struct node{
	int val,lazy;
};
node it[4*N];
int hieu[4*N];
void trans(int i,int l,int r){
	if(l==r) return;
	if(it[i].lazy){
		int mid=l+(r-l)/2,val=it[i].lazy;
		it[2*i].val+=val*(mid-l+1);
		it[2*i+1].val+=val*(r-mid);
		it[2*i].lazy+=val;
		it[2*i+1].lazy+=val;
		it[i].lazy=0;
	}
}
void upd(int i,int l,int r,int u,int v,int val){
	if(v<l||u>r) return;
	if(u<=l&&r<=v){
		it[i].val+=val*(r-l+1);
		it[i].lazy+=val;
		return;
	}
	int mid=l+(r-l)/2;
	trans(i,l,r);
	upd(2*i,l,mid,u,v,val);
	upd(2*i+1,mid+1,r,u,v,val);
	it[i].val=it[2*i].val+it[2*i+1].val;
}
void Upd(int i,int l,int r,int pos,int val){
	if(pos<l||pos>r) return;
	if(pos==l&&pos==r){
		hieu[i]=val;
		return;
	}
	int mid=l+(r-l)/2;
	Upd(2*i,l,mid,pos,val);
	Upd(2*i+1,mid+1,r,pos,val);
	hieu[i]=hieu[2*i]+hieu[2*i+1];
}
int get(int i,int l,int r,int u,int v){
	if(v<l||u>r) return 0;
	if(u<=l&&r<=v) return hieu[i];
	int mid=l+(r-l)/2;
	return get(2*i,l,mid,u,v)+get(2*i+1,mid+1,r,u,v);
}
int ge(int i,int l,int r,int u,int v){
	if(v<l||u>r) return 0;
	if(u<=l&&r<=v) return it[i].val;
	int mid=l+(r-l)/2;
	trans(i,l,r);
	return ge(2*i,l,mid,u,v)+ge(2*i+1,mid+1,r,u,v);
}
main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	int test;
	cin>>test;
	while(test--){
		cin>>n>>m;
		forinc(i,1,4*n){
			it[i].val=0,it[i].lazy=0,hieu[i]=0;
		}
		forinc(i,1,n) cin>>a[i];
		forinc(i,1,n){
			Upd(1,1,n,i,max(0ll,a[i]-a[i-1]));
			upd(1,1,n,i,i,a[i]);
		}
		while(m--){
			int type,u,v,val;
			cin>>type>>u>>v;
			if(type==1){
				cin>>val;
				upd(1,1,n,u,v,val);
				int cur=ge(1,1,n,u,u),pre=ge(1,1,n,u-1,u-1);
				Upd(1,1,n,u,max(0ll,cur-pre));
				if(v<n){
					cur=ge(1,1,n,v,v),pre=ge(1,1,n,v+1,v+1);
					Upd(1,1,n,v+1,max(0ll,pre-cur));
				}
			}
			else{
				cout<<get(1,1,n,u,v)-get(1,1,n,u,u)+ge(1,1,n,u,u)<<'\n';
			}
		}
	}
}

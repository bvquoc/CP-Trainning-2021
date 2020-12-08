#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
const int LOG=32;
const int inf=1e9+7;
int ver[N],now=0,sum1,min2;
string s;
struct node{
	int sum=0,min1=0,lch,rch;
};
node it[N*LOG];
void build_it(int idx,int l,int r){
	if(l==r){
		if(s[l-1]=='('){
			it[idx].sum=it[idx].min1=1;
		}
		else{
			it[idx].sum=it[idx].min1=-1;
		}
		return;
	}
	int mid=(l+r)>>1;
	now++;
	it[idx].lch=now;
	build_it(it[idx].lch,l,mid);
	now++;
	it[idx].rch=now;
	build_it(it[idx].rch,mid+1,r);
	it[idx].sum=it[it[idx].lch].sum+it[it[idx].rch].sum;
	it[idx].min1=min(it[it[idx].lch].min1,it[it[idx].lch].sum+it[it[idx].rch].min1);
}
void upd(int idx,int l,int r,int pos,int old_idx){
	if(l==r){
		it[idx].sum=it[idx].min1=-it[old_idx].sum;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid){
		now++;
		it[idx].lch=now;
		it[idx].rch=it[old_idx].rch;
		upd(now,l,mid,pos,it[old_idx].lch);
	}
	else{
		now++;
		it[idx].lch=it[old_idx].lch;
		it[idx].rch=now;
		upd(now,mid+1,r,pos,it[old_idx].rch);
	}
	it[idx].sum=it[it[idx].lch].sum+it[it[idx].rch].sum;
	it[idx].min1=min(it[it[idx].lch].min1,it[it[idx].lch].sum+it[it[idx].rch].min1);
}
void get_val(int idx,int l,int r,int lef,int rig){
	if(l>rig||r<lef){
		return;
	}
	if(l>=lef&&r<=rig){
		min2=min(min2,sum1+it[idx].min1);
		sum1=sum1+it[idx].sum;
		return;
	}
	int mid=(l+r)>>1;
	get_val(it[idx].lch,l,mid,lef,rig);
	get_val(it[idx].rch,mid+1,r,lef,rig);
}
signed main(){
	freopen("FIXSTR.inp","r",stdin);
	freopen("FIXSTR.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q,n,i,j,k,l;
	cin>>s;
	now++;
	ver[0]=now;
	n=s.size();
	char x;
	build_it(ver[0],1,n);
	cin>>q;
	for(i=1;i<=q;i++){
		cin>>x;
		if(x=='C'){
			cin>>j;
			now++;
			ver[i]=now;
			upd(ver[i],1,n,j,ver[i-1]);
		}
		if(x=='Q'){
			ver[i]=ver[i-1];
			sum1=0;
			min2=inf;
			cin>>j>>k;
			get_val(ver[i],1,n,j,k);
			if(min2<0){
				cout<<sum1-2*min2<<'\n';
			}
			else{
				cout<<sum1<<'\n';
			}
		}
		if(x=='U'){
			cin>>j;
			ver[i]=ver[j-1];
		}
	}
}
/*
((()))
10
C 1 
Q 2 5
C 5
Q 1 6
U 3
C 4
Q 3 6
U 5
C 1
Q 1 5
*/

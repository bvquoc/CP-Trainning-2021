#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node{
	int val, open, close, lef, rig;
} st[25*N];
int n,q,pos,l,r,cnt,qver,las[N],ver[N];
string s;
char type;
//IT
node merge(node a,node b){
	node res;
	int tmp = min(a.open, b.close);
	res.val = a.val + b.val + tmp*2;
	res.open = a.open + b.open - tmp;
	res.close = a.close + b.close - tmp;
	return res;
}
int build(int l,int r){
	if(l == r){
		cnt++; int cur = cnt;
		if(s[l] == '('){
			st[cur].open = 1;
			st[cur].close = 0;
		}else{
			st[cur].open = 0;
			st[cur].close = 1;
		}
		st[cur].val = st[cur].lef = st[cur].rig = 0;
		return cur;
	}
	int mid = (l + r) >> 1;
	cnt++; int cur = cnt;
	int nodeL = build(l, mid);
	int nodeR = build(mid+1, r);
	st[cur] = merge(st[nodeL], st[nodeR]);
	st[cur].lef = nodeL; st[cur].rig = nodeR;
	return cur;
}
int update(int old,int l,int r,int i){
	if(l == r){
		cnt++; int cur = cnt;
		st[cur].open = (st[old].open ^ 1);
		st[cur].close = (st[old].close ^ 1);
		st[cur].val = st[cur].lef = st[cur].rig = 0;
		return cur;
	}
	int mid = (l + r) >> 1;
	cnt++; int cur = cnt;
	if(i <= mid){
		int nodeL = update(st[old].lef, l, mid, i);
		int nodeR = st[old].rig;
		st[cur] = merge(st[nodeL], st[nodeR]);
		st[cur].lef = nodeL; st[cur].rig = nodeR;
	}else{
		int nodeL = st[old].lef;
		int nodeR = update(st[old].rig, mid+1, r, i);
		st[cur] = merge(st[nodeL], st[nodeR]);
		st[cur].lef = nodeL; st[cur].rig = nodeR;
	}
	return cur;
}
node get(int id,int l,int r,int i,int j){
	if(l>j || r<i || i>j){
		return {0, 0, 0, 0, 0};
	}
	if(l>=i && r<=j){
		return st[id];
	}
	int mid = (l + r) >> 1;
	return merge(get(st[id].lef, l, mid, i, j), get(st[id].rig, mid+1, r, i, j));
}
//main
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("FIXSTR.inp","r",stdin);
	freopen("FIXSTR.out","w",stdout);
	cin >> s;
	n = s.length(); s = " " + s;
	cnt = 0; qver++;
	ver[qver] = build(1, n);
	las[0] = qver; 
	cin >> q;
	for(int i=1;i<=q;i++){
		cin >> type;
		if(type == 'C'){
			cin >> pos;
			qver++;
			ver[qver] = update(ver[las[i-1]], 1, n, pos);
			las[i] = qver;
		}
		if(type == 'Q'){
			cin >> l >> r;
			node tmp = get(ver[las[i-1]], 1, n, l, r);
			las[i] = las[i-1];
			cout << r - l + 1 - tmp.val << "\n";
		}
		if(type == 'U'){
			cin >> pos;
			las[i] = las[pos-1];
		}
	}
}

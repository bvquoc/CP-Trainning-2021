#include<bits/stdc++.h>
#define qwer "fixstr"

using namespace std;
const int maxn = 1e6 + 3;
string s;
int n;

struct node
{
	int val,lim,last;
	node() {}
	node(int _a,int _b,int _c) : val(_a),lim(_b),last(_c){}	
	friend ostream&operator << (ostream& s,const node&v)
	{
		s << v.val <<" " << v.lim <<" " << v.last ;
		return s;
	}
};
node operator + (const node&a,const node&b)
{
	node ans;
	ans.val = a.val + b.val;
	ans.lim = min(a.last + b.lim,a.lim);
	ans.last = a.last + b.last;
	return ans;
	//node(0) = 0,0,0
}

template<int sze> struct Eins
{
	vector<node> st;
	Eins() {st.resize(sze);}
	void build(int id,int l,int r)
	{
		if (l == r) {
			if (s[l-1] == '(') st[id] = node(1,0,1);
			else st[id] = node(-1,-1,-1);
			return;
		}
		int mid = l + r >> 1;
		build(id << 1,l,mid);
		build(id << 1|1,mid+1,r);
		st[id] = st[id << 1] + st[id << 1|1];
	}
	void update(int id,int l,int r,int pos)
	{
		if (l > pos || r < pos) return;
		if (l == r) {
			if (st[id].val == 1) st[id] = {-1,-1,-1};
			else st[id] = {1,0,1};
			return ;
		}
		int mid = l + r >> 1;
		update(id << 1,l,mid,pos);
		update(id << 1|1,mid+1,r,pos);
		st[id] = st[id << 1] + st[id << 1|1];
	}
	node get(int id,int l,int r,int L,int R)
	{
		if (l > R || r < L) return node(0,0,0);
		if (L <= l && r <= R) return st[id];
		int mid = l + r >> 1;
		return get(id << 1,l,mid,L,R) + get(id << 1|1,mid+1,r,L,R);
	}
	int get(int L,int R)
	{
		node ans = get(1,1,n,L,R);
		return ans.val - 2 * ans.lim;
	}
};
Eins<maxn << 2> Tree;

int main()
{
	if (fopen(qwer".inp","r")) freopen(qwer".inp","r",stdin),freopen(qwer".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> s >> m;
	n = s.size();
	if (n <= 1000 && m <= 1000) {
		vector<string> save;
		save.emplace_back(s);
		while (m--) {
			char ch;
			cin >> ch;
			if (ch == 'C') {
				int pos;
				cin >> pos;
				--pos;
				if (s[pos] == ')') s[pos] = '(';
				else s[pos] = ')';
			}
			else if (ch == 'Q') {
				int l,r;
				cin >> l >> r;
				int Min = 0,t = 0;
				--l;
				for (int i = l ;i < r;++i) {
					if (s[i] == '(') ++t;
					else --t;
					Min = min(Min,t);
				}
				cout << t - 2 * Min <<"\n";
				// -Min + (t - Min)
			}
			else {
				int pos;cin >> pos;
				assert(pos);
				s = save[--pos];
			}
			save.emplace_back(s);
		}
	}
	else {
		Tree.build(1,1,n);
		while (m--) {
			char ch;
			int l;
			cin >> ch >> l;
			if (ch == 'C') Tree.update(1,1,n,l);
			else {
				int r;
				cin >> r;
				cout << Tree.get(l,r) <<"\n";
			} 
		}
	}
}

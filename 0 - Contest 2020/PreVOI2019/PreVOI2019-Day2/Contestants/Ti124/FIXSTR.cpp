#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
#define ll int
#define ii int
struct node {
	ll l=0;
	ll r=0;
	ll temp=0;
	ll minn=0;
	ll ln=0;
	ll rn=0;
};
ll aa[1000001], statt[21], ti[21], inn[11], outt[11], i, j, k, t, n, m, cur = 0, minn, a, b, adj;
vector<node> st; node h;
char  c;
string s[1000001];
ll abs (ll x)
{
	if (x<0) x=-x;
	return x;
}
ll buildTree(ll l, ll r)
{
	st.push_back(h);
	ll res=st.size()-1,mid=(l+r)/2;
	st[res].l=l;
	st[res].r=r;
	if (l==r) {
		st[res].minn=aa[l]; return res;
	}
	ll x=buildTree(l,mid);
	ll y=buildTree(mid+1,r);
//	cout<<x<<' '<<y<<endl;
	st[res].ln=x;
	st[res].rn=y;
	ll a=st[st[res].ln].minn;
	ll b=st[st[res].rn].minn;
	if (a<b) st[res].minn=a; else st[res].minn=b;
	return res;
}
void flusha(ll cn)
{
//	cout<<"flusha"<<cn<<"\n";
	st[st[cn].ln].temp+=st[cn].temp;
	st[st[cn].rn].temp+=st[cn].temp;
	st[st[cn].ln].minn+=st[cn].temp;
	st[st[cn].rn].minn+=st[cn].temp;
	st[cn].temp=0;
}
void upd(ll l, ll r, ll cn, ll diff)
{
//	cout<<"upd\n";
	if ((l<=st[cn].l)and(r>=st[cn].r))
	{
		st[cn].minn+=diff;
		st[cn].temp+=diff;
	}
	else if ((r<st[cn].l)or(l>st[cn].r)) return;
	else
	{
		flusha(cn);
		upd(l,r,st[cn].ln,diff);
		upd(l,r,st[cn].rn,diff);
	ll a=st[st[cn].ln].minn;
	ll b=st[st[cn].rn].minn;
	if (a<b) st[cn].minn=a; else st[cn].minn=b;
	}
}
ll query(ll l, ll r, ll cn)
{
	
//	cout<<"query"<<st[cn].ln<<st[cn].rn<<cn<<"\n";
	if ((l<=st[cn].l)and(r>=st[cn].r))
	{
		return st[cn].minn;
	}
	else if ((r<st[cn].l)or(l>st[cn].r)) return 1000000001;
	else
	{
		flusha(cn);
		ll a=query(l,r,st[cn].ln);
		ll b=query(l,r,st[cn].rn);
		if (a<b) return a; else return b;
	}
}
int main()
{
	freopen("FIXSTR.INP", "r", stdin);
	freopen("FIXSTR.OUT", "w", stdout);
	cin >> s[0];
	n = s[0].length();
	cin >> m;
	if ((n * m <= 1000000))
	{
		for (i = 1; i <= m; i++)
		{
		
			s[i] = s[i - 1];
		cin >> c;
		if (c == 'U') { cin >> a; s[i] = s[a - 1]; }
		else if (c == 'C') { cin >> a; a--;  if (s[i][a] == '(') s[i][a] = ')'; else s[i][a] = '('; }
		else { cin >> a >> b;
		a--; b--;
		cur = 0; minn = 1000000001;
		for (j = a; j <= b; j++) { if (s[i][j] == '(') cur++; else cur--;  if (cur < minn) minn = cur; }
		k = abs(cur);
		if (minn < 0) k -= 2*minn;
		cout << k << endl;
		}
		}
	}
	else
	{
		aa[0]=0;
		i=0;
		cur=0;
		for (j = 0; j < n; j++) { if (s[i][j] == '(') cur++; else cur--;  aa[j+1]=cur; }
		k=buildTree(1,n);
		for (i = 1; i <= m; i++)
		{
		
		cin >> c;
		if (c == 'U') { return 0; }
		else if (c == 'C') { cin>>a; if (s[0][a-1]=='(') {upd(a,n,k,-2); s[0][a-1]=')';} else {upd(a,n,k,2); s[0][a-1]='(';} }
		else { cin >> a >> b; k=0;
		minn=query(a,b,k);
		cur=query(b,b,k);
		if (a>1) {
			adj=query(a-1,a-1,k);
			minn-=adj;
			cur-=adj;
		}
		k = abs(cur);
		if (minn < 0) k -= 2*minn;
		cout << k << endl;
		}
		}
	}
	fclose(stdin);
	fclose(stdout);
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

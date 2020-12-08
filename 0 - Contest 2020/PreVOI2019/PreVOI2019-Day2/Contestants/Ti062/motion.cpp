#include<bits/stdc++.h>
#define qwer "motion"
#define x first
#define y second
using namespace std;

using Q = pair<long double,long double>;
istream & operator >> (istream&s,Q&x)
{
	s >> x.first >> x.second;
	return s;
}

ostream & operator << (ostream&s,Q&x)
{
	s << x.first <<" " << x.second;
	return s;
}

Q operator + (const Q&a,const Q&b)
{
	return {a.first + b.first,a.second + b.second};
}

int main()
{
	if (fopen(qwer".inp","r")) freopen(qwer".inp","r",stdin),freopen(qwer".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	const long double can = 1e-12;
	while (q--) {
		int n,m;
		vector<Q> a(2),b(2),direct(2);
		cin >> n >> m ;
		for (int i = 0;i < 2;++i) cin >> a[i] >> b[i];
		int div = abs(a[0].x - b[0].x) * abs(a[0].y - b[0].y) * abs(a[1].x - b[1].x) * abs(a[1].y - b[1].y) * 4;		
		for (int i = 0;i < 2;++i) {
			direct[i] = {(b[i].first - a[i].first) / div,(b[i].second - a[i].second) / div};
		}
		auto change = [&](int i,int type)
		{
			if (type == 1) {
				direct[i].second = -direct[i].second;
			}
			else {
				direct[i].first = -direct[i].first;
			}
		};
		int ans = -1;
		for (int i = 1;i <= div * 4544;++i) {
			for (int j = 0;j < 2;++j) {
			//	cout << a[j] <<" ";
				a[j] = a[j] + direct[j];
				if (a[j].first <= can|| abs(a[j].first - n) <= can) change(j,0);
				if (a[j].second <= can || abs(a[j].second - m) <= can) change(j,1);
			//	cout << direct[j] << " | ";
			}
			//cout << endl;
			if (abs(a[0].first - a[1].first) <= can && abs(a[0].second - a[1].second) <= can) {
				ans = i;
				break;
			}
		}
		if (ans == -1) cout << "-1\n";
		else {
			int gg = __gcd(ans,div);
			ans /= gg;
			div /= gg;
			cout << ans <<" " << div <<"\n";
		}
	}
}

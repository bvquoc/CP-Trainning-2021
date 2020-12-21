#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define pii pair<int,int>
#define st first
#define nd second
using namespace std;
const int N = 1e5+1;
int m, n, T = N;
vector<int> ke[N];
int main()
{
	freopen("coolmac.inp","r",stdin);
	freopen("coolmac.out","w",stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> m;
    forinc(i, 1, m)
    {
    	int l, r;
    	cin >> l >> r;
    	ke[l].push_back(r);
    }
    cin >> n;
    forinc(i, 1, n)
    {
    	int t; cin >> t;
    	T = min(T, t);
    }
	priority_queue<int> heap;
	forinc(t, 0, T-1)
		for(int r:ke[t]) heap.push(r);
	int cur = 0, cnt = 0;
	for(int t = T; t<N; t++)
	{
		for(int r:ke[t]) heap.push(r);
		if(cur < t)
		{
			if(heap.empty()) return cout << -1,0;
			cur = heap.top();
			if(cur < t) return cout << -1,0;
			cnt++;
		}
	}
	cout << cnt;
}
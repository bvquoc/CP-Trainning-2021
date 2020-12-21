#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define all(x) begin(x), end(x)
#define vi vector<int> 
#define eb emplace_back
#define ii pair<int, int> 
#define fi first
#define se second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define bitCnt __builtin_popcountll

const int inf = INT_MAX / 2, maxTemp = 1e5, maxN = 1e5 + 5;

int N, M, minTemp = inf, nowH = -1, potH = -1; // nowH is the maximum protected range, potH is the maximum prtceted range if you buy 1 more
vi High[maxN];
int cost;
signed main()
{
	freopen("COOLMAC.inp", "r", stdin);
	freopen("COOLMAC.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M;
	loop(i, 1, M)
	{
		int low, high;
		cin >> low >> high;
		High[low].eb(high);
	}
	cin >> N;
	loop(i, 1, N)
	{
		int t;
		cin >> t;
		minTemp = min(minTemp, t);
	}
	nowH = minTemp - 1; 
	loop(temp, 0, maxTemp)
	{
		for(int high: High[temp])
		{
			potH = max(potH, high);
		}
		if(temp > nowH)
		{
			if(potH < temp)
			{
				return cout << -1, 0;
			}
			else 
			{
				cost++;
				nowH = potH;
			}
		}
	}
	cout << cost;
}
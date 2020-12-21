#include<bits/stdc++.h>

using namespace std;

#define int long long

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define vi vector<int> 
#define eb emplace_back
#define all(x) begin(x), end(x)
#define ii pair<int, int> 
#define fi first
#define se second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define bitCnt __builtin_popcountll

#define iii pair<int, ii> 

const int maxN = 2e5 + 5, mod = 1e9 + 7;

int N, A[maxN], B[maxN], sumInv[maxN], fac[maxN], smlPer[maxN];
void madd(int &a, int b)
{
	a = (a + b) % mod;
}
struct bit
{
	vi arr = vi(maxN, 0);
	void add(int i, int val)
	{
		while(i <= N)
		{
			arr[i] += val;
			i += i & -i;
		}
	}
	int get(int i)
	{
		int re = 0;
		while(i)
		{
			madd(re, arr[i]);
			i -= i & -i;
		}
		return re;
	}
};
int dup(int i) // i * (i - 1) / 2 mod
{
	return i % 2 == 0? i / 2 * (i - 1) % mod: (i - 1) / 2 * i % mod;
}
int solveSml(int per[])
{
	int re = 0;
	bit Sml;
	rloop(pos, N, 1)
	{
		int val = per[pos];
		if(pos == N) smlPer[pos] = 0;
		else
		{
			int sml = Sml.get(val - 1);
			smlPer[pos] = (smlPer[pos + 1] + sml * fac[N - pos] % mod) % mod;
		}
		Sml.add(val, 1);
	}
	loop(pos, 1, N)
	{
		int val = per[pos];
		int sml = Sml.get(val - 1);
		madd(re, sumInv[N - pos] * sml % mod + dup(sml) * fac[N - pos] % mod);
		if(pos < N) madd(re, sml * smlPer[pos + 1] % mod);
		Sml.add(val, -1);
	}
	return re;
}

int solve(int per[])
{
	int re = 0;
	bit Sml;
	loop(i, 1, N)
	{
		Sml.add(i, 1);
	}
	loop(pos, 1, N)
	{
		int val = per[pos];
		int sml = Sml.get(val - 1);
		madd(re, sml);
		Sml.add(val, -1);
	}
	return re;
}
void prep()
{
	loop(i, 0, N)
	{
		fac[i] = !i? 1: fac[i - 1] * i % mod;
	}
	loop(sz, 1, N)
	{
		if(sz == 1)
		{
			sumInv[sz] = 0;
		}
		else 
		{
			sumInv[sz] = (sumInv[sz - 1] * sz % mod + fac[sz - 1] * dup(sz) % mod) % mod; 
		}
	}
}
signed main()
{
	freopen("PERMEOW.inp", "r",stdin);
	freopen("PERMEOW.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	prep();
	loop(pos, 1, N) cin >> A[pos];
	loop(pos, 1, N) cin >> B[pos];
	int ans = solveSml(B) - solveSml(A) + solve(B);
	while(ans < 0) madd(ans, mod);
	cout << ans;
}
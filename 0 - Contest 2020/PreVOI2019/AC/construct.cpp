#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <random>
#include <queue>
#include <stack>

using namespace std;

#define For(i, a, b) for (int i = a, _b = b; i <= _b; ++i)
#define Ford(i, a, b) for (int i = a, _b = b : i >= _b; --i)
#define Rep(i, n) for (int i = 0, _n = n; i < _n; ++i)
#define sz(A) ((int)A.size())
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)

typedef pair<int, int> pt;

const int N = 1e6 + 10;

struct
{
	int n;
	long long b[N];
	void build(int nn)
	{
		this->n = nn;
		fill(b, b + n + 3, 0);
	}
	void add(int x, int v)
	{
		while (x <= n)
		{
			b[x] += v;
			x += x & -x;
		}
	}
	long long get(int x)
	{
		long long ans = 0;
		while (x)
		{
			ans += b[x];
			x -= x & -x;
		}
		return ans;
	}
} mBit, segBit;
struct
{
	long long w[N];
	void build(int nn)
	{
		fill(w, w + nn + 4, 0);
		segBit.build(nn);
	}
	void add(int pos, int val)
	{
		long long contribute = max(0LL, w[pos]);
		segBit.add(pos, -contribute);
		w[pos] += val;
		contribute = max(0LL, w[pos]);
		segBit.add(pos, contribute);
	}
	long long get(int l, int r)
	{
		if (l > r)
			return 0;
		return segBit.get(r) - segBit.get(l - 1);
	}
} mSeg;

int a[N];
long long get(int l, int r)
{
	return a[l] + mBit.get(l) + mSeg.get(l + 1, r);
}
int main()
{

	freopen("construct.inp", "r", stdin);
	freopen("construct.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test;
	while (test--)
	{
		int n = 1e5, m = 1e5;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		mSeg.build(n);
		mBit.build(n);
		for (int i = 1; i <= n; i++)
			mSeg.add(i, a[i] - a[i - 1]);
		while (m--)
		{
			int type, L, R, k;
			cin >> type >> L >> R;
			if (type == 1)
			{
				cin >> k;
				mSeg.add(L, k);
				mSeg.add(R + 1, -k);
				mBit.add(L, k);
				mBit.add(R + 1, -k);
			}
			else
			{
				cout << get(L, R) << '\n';
			}
		}
	}

	return 0;
}

#include <iostream>
#include <fstream>
#include <vector>

#define endl '\n'
#define int ll
#define file "SOCKS"

using namespace std;

typedef long long ll;

ifstream fi(file".inp");
ofstream fo(file".out");
int n, q, Pos[500001], A[500001];
vector<int> Adj[500001];
bool IsRed[500001], Checked[500001];

void sub1()
{
	for (int u = 1; u <= n; u++)
		if (Adj[u].size() == 1)
		{
			Pos[u] = 1;
			int cnt = 1;
			do
			{
				Checked[u] = 1;
				for (int v: Adj[u])
					if (!Checked[v])
					{
						u = v;
						Pos[u] = ++cnt;
						break;
					}
			} while (Adj[u].size() == 2);
			break;
		}
	for (int i = 1; i <= n; i++) A[Pos[i]] = i;
	int l, r;
	for (l = 1; l <= n && !IsRed[A[l]]; l++);
	for (r = n; r > 0 && !IsRed[A[r]]; r--);
	int res = 0;
	for (int i = l; i <= r; i++) res += !IsRed[A[i]];
	// cout << l << ' ' << r << endl << res << endl;
	while (q--)
	{
		int x;
		fi >> x;
		IsRed[x] ^= 1;
		if (l < Pos[x] && Pos[x] < r)
		{
			if (IsRed[x]) res--;
			else res++;
		}
		else
		{
			x = Pos[x];
			if (x == l)
			{
				for (; l <= n && !IsRed[A[l]]; l++) res--;
				res++;
			}
			else
				if (x == r)
				{
					for (; r > 0 && !IsRed[A[r]]; r--) res--;
					res++;
				}
				else
					if (x < l)
					{
						res += l-x-1;
						l = x;
					}
					else
					{
						res += x-r-1;
						r = x;
					}
		}
		fo << res << endl;
	}
	// cin.get();
}

signed main()
{
	fi >> n >> q;
	for (int i = 1; i <= n; i++) fi >> IsRed[i];
	for (int i = 1; i < n; i++)
	{
		int u, v;
		fi >> u >> v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	bool isSub1 = 1;
	for (int i = 1; i <= n; i++)
		if (Adj[i].size() > 2)
		{
			isSub1 = 0;
			break;
		}
	if (isSub1) return sub1(), 0;
}
/*
((_,...,_))    
   |o o|
   \   /
    ^_^   
*/

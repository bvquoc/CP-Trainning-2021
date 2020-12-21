#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>

#define endl '\n'
#define int ll
#define file "COOLMAC"

using namespace std;

typedef long long ll;

const int LIM = 1e5;

ifstream fi(file".inp");
ofstream fo(file".out");
int m, n, L[LIM+1], R[LIM+1], Tree[LIM+1];

void update(int pos, int val)
{
	for (int i = pos; i > 0; i -= i&(-i)) Tree[i] = min(Tree[i], val);
}

int get(int pos)
{
	int res = INT_MAX;
	for (int i = pos; i <= LIM; i += i&(-i)) res = min(res, Tree[i]);
	return res;
}

signed main()
{
	fi >> m;
	for (int i = 1; i <= m; i++) fi >> L[i] >> R[i];
	int minn = INT_MAX;
	fi >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		fi >> x;
		minn = min(minn, x);
	}
	
	fill(Tree, Tree+LIM+1, LIM);
	for (int i = 1; i <= m; i++) update(R[i], L[i]);
	int res = 0, l = LIM;
	while (l > minn)
	{
		int nL = get(l);
		if (nL == l)
		{
			res = -1;
			break;
		}
		l = nL;
		res++;
	}
	fo << res;
}
/*
((_,...,_))    
   |o o|
   \   /
    ^_^   
*/

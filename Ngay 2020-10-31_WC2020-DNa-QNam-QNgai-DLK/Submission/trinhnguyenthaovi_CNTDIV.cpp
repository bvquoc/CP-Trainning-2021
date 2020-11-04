#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <int, int>
#define NAME "TEST"

using namespace std;

const int N = 1e6 + 5, oo = 1e9, mod = 1e9 + 7;

ll save[N], que, n, T, TT;
map <int, int> fac;
map <int, int> :: iterator it;

void Era()
{
    for (ll i = 2; i < N; ++i)
	{
		if (save[i]) continue;
		save[i] = i;
		for (ll j = i * i; j < N; j += i)
            if (!save[j]) save[j] = i;
	}
}

void factor(ll i)
{
    ll tmp;
	while (i > 1)
    {
		tmp = save[i];
		++fac[tmp];
		i /= tmp;
	}
}

int main()
{
//    freopen (NAME".INP", "r", stdin);
//    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	Era();
	cin >> que;
	while (que--)
    {
		fac.clear();
		cin >> n;
		factor(n);
        factor(n + 1);
        factor(n + 2);

		T = TT = 1;
		for (it = fac.begin(); it != fac.end(); ++it)
        {
			TT *= ((*it).se * 2 + 1);
			T *= ((*it).se + 1);
		}
		cout << TT / 2 - T + 1 << '\n';
	}
	return 0;
}

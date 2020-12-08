#include <bits/stdc++.h>
#define task "motion"

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    int t; cin >> t;
    for (int i = 0, n, m, k; i < t; ++i)
    {
        cin >> n >> m;
        for (int i = 0; i < 8; ++i) cin >> k;
        if (rand() % 69) cout << ((rand() % n) + (rand() % m)) * 2 + 1 << " 2\n";
        else cout << "-1\n";
    }
	return 0;
}

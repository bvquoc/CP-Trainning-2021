#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Int k;
	cin >> k;
	if (k == 0) return cout << 0, 0;
	int lim = sqrt(abs(k));
	const Int oo = 1e18;
	Int answer = oo;
	for (int x = 1; x <= lim; x++) if ((k % x) == 0) {
		Int big = abs(k) / x;
		Int small = k / big;
		if ((big + small) % 2) continue;
		Int a = (big + small) / 2;
		Int n = big - a;
		if (a >= 0 and n >= 0) answer = min(answer, a);
	}
	if (answer == oo) cout << "none";
	else cout << answer;
}

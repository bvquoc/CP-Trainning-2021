#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <int, int>
#define NAME "TEST"

using namespace std;

const int N = 5e3 + 5, oo = 1e9, mod = 1e9 + 7;

int n, K, Q, P, a[N]; /// gieo Q hạt, n ngày, <= P hạt/ ngày, cách ít nhất K ngày
int result, f[N][N];

int brute (int i, int sum)
{
    if (i > n) return 0;
    if (sum == Q) return 0;

	int &res = f[i][sum];
	if (res != -1) return res;
	res = -oo;

	res = max (res, brute (i + 1, sum));
	for (int k = 1; k <= min (P, Q - sum); ++k)
        res = max (res, brute (i + K, sum + k) + a[i] * k);

	return res;
}

void sub1 ()
{
    result = -oo;
    memset (f, -1, sizeof(f));
    result = max (result, brute (1, 0));
    cout << result;
    return;
}

int main()
{
//    freopen (NAME".INP", "r", stdin);
//    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> K >> Q >> P;
	for (int i = 1; i <= n; ++i) cin >> a[i];
    sub1 ();

    return 0;
}

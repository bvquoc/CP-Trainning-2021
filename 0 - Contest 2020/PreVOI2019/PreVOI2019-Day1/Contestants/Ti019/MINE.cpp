#include<bits/stdc++.h>

#define M 1000003
#define maxn 400005

using namespace std;
typedef long long ll;

int n, m;
int a[maxn];

ll d[maxn];

ll gt[maxn], igt[maxn];

ll power(ll a, ll b){
	if (b == 0) return 1;
	ll tg = power(a, b / 2);
	if (b % 2 == 0) return (tg * tg) % M;
	return (tg * ((tg * a) % M) ) % M;
}

void ktao(){
	gt[0] = 1;
	ll n = 4e5;
	for (ll i = 1; i <= n; ++i)
		gt[i] = (i * gt[i - 1]) % M;
	igt[n] = power(gt[n], M - 2);
	for (ll i = n - 1 ; i >= 0; --i)
		igt[i] = (igt[i + 1] * (i + 1)) % M;
}

ll C(ll n, ll k){
	return (gt[n] * ((igt[k] * igt[n - k]) % M) ) % M;
}

ll Val(ll n){
    if (n == 0) return 1;
    return (C(n, n / 2) * (igt[n / 2 + 1] * gt[n / 2] % M)) % M;
}

void solve1(){
    d[0] = 1;
    for (int i = 1, j = 0; i <= n; i += 2){
        while (j + 2 <= n && a[j + 2] - a[i] <= m) j += 2;

        for (int k = i + 1; k <= j; ++k)
            d[k] = (d[k] + d[i - 1] * Val(k - i - 1) % M) % M;
    }

    cout << d[n];
}

int main(){
    #define TASK "MINE"
    freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ktao();
    cin >> n >> m;

    n *= 2;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    //if (n <= 4000)
    if (a[n] - a[1] <= m) cout << Val(n);
    else solve1();
    //else solve2();

    return 0;
}

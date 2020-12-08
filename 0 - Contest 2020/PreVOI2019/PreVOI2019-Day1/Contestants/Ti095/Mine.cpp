#include <bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int, int>
#define X first
#define Y second
#define a(i, j) aa[(i - 1) * N + j]  

using namespace std;

const int oo = 1e18;
const int eps = 1e-9;
const int MOD = 1e6 + 3;

int N, M, RES;
int A[1000000], save[1000000];
int res[1000000];
deque <ii> qu;

int POW(int a, int n){
	if (n == 0) return 1;
	if (n == 1) return a % MOD;
	int p = POW(a, n / 2) % MOD;
	if (n % 2 == 0) return (p * p) % MOD;
	else return ((p * p) % MOD * (a % MOD)) % MOD;
}

void SL(){
	int s = 0;
	for (int i = 1; i <= 2 * N; ++i){
		s += res[i];
	}
	if (s != N) return;

	while (!qu.empty()) qu.pop_front();

	bool ok = 1;
	for (int i = 1; i <= 2 * N; ++i){
		if (!qu.empty() && qu.back().Y < A[i]){
			ok = 0;
			break;
		}

		if (res[i]){
			qu.push_front(ii(A[i], A[i] + M));
			continue;
		}

		if (!qu.empty() && !res[i]){
			qu.pop_front();
		}
	}
	if (!qu.empty()) ok = 0;
	RES += ok;
	RES %= MOD;
}

void TRY(int x){
	for (int i = 0; i <= 1; ++i){
		res[x] = i;
		if (x == 2 * N) SL();
		else TRY(x + 1);
	}
}

void slow(){
	TRY(1);
	cout << RES % MOD;
	exit(0);
}

main() {  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Mine.inp", "r", stdin);
    freopen("Mine.out", "w", stdout);
    	cin >> N >> M;
    	for (int i = 1; i <= 2 * N; ++i){
    		cin >> A[i];
    	}
    	if (N <= 10) slow();
    	cout << POW(2, 2 * N) % MOD;
}	

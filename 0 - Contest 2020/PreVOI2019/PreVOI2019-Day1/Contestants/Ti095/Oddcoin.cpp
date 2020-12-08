#include <bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int, int>
#define FI first
#define SE second
#define a(i, j) aa[(i - 1) * N + j]  

using namespace std;

const int oo = 1e18;
const int eps = 1e-9;

int Q, X, T;
int save[500000];
int f[10000010];
int A[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};

int  solve(int sum){
	if (sum == T) return 0;
	if (save[sum] != -1) return save[sum];
	int cur = oo;

	if (sum + X <= T)
		cur = min(cur, solve(sum + X) + 1);

	for (int i = 0; i < 15; ++i){
		if (sum + A[i] <= T)
			cur = min(cur, solve(sum + A[i]) + 1);
	}

	return save[sum] = cur;
}


void sub1(){
	for (int i = 0; i <= T; ++i){
		save[i] = -1;
	}
	cout << solve(0) << '\n';
}

void sub2(){
	for (int i = 0; i <= T; ++i){
		f[i] = 0;
	}
	for (int i = 1; i <= T; ++i){
		int tmp = oo;

		if (i - X >= 0)
				tmp = min(tmp, f[i - X] + 1);

		for (int j = 0; j < 15; ++j){
			if (i - A[j] >= 0)
				tmp = min(tmp, f[i - A[j]] + 1);
		}

		f[i] = tmp;
	}
	cout << f[T] << '\n';
}

vector <int> v;

void sub3(){
	while (!v.empty()) v.pop_back();
	v.push_back(X);
	for (int i = 0; i < 15; ++i){
		v.push_back(A[i]);
	}
	sort(v.begin(), v.end());

	int t = T, s = 0;
	for (int i = v.size() - 1; i >= 0; --i){
		if (t >= v[i]){
			s += (t / v[i]);
			t -= (t / v[i]) * v[i];
		}
		if (!t) break;
	}
	cout << s << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Oddcoin.inp", "r", stdin);
    freopen("Oddcoin.out", "w", stdout);
    	cin >> Q;
    	while (Q--){
    		cin >> X >> T;
    		if (X <= 20 && T <= 20) sub1();
    		else if (T <= 10000000) sub2();
    			else 
    				sub3();
    	}
}

#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 500;
int divs[maxN];
void sieve(int n) {
	divs[0] = divs[1] = 0;
	for (int p = 2; p <= n; p++) if (!divs[p])
		for (int mul = p; mul <= n; mul += p) divs[mul] = p;
}

int exponent[maxN];
set<int> base;
void factorize(int n, int* expo, int direct) {
	while (divs[n] > 0) {
		int p = divs[n];
		for (; n % p == 0; n /= p) expo[p] += direct;
		base.insert(p);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve(maxN - 1);
	int nTests; 
	cin >> nTests;
	for (int n; nTests --> 0; ) {
		cin >> n;
		base.clear();
		factorize(n, exponent, +2);
		factorize(n + 1, exponent, +2);
		factorize(n + 2, exponent, +2);
		long long answer = 1;
		for (int p : base) {
			answer *= (long long) (exponent[p] + 1);
			exponent[p] = 0;
		}
		answer /= 2;
		long long add = 1;
		factorize(n, exponent, +1);
		factorize(n + 1, exponent, +1);
		factorize(n + 2, exponent, +1);
		for (int p : base) {
			add *= (long long) (exponent[p] + 1);
			exponent[p] = 0;
		}		
		answer -= add - 1;
		cout << answer << "\n";
	}
}

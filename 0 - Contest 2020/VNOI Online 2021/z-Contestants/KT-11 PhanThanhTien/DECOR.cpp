#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
// using namespace __gnu_pbds;

#define PI (2*acos(0));
#define sqr(x) ((x) * (x))
#define pb push_back
#define l first
#define r second
typedef long long ll;
typedef pair<int, int> pii;

template<typename T>void maximize(T &a, T b) {if (a < b) a = b;}
template<typename T>void minimize(T &a, T b) {if (a > b) a = b;}
template<typename T1, typename T2> T1 power(T1 a, T2 b) {if (b == 1) return a; T1 t = power(a, b / 2); return (b & 1 ? t * t * a : t * t);}


const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int m, n, k;
string s; 


void sub1() { // 10% score
	int l = 0, r = 0, l_curr = 0;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == '0' || i == n) {
			if (r - l < i - 1 - l_curr) {
				l = l_curr; r = i - 1;
			}

			l_curr = i + 1;
		}
	}

	cout << l + 1 << ' ' << r + 1;
}

void sub2() { // 15% score
	int ansL = 0, ansR = -1;
	for (int l = 0, r = 0, cnt0 = 0; r < n; ++r) {
		if (s[r] == '0') ++cnt0;
		while (cnt0 > k) {
			if (s[l++] == '0') --cnt0;
		}

		if (ansR - ansL < r - l) ansR = r, ansL = l; 
	}

	cout << ansL + 1 << ' ' << ansR + 1;
}


int main() {
	freopen("DECOR.inp", "r", stdin);
	freopen("DECOR.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	cin >> s;

	// BASE_CASE
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {flag = false; break;}
	}
	if (flag == true && k == 0) {cout << -1; return 0;}

	if (m == 0 && k == 0) sub1();
	else if (m == 0) sub2();

	cout << -1;

	return 0;
} 
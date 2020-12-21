#include<bits/stdc++.h>
using namespace std;

//Variables
const int mxN = 5e5 + 5;
const int MOD = 1e9 + 7;
const long long oo = 1e18;
const int d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const int d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

int TestCase , SubTask;
int n , m , k , lans , rans , l , r , mid , mx , len;
int prefix[mxN];
string s;

void sub12() {
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + (s[i] == '0');	
	for (int i = 1; i <= n; i++) {
		l = i;
		r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (prefix[mid] - prefix[i - 1] <= k) {
				l = mid + 1;
				if (mid - i + 1 > mx) {
					mx = mid - i + 1;
					lans = i;
					rans = mid;
				}
			}		
			else r = mid - 1;
		}
	}
	if (!lans) {
		cout << -1;
		exit(0);
	}
	cout << lans << " " << rans << "\n";
	exit(0);
}

void sub3() {
	cout << -1;
	exit(0);	
}

void Solve() {
//	cin >> SubTask;
	cin >> n >> m >> k;
	cin >> s;
	len = s.size();
	s = "#" + s;
	if (!m) sub12();
	else sub3();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("DECOR.INP" , "r" , stdin);
	freopen("DECOR.OUT" , "w" , stdout);
//	cin >> TestCase;
	TestCase = 1;
	while(TestCase--)
		Solve();
	return 0;
}




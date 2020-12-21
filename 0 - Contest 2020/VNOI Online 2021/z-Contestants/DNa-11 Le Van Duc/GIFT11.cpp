#include<bits/stdc++.h>
using namespace std;

//Variables
const int mxN = 2000 + 5;
const int MOD = 1e9 + 7;
const long long oo = 1e18;
const int d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const int d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

int TestCase , SubTask;
long long n , answer;
int a[mxN] , digits[mxN] , rv[20] , even[mxN] , odd[mxN];
bool alleven , allodd;
bool used[mxN];
vector<int> path;

void count(int x , int num) {
	int cnt = 0;
	while (x) {
		rv[++cnt] = x % 10;
		x /= 10;
	}
	digits[num] = cnt;
	
	for (int i = 1; i <= cnt; i++) if (i % 2 == 0) even[num] += rv[i];
	else odd[num] += rv[i];
	return;
}

void dq(int idx) {
	if (idx > n) {
		// tie = false => start at odd 
		// tie = true => star at even
		
		bool tie = false;
		long long sum = 0;
		
		for (auto num : path) {
			if (!tie) sum = sum + odd[num] - even[num];
			else sum = sum + even[num] - odd[num];
			
			if (!tie) {
				if (digits[num] % 2 == 1) tie = true;
			}
			else {
				if (digits[num] % 2 == 1) tie = false;
			}
		}
		if (sum % 11 == 0) answer++;
		if (answer >= MOD) answer -= MOD;
		return;
	}
	for (int i = 1; i <= n; i++) if (!used[i]) {
		used[i] = true;
		path.push_back(i);
		dq(idx + 1);
		used[i] = false;
		path.pop_back();
	}	
}

void Solve() {
	alleven = allodd = true;
//	cin >> SubTask;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		odd[i] = even[i] = 0;
		count(a[i] , i);
		if (digits[i] % 2 == 1) alleven = false;
	}
	answer = 0;
	dq(1);
	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("GIFT11.INP" , "r" , stdin);
	freopen("GIFT11.OUT" , "w" , stdout);
	cin >> TestCase;
//	TestCase = 1;
	while(TestCase--)
		Solve();
	return 0;
}




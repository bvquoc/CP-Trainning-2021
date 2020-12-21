///link:
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(), x.end()
#define ll long long
const int maxn = 1 + 2222;
const ll mod = 998244353;
const int inf = (1 << 30);

int n;
vector <string> vt;

namespace sub1 {

int a[10];
int b[10];
bool odd[11];
int ans = 0;
bool vis[11];

bool check () {
	int even = 1, du = 0;
	for (int i = 0; i < n; ++i) {
//		cout << a[b[i]] << " ";
    if (even) {
			du += a[b[i]];
			du %= 11;
    }
    else {
			du -= a[b[i]];
			du += 11;
			du %= 11;
    }
    if (even && odd[b[i]]) even = 0;
    else if (!even && odd[b[i]]) even = 1;
	}
	if (du % 11 == 0) {
		return 1;
	}
	return 0;
}

void Try (int l	) {
	if (l == n) {
		if (check()) ++ans;
    return ;
	}
  for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
      vis[i] = 1;
      b[l] = i;
      Try(l + 1);
      vis[i] = 0;
		}
  }
}
/// -1 odd, 1 even
void run() {
	ans = 0;
	for (int i = 0; i < n; ++i) {
		vis[i] = odd[i] = b[i] = 0;
	}
  for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int foo = 1, du = 0;
		for (auto u : s) {
			du += foo * (u - '0');
			foo *= -1;
		}
		du = (du + 99) % 11;
		a[i] = du;
		odd[i] = (foo == -1 ? 1 : 0);
  }
	Try(0);
  cout << ans << '\n';
}

}


int main()
{
	#define Task "gift11"
	if (fopen(Task".inp", "r"))
	freopen(Task".inp", "r", stdin), freopen(Task".out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	int Test;
	cin >> Test;
	while (Test --) {
		cin >> n;
		sub1::run();
	}


   return 0;
}

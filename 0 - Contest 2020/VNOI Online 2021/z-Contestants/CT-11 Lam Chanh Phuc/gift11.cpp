/**
      11  11   000000   111111
      11 11       00    111111
      1111       00       11
      11 11     00        11
      11  11   000000     11     **/


#include<bits/stdc++.h>

#define bug(a) cout<< #a << ": " << a << endl;
#define bug2(a, b) cout<< #a << ": " << a << ", " << #b << ": " << b << endl;
#define bugarr(a, i, j) cout<< #a << "{" << i << "..." << j << "}: "; fto(k, i, j-1) cout<< a[k] << ", "; cout<< a[j] << endl;
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d %d", &a, &b)
#define pril(a) printf("%d\n", a)
#define pris(a) printf("%d ", a)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define all(x) (x).begin(), (x).end()
#define oo 998244353
#define maxN 18
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)

using namespace std; 

int a[maxN][4], b[maxN], ans, n, avail[maxN];
ll f[2008];

void solve(int i) {
	if (i > n) {
		int le = 0;
		int chan = 0;
		int len = 0;
		fto(j, 1, n) {
			if (len&1) {
				le += a[b[j]][0];
				chan += a[b[j]][1];
			}
			else {
				le += a[b[j]][1];
				chan += a[b[j]][0];
			}
			len += a[b[j]][2];		
		}
		ans += ((le-chan)%11 == 0);
		return;
	}

	fto(j, 1, n) {
		if (avail[j] == 1) {
			b[i] = j;
			avail[j] = 0;
			solve(i+1);
			avail[j] = 1;
		}
	}
}

ll gt(ll n) {
	if (n == 0) return 1;
	if (f[n] != 0) return f[n];
	ll res = (gt(n-1)*n)%oo;
	return f[n] = res;
}

void solve1() {
	int le = 0;
	int chan = 0;
	fto(i, 1, n) {
		le += a[i][1];
		chan += a[i][0];
	}
	if ((le-chan)%11 == 0) cout << gt(n) << '\n';
	else cout << "0\n";
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);
    #endif

    fast;
    int t;
    cin >> t;
    while(t--) {
	   	cin >> n;
	   	int ok = 1;
	    fto(i, 1, n) {
	    	int x;
	    	cin >> x;
	    	int len = log10(x)+1;
	    	if (len&1) ok = 0;
	    	a[i][2] = len;
	    	int vt = (len&1)?1:0;
	    	a[i][0] = 0;
	    	a[i][1] = 0;
	    	while(x > 0) {
	    		a[i][vt] += x%10;
	    		x/=10;
	    		vt = 1-vt;
	    	}
	    }
	    ans = 0;
	    fto(i, 1, n) avail[i] = 1;
	    if (ok) solve1();
	    else {
	    	solve(1);
	    	cout << ans << '\n';
	    }
	}
  
    return 0;
}

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
#define oo 1000000007
#define maxN 
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)

using namespace std; 

void bfs() {
	ll t = 0;
	fto(i, 1, n) {
		a[i] = i;
		t += a[i]*mu[i-1];
	}

	trace[t] = 1;
	while(!q.empty()) {
		
	}
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);
    #endif

    fast;
    cin >> n;
    mu[0] = 1;
    fto(i, 1, n) mu[i] = mu[i-1]*10; 
    fto(i, 1, n) {
    	cin >> a[i];
    }
    fto(i, 1, n) {
    	cin >> b[i];
    }

    bfs();
  
    return 0;
}

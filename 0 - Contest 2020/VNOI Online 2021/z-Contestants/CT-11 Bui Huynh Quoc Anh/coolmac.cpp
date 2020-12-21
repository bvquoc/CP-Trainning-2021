#include<bits/stdc++.h>
#define bug(a) cout<< #a << ": " << a << endl;
#define bug2(a, b) cout<< #a << ": " << a << ", " << #b << ": " << b << endl;
#define bugarr(a, i, j) cout<< #a << "{" << i << "..." << j << "}: "; fto(k, i, j-1) cout<< a[k] << ", "; cout<<a[j] << endl;
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
#define maxN 100005
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)
using namespace std; 

int b[maxN], n, m, pos;
ii p[maxN];

int cmp(ii a, ii b) {
	return a.ss < b.ss;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    #endif

    sci(m);
    pos = 0;
    int k = 0;
    fto(i, 1, m) {
    	scii(p[i].ff, p[i].ss);
    }
    sort(p+1, p+m+1);
    int mn = oo;
    sci(n);
    fto(i, 1, n) {
    	int x; sci(x);
    	mn = min(mn, x);
    }
    int ans = 0;
    int i = 0;
    fto(j, 1, m) {
    	if (p[j].ff <= mn && p[j].ss >= mn) {
    		if (p[j].ss > p[i].ss) i = j;
    	}
    }
    ++ans;
    int ok = 0;
    while (i < m) {
    	priority_queue<ii> q;
    	int j = i+1;
    	while (p[j].ff <= p[i].ss) {
    		q.push(mp(p[j].ss, j));
    		++j;
    	}
    	if (q.empty()) {
    		ok = 0;
    		break;
    	}
    	ii u = q.top();
    	i = u.ss;
    	++ans;
    	if (p[i].ss == 100000) {
			ok = 1;
    		break;
    	}
    }
    ans = (ok == 0) ? -1 : ans;
    cout << ans << '\n';

    return 0;
}
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
#define maxN 100008
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)

using namespace std; 

struct sth {
	int gt, id, tp;
};

sth a[maxN*3];
ii b[maxN];
int n, m;

bool cmp(sth a, sth b) {
	if (a.gt < b.gt) return 1;
    if (a.gt > b.gt) return 0;
    return a.tp < b.tp;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    #endif
  
    fast;
    cin >> m;
    int cnt = 0;
    fto(i, 1, m) {
    	int l, r;
    	cin >> l >> r;
    	b[i] = mp(l, r);
    	a[i*2].id = i;
    	a[i*2-1].id = i;
    	a[i*2].gt = l;
    	a[i*2-1].gt = r;
    	a[i*2].tp = 0;
    	a[i*2-1].tp = 1;
    	if (r == 100000) {
    		++cnt;
    	}
    }
    if (cnt == 0) {
        cout << "-1\n";
        return 0;
    }

    sort(a+1, a+m*2+1, cmp);

    cin >> n;
    int level = oo;
    fto(i, 1, n) {
    	int x; cin >> x;
    	level = min(level, x);
    }

    int target = oo;
    int vt;
    fdto(i, 2*m, 2*m-cnt+1) {
    	if (target > b[a[i].id].ff) {
    		target = b[a[i].id].ff;
    		vt = a[i].id;
    	}
    }

    if (target <= level) {
        cout << "1\n";
        return 0;
    }

    priority_queue<ii> q;
    int fault = 0;
    int ans = 1;
    fdto(i, 2*m-cnt, 1) {
    	if (a[i].tp == 0 && a[i].id == vt) {
    		int vtcu = vt;
    		if (!q.empty()) vt = q.top().ss;
    		if (vt == vtcu || -q.top().ff >= b[vtcu].ff) {
    			fault = 1;
    			break;
    		}
    		else {
                ++ans;
                if (-q.top().ff <= level) break;
    			while(!q.empty()) q.pop();
    		}
    	}
    	if (a[i].id != vt && a[i].tp == 1) {
    		q.push(mp(-b[a[i].id].ff, a[i].id));
    	}
    }

    if (fault == 0) cout << ans << '\n';
    else cout << "-1" << '\n';

    return 0;
}

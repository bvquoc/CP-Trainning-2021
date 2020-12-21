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
#define maxN 500005
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)
using namespace std; 

int n, m, q;
int heavy[maxN], parent[maxN], depth[maxN], a[maxN], head[maxN], dd[maxN];
vi ke[maxN];

int caydfs(int u) {
	int res = 1, size_c = 0, max_c = 0;
	heavy[u] = -1;
	fto(i, 0, sz(ke[u])-1) {
		int v = ke[u][i];
		if (parent[u] != v) {
			parent[v] = u;
			depth[v] = depth[u] +1;
			size_c = caydfs(v);
			if (size_c > max_c) {
				heavy[u] = v;
				max_c = size_c;
			}
		}
		size_c += res;
	}
	return res;
}

void hld(int u, int h) {
	head[u] = h;
	if (heavy[u] != -1) hld(heavy[u], h);
	fto(i, 0, sz(ke[u])-1) {
		int v = ke[u][i];
		if (parent[u] != v && heavy[u] != v) hld(v, v);
	}
}

int tk(int x, int h) {
	while (head[x] != h) {
		x = parent[x];
	}
	return x;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);
    #endif

    scii(n, q);
    fto(i, 1, n) sci(a[i]);
    fto(i, 1, n-1) {
    	int u, v; scii(u, v);
    	ke[u].pb(v);
    	ke[v].pb(u);
    }

    caydfs(1);
    hld(1, 1);
    int ans = 0;
    fto(i, 1, n) dd[i] = -oo;
    int temp = oo;
    fto(i, 1, n) if (a[i]) {
    	if (dd[head[i]] == -oo) ++ans;
    	dd[head[i]] = max(dd[head[i]], depth[i]);
    	//bug(depth[i]);
    }
    //bugarr(dd, 1, n);
    int start = 0;
    fto(i, 1, n) {
    	if (dd[i] == -oo) continue;
    	if (temp > dd[i]) {
    		temp = dd[i];
    		start = i;
    	}
    }
    //bug2(temp, start);
    //bug(ans);
    fto(i, 1, n) {
    	if (a[i]) {
    		if (head[i] != start) {
    			int x = tk(i, start);
    			//bug(x);
    			//bug2(depth[x], temp);
    			if (depth[x] >= temp) --ans;
    		}
    	}
    }
    cout << ans << '\n';
    
   // return 0;
    fto(t, 1, q) {
    	int x; sci(x);
    	a[x] = 1-a[x];
    	int ans = 0;
    fto(i, 1, n) dd[i] = -oo;
    int temp = oo;
    fto(i, 1, n) if (a[i]) {
    	if (dd[head[i]] == -oo) ++ans;
    	dd[head[i]] = max(dd[head[i]], depth[i]);
    	//bug(depth[i]);
    }
    //bugarr(dd, 1, n);
    int start = 0;
    fto(i, 1, n) {
    	if (dd[i] == -oo) continue;
    	if (temp > dd[i]) {
    		temp = dd[i];
    		start = i;
    	}
    }
    //bug2(temp, start);
    //bug(ans);
    fto(i, 1, n) {
    	if (a[i]) {
    		if (head[i] != start) {
    			int x = tk(i, start);
    			//bug(x);
    			//bug2(depth[x], temp);
    			if (depth[x] >= temp) --ans;
    		}
    	}
    }
    cout << ans << '\n';
    
    }

    return 0;
}
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

int n, m, k, l;
int ans ,res;
int b[maxN], avail[maxN], d[maxN], visited[maxN], dd[10], dn[maxN];
int a1[1003][1003];
vi a[maxN];
vector<ii > ke[maxN];


int check() {
	res = 0;
	int dem = 0;
	fto(i, 1, k) dd[i] = 0;
	fto(i, 2, n) {
		if (a1[b[i-1]][b[i]] == 0 || a1[b[i-1]][b[i]] == oo) {
			return 0;
		}
	}
	//bugarr(b, 1, n);
	fto(i, 1, n) {
		if (i != 1) {
			if (a1[b[i-1]][b[i]] == 0 || a1[b[i-1]][b[i]] == oo) return 0;
			//bug2(b[i-1], b[i]);
			res += a1[b[i-1]][b[i]];
			//bug(res);
		}
		fto(j, 0, sz(a[b[i]])-1) {
			if (!dd[a[b[i]][j]]) ++dem;
			dd[a[b[i]][j]] = 1;
		}
		//bug(b[i]);
		//bug2(i, dem);
		if (dem >= l) {
			//bug(i);
			fto(i1, 1, n) visited[i1] = 0;
			fto(i1, 0, n) d[i1] = oo;
		   	d[b[i]] = 0; 
		   	while (1) {
		   		int u = 0;
		   		fto(i1, 1, n) {
		   			if (d[u] > d[i1] && visited[i1] == 0) u = i1;
		   		}
		   		if (u == 0) break;
		   		visited[u] = 1;
		   		fto(v, 1, n) {
		   			d[v] = min(d[v], d[u] + a1[u][v]);
		   		}
		   	}
		   //	bug(d[n]);
		   	res += d[n];
		   	return 1;
		}
	}
	return (dem >= l);
}

void sinhnp(int pos) {
	if (pos > n) {
		//bugarr(b, 1, n);
		if (check()) {
			//bugarr(b, 1, n);
			ans = min(ans, res);
		}
		return;
	}
	fto(i, 2, n) {
		if (avail[i]) {
			avail[i] = 0;
			b[pos] = i;
			sinhnp(pos+1); 
			avail[i] = 1;
		}
	}
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);
    #endif

    scii(n, m); scii(k, l);
    fto(i, 1, n) {
    	int sl; sci(sl);
    	fto(j, 1, sl) {
    		int x; sci(x);
    		a[i].pb(x);
    	}
    }

    if (n <= 10) {
    	fto(i, 1, n) fto(j, 1, n) a1[i][j] = (i == j) ? 0 : oo;
   		fto(i, 1, m) {
	    	int u, v, w;
	    	scii(u, v); sci(w);
	    	a1[u][v] = a1[v][u] = w;
    	}
    	fto(i, 1, n) avail[i] = 1;
    	ans = oo; 
    	b[1] = 1;   
    	sinhnp(2);
    	//bug(res);
    	cout << ans << '\n';
    	return 0;
    }
    fto(i, 1, m) {
	    int u, v, w;
	    scii(u, v); sci(w);
	    ke[u].pb(mp(v, w));
	    ke[v].pb(mp(u, w));
    }

    if (l == 0) {
	   	fto(i, 0, n) d[i] = oo;
	   	d[1] = 0; 
	   	priority_queue<ii > q;
	   	q.push(mp(0, 1));
	   	visited[1] = 1;
	   	while (!q.empty()) {
	   		ii t = q.top(); q.pop();
	   		int u = t.ss;
	   		//bug(u);
	   		if (t.ff*-1 > d[u]) continue;
	   		//int w = t.ss*-1;
	   		fto(i, 0, sz(ke[u])-1) {
	   			int v = ke[u][i].ff;
	   			int w = ke[u][i].ss;
	   			if (d[v] > d[u] + w) {
	   				d[v] = d[u] + w;
	   				if (!visited[v]) {
	   					visited[v] = 1;
	   					q.push(mp(d[v]*-1, v));
	   				}
	   			}
	   		}
	   	}
	   	 cout << d[n] << '\n';
	     return 0;
   	}
  	if (k == 1) {
  		fto(i, 0, n) d[i] = oo;
	   	d[1] = 0; 
	   	priority_queue<ii > q;
	   	q.push(mp(0, 1));
	   	visited[1] = 1;
	   	while (!q.empty()) {
	   		ii t = q.top(); q.pop();
	   		int u = t.ss;
	   		//bug(u);
	   		if (t.ff*-1 > d[u]) continue;
	   		//int w = t.ss*-1;
	   		fto(i, 0, sz(ke[u])-1) {
	   			int v = ke[u][i].ff;
	   			int w = ke[u][i].ss;
	   			if (d[v] > d[u] + w) {
	   				d[v] = d[u] + w;
	   				if (!visited[v]) {
	   					visited[v] = 1;
	   					q.push(mp(d[v]*-1, v));
	   				}
	   			}
	   		}
	   	}
	   	fto(i, 0, n) dn[i] = oo;
	   	dn[n] = 0; 
	   	q.push(mp(0, n));
	   	fto(i, 1, n) visited[i] = 0;
	   	visited[1] = 1;
	   	while (!q.empty()) {
	   		ii t = q.top(); q.pop();
	   		int u = t.ss;
	   		//bug(u);
	   		if (t.ff*-1 > dn[u]) continue;
	   		//int w = t.ss*-1;
	   		fto(i, 0, sz(ke[u])-1) {
	   			int v = ke[u][i].ff;
	   			int w = ke[u][i].ss;
	   			if (dn[v] > dn[u] + w) {
	   				dn[v] = dn[u] + w;
	   				if (!visited[v]) {
	   					visited[v] = 1;
	   					q.push(mp(dn[v]*-1, v));
	   				}
	   			}
	   		}
	   	}
	   	int ans = oo;
	   	fto(i, 1, n) {
	   		if (sz(a[i]) > 0) ans = min(ans, d[i] + dn[i]);
	   	}
	   	cout << ans;
	   	return 0;
  	}

    return 0;
}
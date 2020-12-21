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
#define maxN 500008
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)

using namespace std; 

int sum[maxN], p[maxN], dd[maxN], n, m, k, u[maxN], mx, l;
vi daco;
ii ans;
priority_queue<int> q[maxN], qk;

void init(int n) {
  fto(i, 1, n) p[i] = i;
}

int findset(int i) {
  return (p[i] == i) ? i : p[i] = findset(p[i]);
}

void unionset(int i, int j) {
  sum[findset(j)] += sum[findset(i)];
  p[findset(i)] = findset(j);
}

int issameset(int i, int j) {
  return (findset(i) == findset(j));
}

void calans(int i) {
  if (mx < i-l) {
      mx = i-l;
      ans = mp(l, i);
  }
}

int tk(int i) {
  int kt = 0;
  if (!qk.empty() && -qk.top() < i) kt = 1;
  if (!q[findset(i)].empty() && -q[findset(i)].top() < -qk.top() && -q[findset(i)].top() < i) kt = 2;
  if (kt == 0) return i;
  int li;
  if (kt == 1) {
    li = -qk.top();
    qk.pop();
    qk.push(-i);
    return min(tk(li), i);
  }
  else {
    li = -q[findset(i)].top();
    q[findset(i)].pop();
    q[findset(i)].push(-i);
    return min(i, tk(li));
  }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);
    #endif

   fast;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    fto(i, 0, n-1) {
      sum[i+1] = (int)(s[i]-'0');
    }
    init(n);

    fto(i, 1, m) {
      int u, v;
      cin >> u >> v;
      if (!issameset(u, v)) unionset(u, v);
    }

    fto(i, 1, n) {
      if (dd[findset(i)] == 0){
        daco.pb(findset(i));
        dd[findset(i)] = 1;
      }
    }

   mx = -1;
   l = 1;
   if (n <= 3000) {
   	fdto(i, n, 1) {
   		int xcu = i;
   		int x = i;
   		fto(j, 0, sz(daco)-1) {
   			u[daco[j]] = sum[daco[j]];
   		}
   		int t = k;
   		while(x > 0) {
   			if (u[findset(x)] > 0) {
   				--u[findset(x)];
   				--x;
   				continue;
   			}
   			else {
   				if (t == 0) break;
   				--t;
   				--x;
   				continue;
   			}
   		}
   		x += 1;
   		if (mx <= xcu-x) {
   			mx = xcu-x;
   			ans.ff = x;
   			ans.ss = xcu;
   		}
   	}
  
   	if (mx == -1) cout << mx << '\n';
   	else {
   		cout << ans.ff << " " << ans.ss << '\n';
   	}
   }
   else {
      fto(i, 1, n) {
      if (sum[findset(i)] > 0) {
        --sum[findset(i)];
        q[findset(i)].push(-i);
        calans(i);
      } else if (k > 0) {
        --k;
        qk.push(-i);
        calans(i);
      }
      else {
        int kt = 0;
        if (!qk.empty()) kt = 1;
        if (!q[findset(i)].empty() && kt == 1 && -q[findset(i)].top() < -qk.top()) kt = 2;
        if (kt == 0) break;
        if (kt == 1) {
          l = tk(i)+1;
          calans(l+1);
        }
        if (kt == 2) {
          l = tk(i)+1;
          calans(l+1);
        }
        while(!qk.empty() && -qk.top() < l) {
          ++k;
          qk.pop();
        }
        //bug(l);
        while(!q[findset(i)].empty() && -q[findset(i)].top() < l) {
          ++sum[findset(i)];
          q[findset(i)].pop();
        }
      }
    }

    if (mx == -1) cout << mx << '\n';
    else {
      cout << ans.ff << " " << ans.ss << '\n';
    }
   }

    return 0;
}

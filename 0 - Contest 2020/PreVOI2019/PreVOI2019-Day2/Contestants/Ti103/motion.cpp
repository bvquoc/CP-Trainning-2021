/*
5
7 2 0 0 1 2 7 2 6 0
3 3 0 0 3 3 3 0 2 1
4 4 0 2 2 4 3 2 2 2
4 4 1 0 4 4 3 0 0 4
9 7 0 0 1 1 9 0 8 7
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 1e18;
using pt = pair<ll, ll>;
#define x first
#define y second

void norm(pt& p) {
   ll g = __gcd(p.x, p.y);
   p.x /= g;
   p.y /= g;
}

pt operator + (const pt &l, const pt &r) {
   return pt(l.first + r.first, l.second + r.second);
}

pt operator - (const pt &l, const pt &r) {
   return pt(l.first - r.first, l.second - r.second);
}

ll pw(ll x, ll y, ll mod) {
   ll ans = 1;
   for (; y > 0; y >>= 1, x = x * x % mod) {
      if (y & 1) {
         ans = ans * x % mod;
      }
   }
   return ans;
}

ll phi(ll X) {
   ll ans = X;
   for (ll z = 2; z * z <= X; ++z) {
      if (X % z == 0) {
         ans -= (ans / z);
         while (X % z == 0) {
            X /= z;
         }
      }
   }
   if (X > 1) {
      ans -= (ans / X);
   }
   return ans;
}

ll inv(ll x, ll mod) {
   return pw(x, phi(mod) - 1, mod);
}

ll frac(ll x, ll y, ll mod) {
   ll g = __gcd(x, y);
   x /= g;
   y /= g;
   return x * inv(y, mod) % mod;
}

ll find(ll A, ll B, ll C, ll D) {
   ll G = __gcd(A, C);
   if ((D - B) % G) {
      return -1ll;
   }
   ll X = frac((D - B) % C + C, A, C);
   return (A * X + B) % (A * C / __gcd(A, C));
}

void solve() {
   int N, M;
   cin >> N >> M;
   ll xa, ya, xb, yb, xc, yc, xd, yd;
   cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
   pt ans(-1, -1);
   auto mnm = [&](ll x, ll y) {
      pt cur(x, y);
      norm(cur);
      if (ans.x == -1 || ans.x * cur.y > ans.y * cur.x) {
         ans = cur;
      }
   };
   auto go = [&](ll xa, ll ya, ll xc, ll yc, ll xspeed, ll yspeed) {
      pt speed(xspeed, yspeed);
      if (speed.x < 0) {
         speed.x = -speed.x;
         xa = -xa;
         xc = -xc;
      }
      if (speed.y < 0) {
         speed.y = -speed.y;
         ya = -ya;
         yc = -yc;
      }
      pt delta(xa - xc, ya - yc);
      delta.x %= (2 * N);
      if (delta.x < 0) {
         delta.x += (2 * N);
      }
      delta.y %= (2 * M);
      if (delta.y < 0) {
         delta.y += (2 * M);
      }
      if (speed.x == 0 && speed.y == 0) {
         if (delta.x == 0 && delta.y == 0) {
            mnm(0, 1);
         }
      } else if (speed.x == 0) {
         if (delta.x == 0) {
            mnm((delta.y == 0 ? 0 : 2 * M) - delta.y, speed.y);
         }
      } else if (speed.y == 0) {
         if (delta.y == 0) {
            mnm((delta.x == 0 ? 0 : 2 * N) - delta.x, speed.x);
         }
      } else {
         pair<ll, ll> xeq;
         pair<ll, ll> yeq;
         xeq.x = speed.y * 2 * N;
         xeq.y = speed.y * ((delta.x == 0 ? 0 : 2 * N) - delta.x);
         yeq.x = speed.x * 2 * M;
         yeq.y = speed.x * ((delta.y == 0 ? 0 : 2 * M) - delta.y);
         ll val = find(xeq.x, xeq.y, yeq.x, yeq.y);
         if (val != -1) {
            mnm(val, speed.x * speed.y);
         }
      }
   };
   go(xa, ya, xc, yc, (xb - xa) - (xd - xc), (yb - ya) - (yc - yd));
   go(xa, ya, xc, -yc, (xb - xa) - (xd - xc), (yb - ya) + (yc - yd));
   go(xa, ya, -xc, yc, (xb - xa) + (xd - xc), (yb - ya) - (yc - yd));
   go(xa, ya, -xc, -yc, (xb - xa) + (xd - xc), (yb - ya) + (yc - yd));
   if (ans.x == -1) {
      cout << "-1\n";
   } else {
      norm(ans);
      cout << ans.x << " " << ans.y << "\n";
   }
}

int main() {
   ios_base::sync_with_stdio(false);
#ifndef KienVu
   freopen("motion.inp", "r", stdin);
   freopen("motion.out", "w", stdout);
#endif // KienVu
   int T;
   cin >> T;
   while (T--) {
      solve();
   }
}

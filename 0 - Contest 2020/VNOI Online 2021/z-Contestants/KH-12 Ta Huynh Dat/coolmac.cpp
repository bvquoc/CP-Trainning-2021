#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define II pair<int,int>

const int MAX = 1e5;
const int oo = 1e9 + 7;
const int N = 1e5 + 7;

int n, m;
II a[N];
int st[4*N], lz[4*N], val[N];

void minimize(int &a, const int &b)
{
   a = min(a, b);
}

void down(int i)
{
   int t = lz[i];
   minimize(lz[i*2], t);
   minimize(lz[i*2+1], t);
   minimize(st[i*2], t);
   minimize(st[i*2+1], t);
   lz[i] = oo;
}

void build(int i, int l, int r)
{
   st[i] = oo;
   lz[i] = oo;
   if(l == r) return;

   int m = (l + r) >> 1;
   build(i * 2, l, m);
   build(i * 2 + 1, m + 1, r);
}

void upd(int i, int l, int r, int u, int v, int val)
{
   if(r < u || v < l) return;
   if(u <= l && r <= v){
      st[i] = min(st[i], val);
      lz[i] = min(lz[i], val);
      return;
   }
   if(lz[i] != oo) down(i);

   int m = (l + r) >> 1;

   upd(i * 2, l, m, u, v, val);
   upd(i * 2 + 1, m + 1, r, u, v, val);
   st[i] = min(st[i*2], st[i*2+1]);
}

int get(int i, int l, int r, int u, int v)
{
   if(r < u || v < l) return oo;
   if(u <= l && r <= v){
      return st[i];
   }
   if(lz[i] != oo) down(i);

   int m = (l + r) >> 1;

   return min(get(i * 2, l, m, u, v),
              get(i * 2 + 1, m + 1, r, u, v));
}

void downall(int i, int l, int r)
{
   if(l == r){
      //cerr << st[i] << '\n';
      val[l] = st[i];
      return;
   }

   if(lz[i] != oo) down(i);

   int m = (l + r) >> 1;

   downall(i * 2, l, m);
   downall(i * 2 + 1, m + 1, r);
}

int main()
{
   freopen("coolmac.inp","r",stdin);
   freopen("coolmac.out","w",stdout);

   cin >> n;
   for(int i = 0; i < n; ++i){
      cin >> a[i].fi >> a[i].se;
   }
   cin >> m;
   int mini = MAX;
   for(int i = 0, x; i < m; ++i){
      cin >> x;
      mini = min(mini, x);
   }
   sort(a, a + n);

   build(1, 1, MAX);

   for(int i = 0; i < n; ++i){
      if(a[i].se < mini) continue;

      if(a[i].fi <= mini){
            upd(1, 1, MAX, a[i].fi, a[i].se, 1);
      }
      else{
            int v = get(1, 1, MAX, a[i].fi, a[i].se);
            if(v != oo) upd(1, 1, MAX, a[i].fi, a[i].se, v + 1);
      }
   }

   int ans = get(1, 1, MAX, MAX, MAX);
   cout << (ans == oo ? -1 : ans);
}

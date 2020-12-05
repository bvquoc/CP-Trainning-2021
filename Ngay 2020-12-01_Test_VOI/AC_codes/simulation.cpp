#include <bits/stdc++.h>
#include <unordered_map>

#define N 100005
#define TASK "simulation"

using namespace std;

struct BIT {
  unordered_map<int, int> tree;

  void update(int i, int p) {
    for (i += 1e8 + 1; i <= 2e8 + 5; i += i & (-i)) {
      tree[i] += p;
    }
  }

  int get(int i) {
    int p = 0;
    for (i += 1e8 + 1; i; i -= i & (-i)) {
      p += tree[i];
    }
    return p;
  }
};

struct Segments {
  //Treap tl, tr;
  BIT tl, tr;

  void push(int l, int r) {
    if (l > r) {
      swap(l, r);
    }
    tl.update(l, 1);//tl.add(l);
    tr.update(r, 1);//tr.add(r);
  }

  void pop(int l, int r) {
    if (l > r) {
      swap(l, r);
    }
    tl.update(l, -1);//tl.remove(l);
    tr.update(r, -1);//tr.remove(r);
  }

  int get(int d) {
    return tl.get(d - 1) - tr.get(d);
  }
} listX, listY;

int n;
int dx[N], dy[N], px[N], py[N];

int intersect(int l, int r) {
  if (l > r) {
    swap(l, r);
  }
  return l < 0 && r > 0;
}

int main() {
  freopen(TASK".inp", "r", stdin);
  freopen(TASK".out", "w", stdout);
  scanf("%d", &n);
  px[0] = py[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", dx + i, dy + i);
    px[i] = px[i - 1] + dx[i];
    py[i] = py[i - 1] + dy[i];
  }
  for (int i = 1; i < n; i++) {
    listX.push(px[i], px[i + 1]);
    listY.push(py[i], py[i + 1]);
  }

  int q, fx = 0, fy = 0;
  int res = 0;

  int p = 1;
  scanf("%d", &q);
  while (q--) {
    char type;
    scanf("\n%c", &type);
    if (type == 'B') {
      if (p > 1) {
        res -= intersect(px[p - 2], px[p - 1]);
        res -= intersect(py[p - 2], py[p - 1]);
        px[p - 1] = px[p] - dx[p];
        py[p - 1] = py[p] - dy[p];
        listX.push(px[p - 1], px[p]);
        listY.push(py[p - 1], py[p]);
        p--;
      }
    }
    if (type == 'F') {
      if (p < n) {
        listX.pop(px[p], px[p + 1]);
        listY.pop(py[p], py[p + 1]);
        px[p] = px[p - 1] + dx[p];
        py[p] = py[p - 1] + dy[p];
        res += intersect(px[p - 1], px[p]);
        res += intersect(py[p - 1], py[p]);
        p++;
      }
    }
    if (type == 'C') {
      int nx, ny;
      scanf("%d%d", &nx, &ny);
      fx -= nx - dx[p];
      fy -= ny - dy[p];
      dx[p] = nx;
      dy[p] = ny;
    }
    if (type == 'Q') {
      printf("%d\n", res + listX.get(fx) + listY.get(fy) + intersect(px[p - 1], px[p - 1] + dx[p]) + intersect(py[p - 1], py[p - 1] + dy[p]));
    }
  }
}

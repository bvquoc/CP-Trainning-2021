#include<bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d ", a)
#define pril(a) printf("%d\n", a)
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define pb push_back
#define sz(a) (int)a.size()
#define pi pair<int, int>
#define ff first
#define sd second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define oo 1000000007
#define maxN 500005

using namespace std;

int n, m, k, con[maxN], mark[maxN];
queue<int> ss[maxN];
char a[maxN];
pi edg[maxN];

void solveS1() {
    int mx = 0, ans_l = -1, ans_r = -1;
    fto(l, 1, n) {
        if(a[l] == '1') {
            fto(r, l, n) {
                if(a[r] == '0') {
                    --r;
                    if(r - l + 1 > mx) {
                        mx = r - l + 1;
                        ans_l = l;
                        ans_r = r;
                    }
                    l = r;
                    break;
                }
                if(r == n) {
                    if(r - l + 1 > mx) {
                        mx = r - l + 1;
                        ans_l = l;
                        ans_r = r;
                    }
                    l = r;
                }
            }
        } 
    }
    if(ans_l == -1) {
        cout << -1;
        return;
    }
    cout << ans_l << " " << ans_r << "\n";
}



void solveS2() {
    vi b(n+2, 0);
    fto(i, 1, n) {
        b[i] = b[i-1];
        if(a[i] == '0') ++b[i];
    }

    int mx = 0, ans_l = -1, ans_r = -1;
    fto(i, 1, n) {
        int l = i, r = n, id = -1;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(b[mid] - b[i-1] <= k) {
                id = mid;
                l = mid+1;
            } else r = mid-1;
        }
        if(id != -1 && id - i + 1 > mx) {
            mx = id - i + 1;
            ans_l = i, ans_r = id;
        }
    }

    if(ans_l == -1) {
        cout << -1;
        return;
    } else cout << ans_l << " " << ans_r << "\n";
}

int par[maxN], bac[maxN];

int find_par(int u) {
    if(u == par[u]) return u;
    else return par[u] = find_par(par[u]);
}

bool join(int u, int v) {
    u = find_par(u);
    v = find_par(v);
    if(u == v) return 0;
    if(bac[u] < bac[v]) swap(u, v);
    bac[u] += bac[v];
    par[v] = u;
    return 1;
}

void solveS3() {
    fto(i, 1, n) {
        par[i] = i;
        if(a[i] == '1') bac[i] = 1;
    }
    fto(i, 1, m) join(edg[i].ff, edg[i].sd);

    int mx = 0, ans_l = -1, ans_r = -1;
    fto(i, 1, n) {
        vi c(n+2), remain(n+2), b(n+2, 0);
        fto(j, 1, n) remain[j] = bac[j];

        fto(j, i, n) {
            b[j] = b[j-1];
            if(remain[find_par(j)]) --remain[find_par(j)];
            else ++b[j];
        }

        int l = i, r = n, id = -1;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(b[mid] - b[i-1] <= k) {
                id = mid;
                l = mid+1;
            } else r = mid-1;
        }
        if(id != -1 && id - i + 1 > mx) {
            mx = id - i + 1;
            ans_l = i, ans_r = id;
        }
    }

    if(ans_l == -1) {
        cout << -1;
        return;
    } else cout << ans_l << " " << ans_r << "\n";
}

void solveS4() {
    fto(i, 1, n) {
        par[i] = i;
        if(a[i] == '1') bac[i] = 1;
    }
    fto(i, 1, m) join(edg[i].ff, edg[i].sd);

    int remain_k = k;
    int l = 1, mx = 0, ans_l = -1, ans_r = -1;

    fto(r, 1, n) {
        while(l < r && !bac[find_par(r)] && !remain_k) {
            if(mark[l] == 1) {
                ++bac[find_par(l)];
                if(con[find_par(l)]) {
                    --bac[find_par(l)];
                    --con[find_par(l)];
                    mark[ss[find_par(l)].front()] = 1;
                    ss[find_par(l)].pop();
                    ++remain_k;
                }
            }
            if(mark[l] == 2) {
                ++remain_k;
                --con[find_par(l)];
                ss[find_par(l)].pop();
            }
            ++l;
        }

        if(bac[find_par(r)]) {
            mark[r] = 1;
            --bac[find_par(r)];
        } else if(remain_k) {
            mark[r] = 2;
            ++con[find_par(r)];
            ss[find_par(r)].push(r);
            --remain_k;
        }

        if(mark[r] && r - l + 1 > mx) {
            mx = r - l + 1;
            ans_l = l;
            ans_r = r;
        }
    }

    if(ans_l == -1) {
        cout << -1;
        return;
    } else cout << ans_l << " " << ans_r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);

    cin >> n >> m >> k;
    fto(i, 1, n) cin >> a[i];

    fto(i, 1, m) {
        int u, v;
        cin >> u >> v;
        edg[i] = mp(u, v);
    }

    if(m == 0 && k == 0) {
        solveS1();
        return 0;
    }

    if(m == 0) {
        solveS2();
        return 0;
    }

    if(n <= 2000) {
        solveS3();
        return 0;
    }

    solveS4();

    return 0;
}
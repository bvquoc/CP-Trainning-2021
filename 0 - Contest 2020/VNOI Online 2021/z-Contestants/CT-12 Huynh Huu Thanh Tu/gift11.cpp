#include <bits/stdc++.h>
using namespace std;

#define oo 1000000007
#define maxN 10010
#define fto(i,a,b) for (int i=a; i<=b; ++i)
#define fdto(i,a,b) for (int i=a; i>=b; --i)
#define sci(a) scanf("%d", &a)
#define scii(a,b) scanf("%d%d", &a, &b)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (int)a.size()
#define mod 998244353

int t, n, S, a[maxN], f[maxN], avail[maxN], total, ans;
int chan_tt[maxN], le_tt[maxN], sz_tt[maxN], max_chan, max_le;

void init() {
    ans = 0;
    fto(i, 1, n) f[i] = avail[i] = chan_tt[i] = le_tt[i] = 0;
}

int get() {
    int total_chan = 0, total_le = 0;
    fto(i, 1, n) {
        int tmp = a[i], cnt = 0;
        while(tmp > 0) {
            ++cnt;
            if (cnt % 2) le_tt[i] += (tmp % 10);
            else chan_tt[i] += (tmp % 10);
            tmp /= 10;
        }

        if (cnt % 2 == 0) swap(chan_tt[i], le_tt[i]);
        sz_tt[i] = cnt;

        if (sz_tt[i] % 2) ++total_le;
        else ++total_chan;
        //cout << chan_tt[i] << " " << le_tt[i] << endl;
    }

    if (total_le == 0) return 2;
    if (total_chan == 0) return 3;
    return 4;
}

void solve1(int i, int n) {
    //cout << i << "    " << n << endl;
    if (i > n) {
        int curr = 0, chan = 0, le = 0;
//        fto(j, 1, n) cout << f[j] << " ";
//        cout << endl;
        fto(j, 1, n) {
//            cout << f[j] << " " << curr << endl;
            if (curr == 0) {
                le += le_tt[f[j]];
                chan += chan_tt[f[j]];

                if (sz_tt[f[j]] % 2) curr = 1;
            }
            else {
                le += chan_tt[f[j]];
                chan += le_tt[f[j]];

                if (sz_tt[f[j]] % 2) curr = 0;
            }
        }

        //cout << le << " " << chan << endl;
        if (le < chan) swap(le, chan);
        if ((le - chan) % 11 == 0) ans = (ans + 1) % mod;

        //cout << endl;
        return;
    }

    fto(j, 1, n) {
//        cout << i << " " << j << " " << avail[j] << endl;
        if (avail[j] == 0) {
            f[i] = j;
            avail[j] = 1;
            solve1(i+1, n);
            avail[j] = 0;
        }

    }
}

ll gt(int n) {
    if (n == 0) return 1;
    return (gt(n-1) * n) % mod;
}

void solve2() {
    int chan = 0, le = 0;
    fto(i, 1, n) chan += chan_tt[i], le += le_tt[i];

    //cout << le << " " << chan << endl;
    if (le < chan) swap(le, chan);
    if((le - chan) % 11 == 0) cout << gt(n) << endl;
    else cout << 0 << endl;
}

void solve3() {
    int chan = 0, le = 0, cnt = 0;
    fto(i, 1, n) {
        ++cnt;
        if (cnt % 2) chan += chan_tt[i], le += le_tt[i];
        else chan += le_tt[i], le += chan_tt[i];
    }

    if (le < chan) swap(le, chan);
    if((le - chan) % 11 == 0) cout << gt(n) << endl;
    else cout << 0 << endl;
}

void solve3(int i, int num_chan, int num_le) {
    //cout << i << " " << num_chan << " " << num_le << endl;
    if (i > n) {
        int chan = 0, le = 0;

//        fto(j, 1, n) cout << f[j] << " ";
//        cout << endl;
        fto(j, 1, n) {
            if (f[j] == 0) {
                chan += le_tt[j];
                le += chan_tt[j];
            }
            else {
                chan += chan_tt[j];
                le += le_tt[j];
            }
        }
        //cout << chan << " " << le << endl;

        if (le < chan) swap(le, chan);
        if ((le - chan) % 11 == 0) ans = (ans + total) % mod;
        return;
    }

    fto(j, 0, 1) {
        if (j == 0) {
            if (num_chan < max_chan) {
                f[i] = j;
                solve3(i+1, num_chan+1, num_le);
            }
        }
        else {
            if (num_le < max_le) {
                f[i] = j;
                solve3(i+1, num_chan, num_le+1);
            }

        }
    }
}

void solve4() {
    cout << 0 << endl;
    return;
}

int main() {
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);

    sci(t);
    while(t--) {
        sci(n);
        fto(i, 1, n) sci(a[i]);

        init();
        int id = get();
        if (n <= 8) {
            solve1(1, n);
            cout << ans << endl;
            continue;
        }

        //cout << id << endl;
        if (id == 2) solve2();
        else if (id == 3) {
            max_chan = n / 2;
            max_le = n / 2;
            if (n % 2) ++max_le;

            total = (gt(max_chan) * gt(max_le)) % mod;
            //cout << total << endl;
            solve3(1, 0, 0);
            cout << ans << endl;
        }
        else solve4();
    }


    return 0;
}


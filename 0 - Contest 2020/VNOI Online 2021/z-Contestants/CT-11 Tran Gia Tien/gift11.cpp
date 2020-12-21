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
#define maxN 51
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)

using namespace std;

ii p[maxN];
int b[maxN], avail[maxN], a[maxN], so[maxN], ans = 0;
int n, cnt;

void sinhHV(int i) {
    if (i > n) {
        //bugarr(b, 1, n);
        int ok = 0, prev = 0, chan = 0, le = 0;
        fto(j, 1, n) {
            fto(k, 1, n) {
                if (b[k] == j) {

                    if (k == 1) {
                        chan += p[k].ss;
                        le += p[k].ff;
                        prev = so[k];
                        continue;
                    }
                    if (prev % 2 == 1) {
                        if (so[k] == 1) chan += p[k].ff;
                        else {
                            chan += p[k].ss;
                            le += p[k].ff;
                        }
                    } else {
                        if (so[k] == 1) le += p[k].ff;
                        else {
                            le += p[k].ss;
                            chan += p[k].ff;
                        }
                    }
                    prev += so[k];
                    break;

                }
            }
        }
        //bug2(chan, le);
        if ((le - chan) % 11 == 0) ++ans;
    }
    fto(j, 1, n) {
        if (avail[j]) {
            b[i] = j;
            avail[j] = 0;
            sinhHV(i+1);
            avail[j] = 1;

        }
    }
}


ii build(int x) {
    cnt = 1;
    int chan = 0, le = 0;
    //bug(x);
    while(x > 0) {
        if (cnt % 2 == 1) le += x%10;
        else chan += x%10;
        x/=10;
        ++cnt;
    }
    return mp(le, chan);
}


int main () {
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);

    int t;
    sci(t);
    while(t--) {
        sci(n);
        fto(i, 1, n) {
            sci(a[i]);
            p[i] = build(a[i]);
            so[i] = cnt-1;
            //cout << p[i].ff << " " << p[i].ss;
            //puts("");
        }
        //bugarr(so, 1, n);
        fto(i, 1, n) avail[i] = 1;
        ans = 0;
        sinhHV(1);
        cout << ans << '\n';


    }
    return 0;
}

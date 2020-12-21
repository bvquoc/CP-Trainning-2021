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
#define maxN 100005

using namespace std;

int n, m, mn = oo;
vi ke[maxN];

int main() {
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);

    sci(m);
    fto(i, 1, m) {
        int l, r;
        scii(l, r);
        ke[l].pb(r);
    }

    sci(n);
    fto(i, 1, n) {
        int x;
        sci(x);
        mn = min(mn, x);
    }

    priority_queue<int> pq;
    int ans = 0, dur = 0;
    fto(i, 1, 99999) { 
        fto(j, 0, sz(ke[i])-1) pq.push(ke[i][j]);
        
        if(i >= mn) {
            if(dur < i + 1) {
                if(pq.empty() || pq.top() < i + 1) {
                    cout << -1;
                    return 0;
                } else {
                    ++ans;
                    dur = pq.top();
                }
            }
        }
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fr(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
#define ii pair<int,int>
#define pb push_back

int n,m,k;
string S;
int a[500010];
int b[500010];
int sum[500010];

void io () {
    freopen ("decor.inp", "r", stdin);
    freopen ("decor.out", "w", stdout);
}

void inp () {
    cin >> n >> m >> k;
    cin >> S;
    S = " " + S;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
    }
}

void sub () {
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (int)(S[i] - '0');
    }
    ll now = 0;
    int resL, resR;
    for(int i = 1; i <= n; i++)
    {
        int l = i - 1;
        int r = n;
        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            if(mid - i + 1 - sum[mid] + sum[i - 1] <= k) l = mid;
            else r = mid - 1;
        }
        if(r - i + 1 > now)
        {
            now = r - i + 1;
            resL = i;
            resR = r;
        }
    }
    if(now == 0) cout << "-1";
    else cout << resL << " " << resR << "\n";
}

int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    io ();
    inp ();
    sub ();
    return 0;
}

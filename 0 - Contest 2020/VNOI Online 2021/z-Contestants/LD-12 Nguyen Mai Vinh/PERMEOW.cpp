#include<bits/stdc++.h>
#define ll int
//<(")
using namespace std;

typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

const ll siz = 1e5 + 10;
const ll mod = 1e9 + 9;
const ll base = 32;
const ll MAXX = 1e18;
const ll off = 300;

void con_meo_ngoo() {
    //khong lam gi ca
}

ll n;
vector<ll> a, b;

int getInvCount(vector<ll> arr)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PERMEOW.INP", "r", stdin);
    freopen("PERMEOW.OUT", "w", stdout);
    con_meo_ngoo();
    cin >> n;
    a.resize(n); b.resize(n);
    bool c1 = true;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] != b[i]) {
            c1 = false;
        }
    }
    if (c1) {
        cout << getInvCount(a) << '\n';
        return 0;
    }

    return 0;
}

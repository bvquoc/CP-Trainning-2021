#include <bits/stdc++.h>
#define int64_t long long
using namespace std;

const int N = 2005;
const int Mod = 998244353;

int64_t n;
string arr[N];

namespace Sub1 {

int64_t ans;

bool check(string s) {
    int64_t le = 0, chan = 0;
    for(int i = 0; i < s.size(); ++i) {
        if((i+1) % 2) le += s[i] - '0';
        else chan += s[i] - '0';
    }

    if((le - chan) % 11) return false;
    else return true;
}

long long a[100];
bool kt[100];

void thu(long long x) {
    for(int i = 1; i <= n; i++){
        if(kt[i] == false){
            a[x] = i;
            if(x == n){
                string s = "";
                for (int k = 1; k <= n; k++)
                    s += arr[a[k]];
                if(check(s)) ans++;
            }
            else{
                kt[i] = true;
                thu(x+1);
                kt[i] = false;
            }
        }
    }
}

void solve() {
    memset(a, 0, sizeof(a));
    memset(kt, 0, sizeof(kt));
    ans = 0;

    thu(1);

    cout << ans % Mod << '\n';
}

}//namespace Sub1

namespace Sub2 {

int64_t ans;

int64_t giaiThua(int64_t n) {
    if(n == 1) return 1;
    return n * giaiThua(n - 1);
}

int64_t check(string s) {
    int64_t le = 0, chan = 0;
    for(int i = 0; i < s.size(); ++i) {
        if((i+1) % 2) le += s[i] - '0';
        else chan += s[i] - '0';
    }

    return le - chan;
}

void solve() {
    ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += check(arr[i]);

    if(ans % 11) cout << 0 << '\n';
    else cout << giaiThua(n) % Mod << '\n';
}

}//namespace Sub2

int main() {
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        bool check = false;
        for(int i = 1; i <= n; ++i) {
            cin >> arr[i];
            if(arr[i].size() != 2) check = true;
        }

        if(check) Sub1::solve();
        else Sub2::solve();
    }

    return 0;
}

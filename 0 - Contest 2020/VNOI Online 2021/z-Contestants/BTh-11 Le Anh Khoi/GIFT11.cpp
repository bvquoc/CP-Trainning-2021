#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
int q, n, S = 0, a[2005], res = 0, sub = -1;
ll f[10][555][9*9+1][9*9+1];

ll dp(int i, int bit, int odd, int even, string s)
{
    if(i > n) return ((odd - even)%11 == 0);

    if(f[i][bit][odd][even] != -1) return f[i][bit][odd][even]%MOD;

    ll cnt = 0;
    for(int v = 1; v <= n; v++){
        if(!((bit>>(v-1))&1)){
            int tmp = a[v];
            int n_odd = odd, n_even = even;
            string n_s = s;
            vector<int> digit;
            while(tmp != 0){
                digit.push_back(tmp%10);
                tmp/=10;
            }
            reverse(digit.begin(), digit.end());
            for(int d = 0; d < (int)digit.size(); d++){
                char c = digit[d] + '0';
                n_s = n_s + c;
                if(((int)s.size() + 1)%2){
                    if((d+1)%2) n_odd += digit[d];
                    else n_even += digit[d];
                }
                else{
                    if((d+1)%2) n_even += digit[d];
                    else n_odd += digit[d];
                }
            }
            cnt = (cnt + dp(i+1, (bit|(1<<(v-1))), n_odd, n_even, n_s))%MOD;
        }
    }
    return f[i][bit][odd][even] = cnt%MOD;
}

int chuso(int x)
{
    int cnt = 0;
    while(x != 0){
        cnt++;
        x/=10;
    }
    return cnt;
}

int main()
{
    freopen("GIFT11.INP", "r", stdin);
    freopen("GIFT11.OUT", "w", stdout);
    cin >> q;
    while(q--){
        cin >> n;
        sub = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(sub == -1) sub = chuso(a[i])%2;
            else if(sub == 1 && chuso(a[i])%2 == 0) sub = 2;
            else if(sub == 0 && chuso(a[i])%2 == 1) sub = 2;
        }
        if((sub == 2 || sub == 1) && n <= 8){
            memset(f, -1, sizeof f);
            cout << dp(1, 0, 0, 0, "")%MOD << "\n";
        }
        else if(sub == 0){
            ll res = 1, check = 0;
            for(int i = 1; i <= n; i++)
                check = (check + a[i])%11;
            if(!check){
                for(int i = 1; i <= n; i++){
                    res = (res * i)%MOD;
                }
            }
            cout << res;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        string a, b;
        cin >> a >> b;

        int l = a.size();
        int r = b.size();

        string res;
        int i = 1;
        int plus = 0;
        
        auto calc = [&](string &res) {
            int sum = 0;
            if (l >= i) sum += a[l - i] - '0';
            if (r >= i) sum += b[r - i] - '0';

            sum += plus;

            if (sum <= 9) {
                res += sum + '0';
                plus = 0;
            }
            else {
                res += sum % 10 + '0';
                plus = 1;
            }
            return res;
        };

        while (l >= i || r >= i) {
            calc(res);
            i++;
        }
        if (plus == 1) res += "1";

        reverse(res.begin(), res.end());
        cout << res << '\n';
    }    

    return 0;
}
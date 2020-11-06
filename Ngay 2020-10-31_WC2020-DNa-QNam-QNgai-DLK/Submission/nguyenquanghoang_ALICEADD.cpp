#include<bits/stdc++.h>
using namespace std;
int t;
string sum(string x, string y) {
    string res;
    while(x.size() < y.size()) x = '0' + x;
    while(y.size() < x.size()) y = '0' + y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int carry = 0;
    for(int i = 0; i < x.size(); ++ i) {
        int pos = x[i] + y[i] - 96 + carry;
        carry = pos / 10;
        pos %= 10;
        res += char(pos + 48);
    }
    if(carry) res += '1';
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t --) {
        string x, y;
        cin >> x >> y;
        cout << sum(x, y) << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

string s;
int z[1000001];

void calc_z(string s, int z[]) {
    z[0] = s.size();
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++)
        if (i > r) {
            l = r = i;
            while (r < s.size() && s[r] == s[r-l]) r++;
            r--;
            z[i] = r - l + 1;
        }
        else
            if (z[i-l] < r-i+1) z[i] = z[i-l];
            else {
                l = i;
                while (r < s.size() && s[r-l] == s[r]) r++;
                r--;
                z[i] = r - l + 1;
            }
}

int main() {
    freopen("simi.inp", "r", stdin);
    freopen("simi.out", "w", stdout);
    cin >> s;
    calc_z(s, z);
    long long t = 0;
    for (int i = 0; i < s.size(); i++) t += z[i];
    cout << t << '\n';
    return 0;
}

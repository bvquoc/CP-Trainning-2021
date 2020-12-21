#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
int getbit(int mask, int i) {
    return (mask >> i) & 1;
}
#define PROBLEMS            "gift11"
ifstream fi (PROBLEMS".inp");
ofstream fo (PROBLEMS".out");
#define camnguyenmeow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<string> a[11];
int suml[11][2001], sumc[11][2001], n[11];
bool ok(vector<int> &pmt, int t) {
    string x = "";
    int ln = 1, sum1 = 0, sum2 = 0;
    for (int i : pmt) {
        if (ln % 2 == 0) {
            sum1 += suml[t][i];
            sum2 += sumc[t][i];

        } else {
            sum1 += sumc[t][i];
            sum2 += suml[t][i];
        }
        ln += a[t][i].length();
    }
    if ((sum1 - sum2) % 11 == 0) return true;
    return false;
}
int main()
{
    camnguyenmeow;
    int t; fi >> t;
    for (int i = 0; i < t; ++i) {
        fi >> n[i];
        a[i].resize(n[i]);
        for (string &str : a[i]) fi >> str;
    }
    for (int T = 0; T < t; ++T) {
        for (int i = 0; i < n[T]; ++i) {
            a[T][i] = a[T][i] + "0";
            for (int j = 0, ln = a[T][i].length()-1; j < ln; j += 2) {
                suml[T][i] += (a[T][i][j] - '0');
                sumc[T][i] += (a[T][i][j+1] - '0');
            }
            a[T][i].pop_back();
        }
    }
    for (int T = 0; T < t; ++T) {
        vector<int> pmt;
        int ans = 0;
        for (int i = 0; i < n[T]; ++i)
            pmt.push_back(i);
        do {
            if (ok(pmt, T)) ans++;
        } while (next_permutation(pmt.begin(), pmt.end()));
        fo << ans <<'\n';
    }
    return 0;
}

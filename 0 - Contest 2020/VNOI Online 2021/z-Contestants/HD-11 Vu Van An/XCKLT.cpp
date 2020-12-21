//
#include <bits/stdc++.h>

using namespace std;
#define task        "XCKLT"
#define maxn        505
#define maxm
#define maxs
#define p_b         push_back
#define fs          first
#define sc          second
#define oo          2000000000
#define mod         1000000007
#define ll          long long

typedef pair <int, int> II;
typedef pair <II, int> III;

string A, B, C;

void sub1() {
    if (A == B && B != C) {
        cout << 1 << "\n" << A;
    } else
        cout << "TRETRAU";
}

void sub3() {
    int n = A.size();
    int m = B.size();
    int k = C.size();
    char c = C[0], n_c = 0;
    int res = 0;
    string r = "";
    int j = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == c) ++cnt;
        if (A[i] == B[j]) ++j;
        res++;
        r = r + A[i];
    }
    while (j < m) {
        if (B[j] == c) ++cnt;
        r = r + B[j];
        ++j;
        ++res;
    }
    if (cnt > k) cout << "TRETRAU";
    else cout << res << "\n" << r;
}

//
int main() {
    freopen (task".inp", "r", stdin);
    freopen (task".out", "w", stdout);
    ios::sync_with_stdio (false);
//    cin.tie(0);
//    cout.tie(0);
    cin >> A >> B >> C;
    if (A.size() == 1 && B.size() == 1 && C.size() == 1)
        sub1();
    else sub3();
}

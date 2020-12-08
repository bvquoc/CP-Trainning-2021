#include <bits/stdc++.h>

using namespace std;
int n, k;

vector<pair<int, int> > a;
long long Calc(const vector<pair<int, int> > &a) {
    long long res = 0;
    vector<int> X, Y;
    for (int i = 0; i < n; ++i)
        X.push_back(a[i].first), Y.push_back(a[i].second);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    long long sumX = 0, sumY = 0;
    for (int i = 0; i < n; ++i) {
        res += 1ll * X[i] * i - sumX;
        res += 1ll * Y[i] * i - sumY;
        sumX += X[i];
        sumY += Y[i];
    }
    return res;
}
void check(bool x, string s = "WA") {
    if (!x) {
        cout << s;
        exit(0);
    }
}
void Init(vector<pair<int, int> > &X, vector<long long> &ans, int lim) {
    long long sum = 0;
    ans[0] = 0;
    for (int i = 0; i < X.size(); ++i) {
        ans[0] += 1ll * X[i].first * i - sum;
        sum += X[i].first;
    }
    for (int i = 1; i <= lim; ++i) {
        ans[i] = ans[i - 1];
        if (X[0].first == X.back().first) {
            continue;
        }
        long long L = lower_bound(X.begin(), X.end(), make_pair(X[0].first, (int) 1e9)) - X.begin() - 1;
        long long R = lower_bound(X.begin(), X.end(), make_pair(X.back().first, -1)) - X.begin();
        long long cntL = L + 1;
        long long cntR = X.size() - R;
        if (cntL < cntR) {
            ++X[L].first;
            ans[i] = ans[i] - (n - cntL) + cntL - 1;
        }
        else {
            --X[R].first;
            ans[i] = ans[i] - (n - cntR) + cntR - 1;
        }
        
    }
}
int main() {
#if ONLINE_JUDGE || THEMIS
    freopen("tigersugar2.inp", "r", stdin);
    freopen("tigersugar2.out", "w", stdout);
#endif
    
#ifdef LDT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    vector<pair<int, int> > X, Y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        X.push_back({a[i].first, i});
        Y.push_back({a[i].second, i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    vector<long long> ansX(k + 1), ansY(k + 1);
    Init(X, ansX, k);
    Init(Y, ansY, k);
    long long cost = ansX[0] + ansY[k];
    int bestX = 0;
    for (int i = 1; i <= k; ++i) {
        long long cur = ansX[i] + ansY[k - i];
        if (cur < cost) {
            cost = cur;
            bestX = i;
        }
    }
    //trace
    for (int i = 0; i < n; ++i) {
        X[i] = {a[i].first, i};
        Y[i] = {a[i].second, i};
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    Init(X, ansX, bestX);
    Init(Y, ansY, k - bestX);
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; ++i)
        b[X[i].second].first = X[i].first,
        b[Y[i].second].second = Y[i].first;
    cout << cost << '\n';
    for (int i = 0; i < n; ++i)
        cout << b[i].first << ' ' << b[i].second << '\n';
    return 0;
}

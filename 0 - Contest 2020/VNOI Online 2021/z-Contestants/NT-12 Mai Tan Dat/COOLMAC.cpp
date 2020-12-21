#include <bits/stdc++.h>
using namespace std;
using pii = pair< int, int >;
using ll = long long;

const int M = 1e5 + 7, mod = 1e9 + 7;
int m, n, Min = 1e9, res;
pii seg[M];
int temp[M];
stack< pair< pii, int > > st;

bool _cmp(pii x, pii y) {
    return x.second > y.second;
}


void _sub3() {
    for (int i = 1; i <= n; ++i)
        Min = min(Min, temp[i]);

    sort(seg + 1, seg + m + 1, _cmp);

    for (int i = 1; i <= m; ++i) {
        while (!st.empty()
             && seg[i].second >= st.top().second
             && seg[i].first <= st.top().first.first)
        st.pop();

        if (st.empty())
            st.push({seg[i], 1e5});
        else if (seg[i].first < st.top().first.first)
            st.push({seg[i], min(st.top().first.first, st.top().second)});
    }

    while (st.top().second <= Min) st.pop();
    res = st.size();

    bool ok = (st.top().first.first <= Min);
    while (st.size() >= 2) {
        ok &= st.top().first.second >= st.top().second;
        st.pop();
    }
    ok &= st.top().first.second == 1e5;

    if (!ok)
        res = -1;
}


void _read() {
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);

    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> seg[i].first >> seg[i].second;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> temp[i];
}

int _random(int l, int r) {
    srand(time(NULL) + rand());
    return (ll) rand() * rand() % (r - l + 1) + l;
}

void _gentest() {
    srand(time(NULL));

    m = _random(1, 5);
    for (int i = 1; i <= m; ++i) {
        seg[i].first = _random(0, 1e5);
        seg[i].second = _random(0, 1e5);
        if (seg[i].first > seg[i].second)
            swap(seg[i].first, seg[i].second);
    }
    n = _random(1, 10);
    for (int i = 1; i <= n; ++i)
        temp[i] = _random(0, 1e5);

    seg[1].second = 1e5;

    cout << m << '\n';
    for (int i = 1; i <= m; ++i)
        cout << seg[i].first << ' ' << seg[i].second << '\n';
    cout << n << '\n';
    for (int i = 1; i <= n; ++i)
        cout << temp[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    _read();
//    _gentest();


    _sub3();

    cout << res;


    return 0;
}

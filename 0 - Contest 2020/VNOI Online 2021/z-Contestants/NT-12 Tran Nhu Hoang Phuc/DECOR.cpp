#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define FILE_NAME "DECOR"

using namespace std;

string s;
int n, m, k;
vector<pair<int, int> > a;

void Sub_1()
{
    int ri, len = LLONG_MIN;
    int f[n+2];
    memset(f, 0, sizeof(f));

    for (int i = 0; i <= n; ++i) {
        if (s[i] == '1')
            f[i] = f[i-1]+1;
        else f[i] = 0;
        if (len < f[i]) {
            len = f[i];
            ri = i;
        }
    }

    if (len < 1)
        cout << -1;
    else
        cout << ri-len+1 << ' ' << ri;
}

int main()
{
    FAST_IO;
    ifstream cin(FILE_NAME".INP");
    ofstream cout(FILE_NAME".OUT");

    cin >> n >> m >> k;
    cin >> s;
    s = " "+s;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    if (m == 0 && k == 0)
        Sub_1();
    return 0;
}


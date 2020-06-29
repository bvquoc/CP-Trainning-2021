#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 1003;
int n, m, m_max = 0;
int res = 0;
vector <int> a, c[N];

int f[10000007];
void Sub1_2() {

    // a[] = { 1,2,2,1,2,2 } -> 9
    for (int i=1; i<=m; i++) {
        for (int j=0; j<=a[i]; j++) {
            f[a[i]] = max(f[a[i]], f[j]+a[i]);
        }
        cerr << f[a[i]] << ' ';
    }
    
    for (int i=1; i<=m; i++) {
        res = max(res, f[a[i]]);
    }
}

int32_t main(void) {
    FastIO;
    freopen("pig.inp","r",stdin);
    freopen("pig.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> m;
        m_max = max(m_max, m);
        c[i].assign(m+1,0);
        for (int j=1; j<=m; j++) {
            cin >> c[i][j];
        }
    }

    if (m_max == 0) {
        cout << res;
        return 0;
    }
    
    if (m_max == 1) {
        a.push_back(0);
        for (int i=1; i<=n; i++) {
            int m = c[i].size()-1;
            for (int j=1; j<=m; j++) {
                a.push_back(c[i][j]);
            }
        }
        m = a.size()-1;
        Sub1_2();
        cout << res;
        return 0;
    }
    
    cout << res;
    return 0;
}


// int z[30];
// void update() {
//     int cur_sum = 0;
//     for (int i=1;i<=m;i++) {
//         if (z[i]==1) cur_sum += a[i];
//     }
//     res = max(cur_sum, res);
// }
// void Try(int i, int cur) {
//     for (int j=0;j<=1;j++) {
//         if (j==0 || a[i]>=cur) {
//             z[i] = j;
//             if (i==m) update();
//             else {
//                 int tmp = 0;
//                 if (j == 1) {
//                     tmp = a[i];
//                 }
//                 Try(i+1, tmp);
//             }
//         }
//     }
// }
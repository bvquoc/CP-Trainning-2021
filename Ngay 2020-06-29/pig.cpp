#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 1003;
int n, m, m_max = 0;
int res = 0;
vector <int> a, c[N];


vector<int> f;
int solve1(int n) {
    f.assign(n+1,0);
    f[1] = a[1];
    for (int i=2; i<=n; i++) {
        for (int j=0;j<i;j++) {
            if (a[i]>=a[j]) {
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
    }
    return *max_element(f.begin(),f.end());
}
int solve2(int n) {
    f.assign(n+1,0);
    f[1] = 1;
	int ans = 1;
	for (int i=2; i<=n; i++) {
		int l = 1, r = ans, j = 0;
		while (l <= r) {
			int m = (l+r)/2;
			if (a[i] >= a[f[m]]) {
				j = m;
				l = m+1;
			} else r = m-1;
		}
		if (j == ans) f[++ans] = i;
		if (a[i] < a[f[j+1]]) f[j+1] = i;
	}
    int tmp = ans; ans = 0;
    while (tmp!=0) {
        ans += a[f[tmp--]];
    }
    return ans;
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
        res = ((m<=N) ? solve1(m) : solve2(m));
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
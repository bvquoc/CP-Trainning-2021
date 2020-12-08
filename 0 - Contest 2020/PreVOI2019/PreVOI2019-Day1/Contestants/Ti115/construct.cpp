#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair< int, int > ii;

const int N = 1e5 + 5;

int test, n, m;
int L[N], R[N];
long long w[N];

stack< int > st;

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1) {
            int k;
            cin >> k;
            for(int j = l; j <= r; j++)
                w[j] += k;
        }
        else {
            while(!st.empty()) st.pop();
            for(int j = l; j <= r; j++) {
                while(!st.empty() && w[st.top()] > w[j]) st.pop();
                if(st.empty())
                    L[j] = l - 1;
                else
                    L[j] = st.top();
                st.push(j);
            }
            while(!st.empty()) st.pop();
            for(int j = r; j >= l; j--) {
                while(!st.empty() && w[st.top()] >= w[j]) st.pop();
                if(st.empty())
                    R[j] = -1;
                else
                    R[j] = st.top();
                st.push(j);
            }
            long long ans = 0;
            for(int j = l; j <= r; j++) {
                if(L[j] == l - 1 && R[j] == -1)
                    ans += w[j];
                else if(L[j] == l - 1 && R[j] != -1)
                    ans += (w[j] - w[ R[j] ]);
                else if(L[j] != l - 1 && R[j] == -1)
                    ans += (w[j] - w[ L[j] ]);
                else
                    ans += ( w[j] - max(w[ L[j] ], w[ R[j] ]) );
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    freopen("construct.inp", "r", stdin);
    freopen("construct.out", "w", stdout);
    cin >> test;
    while(test--)
        solve();
}


#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int T, ans, a, res, d[N + 1], f[N + 1], run, v[N + 1];
bool pr[N + 1];
vector <int> S[N + 1];
set <int> A;

void solve(int a, set<int> &A) {
    if (a == 1) return;
    int x = f[a];
    A.insert(x);
    while(!(a % x))
        a = a / x, d[x] = d[x] + 1;
    solve(a, A);
}

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= N; i++)
        f[i] = i;
    for (int i = 2; i <= sqrt(N); i++)
        if (!pr[i])
            for (int j = i + i; j <= N; j += i)
                pr[j] = true, f[j] = i;
    for (run = 0; run < T; run++){
        A.clear(), ans = 1, res = 1;
       // memset(d, 0, sizeof(d));
        scanf("%d", &a);
        solve(a, A), solve(a + 1, A), solve(a + 2, A);
      //  cout <<"end";
        set <int> :: iterator it;
        for (it = A.begin(); it != A.end(); ++it){
            ans = ans * (d[*it] + 1);
            res = res * (d[*it] * 2 + 1);
            d[*it] = 0;
        }
        int x = (res + 1) / 2;
        printf("%d\n", x - ans);
    }
}

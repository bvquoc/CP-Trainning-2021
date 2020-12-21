#include <bits/stdc++.h>
#define TASK "PERMEOW"
#define X first
#define Y second
#define ll long long
#define pi pair<int,int>
#define Bit(i) (1<<(i))
#define Get_Bit(i,x) (((x)>>i)&1)

using namespace std;
const int N = 2e5;
int n,a[N],b[N];
bool ok = 1;

void Sub1()
{
    int res = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=i; j>1; --j)
            if (a[j]<a[j-1]) swap(a[j-1],a[j]), ++res;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i) cin >> b[i],   ok &= (a[i]==b[i]);
    if (ok) Sub1();
    return 0;
}

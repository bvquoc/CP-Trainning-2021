#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ten "permeow"

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef unsigned long long ull;

int n, a[200003], b[200003], res = 0, ok = 0, add[200003];

int Solve()
{
    for(int i = 1; i <= n; i++)
        add[i] = 0;

    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[j] > i) add[a[j]]++;
            if(a[j] == i)
            {
                sum = (sum + max(0, j - i + add[i])) % MOD;
                break;
            }
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(ten".inp", "r", stdin);
    freopen(ten".out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    next_permutation(b + 1, b + n + 1);

    do
    {
        ok = 1;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != b[i]) ok = 0;
        }

        if(ok) break;

        res = (res + Solve()) % MOD;
    }
    while(next_permutation(a + 1, a + n + 1));

    cout << res;

    return 0;
}

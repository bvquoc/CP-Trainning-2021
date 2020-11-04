/// Author: djxone123456(Mong u)

#include<bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi pair<int, int>
#define pii pair<pi, int>
#define Task "debug"
#define MOD 1000000007
#define INF INT_MAX
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

long a, b, c;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    long add = -a / c;
    add += b / c;
    if (add == 0)
    {
        long res = b - a;
        res = res / 2 + (res % 2);
        cout << res;
        return 0;
    }
    if (c % 2 != 0)
    {
        long fi = c - 1 - (a % c);
        long se = (b % c) - 1;
        long step = c - 2;
        fi = fi / 2 + fi % 2;
        se = se / 2 + se % 2;
        step = step / 2 + step % 2;
        cout << fi + se + add + step * (add - 1);
        return 0;
    }
    long res = 0;
    if (a % 2 == 0) a++, res++;
    cout << (b - a) / 2 + (b - a) % 2 + res;
    return 0;
}

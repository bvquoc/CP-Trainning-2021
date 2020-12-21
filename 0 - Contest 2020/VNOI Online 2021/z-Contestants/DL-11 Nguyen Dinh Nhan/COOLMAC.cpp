#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
#define getBit(A, bit) ((A & 1LL << bit) != 0)
#define turnOn(A, bit) (A |= 1LL << bit)
#define turnOff(A, bit) (A &= ~(1LL << bit))
#define filename "COOLMAC"

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

const ll INF = 1e9;

pi a[100005];
int n, m, lim = INF, cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("debug.inp", "r"))
    {
        freopen("debug.inp", "r", stdin);
        freopen("debug.out", "w", stdout);
    }
    else
    {
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;

    cin >> m;

    for(int i = 1; i <= m; i++)
    {
        int tmp;

        cin >> tmp;

        lim = min(lim, tmp);
    }

    sort(a + 1, a + n + 1);

    int i = 1;

    while(lim < 1e5 && i <= n)
    {
        int oldi = i, en = -INF;

        while(a[i].x <= lim)
        {
            en = max(en, a[i].y);
            i++;
        }

        cnt++;

        lim = en;
        if(oldi == i)
        {
            cout << -1;
            return 0;
        }

    }

    if(lim == 1e5)
    {
        cout << cnt;
        return 0;
    }

    cout << -1;

    return 0;
}

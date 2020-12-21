#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 998244353
#define endl '\n'
#define getBit(A, bit) ((A & 1LL << bit) != 0)
#define turnOn(A, bit) (A |= 1LL << bit)
#define turnOff(A, bit) (A &= ~(1LL << bit))
#define filename "GIFT11"

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

const ll INF = 1e9;
unordered_map<int, pii> f;
int n, a[100000];

pii getsum(int a)
{
    if(f[a].y.x != 0 || f[a].y.y != 0) return f[a];
    int sum[2] = {}, cnt = 0;

    while(a > 0)
    {
        cnt++;
        sum[cnt & 1] += a % 10;
        a /= 10;
    }

    return f[a] = pii((cnt & 1), pi(sum[!(cnt & 1)], sum[(cnt & 1)]));
}

ll brute(int bitmask, int sum1, int sum2, int tt)
{
    if(!bitmask) return (abs(sum1 - sum2) % 11 == 0);

    ll res = 0;
    int pos = __builtin_popcount(bitmask);

    for(int i = 0; i < n; i++)
    {
        int mask = bitmask;
        if(getBit(mask, i))
        {
            turnOff(mask, i);
            pii info = getsum(a[i + 1]);

            int arr[2] = {info.y.x, info.y.y};
            int cl = info.x;

            res = (res + brute(mask, sum1 + arr[(tt + cl) % 2], sum2 + arr[(tt + cl + 1) % 2], (tt + cl) % 2)) % MOD;
        }
    }

    return res;
}


void subtask1()
{
    cout << brute((1 << n) - 1, 0, 0, 0) << "\n";
}

void subtask2()
{
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; i++)
    {
        pii info = getsum(a[i + 1]);

        int arr[2] = {info.y.x, info.y.y};

        sum1 += arr[0];
        sum2 += arr[1];
    }

    if(abs(sum1 - sum2) % 11 == 0)
    {
        ll res = 1;
        for(int i = 2; i <= n; i++)
            res = (res * i) % MOD;

        cout << res;
    }
    else cout << 0;

    cout << "\n";
}

void subtask3()
{
    ll sum = 1;
    for(int i = 1; i <= n / 2; i++)
        sum = (sum * i) % MOD;
    for(int j = 1; j <= n - n / 2; j++)
        sum = (sum * j) % MOD;

    cout << sum << "\n";
}

void query()
{
    cin >> n;

    bool sochan = 0, sole = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sochan |= ((a[i] & 1) == 0);
        sole |= (a[i] & 1);
    }

    if(sochan && !sole)
    {
        subtask2();
        return;
    }

    if(n <= 20)
    {
        subtask1();
        return;
    }

    if(!sochan && sole)
    {
        subtask3();
        return;
    }
    cout << 0 << "\n";
}

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

    int t;

    cin >> t;

    while(t--)
    {
        query();
    }

    return 0;
}

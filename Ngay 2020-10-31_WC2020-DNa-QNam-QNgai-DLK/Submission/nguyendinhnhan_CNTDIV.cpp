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

int minPrime[2000006];
map<int, int> dd;

void sang()
{
    int n = 1e6 + 7;
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

set<int> st;

void ptich(int n) {
    while (n != 1) {
        st.insert(minPrime[n]);
        dd[minPrime[n]]++;
        n /= minPrime[n];
    }
}

ll n, t;
vector<int> nto;

void query()
{
    cin >> n;

    st.clear();
    dd.clear();

    for(int i = n; i <= n + 2; i++)
        ptich(i);

    ll cntt = 1, cntt2 = 1;

    for(set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        cntt *= (dd[*it] + 1);
        cntt2 *= (dd[*it] * 2 + 1);
    }

    cout << cntt2 / 2 - cntt + 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    #endif // djxone123456

    sang();

    int t;

    cin >> t;

    while(t--)
        query();

    return 0;
}

#include <bits/stdc++.h>
#define getbit(x, i) (x >> (i - 1) & 1)
#define onbit(x, i) (x | (1 << (i - 1)))
#define offbit(x, i) (x ^ (1 << (i - 1)))
#define cntone(x) (__builtin_popcount(x))
#define sum(x, y, u, v) (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1])

using namespace std;

typedef long long ll;
const int oo = 1e9;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;

template < typename T > inline void read(T &x)
{
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do x = x * 10 + c - 48; while(isdigit(c = getchar()));
}

int t, n, m, a[maxn];

ll cost(int L, int R)
{
    ll sum = 0;
    vector < int > v;
    for(int i = L; i <= R; i++)
        v.push_back(a[i]);
    v.push_back(1);
    int i = 0;
    while(i < v.size())
    {
        //cout << i << '\n';
        if(v[i] != 0)
        {
            int Min = v[i];
            int j = i;
            while(v[j] > 0) Min = min(Min, v[j]), j++;
            sum += Min;
            for(int k = i; k < j; k++)
                v[k] -= Min;
            //for(int k : v) cout << k << ' ';
            //cout << Min << '\n';
        }
        if(v[i] == 0) i++;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL);
    if(fopen("CONSTRUCT.inp", "r"))
    {
       freopen("CONSTRUCT.inp", "r", stdin);
       freopen("CONSTRUCT.out", "w", stdout);
    }
    read(t);
    while(t--)
    {
        read(n); read(m);
        for(int i = 1; i <= n; i++) read(a[i]);
        while(m--)
        {
            int type, L, R, k;
            read(type);
            if(type == 1)
            {
                read(L); read(R); read(k);
                for(int i = L; i <= R; i++)
                    a[i] += k;
            }
            else
            {
                read(L); read(R);
                cout << cost(L, R) << '\n';
            }
        }
    }
    //cout << cost(1, 5);
}

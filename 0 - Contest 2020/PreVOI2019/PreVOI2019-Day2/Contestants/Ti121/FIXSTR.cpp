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
const int maxn = 1e5 + 10;

string s;
vector < string > v;
int m;

int cost(int L, int R)
{
    int sum = 0, hieu = 0;
    for(int i = L; i <= R; i++)
    {
        if(s[i] == '(') hieu++;
        else hieu--;
        if(hieu < 0) hieu = 0, sum++;
    }
    return sum + hieu;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("FIXSTR.inp", "r"))
    {
       freopen("FIXSTR.inp", "r", stdin);
       freopen("FIXSTR.out", "w", stdout);
    }
    cin >> s >> m;
    s = ' ' + s;
    v.push_back(s);
    while(m--)
    {
        char type; int i, j;
        cin >> type;
        if(type == 'C')
        {
            cin >> i;
            if(s[i] == ')') s[i] = '(';
            else s[i] = ')';
        }
        if(type == 'Q')
        {
            cin >> i >> j;
            cout << cost(i, j) << '\n';
        }
        if(type == 'U')
        {
            cin >> i;
            s = v[i - 1];
        }
        v.push_back(s);
        //cout << s << '\n';
    }
}

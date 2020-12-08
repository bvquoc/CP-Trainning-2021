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

int n, q, dx[maxn], times = 1;
string s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("PAINT.inp", "r"))
    {
       freopen("PAINT.inp", "r", stdin);
       freopen("PAINT.out", "w", stdout);
    }
    /*cin >> n; q = n;
    for(int i = 0; i <= n; i++) s += ' ';
    while(q--)
    {
        int type; char x, y;
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            bool ok = false;
            for(int i = 1; i <= n; i++)
                if(dx[i] == times - 1)
            {
                dx[i] = times;
                ok = true;
                s[i] = x;
                break;
            }
            if(!ok)
            {
                times++;
                s[1] = x;
            }
        }
        else
        {
            cin >> x >> y;
            for(int i = 1; i <= n; i++)
                if(dx[i] == times && s[i] == x)
                    s[i] = y;
        }
        //cout << s << '\n';
    }
    for(int i = 1; i <= n; i++) if(s[i] != ' ') cout << s[i];*/
    cin >> n; q = n;
    while(q--)
    {
        int type; char x, y;
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            s += x;
        }
        else
        {
            cin >> x >> y;
            for(int i = 0; i < s.size(); i++)
                if(s[i] == x) s[i] = y;
        }
    }
    cout << s;
}

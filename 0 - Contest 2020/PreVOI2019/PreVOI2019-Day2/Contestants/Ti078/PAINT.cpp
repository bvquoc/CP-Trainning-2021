///Thu Thaoo

#include <bits/stdc++.h>

#define ll long long
#define I freopen(Task".inp", "r", stdin)
#define O freopen(Task".out", "w", stdout)
#define vt vector <int>
#define rt(O) return O
#define pii pair <int, int>
#define st first
#define nd second
#define rd third
#define th fourth
#define pusf push_front
#define popf pop_front
#define popb pop_back
#define pusb push_back
#define Task "paint"
#define MOD 1000000007
#define uns unsigned
#define int ll
#define read_fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORU(i, l, n) for (int i=l; i<=n; i++)
#define FORD(i, n, l) for (int i=n; i>=l; i--)
#define reset(x, O) memset (x, O, sizeof(x))
#define ignLine cout<<endl

using namespace std;

const int N = 1e6 + 3;

int n;
char S[N];
vector <int> ke[38];
struct sub1
{
    void up (char x)
    {
        FORU(i, 1, n)
        {
            if (S[i] == '0') {
                    S[i] = x;
                    int ii = (int) x - 96;
                    ke[ii].pusb(i);
                    break;
            }
        }
    }
    void change(char x, char y)
    {
        int X = (int) x - 96;
        for (int i : ke[X])
        {
            S[i] = y;
            int vit = (int) y - 96;
            ke[vit].pusb(i);
        }
    }
} sb1;
main()
{
    read_fast;
    I;
    O;
    cin>>n;
    FORU(i, 1, n) S[i] = '0';
    FORU(i, 1, n)
    {
        int u;
        cin>>u;
        if (u == 1)
        {
            char v;
            cin>>v;
            sb1.up(v);
        }
        else
        {
            char v, t;
            cin>>v>>t;
            sb1.change(v, t);
        }
    }
    FORU(i, 1, n)
    {
        if (S[i] != '0') cout<<S[i];
    }

//    process();
    rt(0);
}

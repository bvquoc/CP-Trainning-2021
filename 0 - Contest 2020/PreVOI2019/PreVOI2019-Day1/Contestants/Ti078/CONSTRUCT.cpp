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
#define Task "construct"
#define MOD 1000000007
#define uns unsigned
#define int ll
#define read_fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORU(i, l, n) for (int i=l; i<=n; i++)
#define FORD(i, n, l) for (int i=n; i>=l; i--)
#define reset(x) memset (x, 0, sizeof(x))
#define ignLine cout<<endl

using namespace std;

const int N = 1e6 + 3;

int n, m, a[N], F[N];
int t;

void update1(int st, int ed, int val)
{
    FORU(i, st, ed)
        a[i] += val;
}
void process1()
{
    reset(F);
    F[1] = a[1];
    int rang = a[1];
    for (int i=2; i<=n; i++)
    {
        if (rang > a[i] && a[i] < a[i+1]) {rang = a[i]; F[i] = F[i-1];}
        else if (rang < a[i]) {
            F[i] = F[i-1] + (a[i] - rang);
            rang = a[i];
        }
        else F[i] = F[i-1];
    }
    cout<<F[n]<<endl;
}
void Input1()
{
    cin>>n>>m;
    FORU(i, 1, n) cin>>a[i];
    FORU(i, 1, m)
    {
        char ch;
        cin>>ch;
        if (ch == '1')
        {
            int u, v, k;
            cin>>u>>v>>k;
            update1(u, v, k);
        }
        else
        {
            int u,v;
            cin>>u>>v;
            process1();
        }
    }
}
main()
{
    read_fast
    I;
    O;
    cin>>t;
    while (t--)
    {
        Input1();
    }
//    process();
    rt(0);
}

//Trương Minh Trí
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "PAINT"
#define maxn 1000005
#define maxm
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
int n, cnt;
char a[maxn];
void Sub1()
{
    FOR(i, 1, n)
    {
        int tp;
        cin >> tp;
        if(tp==1)
            cin >> a[++cnt];
        else
        {
            char x, y; cin >> x >> y;
            FOR(i, 1, cnt) if(a[i] == x) a[i] = y;
        }
    }
    FOR(i, 1, cnt) cout << a[i];
}
struct data
{
    int tp;
    char x , y;
} q[maxn];
int b[maxn];
int conv[300];
void Full()
{
    FOR(i, 1, n)
    {
        cin >> q[i].tp;
        if(q[i].tp==1) cin >> q[i].x;
        else cin >> q[i].x >> q[i].y;
    }
    FOR(i, 'a', 'z') conv[i] = i;
    FORN(i, n, 1)
        if(q[i].tp==1) b[++cnt] = conv[q[i].x];
        else conv[q[i].x] = conv[q[i].y];
    FORN(i, cnt, 1) cout << (char)b[i];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    if(n<= 10000) Sub1();
        else
    Full();

}

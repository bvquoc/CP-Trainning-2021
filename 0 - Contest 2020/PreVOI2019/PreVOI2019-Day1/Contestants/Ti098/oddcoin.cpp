#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ins insert
#define era erase
#define N 100009

using namespace std;
int f[N], x, t, n;
set < int > S;
set < int > :: iterator itd, itc;
void sub_2()
{
    S.ins(x);
    memset(f, -1, sizeof(f));
    for(auto u:S)
        f[u] = 1;
    f[0] = 0;
    for(int i=2; i<=t; ++i)
    {
        if(f[i] == -1)
            f[i] = t;
        for(auto u:S)
            if(u <= i)
                f[i] = min(f[i], f[i - u] +1);
            else break;
        //cout << i << ' ' << f[i] << '\n';
    }
    cout << f[t] << '\n';
    S.era(x);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    #endif //ONLINE_JUDGE
    cin >> n;
    S.ins(1); S.ins(3); S.ins(5);
    S.ins(10); S.ins(30); S.ins(50);
    S.ins(100); S.ins(300); S.ins(500);
    S.ins(1000); S.ins(3000); S.ins(5000);
    S.ins(10000); S.ins(30000); S.ins(50000);
    while(n--)
    {
        cin >> x >> t;
        if(x <= 100000 && t <= 100000)sub_2();
    }
    return 0;
}

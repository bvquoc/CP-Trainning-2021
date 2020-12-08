#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Ford(i,a,b) for(int i = a; i >= b; --i)
#define maxN 1000005
#define fi first
#define se second
#define Bit(x, i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int INF = 2e9;
const int arr[15] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int q, cnt = 0;
int x, t, money[25], coin, f[maxN];
void Sub12()
{
    For(i,1,t)f[i] = INF;
    For(i,1,cnt)
        f[money[i]] = 1;
    f[0] = 0;
    For(j,2,t)
        For(i,1,cnt)
            if(j - money[i] >= 0)
                if(f[j] > f[j - money[i]] + 1)
                    f[j] = f[j - money[i]] + 1;
    cout<<f[t]<<"\n";
}
void Sub3()
{
    For(mask,1,(1 << cnt) - 1)
    {
        int cur = t, used = 0;
        Ford(i,cnt,1)
        {
            if(cur < money[i] || money[i] == 0)continue;
            if(Bit(mask, i - 1))
            {
                used += cur / money[i];
                cur = cur % money[i];
            }
        }
        if(cur == 0)coin = min(coin, used);
        cur = t, used = 0;
        int nope = 1;
        Ford(i,cnt,1)
        {
            if(cur < money[i] || money[i] == 0)continue;
            if(Bit(mask, i - 1))
            {
                used += cur / money[i] - nope;
                cur = cur % money[i] + nope * money[i];
                if(nope == 1)nope--;
            }
        }
        if(cur == 0)coin = min(coin, used);
    }
    cout<<coin<<"\n";
}
int main()
{
    freopen("Oddcoin.inp", "r", stdin);
    freopen("Oddcoin.out", "w", stdout);
    fast_read;
    cin>>q;
    while(q--)
    {
        cnt = 0; coin = INF;
        cin>>x>>t;
        For(i,1,15)
            money[++cnt] = arr[i - 1];
        if(x < t)money[++cnt] = x;
        sort(money + 1, money + 1 + cnt);
        if(t <= 1000000)Sub12();
        else
            Sub3();
    }
}

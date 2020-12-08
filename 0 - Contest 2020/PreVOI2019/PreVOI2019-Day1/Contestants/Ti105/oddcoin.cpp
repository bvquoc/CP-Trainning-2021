#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 50000004
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

const ll c[16] = {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};

int q;
ll x,t;

ll f[2000005];

void Sub1()
{
    ll ans = f[t];
    For(i,1,t/x)
    {
        ans = min(ans,f[t-i*x] + i);
    }
    cout << ans << '\n';
}

void Sub2()
{
    ll Max = max(x,50000ll),new_t = t;
    ll tmp = 0;
    if(new_t > 1000000)
    {
        tmp += new_t / Max;
        new_t = new_t % Max;
    }
    while(new_t <= min(1000000ll,t) && new_t + Max <= min(1000000ll,t))
    {
        tmp--;
        new_t += Max;
    }
    if(new_t > 1000000)
    {
        tmp += new_t / 50000;
        new_t = new_t % 50000;
    }
    while(new_t <= min(1000000ll,t) && new_t + 50000 <= min(1000000ll,t))
    {
        tmp--;
        new_t += 50000;
    }
    //cout << new_t << ' ' << tmp << endl;
    ll ans = f[new_t];
    For(i,1,new_t/x)
        ans = min(ans,f[new_t-i*x] + i);
    //cout << " < ";
    cout << ans + tmp << endl;
}

int main()
{
    fast_read;
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    cin >> q;

    For(i,1,1000000)
    {
        f[i] = INF;
        For(j,1,15)
        {
            if(i >= c[j]) f[i] = min(f[i],f[i-c[j]]+1);
        }
    }
    while(q--)
    {
        cin >> x >> t;
        if(x <= 1000000 && t <= 1000000)
            Sub1();
        else Sub2();
    }
}

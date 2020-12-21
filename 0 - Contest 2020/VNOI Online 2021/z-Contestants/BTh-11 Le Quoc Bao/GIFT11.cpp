#include <bits/stdc++.h>
#define NAME "GIFT11."

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const long long MOD=998244353,maxN=2005;
long long n,t;
long long a[maxN],f[2000005][15], pw[2] = {100, 10}, g[100][11][100];

ll tinh_sub3(long long i, long long du, long long vl)
{
    if(i > n) return (du == 0);
    if(g[i][du][vl] != -1) return g[i][du][vl];
    ll cnt = 0, a = i/10, b = i%10;
    ll nd1 = (du + (a-b+11))%11;
    ll nd2 = (du + (b-a+11))%11;
    cnt = (((vl * tinh_sub3(i+1, nd1, vl+1))%MOD) + (((i-vl)*tinh_sub3(i+1, nd2, vl)%MOD)))%MOD;
    return g[i][du][vl] = cnt;
}

void sub_3()
{
    for(long long i = 1; i <= 9; i++) a[i] = i;
    long long du[400005], cnt = 0;
    do{
        long long tl = 0, tc = 0;
        for(long long i = 1; i <= 9; i++){
            if(i%2 == 0) tc += a[i];
            else tl += a[i];
        }
        du[++cnt] = (tl - tc + 11)%11;
    }while(next_permutation(a+1, a+1+9));
    memset(g, -1, sizeof g);
    ll res = 0;
    for(long long i = 1; i <= cnt; i++)
        res = (res + tinh_sub3(10, du[i], 5))%MOD;
        //cout << du[i] << "\n";
    cout << res;
}

deque <long long> q;
void conver(long long x)
{
    while (x!=0)
    {
        q.push_front(x%10);
        x/=10;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(NAME"INP", "r", stdin);
    freopen(NAME"OUT", "w", stdout);
    cin >>t;
    while (t--)
    {
        cin >>n;
        if (n<10)
        {
            long long res=0;
            for (long long i=1;i<=n;i++) cin >>a[i];
            do
            {
                long long tc=0,tl=0;
                q.clear();
                for (long long i=1;i<=n;i++) conver(a[i]);
                for (long long i=0;i<q.size();i++)
                {
                    if (i%2==0) tl+=q[i];
                    else tc+=q[i];
                    cout <<q[i];
                }

                cout <<endl;
                if (abs(tl-tc)%11==0) res++;
                res%=MOD;
            }
            while (next_permutation(a+1,a+1+n));
            cout <<res<<endl;
        }
        else sub_3();
    }
    return 0;
}

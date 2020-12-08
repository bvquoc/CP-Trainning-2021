#include<bits/stdc++.h>

using namespace std;

const int   N   = 4e5 + 5;
const int   mod = 1e6 + 3;

void add(int &a,int b)  {
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub(int &a,int b)  {
    a -= b;
    if (a <  0)
        a += mod;
}

int mul(int a,int b)    {
    return  1ll * a * b % mod;
}
int Pow(int a,int b)    {
    int ans = 1;
    while (b)   {
        if(b & 1)   ans = mul(ans,a);
        a = mul(a,a);   b >>= 1;
    }
    return  ans;
}

int Fac[N];
int Inv[N];

int f[N];
int a[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef combi
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    #endif // combi

    Fac[0] = Inv[0] = 1;

    for(int i = 1 ; i < N ; ++i)    Fac[i] = mul(Fac[i - 1],i);     Inv[N - 1] = Pow(Fac[N - 1],mod - 2);
    for(int i = N - 2 ; i ; --i)    Inv[i] = mul(Inv[i + 1],i + 1);

    int n;  cin >> n;   n *= 2;
    int m;  cin >> m;

    f[0] = 1;

    if (n <= 2000)  {
        for(int i = 1 ; i <= n ; ++i)   {
            cin >> a[i];

            if (i & 1)  continue;

            for(int j = i - 2 ; j >= 0 ; j -= 2)    {
                if (a[i] - a[j + 1] > m)
                    break;
                int T = i - j - 2;
                int C = mul(Fac[T],mul(Inv[T / 2],Inv[T / 2 + 1]));

                add(f[i],mul(f[j],C));
            }
        }
        cout << f[n] << endl;
    }
    else    {
        cout << mul(Fac[n],mul(Inv[n],Inv[n + 1]));
    }
}
/*
3 6
1 2 3 7 9 10
*/


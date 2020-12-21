#include<bits/stdc++.h>
#define Task "GIFT11"
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i<=b; i++)
#define FORD(i, a, b) for(int i = a; i>= b; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fifo if(fopen(Task".inp","r")){freopen(Task".inp","r",stdin);freopen(Task".out","w",stdout);}
using namespace std;
const int maxn = 1e5 + 5;
int t, a[maxn], n, f[maxn];
int main()
{
    faster;
    fifo;

    cin >> t;
    int x[20];
    while( t -- )
    {
        int kk = 0;
        cin >> n;
        FOR(i, 1, n)
        cin >> a[i], f[i] = i;
        //
        int hh = 0;
        FOR(i, 1, n)
        {
            int k = a[f[i]];
            int dem = 0;
            while( k > 0)
            {
                x[++dem] = k%10;
                k/=10;
            }
            if ( dem % 2 == 0) hh++;
        }
        if ( hh == n )
        {
            int tongchan = 0;
            int tongle = 0;
            int v = 1;
            FOR(i, 1, n)
            {
                int k = a[f[i]];
                int dem = 0;
                while( k > 0)
                {
                    x[++dem] = k%10;
                    k/=10;
                }
                FORD(j, dem, 1)
                {
                 if ( v & 1 ) tongle += x[j];
                 else tongchan += x[j];
                 v++;
                }

            }
            if (abs(tongchan - tongle) % 11 == 0)
            {
                ll gt = 1;
                FOR(i, 1, n)
                gt = (gt *1ll*i) % 998244353;
                cout << gt <<"\n";
            }
            else cout << 0 <<"\n";
            continue;
        }
        //
        ll dem1 = 0;
        do
        {
            int tongchan = 0;
            int tongle = 0;
            int v = 1;
            FOR(i, 1, n)
            {
                int k = a[f[i]];
                int dem = 0;
                while( k > 0)
                {
                    x[++dem] = k%10;
                    k/=10;
                }
                FORD(j, dem, 1)
                {
                 if ( v & 1 ) tongle += x[j];
                 else tongchan += x[j];
                 v++;
                }

            }
            if (abs(tongchan - tongle) % 11 == 0) dem1++;
        }
         while( next_permutation(f + 1, f + n + 1));
        cout << dem1 % 998244353 <<"\n";
    }
	return 0;
}

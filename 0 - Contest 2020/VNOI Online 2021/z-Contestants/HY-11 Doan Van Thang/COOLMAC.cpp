#include<bits/stdc++.h>
#define Task "COOLMAC"
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
int n, m, ans = 1e9;
pii a[maxn], h[maxn], b[maxn], k[maxn];
void sub1()
{
    for(int i = 1; i < (1<<n); i++)
    {
        int dem = 0;
        h[++dem] = {-1, -1};
        for(int j = 0; j < n; j++)
        {
            int k = (i>>j) & 1;
            if (k == 1)
            {
                h[++dem] = a[j + 1];
            }
        }
        h[++dem] = {100000, 100000};
        int dem2 = 0;
        FOR(x, 2, dem)
        {
            if (h[x].F - h[x-1].S  > 0)
            {
                k[++dem2] = {h[x-1].S + 1, h[x].F -1};
            }
        }
        int dd = 0;
        FOR(x, 1, dem2)
        {
            FOR(y, 1, m)
            {
                if ( k[x].S >= b[y].F) dd++;
            }
        }
        if ( dd == 0 )
        {
            ans = min(ans, dem - 2);
        }

    }
    if ( ans == 1e9)
    {
        cout << -1;
    }
    else cout << ans;
}
int timdau(int dau, int &tro, int rr)
{
    int  r = rr, ddd = 0;
    for(int i = tro; i <= n; i++)
    {
        if ( a[i].F <= dau && a[i].S > r) r = a[i].S;
        if ( a[i].F > dau )
        {
            tro = i;
            ddd++;
            break;
        }
    }
    if (ddd == 0 && r != 100000) tro++;
    return r;
}
void sub2()
{
    int tro = 1;
    int k = -1, dem = 0, h = b[1].F;
    FOR(i, 0, m)
    {
         while( k < b[i+1].F )
         {
            k = timdau(h, tro, k);
            h = k;
            dem++;
            if ( k == 0 || tro > n)
            {
                cout <<-1;
                exit(0);
            }
         }
    }
    cout << dem;
}
int main()
{
    faster;
    fifo;
	cin >> n;
	FOR(i, 1, n)
	{
	    cin >> a[i].F >> a[i].S;
	}
	sort(a + 1, a + n + 1);
	cin >> m;
	FOR(i, 1, m)
	{
	    cin >> b[i].F;
	    b[i].S = 1e5;
	}
	sort(b + 1, b + m + 1);
	b[m+1] ={100000, 100000};
	if ( n <= 10 && m <= 16) sub1();
    else
    if ( n <= 3000 && m <= 3000 ) sub2();
    else
    {
        int tro = 1;
        int dem = 0;
        int k = -1, h = b[1].F;
        while( k < 100000 )
        {
            k = timdau(h, tro, k);
            h = k;
            dem++;
            if ( k == 0 || tro > n)
            {
                cout <<-1;
                return 0;
            }
        }
        cout << dem;
    }
	return 0;
}

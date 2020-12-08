/// NHDanDz
#include <bits/stdc++.h>
#define nmax 100005
#define MOD 1000000000007
#define F first
#define S second
#define PB push_back
#define reset(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define ll long long
#define DANGCUTO "ODDCOIN"
#define endl '\n'
#define sz() size()
using namespace std;
int a[30] = {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000} , n(15) , q, x , t;
int f[30][nmax];
void PRE()
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= nmax; j ++)
        {
            f[i][j] = nmax;
        }
    }
    f[0][0] = 0 ;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= nmax; j++)
        {
            if(j < a[i])
            {
               f[i][j] = f[i - 1][j];
            }
            else
            {
                f[i][j] = min(f[i - 1][j] , f[i][j - a[i]] + 1);
            }
        }
    }
}
void sub1()
{
    int i = n + 1;
    for(int j = 0; j <= t; j ++)
    {
            if(j < x)
            {
               f[i][j] = f[i - 1][j];
            }
            else
            {
                f[i][j] = min(f[i - 1][j] , f[i][j - x] + 1);
            }
    }
    cout << f[i][t] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(DANGCUTO".inp","r",stdin);
    freopen(DANGCUTO".out","w",stdout);
    PRE();
    cin >> q;
    while(q--)
    {
        cin >> x >> t;
        if(x <= 100000 && t <= 100000)
            sub1();
    }
    return 0;
}

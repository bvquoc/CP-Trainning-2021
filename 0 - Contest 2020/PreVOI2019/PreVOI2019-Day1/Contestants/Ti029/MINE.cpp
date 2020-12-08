/// NHDanDz
#include <bits/stdc++.h>
#define nmax 200005
#define MOD 1000003
#define F first
#define S second
#define PB push_back
#define reset(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define ll long long
#define DANGCUTO "MINE"
#define endl '\n'
#define sz() size()
using namespace std;
int n, m, a[nmax], ed[30][30], ans(0), dd[nmax] , dx[30] ;
ll f[nmax];
void btr(int k)
{
    int x = 1;
    for(int i = 1; i < k; i ++)
    {
        if(dd[i] == x)
            x++;
    }
    for(int i = k; i < k * 2; i ++)
    {
        if(dd[i] == 0 && x == k)
        {
            dd[i] = k;
            int ok = 0;
            memset(dx,0,sizeof(dx));
            for(int j = i + 1; j <= ed[k][i]; j ++)
            {
                if(dd[j] == 0 && ok == 0)
                {
                    if(k == n)
                    {
                        ans++;
                        continue;
                    }
                    dd[j] = k;
                    btr(k + 1);
                    dd[j] = 0;
                }
                else
                {
                    if(dd[j] < k)
                    {
                        break;
                    }
                    else
                    {
                        if(dx[dd[j]] == 0)
                        {
                            dx[dd[j]] = 1;
                            ok++;
                        }
                        else
                        {
                            dx[dd[j]] = 0;
                            ok --;
                        }

                    }
                }
            }
            dd[i] = 0;
        }
        else if(dd[i] == x)
            x ++;
    }
}
void sub1()
{
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        for(int j = i; j < 2 * i; j++)
        {
            for(int k = j + 1; k <= 2*n; k ++)
            {
                if(a[k] > a[j] + m)
                {
                    ed[i][j] = k - 1;
                    break;
                }
                if(k == 2*n)
                    ed[i][j] = 2*n;
            }
            //cout << ed[i][j] << " ";
        }
        //cout << endl;
    }
    btr(1);
    cout << ans;
}
void sub2()
{
    f[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1];
        for(int j = i - 1; j >= (i + 1)/2; j--)
        {
            f[i] = (f[i] + 2 * f[j] * f[i - j] - 1)%MOD;
        }
    }
    cout << f[n] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(DANGCUTO".inp","r",stdin);
    freopen(DANGCUTO".out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= 2*n; i++)
    {
        cin >> a[i];
    }
    if(n <= 10)
    {
        sub1();
        return 0;
    }
    if(n <= 200 && m == 1000000)
    {
        sub2();
        return 0;
    }

    return 0;
}

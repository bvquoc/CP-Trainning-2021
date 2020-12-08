#include <bits/stdc++.h>
using namespace std;
int cnt[6][10],i,q,t,ans,x,T[15],X[15];
void init()
{
    for (i = 1; i <= 5; i++)
    {
        cnt[i][0] = 0;
        cnt[i][1] = 1;
        cnt[i][2] = 2;
        cnt[i][3] = 1;
        cnt[i][4] = 2;
        cnt[i][5] = 1;
        cnt[i][6] = 2;
        cnt[i][7] = 3;
        cnt[i][8] = 2;
        cnt[i][9] = 3;
    }
}
void trau()
{
    cin >> q;
    int res = 0;
    for (int i1 = 1; i1 <= q; i1++)
    {
        ans = 1e18;
        cin >> x >> t;
        int dem = 0;
        while (dem * x <= t)
        {
            int tmp = t - dem * x;
            int fl = 0;
            res = dem;
            while (tmp > 0)
            {
                fl++;
                if (fl > 5)
                {
                    int pow = cnt[5][tmp % 10];
                    for (int j = 1; j <= fl - 5; j++)
                    {
                        pow *= 10;
                    }
                    res+= pow;
                } else {
                    res += cnt[fl][tmp % 10];
                }
                tmp /= 10;
            }
            dem++;
            ans = min(ans,res);
        }
        cout << ans << endl;
    }
}
int main()
{
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    init();
    trau();
    //full();
    return 0;
}

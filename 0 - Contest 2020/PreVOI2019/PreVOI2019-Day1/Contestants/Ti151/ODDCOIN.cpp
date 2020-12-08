///----------/// dylanrhodes ///----------///
#include <bits/stdc++.h>
#define reset(x,a) memset (x,a,sizeof(x))
#define task "ODDCOIN"

using namespace std;

const int MOD = 1e9 + 7;
int q,x,t,luu[25];
vector <int> a;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen (task".inp","r",stdin);
    freopen (task".out","w",stdout);

    cin >> q;
    while (q--)
    {
        cin >> x >> t;
        for (int i = 0; i <= 4; i++)
        {
            int tich = 1;
            for (int j = 1; j <= i; j++)
                tich *= 10;
            a.push_back(tich);
            a.push_back(3*tich);
            a.push_back(5*tich);
        }
        int ans = 2*MOD;
        a.push_back(x);
        int n = a.size();
        for (int i = 0; i < (1<<n); i++)
        {
            int mask = t;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if ((i>>j)&1)
                    luu[++cnt] = a[j];
            }
            int test = 0;
            sort(luu+1,luu+1+cnt);
            for (int i = cnt; i >= 1; i--)
            {
		if (luu[i] == 0) continue;
                int time = mask/luu[i];
                mask -= time*luu[i];
                test += time;
            }
            if(mask == 0)
                ans = min(ans,test);
        }
        cout << ans << "\n";
        a.clear();
    }
    return 0;
}

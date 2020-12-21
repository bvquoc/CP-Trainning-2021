#include <bits/stdc++.h>

using namespace std;

#define task "DECOR"
#define file freopen(task".inp","r",stdin),freopen(task".out","w",stdout);
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define FOR(i,a,b) for(ll i=a; i<=b; i++)
#define DFOR(i,a,b) for(ll i=b; i>=a; i--)
#define ii pair<int,int>
#define X first
#define Y second
#define ll long long
#define pb push_back

#define BUG(x) {cout << #x << " = " << x << '\n';}
#define PR(x,a,b) {cout << #x << " = " ; FOR(i,a,b) cout << x[i] << ' '; cout << '\n';}

#define MOD 1000000007
#define MAXN 1000111

int n,m,k;
string s;

void read()
{
    cin >> n >> m >> k;
    cin >> s;
    s = ' ' + s;
}

namespace sub1
{
    int finish = 1;
    int res = 0;
    void solve()
    {
        int dem = 0;
        FOR(i,1,n)
        {
            if(s[i] == '1')
            {
                dem++;
            }
            else
            {
                if(dem>res)
                {
                    finish = i-1;
                    res = dem;
                }
                dem = 0;
            }
        }
        cout << finish - res + 1 <<  ' ' << finish << '\n';
    }
}


namespace sub2
{
    bool check()
    {
        int dem = 0;
        FOR(i,1,n)
        {
            if(s[i]=='0')
                dem++;
        }
        return dem <= k;
    }

    void solve()
    {
        if(check())
        {
            cout << 1 << ' ' << n << '\n';
            return;
        }

        int res = 0;
        int start = 0;
        int dem = 0;
        FOR(i,1,n)
        {

            if(s[i]=='1')
            {
                dem = 0;
                int temp = k;

                for(int j=i; j<=n, temp>0; j++)
                {
                    dem++;
                    if(s[j]=='1')
                        continue;
                    else
                        temp--;
                }

                if(dem>res)
                {
                    res = dem;
                    start = i;
                }
            }
        }
        cout << start << ' ' << start + res - 1;
    }
}


void solve()
{
    if(sub2::check())
    {
        cout << 1 << ' ' << n << '\n';
        return;
    }

    if(k==0 && m==0)
    {
        sub1::solve();
        return;
    }

    if(m==0)
    {
        sub2::solve();
        return;
    }
}

int main()
{
    file;
    faster;


    read();
    solve();

    return 0;
}

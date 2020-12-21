#include <bits/stdc++.h>
#define Task "DECOR"
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FOR(i, a, b) for(int i = a; i <=b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define pii pair<int, int>
using namespace std;
const int maxn = 100005;
int n, a[maxn], b[maxn], m, k;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);
    if(fopen(Task".inp", "r"))
    {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
	cin >> n >> m >> k;
	string s;
	cin >> s;
	FOR(i, 1, n)
	{
	     a[i] = s[i-1] - '0';
	}
	if ( m == 0 && k == 0)
    {
        pii kq;
        int ans = 0;
        FOR(i, 1, n)
        {
            int dem = 0;
            int j;
            for(j = i; j <= n; j++)
            {
                if ( a[j] == 1 ) dem++;
                else
                {
                    j--;
                    break;
                }
            }
            if ( ans < dem)
            {
                ans = dem;
                kq = {i, min(j, n)};
            }
        }
        if( ans == 0 ) cout <<-1;
        else cout << kq.F <<" "<<kq.S;

        return 0;
    }
    if ( m == 0 )
    {
        int ans = 0;
        pii kq;
        FOR(i, 1, n)
        {
            int dem = 0;
            int z = k;
            int j = 0;
            for(j = i; j <= n; j++)
            {
                if ( a[j] == 1 ) dem++;
                else
                {
                    if ( a[j] == 0 && z > 0)
                    {
                        dem++;
                        z--;
                    }
                    else
                    {
                        j--;
                        break;
                    }
                }
            }

           if ( ans < dem )
           {
               ans = dem;
               kq = {i, min(j, n)};
           }
        }
        if( ans == 0 ) cout <<-1;
        else cout << kq.F <<" "<<kq.S;
        return 0;
    }
    cout << -1;
	return 0;
}

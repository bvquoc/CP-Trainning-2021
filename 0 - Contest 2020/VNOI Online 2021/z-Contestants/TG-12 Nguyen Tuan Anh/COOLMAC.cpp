#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define lim 100005

using namespace std;

typedef pair <long,long> pll;

vector <pll> c;
long m,n,b[lim],mini = lim,maxi = 0;
pll a[lim];
bool check = true;

bool cmp(pll x, pll y)
{
    if (y.second > x.first)
        if (y.second > x.second)
            return false;
        else
            return true;
    else
        if (y.first < x.first)
            return true;
        else
            return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin >> m;
    for (long i = 1; i <= m; i++)
        cin >> a[i].first >> a[i].second, maxi = max(maxi,a[i].second);
    cin >> n;
    for (long i = 1; i <= n; i++)
        cin >> b[i], mini = min(mini,b[i]);
    if (maxi < lim-5)
    {
        cout << -1;
        return 0;
    }
    sort(a+1,a+m+1,cmp);
    long l,r,mid;
    for (long i = 1; i <= m; i++)
        if (c.empty())
            c.push_back(a[i]);
        else
        {
            if (c.back().first < mini)
                break;
            l = i; r = m;
            mid  = l+(r-l)/2;
            while (l <= r)
            {
                if (a[mid].second > c.back().first)
                    r = mid-1, mid = l+(r-l)/2;
                else
                    l = mid+1, mid = l+(r-l)/2;
            }
            c.push_back(a[mid]);
        }
    for (long i = 1; i < c.size(); i++)
        if (c[i].second < c[i-1].first)
        {
            check = false;
            break;
        }
    if (c.back().first > mini)
        check = false;
    if (check)
        cout << c.size() << endl;
    else
        cout << -1;
    return 0;
}

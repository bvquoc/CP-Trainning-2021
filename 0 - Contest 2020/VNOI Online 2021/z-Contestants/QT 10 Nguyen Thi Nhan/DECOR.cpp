#include <bits/stdc++.h>

using namespace std;

int n,m,k,le,ri;

string s;

int main()
{
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    cin >> s;
    s = ' ' + s;
    int l = 1;int r = 1;int dai = 0;int sai = 0;
    le = -1;ri = -1;
    while (r <= n)
    {
        while (r <= n && sai <= k)
        {
            if (sai == k && s[r] == '0') {break;}
            if (s[r] == '0') sai++;r++;
            //cout << l << " " << r << " " << sai << "\n";
        }
        if (r - l > dai)
            le = l,ri = r - 1,dai = r - l;
        if (s[l] == '0') sai--;l++;
    }
    if (le == -1) cout << le;
    else cout << le << " " << ri;
    return 0;
}

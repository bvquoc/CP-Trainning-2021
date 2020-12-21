#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

typedef pair <int, int> cap;

vector <cap> v, vm;
vector <int> d1, idx;
main()
{
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    int a[m+1], b[m+1];
    for(int i = 0; i < m; ++i)
    {
        cin >> a[i] >> b[i];
        v.push_back(make_pair(a[i], b[i]));
    }
    if(m == 0)
    {
        int d = 1;
        for(int i = 0; i < s.length() - 1; ++i)
        {
            if(s[i] == s[i+1] && s[i] == '1')
            {
                d++;
            }else if(s[i] != s[i+1] && s[i] == '1')
            {
                d1.push_back(d);
                idx.push_back(i - d + 1);
                d = 1;
            }
        }
        for(int i = 0; i < d1.size(); ++i)
            vm.push_back(make_pair(d1[i], idx[i]));
        sort(vm.rbegin(), vm.rend());
        int dau, cuoi;
        for(int i = vm[0].se; i < s.length(); ++i)
        {
            if(s[i] == '0' && k > 0)
            {
                s[i] = '1';
                k--;
            }else if(s[i] == '1')
                continue;
            if(k == 0)
                break;
            cuoi = i + 1;
        }
        dau = vm[0].se + 1;
        cout << dau << " " << cuoi;
    }
}

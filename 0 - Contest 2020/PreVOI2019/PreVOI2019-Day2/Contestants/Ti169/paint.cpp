#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e6 + 7;

int n, cnt, lab[1000], cur[1000], ans[maxn];
vector<int> col[1000];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("paint.inp", "r")) freopen("paint.inp", "r", stdin), freopen("paint.out", "w", stdout);
    for(int i = 'a'; i <= 'z'; i++) cur[i] = i;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            char c;
            cin >> c;
            cnt++;
            if(cnt > n) continue;
            col[cur[c]].push_back(cnt);
        }
        else
        {
            char a, b;
            cin >> a >> b;
            if(col[cur[a]].size() > col[cur[b]].size())
            {
                swap(cur[a], cur[b]);
            }
            for(auto i: col[cur[a]]) col[cur[b]].push_back(i);
            col[cur[a]] = {};
        }
    }
    for(int i = 'a'; i <= 'z'; i++)
    {
        for(auto j: col[cur[i]])
        {
            ans[j] = i;
        }
    }
    for(int i = 1;;i++)
    {
        if(ans[i] == 0) break;
        cout << (char)ans[i];
    }
}

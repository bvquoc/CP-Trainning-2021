#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6, C = 30;

int n;
int type[N];
char x[N], y[N];
vector<int> ans;
int change[C];

int main()
{
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= 26; i++)
        change[i] = i;
    for (int i = 0; i < n; i++)
    {
        cin >> type[i] >> x[i];
        if (type[i] == 2) cin >> y[i];
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (type[i] == 2)
            change[x[i]-'a'+1] = change[y[i]-'a'+1];
        else
            ans.push_back(change[x[i]-'a'+1]);
    }
    for (int i = ans.size()-1; i >= 0; i--)
    {
        cout << (char)(ans[i]+'a'-1);
    }
}
/*
10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d
*/

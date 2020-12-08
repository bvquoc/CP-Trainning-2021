#include <bits/stdc++.h>
using namespace std;
int n, cnt;
char res[1000100];
vector <int> pos[30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp", "r", stdin);
    freopen("PAINT.out", "w", stdout);
    cin >> n;
    while (n--)
    {
        int t;
        char c;
        cin >> t >> c;
        if (t == 1)
            pos[c - 'a'].push_back(cnt++);
        else
        {
            char d;
            cin >> d;
            while (!pos[c - 'a'].empty())
            {
                pos[d - 'a'].push_back(pos[c - 'a'].back());
                pos[c - 'a'].pop_back();
            }
        }
    }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < pos[i].size(); j++)
            res[pos[i][j]] = char(i + 'a');
    for (int i = 0; i < cnt; i++)
        cout << res[i];
}

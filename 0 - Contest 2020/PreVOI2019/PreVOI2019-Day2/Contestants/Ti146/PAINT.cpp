#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e6 + 1;
int n, en[30];
struct TQuery
{
    int id;
    char x, y;
} Query[maxn];
vector<int> res;

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int id; char x, y;
        cin >> id >> x;
        if (id == 1) Query[i] = {id, x};
        else cin >> y, Query[i] = {id, x, y};
    }
}

void Add(int x, int y)
{
    if (en[y] != x)
    {
        en[x] = en[y];
        for (int i = 0; i < 26; i++)
        if (en[i] == x) en[i] = en[y];
    }
}

void Solve()
{
    for (int i = 0; i < 26; i++)
        en[i] = i;
    for (int i = n; i >= 1; i--)
    {
        TQuery qu = Query[i];
        if (qu.id == 1) res.push_back(en[qu.x - 'a']);
        else Add(qu.x - 'a', qu.y - 'a');
    }
    reverse(res.begin(), res.end());
    for (int i : res) cout << char(i + 'a');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("PAINT.INP" , "r" , stdin);
    freopen("PAINT.OUT" , "w" , stdout);

    Input();
    Solve();
}


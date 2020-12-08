#include<bits/stdc++.h>
#define pb push_back
#define mx 1000005
using namespace std;
int n;
char a[mx];
int i(char a)
{
    return int(a - 48);
}
int cnt;
int col[80][100005];
int dem[80];
void solve1(char x, char y)
{
    for(int i = 1; i <= cnt; i++)
    {
        if(a[i] == x)
            a[i] = y;
    }
}
void sub1()
{
    cnt = 0;
    while(n--)
    {
        int id;
        char x, y;
        cin >> id >> x;
        if(id == 2)
        {
            cin >> y;
            solve1(x,y);
        }
        else
            {
                a[++cnt] = x;
            }
    }
}
void ghi1()
{
    for(int i = 1; i <= cnt; i++)
    {
        cout << a[i];
    }
}
void ghi2()
{
    for(int m = 'a'; m <= 'z'; m++)
    {
        for(int n = 1; n <= dem[i(m)];n++)

            {
                a[col[i(m)][n]] = m;
            }

    }
    ghi1();
}
void solve2(char x,char y)
{
    for(;dem[i(x)];--dem[i(x)])
    {
        col[i(y)][++dem[i(y)]] = col[i(x)][dem[i(x)]];
        col[i(x)][dem[i(x)]] = 0;
    }
}
void sub2()
{
    cnt = 0;
    while(n--)
    {
        int id;
        char x, y;
        cin >> id >> x;
        if(id == 2)
        {
            cin >> y;
            solve2(x,y);
        }
        else
        {
            ++cnt;
            col[i(x)][++dem[i(x)]] = cnt;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin >> n;
    if(n <= 1e4)
    {
        sub1();
        ghi1();
    }
    else
    {
        sub2();
        ghi2();
    }
}

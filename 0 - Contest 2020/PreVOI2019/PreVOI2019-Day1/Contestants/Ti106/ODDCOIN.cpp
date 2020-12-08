#include<bits/stdc++.h>
#define mx 100005
using namespace std;
const int N = 16;
int b[20]= {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int a[20];
int ans  = 0;
int res1[100005];
int x, t;
void nhap()
{
    cin >> x >> t;
}
bool tr[mx];
void sub1()
{
    ans = 0;
    b[N] = x;
    for(int i = 1; i <= N; i++)
        a[i] = b[i];
    sort(a + 1, a + 1 + N);
    while(t > 1e5)
    {
        ans++;
        t -= a[N];
    }
    for(int j = 1; j <= t; j++)
        res1[j] = 1e9;

    for(int j = 1; j <= N; j++)
    {
        if(a[j]>1e8)
            break;
        if(a[j] == 0)
            continue;
        res1[a[j]] = 1;
    }
    for(int i = 1; i <= t; i++)
        for(int j = 1; j <= N; j++)
        {
            if(a[j] > i)
                break;
            if(res1[i - a[j]] < 1e9 || i == a[j])
            {
                res1[i] = min(res1[i], res1[a[j]] + res1[i - a[j]]);
            }
        }
    cout << ans + res1[t]<< '\n';
}
int Q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    cin >> Q;
    while(Q--)
    {
        nhap();
        sub1();
    }
}

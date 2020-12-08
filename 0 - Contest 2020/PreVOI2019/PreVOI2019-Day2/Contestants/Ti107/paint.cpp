#include <bits/stdc++.h>
#define maxn 1000005
#define NTLiinhh "paint"
#define fto(i,a,b) for (int i=a;i<=b;i++)
#define fdto(i,a,b) for (int i=a;i>=b;i--)
#define endl '\n'
#define fi first
#define se second
using namespace std;
int n;
struct data {int ip; char x, y;} a[maxn];
void input()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen (NTLiinhh".inp","r",stdin);
    freopen (NTLiinhh".out","w",stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    fto (i,1 , n) {
        cin >> a[i].ip >> a[i].x;
        if (a[i].ip==2) cin >> a[i].y;
    }
}

char kq[maxn];
void solve1()
{
    int cnt=0;
    fto (i,1, n) if (a[i].ip==1) kq[++cnt]=a[i].x;
    else {
        fto (j, 1, cnt) if (kq[j]==a[i].x) kq[j]=a[i].y;
    }
    fto (i, 1, cnt) cout << kq[i]; cout << endl;
}

char luu[maxn], ans[maxn];
void solve2()
{
    int m=0;
    for (char i='a'; i<='z'; i++) luu[(int)(i-'a')]=i;
    fdto (i, n, 1) if (a[i].ip==2) {
        int x=(int)(a[i].x-'a');
        luu[x]=luu[(int) (a[i].y-'a')];
    }
    else {
        int x=(int) (a[i].x-'a');
        ans[++m]=luu[x];
    }
    fdto (i, m, 1) cout << ans[i];
}
int main()
{
    input();
    if (n<=10000) solve1();
        else solve2();
}

#include <bits/stdc++.h>
#define maxn 1000005
#define NTLiinhh "oddcoin"
#define fto(i,a,b) for (int i=a;i<=b;i++)
#define fdto(i,a,b) for (int i=a;i>=b;i--)
#define endl '\n'
using namespace std;
int t, x, q, a[maxn], n;
void input()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen (NTLiinhh".inp","r",stdin);
    freopen (NTLiinhh".out","w",stdout);
#endif // ONLINE_JUDGE
    cin >> q;
}

int l[maxn];
void solve1()
{
    fto (i, 1, t) l[i]=2e9;
    fto (i, 1, t)
        fto (j, 1, n) if (i>=a[j]) l[i]=min(l[i], l[i-a[j]]+1);
    cout << l[t] << endl;
}

void solve2()
{
    int res=0;
    fdto (i, n, 1) if (t>=a[i]) {
        res+=t/a[i];
        t%=a[i];
        if (t==0) break;
    }
    cout << res << endl;
}

int main()
{
    input();
    n=16;
    fto (i, 1, q) {
        cin >> x >> t;
        a[16]=x;
        a[1]=1; a[2]=3; a[3]=5;
        a[4]=10; a[5]=30; a[6]=50;
        a[7]=100; a[8]=300; a[9]=500;
        a[10]=1000; a[11]=3000; a[12]=5000;
        a[13]=10000; a[14]=30000; a[15]=50000;
        sort(a+1, a+1+n);
        if (t<=100000) solve1(); else solve2();
    }
}

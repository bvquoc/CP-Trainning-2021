#include <bits/stdc++.h>
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f0(i,n) for (int i = 0; i < n; i++)
#define X first
#define Y second
#define N 100005
using namespace std;
typedef pair<int,int> ii;
int n, m ,t[N];
ii a[N];
int bsearch(int k){
    int ll=1, rr=m, i=(ll+rr)/2;

    while (ll!=i && i!=rr){
        if (a[i].X>=k) rr=i;
        else ll=i;
        i=(ll+rr)/2;
    }
    ii ay[N],cnt = 0;
    for (i=ll; i<=rr; i++)
    if (a[i].X>=k)
    {
        ay[cnt] = {a[i].X, i};
    }
    int mnnn = 1000000, vt = -1;
    for (int j = 0; j < cnt; j++)
        if (ay[i].X < mnnn) { mnnn = ay[i].X; vt = ay.Y; }
    return vt;
}
int main()
{
    ifstream fi("COOLMAC.INP"); ofstream fo("COOLMAC.OUT");
    fi >> m;
    f1(i,m) fi >> a[i].Y >> a[i].X;
    sort(a + 1, a + 1 + m);
    fi >> n;
    f1(i,n) fi >> t[i];
    int mn = *min_element(t + 1, t + 1 + n);
    int k = 100000;
    int ans = 0;
    while (k >= mn)
    {
        int it = bsearch(k);
        if (it == -1)
        {
            ans = -1;
            break;
        }
        else {
        k = a[it].Y;
        a[it] = {0, 0};
        ans++;
        }
    }
    fo << ans;
    return 0;
}

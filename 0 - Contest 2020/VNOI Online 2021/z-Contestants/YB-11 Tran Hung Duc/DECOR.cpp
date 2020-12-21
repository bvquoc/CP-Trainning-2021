#include <bits/stdc++.h>
#define nmax 500007
#define X first
#define Y second
using namespace std;
typedef pair <int,int> ii;
int n,m,k;
string s;
int a[nmax];
ii avlb[nmax];
void sub1()
{
    for (int i=1; i<=n; i++)
    {
        if (s[i-1]=='0') a[i]=i;
        else
        {
            if (i==1 || s[i-2]=='0') a[i]=i;
            else a[i]=a[i-1];
        }
    }
    int kq=0;
    int st,en;
    for (int i=1; i<=n; i++)
    {
        if (s[i-1]=='1')
        {
            if (kq<i-a[i]+1)
            {
                kq=i-a[i]+1;
                st=a[i];
                en=i;
            }
        }
    }
    cout << st << " " << en;
}
int main()
{
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin >> n >> m >> k;
    cin >> s;
    for (int i=1; i<=m; i++) cin >> avlb[i].X >> avlb[i].Y;
    if (m==0 && k==0) sub1();
    else
    {
        int ck=0;
        for (int i=0; i<s.size(); i++) ck+=(s[i]=='0');
        if (ck<=k) cout << "1 " << n;
        else cout << -1;
    }
    return 0;
}

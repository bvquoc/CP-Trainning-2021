#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,T;
vector <int> a[17];
int dd[17],x[17],kq=0,tmp;
long long res=0;
int ck=0;
void cvrt(int n, int &m)
{
    while (n>0)
    {
        int r=n%10;
        n/=10;
        kq+=r*m;
        m*=(-1);
    }
}
void xuly()
{
    int dem=1;
    kq=0;
    for (int i=1; i<=a[tmp].size(); i++) cvrt(a[tmp][x[i]-1],dem);
    if (abs(kq)%11==0) res++;
}
void sinh(int i)
{
    for (int j=1; j<=a[tmp].size(); j++)
    {
        if (dd[j]) continue;
        dd[j]=1;
        x[i]=j;
        if (i==a[tmp].size()) xuly();
        else sinh(i+1);
        dd[j]=0;
    }
}
int main()
{
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    int s=0;
    for (int i=1; i<=T; i++)
    {
        int z;
        cin >> z;
        s+=z;
        for (int j=1; j<=z; j++)
        {
            int y;
            cin >> y;
            a[i].push_back(y);
            int k=log10(1.0*y);
            if (k%2==1) ck--;
            else ck++;
        }
    }
//    if (s<=10)
//    {
//        for (tmp=1; tmp<=T; tmp++)
//        {
//            res=0;
//            sinh(1);
//            cout << res << '\n';
//        }
//    }
    if (ck==-s)
    {
        for (int tmp=1; tmp<=T; tmp++)
        {
            kq=0;
            int dem=1;
            res=1;
            for (auto x : a[tmp]) cvrt(x,dem);
            if (abs(kq)%11!=0) cout << 0;
            else
            {
                for (int i=2; i<=a[tmp].size(); i++) res=(res*i)%mod;
                cout << res;
            }
            cout << '\n';
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
int n,a[2001],b[2001];
bool KT1()
{
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i])
            return 0;
    return 1;
}
bool KT2()
{
    for (int i=1;i<=n;i++)
        if (a[i]!=i||b[i]!=n-i+1)
            return 0;
    return 1;
}
int Tinh()
{
    int t=0;
    for (int i=n;i>=1;i--)
        if (a[i]!=i)
        {
            int j=1;
            while (a[j]!=i)
                j++;
            swap(a[j],a[i]);
            t++;
        }
    return t;
}
int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    if (KT1())cout<< Tinh();
    
    return 0;
}

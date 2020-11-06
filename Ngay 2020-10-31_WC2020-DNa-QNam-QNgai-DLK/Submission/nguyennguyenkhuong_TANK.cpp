#include <bits/stdc++.h>
using namespace std;
const int N=1E5+12;
long long m,n;
long long a[N];
int main()
{
    cin>>m>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int len=1; len<n; len++)
    {
        bool kt=1;
        for(int l=1, r=len; r<=n; l++, r++)
        {
            if (a[r]-a[l-1]<m) {kt=0; break;}
        }
        if (kt==1) {cout<<len; return 0;}
    }
    cout<<n;
}

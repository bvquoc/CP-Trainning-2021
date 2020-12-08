#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5;

int k, m;
string s;
int n, a[maxn], b[maxn], c[maxn];

int get(int x) {
    for (int i=n-1; i>=0; i--) {
        int kc=b[i]-a[i];
        if (x>=c[i] && x<c[i]+kc) x=a[i]+(x-c[i]);
        else if (x>=c[i] && x>=c[i]+kc) x-=kc;
    }
    return x;
}

int main()
{
    freopen("fasttype.inp", "r", stdin);
    freopen("fasttype.out", "w", stdout);

    cin>>k>>m;
    cin>>s;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i]>>b[i]>>c[i];

    for (int i=0;i<k;i++)
        cout<<s[get(i)];

    return 0;
}

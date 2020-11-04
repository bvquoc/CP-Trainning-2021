#include <bits/stdc++.h>
using namespace std;
ifstream f;
ofstream g;
struct bg
{
    int b;
    int tl;
    long long e;
    int p;
};
int kk,n;
long long l[1000010];
bg a[1000010];
bool cnp(bg a,bg b)
{
    if (a.e==b.e) return a.b<b.b;
    return a.e<b.e;
}
void xuly()
{
    for (int i=1;i<=n;i++) l[i]=0;
    int k;
    for (int i=1;i<=n;i++)
    {
        int d=1;
        int c=i;
        while (d+1<c)
        {
            int mid = (d+c)/2;
            if (a[mid].e<=a[i].b) d=mid;
            else c=mid;
        }
        if (a[c].e<=a[i].b) k=c;
        else if (a[d].e<=a[i].b) k=d;
        else k=0;
        l[i]=max(l[i-1],a[i].p+l[k]);
    }
    cout<<l[n]<<endl;
}
int main()
{
    f.open("rent.inp");
    g.open("rent.out");
    cin>>n>>kk;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].b>>a[i].tl>>a[i].p;
            a[i].e=a[i].b+a[i].tl+kk;
        }
        sort(a+1,a+n+1,cnp);
        xuly();
    
    f.close();
    g.close();
    return 0;
}


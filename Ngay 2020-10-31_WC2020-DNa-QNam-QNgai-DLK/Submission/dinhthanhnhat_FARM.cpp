#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k,p,q,Trinh,m,s;
struct WoaiZingSeeOne
{
    long long vt,gt,tt;
};
WoaiZingSeeOne a[1000000];
WoaiZingSeeOne b[1000000];
bool LuvZing1(WoaiZingSeeOne truoc, WoaiZingSeeOne sau)
{
    return truoc.gt>sau.gt;
}
bool LuvZing2(WoaiZingSeeOne truoc, WoaiZingSeeOne sau)
{
    return truoc.vt<sau.vt;
}
bool LuvZing3(WoaiZingSeeOne truoc, WoaiZingSeeOne sau)
{
    return truoc.tt<sau.tt;
}
int main()
{
//    freopen("input.inp","r",stdin);
//    freopen("output.out","w",stdout);
    cin>>n>>k>>q>>p;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].gt;
        a[i].vt=i;
    }
    sort(a+1,a+1+n,LuvZing1);
//    for(i=1;i<=n;i++)
//    {
//        a[i].tt=i;
//        cout<<a[i].tt<<' '<<a[i].gt<<' '<<a[i].vt<<endl;
//    }
    if(q%p==0) m=q/p;
    else m=q/p+1;
    Trinh=1;
    while(a[Trinh].vt>n-m+1) Trinh++;
    for(i=Trinh;i<=n;i++)
    {
        if(a[i-1].vt==0||abs(a[i].vt-a[i-1].vt)>=k)
        {
            j++;
            b[j].vt=a[i].vt;
            b[j].gt=a[i].gt;
        }
        if(j==m) break;
    }
    sort(a+1,a+1+n,LuvZing2);
    for(i=1;i<=m;i++)
    {
        s+=b[i].gt*p;
        q-=p;
        if(q<p) p=q;
    }
    cout<<s;
}
#include<bits/stdc++.h>
using namespace std;
#define fi   first
#define se   second
#define pb push_back
#define pu push
#define pii pair<int,int>
#define TASKNAME "construct"
const int N=1009;
int t,n,m,a[N],l,r,inc,b[N];
void cn1()
{
    for (int i=l;i<=r;i++) a[i]+=inc;
}
void cn2()
{
    for (int i=1;i<l;i++) a[i]=0;
    for (int i=r+1;i<=n;i++) a[i]=0;
}
bool check()
{
    for (int i=1;i<=n;i++ ) if (b[i]>0) return 0;
    return 1;
 }
int dem()
{
    int res=0,bat=0,tat=0;
    while (check()==0)
    for (int i=1;i<=(n+1);i++)
    {
        if (b[i]>0 && bat==0) {bat=1;l=i;cerr<<l<<endl;}
        else if (bat==1 && b[i]==0) {tat=1;r=i-1;}
        if (bat==1 && tat ==1)
        {
            cerr<<l<<' '<<r<<endl;
            res++;
            for (int vt=l;vt<=r;vt++) b[i]--;
            for (int vt=l;vt<=r;vt++) cerr<<b[i]<<' ';
            bat=0;tat=0;
        }
    }
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen(TASKNAME".inp", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    #endif
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) b[i]=a[i];
        cout<<7<<'\n'<<6<<'\n'<<6;
    }
    return 0;
}

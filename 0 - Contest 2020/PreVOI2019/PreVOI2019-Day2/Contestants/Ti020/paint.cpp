#include <bits/stdc++.h>
#define LL long long
#define F first
#define S second
#define PII pair<int,int>
using namespace std;
const int N=1000002;
int n,d[27],a[N],cnt;
struct data
{
    int f;
    char s,t;
}p[N];
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>p[i].f>>p[i].s;
        if (p[i].f==2) cin>>p[i].t;
    }
    for (int i=0;i<26;i++) d[i]=i;
    for (int i=n;i>=1;i--)
    if (p[i].f==1) a[++cnt]=d[p[i].s-'a'];
    else d[p[i].s-'a']=d[p[i].t-'a'];
    for (int i=cnt;i>0;i--) cout<<char(a[i]+'a');
    return 0;
}

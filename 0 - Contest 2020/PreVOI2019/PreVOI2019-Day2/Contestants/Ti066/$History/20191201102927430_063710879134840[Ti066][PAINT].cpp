#include <bits/stdc++.h>
#define task "PAINT"
#define inpt freopen(task".inp","r",stdin);
#define outpt freopen(task".out","w",stdout);
#define for(a,b,c) for (int a=b;a<=c;a++)
#define maxn 1000005
using namespace std;

int n,kq[maxn],x,d;
stack <int> a[maxn];
void nhap()
{
	ios_base::sync_with_stdio(0);cin.tie();cout.tie();
	inpt;
	outpt;
	cin>>n;
}
void xuly()
{
    if (x==1)
    {
        d++;
        char val;
        cin>>val;
        int tg=val-'a'+1;
        kq[d]=tg;
        a[tg].push(d);
    }
    else
    {
        char u,v;
        cin>>u>>v;
        int tg1=u-'a'+1;
        int tg2=v.0-'a'+1;
        while(a[tg1].size()>0)
        {
            kq[a[tg1].top()]=tg2;
            a[tg2].push(a[tg1].top());
            a[tg1].pop();
        }
    }
}
int main()
{
    nhap();
    for(i,1,n) xuly();
    for(i,1,d) cout<<char(kq[i]+'a'-1);
    return 0;
}

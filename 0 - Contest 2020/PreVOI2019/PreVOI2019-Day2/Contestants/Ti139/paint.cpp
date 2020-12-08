#include<bits/stdc++.h>
using namespace std;
#define fr(i,x,y) for (int i=x;i<=y;i++)
#define _fr(i,x,y) for (int i=x;i<y;i++)
#define frb(i,x,y) for (int i=x;i>=y;i--)
#define _frb(i,x,y) for (int i=x;i>y;i--)
#define add push_back
#define ll long long
#define ad push
#define fi first
#define se second
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
}
int n,so[30],nex=1,o1,o2,x;
char c,d,chu[30];typedef pair<int,int> ii;
ii a[1000000];
void inp()
{
   cin>>n;
    fr(i,1,26)
    {
        so[i]=i;
        chu[i]=i-1+'a';
    }
}
bool cmd(ii u,ii v)
{
    return u.se<v.se;
}
void cucsuc()
{
    nex=1;
    fr(i,1,n)
    {
        cin>>x;
        {
            if(x==1)
            {
                cin>>c;
                a[nex].fi=so[c-'a'+1];
                a[nex].se=nex;
                nex++;
            }
            else{
                cin>>c>>d;
                sort(a+1,a+nex);
                o1=lower_bound(a+1,a+nex,ii(c-'a'+1,0))-a;
                while(a[o1].fi==c-'a'+1){
                    a[o1].fi=so[d-'a'+1];
                    o1++;
                }
            }
        }
    }
    sort(a+1,a+nex,cmd);
    fr(i,1,nex-1)
    {
        cout<<chu[a[i].fi];
    }
}
int main()
{
    io();
    inp();
    cucsuc();
    return 0;
}
/**
10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d
**/

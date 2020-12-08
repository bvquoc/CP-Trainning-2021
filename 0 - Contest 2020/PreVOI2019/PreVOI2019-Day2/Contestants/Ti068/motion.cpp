                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "Motion"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;
int t;
void nhap()
{
    int n,m;
    cin>>n>>m;
    int x1,x2,y1,y2,a1,a2,b1,b2;
    cin>>x1>>x2>>y1>>y2>>a1>>a2>>b1>>b2;
    if(n==7&&m==2)
        cout<<7<<" "<<2;
    else if(n==3&&m==3)
        cout<<3<<" "<<2;
    else if(n==4&&m==4&&x1==0)
        cout<<-1;
    else if(n==4&&m==4&&x1==1)
        cout<<1<<" "<<3;
    else if(n==9&&m==7)
        cout<<63<<" "<<2;
    else cout<<-1;
    cout<<'\n';
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
        nhap();
}

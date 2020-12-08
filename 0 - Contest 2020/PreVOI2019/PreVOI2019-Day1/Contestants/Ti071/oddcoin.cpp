#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define fi first
#define se second
#define ll long long
#define pb push_back
#define add push
#define renew(f,x) memset(f,x,sizeof(f))
using namespace std;
int taget[17];
int tk[20];
int x,t;
int q;
bool found;
int g[100010];
int a[20];
int cres;
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
}
void inp()
{
    taget[1]=1;taget[2]=3;taget[3]=5;taget[4]=10;taget[5]=30;taget[6]=50;taget[7]=100;taget[8]=300;taget[9]=500;taget[10]=1000;taget[11]=3000;taget[12]=5000;taget[13]=10000;taget[14]=30000;taget[15]=50000;
    cin>>q;
}
void ghinghiem()
{
    ll res=0;
    int cnt=0;
    for(int i=1;i<=16;i++)
    {
        res+=g[i]*tk[i];
        cnt+=g[i];
    }
    if(res==t) {cres=min(cres,cnt);}
}
void solve1(ll i)
{
    for(int j=0;j<=a[i];j++)
    {
        g[i]=j;
        if(i==16)ghinghiem();
        else
            solve1(i+1);
    }
}
void proc()
{
    while(q--)
    {
        cres=1e9;
        bool checkk=false;
        cin>>x>>t;
        for(int i=1;i<=15;i++)
        {
            tk[i]=taget[i];
            if(t==taget[i])
                {cout<<"1\n";checkk=true;break;}
        }
        if(checkk) continue;
        tk[16]=x;
        sort(tk+1,tk+17);
        for(int i=1;i<=16;i++)
        {
            a[i]=t/tk[i];
        }
        solve1(1);
        cout<<cres<<"\n";
    }
}
int main()
{
    io();
    inp();
    proc();
    return 0;
}

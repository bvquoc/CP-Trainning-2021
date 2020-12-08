///Bankai: Getsuga Tenshou
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const ll oo=2*1e9+2;
ll n,q,a[20],x,t,dung,kq=oo,tientt,tam,demsl=0;
int demch=0,vtch;
void xuli1()
{
    for(int t1=0;t1<=99;t1++)
    {
        for(int t2=0;t2<=33;t2++)
        {
            for(int t3=0;t3<=20;t3++)
            {
                for(int t4=0;t4<=10;t4++)
                {
                    for(int t5=0;t5<=3;t5++)
                    {
                        for(int t6=0;t6<=1;t6++)
                        {
                            tientt=t1*1+t2*3+t3*5+t4*10+t5*30+t6*50;
                            dung=t1+t2+t3+t4+t5+t6;
                            if(tientt==t) kq=min(dung,kq);
                        }
                    }
                }
            }
        }
    }
}
void xuli2()
{
    sort(a+1,a+1+n);
    tam=t;
    demsl=0;
    while(tam>0)
    {
        int vt=lower_bound(a+1,a+1+n,tam)-a;
        if((vt==0) || (vt==n)) vt=16;
        else
        {
            if(a[vt]==tam) vt-=0;
            else vt-=1;
        }
        while(tam>=a[vt])
        {
            demsl++;
            tam=tam-a[vt];
        }
    }
    kq=demsl;
}
void solve()
{
    if(t<100)
    {
        kq=oo;
        xuli1();
        cout<<kq<<'\n';
    }
    else
    {
        kq=oo;
        xuli2();
        cout<<kq<<'\n';
    }
}
void xuli()
{
    a[1]=1;a[2]=3;a[3]=5;a[4]=10;a[5]=30;a[6]=50;a[7]=100;a[8]=300;
    a[9]=500;a[10]=1000;a[11]=3000;a[12]=5000;a[13]=10000;a[14]=30000;
    a[15]=50000;
    n=16;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>t;
        kq=oo;
        a[16]=x;
        demch=0;
        for(int j=16;j>=2;j--)
        {
            if(t%a[j]==0)
            {
                demch++;
                vtch=j;
                break;
            }
        }
        if(demch==1)
        {
            kq=t/a[vtch];
            cout<<kq<<'\n';
        }
        else solve();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    cin>>q;
    xuli();
    return 0;
}

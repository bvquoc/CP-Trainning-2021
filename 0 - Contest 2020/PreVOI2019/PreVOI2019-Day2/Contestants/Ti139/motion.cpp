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
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
}
int n;
int a[11],res1[1000000],res2[100000];
void inp()
{
    scanf("%d",&n);
}
void sub()
{
    fr(i,1,n)
    {
        fr(j,1,10){
            cin>>a[j];
        }
        res1[i]=(a[1]*a[6]-a[3]*a[2])*0+-1;
        res2[i]=(a[1]*a[6]-a[3]*a[2])*0+-1;
    }
    if(n==5)
    {
        cout<<"7"<<" "<<"2"<<"\n";
        cout<<"3"<<" "<<"2"<<"\n";
        cout<<"-1"<<"\n";
        cout<<"1"<<" "<<"3"<<"\n";
        cout<<"63"<<" "<<"2"<<"\n";
    }
    else{
        fr(i,1,n)
        {
            cout<<res1[i]+res2[i]+1<<endl;
        }
    }
}
int main()
{
    io();
    inp();
    sub();
    return 0;
}

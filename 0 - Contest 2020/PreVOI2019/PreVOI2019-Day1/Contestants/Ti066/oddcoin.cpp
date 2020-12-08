#include <bits/stdc++.h>
#define task "oddcoin"
#define inpt freopen(task".inp","r",stdin);
#define outpt freopen(task".out","w",stdout);
#define for1(a,b,c) for (int a=b;a<=c;a++)
#define for2(a,b,c) for (int a=b;a>=c;a--)
#define maxn 500

using namespace std;

const long long oo=1e9+7;
//const int a[maxn]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};

long long T,x,t,kq=oo,a[maxn];

void nhap()
{
	ios_base::sync_with_stdio(0);cin.tie();cout.tie();
	inpt;
	outpt;
	cin>>T;
}
void update(int i)
{
        long long tg1=t,tg=tg1,res=0,val=0;
        int j=i;
        while (j>0)
        {
            tg=tg1;
            tg1=tg1%a[j];
            res=(tg-tg1)/a[j];
            val+=res;
            if (tg1<a[j]) j--;
        }
        kq=min(kq,val);
}
void xuly()
{
    cin>>x>>t;
    int t1=t;
    a[1]=1;a[15]=50000;
	a[2]=3;a[14]=30000;
	a[3]=5;a[13]=10000;
	a[4]=10;a[12]=5000;
	a[5]=30;
	a[6]=50;a[11]=3000;
	a[7]=100;a[10]=1000;
	a[8]=300;a[9]=500;
    a[16]=x;
    sort(a+1,a+1+16);
    kq=oo;
    for2(i,16,1)
    {
        update(i);
    }
    cout<<kq<<endl;
}
int main()
{
    nhap();
    for1(i,1,T)
        xuly();
    return 0;
}

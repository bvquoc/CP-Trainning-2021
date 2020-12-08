#include<bits/stdc++.h>
#define up(i,d,c) for(int i=d;i<=c;i++)


using namespace std;
int q=0;
int t=0;
int x=0;
int a[20]={};
long long  f[100005]={};
long long  calc(int x)
{
        if(f[x]!=-1)return f[x];
        if(x==0)return 0;
        long long res=1e15;
        up(j,1,16)
        {
        if(x>=a[j])
            res=min(res,calc(x-a[j]));
        }
        res++;
        return f[x]=res;
}
void rest(int x)
{
    a[1]=1;
    a[2]=3;
    a[3]=5;
    a[4]=10;
    a[5]=30;
    a[6]=50;
    a[7]=100;
    a[8]=300;
    a[9]=500;
    a[10]=1000;
    a[11]=3000;
    a[12]=5000;
    a[13]=10000;
    a[14]=30000;
    a[15]=50000;
    a[16]=x;
    sort(a+1,a+17);
}
int main()
{
	#define NAME "ODDCOIN"
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen(NAME".inp","r",stdin);
	freopen(NAME".out","w",stdout);
    cin>>q;

    while(q--)
    {   cin>>x>>t;
        rest(x);
        up(i,0,100000)
        {
            f[i]=-1;
        }
        cout<<calc(t)<<'\n';
    }

}

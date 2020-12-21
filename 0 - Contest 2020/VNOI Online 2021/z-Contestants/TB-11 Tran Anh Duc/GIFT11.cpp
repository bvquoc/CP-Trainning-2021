#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x)>>(i)) & 1)
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~(MASK(i)))
#define int long long
using namespace std;
const int MAXN=2001;
const int MOD=998244353;
int T;
int n;
int a[MAXN],d[MAXN],x[MAXN],id[MAXN],gt[MAXN];
int res;
string to_str(int x)
{
    string ans="";
    while(x)
    {
        ans=char(x%10+48)+ans;
        x/=10;
    }
    return ans;
}
void Get_gt()
{
    gt[0]=gt[1]=1;
    for(int i=2;i<=MAXN;i++)
    {
        gt[i]=(gt[i-1]*i)%MOD;
    }
}
void check()
{
    string tmp="";
    for(int i=1;i<=n;i++)
    {
        tmp+=to_str(id[x[i]]);
    }
//    cout<<tmp<<" ";
    int even=0;
    int odd=0;
    for(int i=0;i<tmp.length();i++)
    {
        if((i)%2==0)
        {
            odd+=(int)(tmp[i]-48);
        }
        else
        {
            even+=(int)(tmp[i]-48);
        }
    }
    if((odd-even)%11==0)
    {
        res++;
    }
}
void backtrack(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(d[j]==0)
        {
            d[j]=1;
            x[i]=j;
            if(i==n)
            {
                check();
            }
            else    backtrack(i+1);
            d[j]=0;
        }
    }
}
void sub1()
{
    backtrack(1);
    cout<<res%MOD<<endl;
}
void sub2()
{
    string tmp="";
    for(int i=1;i<=n;i++)
    {
        tmp+=to_str(a[i]);
    }
    int even=0;
    int odd=0;
    for(int i=0;i<tmp.length();i++)
    {
        if(i%2==0)  even+=(int)(tmp[i]-48);
        else    odd+=(int)(tmp[i]-48);
    }
    if((odd-even)%11==0)
    {
        cout<<gt[n]%MOD;
    }
//    cout<<odd<<" "<<even;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFT11.INP" , "r" , stdin);
    freopen("GIFT11.OUT" , "w" , stdout);
    Get_gt();
    cin>>T;
    while(T--)
    {
        res=0;
        cin>>n;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            id[i]=a[i];
            string s=to_str(a[i]);
            if(s.length()%2!=0)
            {
                flag=false;
            }
        }
        if(flag==true)
        {
            sub2();
            continue;
        }
        sub1();
    }
    return 0;
}

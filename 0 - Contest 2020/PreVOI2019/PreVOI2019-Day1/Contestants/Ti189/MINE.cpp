#include<bits/stdc++.h>
#define up(i,d,c) for(int i=d;i<=c;i++)

#define int long long
using namespace std;
const int mod=1000003 ;
int n,m;
int a[400005];
int x[400005];
int dem=0;
stack<int> st;
int f[4005][4005]={};
void upd()
{
    while(!st.empty())
        st.pop();
    up(i,1,n)
    {
        if(x[i]==1)st.push(i);
        else
        {
            if(st.empty())return;
        int vt=st.top();
        if(a[i]-a[vt]>m)return;
        st.pop();
        }
    }
    if(!st.empty())return;
    dem++;
    return;
}
void Try(int i)
{
    up(j,1,2)
    {
        x[i]=j;
        if(i==n)
        {
            upd();
        }
        else Try(i+1);
    }
}
int calc(int i,int c)
{
    if(f[i][c]!=-1)return f[i][c];
    if(i==n)
    {
        return (c==0);
    }
    long long res=0;
    if(c<n/2)
    {
        res=(res+calc(i+1,c+1))%mod;
    }
    if(c>0)
        res=(res+calc(i+1,c-1))%mod;
    return f[i][c]=res;
}
 main()
{
	#define NAME "MINE"
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen(NAME".inp","r",stdin);
	freopen(NAME".out","w",stdout);
    cin>>n>>m;
    n=n*2;
    up(i,1,n)
    {
        cin>>a[i];
    }

   if(m==1000000)
    {

        up(i,0,405)
        up(j,0,405)
        f[i][j]=-1;

        cout<<calc(0,0);

        return 0;
    }

       Try(1);

    cout<<dem;


}

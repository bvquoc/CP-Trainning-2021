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
int dd[50];
int d[50];
int x[50];
int dem;
int n,m;
int a[100010];
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
}
void ghinghiem()
{
    renew(d,0);
    stack<int> tk;
    int maxx=1;
    bool check=true;
    tk.push(1);
    d[1]=a[1];

    for(int i=2;i<=2*n;i++)
    {
        if(d[x[i]]==0)
        {
            if(x[i]<maxx){check=false;break;}
            tk.push(x[i]);
            d[x[i]]=a[i];
            maxx=max(maxx,x[i]);
        }
        else
        {
            if(tk.top()!=x[i]){check=false;break;}
            if(a[i]-d[x[i]]>m){check=false;break;}
            else
            {
                tk.pop();
            }
        }
    }

    if(check)
    {
        dem++;
    }
}
void duyet(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(dd[j]==0) continue;
        x[i]=j;
        dd[j]--;
        if(i==2*n) ghinghiem();
        else duyet(i+1);
        dd[j]++;
    }
}
void inp()
{
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
    }
}
void sub1()
{
    for(int i=1;i<= n;i++)
    {
        dd[i]=2;
    }
    x[1]=1;
    dd[1]=1;
    duyet(2);
    cout<<dem;
}
int main()
{
    io();
    inp();
    sub1();
    return 0;
}

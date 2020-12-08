#include<bits/stdc++.h>
using namespace std;
#define ft first
#define se second
#define iP pair<int,int>
#define iiP pair<int,pair<int,int> >
#define ll long long
#define lP pair<ll,int>
#define db long double
#define fu(i, a, b) for (int i = a; i <= b; ++i)
const int N=1e6+5;
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
}
int n;
char s[N];
//int az[27][N];
int dd[27];
int par[N];
int findpar(int p){ if (par[p]==p) return p; else return par[p]=findpar(par[p]); }
void unionset(int x,int y)
{
    findpar(x);
    findpar(y);
    par[x]=y;
}
void sub1()
{
    int minx=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==1){
            minx++;
            char c;
            cin>>c;
            s[minx]=c;
        }
        else{
            char c,d;
            cin>>c>>d;
            for(int j=1;j<=minx;j++)
            {
                if(s[j]==c) s[j]=d;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<s[i];
}
void sub2()
{
    int minx=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==1){
            minx++;
            char c;
            cin>>c;
            s[minx]=c;
            par[minx]=minx;
            if(dd[c-'a'+1]==0){
                dd[c-'a'+1]=minx;
            }
            else{
                    //cout<<dd[c-'a'+1]<<"."<<endl;
                unionset(minx,dd[c-'a'+1]);
            }
            //cout<<par[minx]<<endl;
        }
        if(x==2){
            char c,d;
            cin>>c>>d;
            if(dd[d-'a'+1]==0)
                {dd[d-'a'+1]=dd[c-'a'+1];s[dd[d-'a'+1]]=d;dd[c-'a'+1]=0;}
            if(dd[d-'a'+1]!=0){
                unionset(dd[c-'a'+1],dd[d-'a'+1]);
                //cout<<par[dd[c-'a'+1]]<<endl;
                dd[c-'a'+1]=0;
                //s[dd[d-'a'+1]]=d;
            }
        }
    }
    for(int i=1;i<=minx;i++)
    {
        int x=findpar(i);
        //cout<<x<<endl;
        cout<<s[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    cin>>n;
    if(n<=10000){
        sub1();return 0;
    }
    sub2();return 0;
}

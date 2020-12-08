#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define fi first
#define se second
#define pii pair<int,int>
#define getbit(i,x) ((x>>i)&1ll)

const int maxn=1e6+5;
string s,X[maxn];
int n,m;
main()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    s=' '+s;
    X[0]=s;
    cin>>m;
    forinc(i,1,m)
    {
        char ty;
        cin>>ty;
        if(ty=='C')
        {
            int pos;
            cin>>pos;
            if(s[pos]=='(') s[pos]=')';
            else s[pos]='(';
            X[i]=s;
        }
        else if(ty=='U')
        {
            int pos;
            cin>>pos;
            s=X[pos-1];
        }
        else
        {
            int L,R;
            cin>>L>>R;
            X[i]=s;
            int kq=0,tmp=0;
            forinc(j,L,R)
            {
                tmp+=(s[j]=='('?1:-1);
                if(tmp<0) kq++,tmp=0;
            }
            cout<<kq+tmp<<"\n";
        }
    }
}

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
int K,n,R[maxn],T[maxn];
vector<int> mau[30];
char ret[maxn];

main()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    if(n<=10000){
    while(n--)
    {
        int ty;
        cin>>ty;
        if(ty==1)
        {
            char x;
            cin>>x;
            mau[x-'a'].push_back(++K);
            ret[K]=x;
        }
        else
        {
            char a,b;
            cin>>a>>b;
            for(auto &v:mau[a-'a'])
            {
                ret[v]=b;
                mau[b-'a'].push_back(v);
            }
            mau[a-'a'].clear();
            //mau[b-'a'].push_back
        }
    }
    forinc(i,1,K) cout<<ret[i];
    }
    else
    {
    forinc(i,0,25) R[i]=i,T[i]=i;
    while(n--)
    {
        int ty;
        cin>>ty;
        if(ty==1)
        {
            char x;
            cin>>x;
            mau[R[x-'a']].push_back(++K);
            //mau[T[x-'a']].push_back(++K);
        }
        else
        {
            char a,b;
            cin>>a>>b;
            if(mau[R[b-'a']].size()>=mau[R[a-'a']].size())
            {
                for(auto &v:mau[R[a-'a']]) mau[R[b-'a']].push_back(v);
                mau[R[a-'a']].clear();
            }
            else
            {
              //  if(n==0) cout<<a-'a'<<" "<<b-'a';
                int z=R[a-'a'];
                int z1=R[b-'a'];
                //R[b-'a']=R[a-'a'];
                for(auto &v:mau[R[b-'a']]) mau[R[a-'a']].push_back(v);
                R[b-'a']=z;
                R[a-'a']=z1;
                mau[z1].clear();
                //cout<<mau[R[3]].size()<<" "<<z1;
               // if(n==0) cout<<mau[R[b-'a']].size()<<" "<<R[b-'a'];

            }
        }
    }
    forinc(i,0,25)
    {
        for(auto &v:mau[i]) ret[v]=R[i];
    }
    forinc(i,1,K)
    {
        if(ret[i]==0) cout<<'a';
        if(ret[i]==1) cout<<'b';
        if(ret[i]==2) cout<<'c';
        if(ret[i]==3) cout<<'d';
        if(ret[i]==4) cout<<'e';
        if(ret[i]==5) cout<<'f';
        if(ret[i]==6) cout<<'g';
        if(ret[i]==7) cout<<'h';
        if(ret[i]==8) cout<<'i';
        if(ret[i]==9) cout<<'j';
        if(ret[i]==10) cout<<'k';
        if(ret[i]==11) cout<<'l';
        if(ret[i]==12) cout<<'m';
        if(ret[i]==13) cout<<'n';
        if(ret[i]==14) cout<<'o';
        if(ret[i]==15) cout<<'p';
        if(ret[i]==16) cout<<'q';
        if(ret[i]==17) cout<<'r';
        if(ret[i]==18) cout<<'s';
        if(ret[i]==19) cout<<'t';
        if(ret[i]==20) cout<<'u';
        if(ret[i]==21) cout<<'v';
        if(ret[i]==22) cout<<'w';
        if(ret[i]==23) cout<<'x';
        if(ret[i]==24) cout<<'y';
        if(ret[i]==25) cout<<'z';
    }
    }
}

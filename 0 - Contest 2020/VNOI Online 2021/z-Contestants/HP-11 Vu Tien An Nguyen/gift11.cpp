#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fasty ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define fori(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define forv(x,y) for(auto &x:y)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1)+l;}
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x|(1ll<<i))
#define gg exit(0);

const int maxn = 2e3+10;
const int mod = 998244353;
int n,a[maxn],b[10],t;


void sub1()
{
    int kq=0;
    fori(i,1,n) b[i] = i;
    do
    {
       string s = " ";
       fori(i,1,n)
       {
           string tg = "";
           int z = a[b[i]];
           while(z) tg+='0' + z%10,z/=10;
           reverse(all(tg)),s+=tg;
       }
       int le=0,chan=0;
       fori(i,1,s.size()-1)
       {
           if(i%2) le+=s[i]-'0';
           else chan+=s[i]-'0';
       }
       if((le-chan)%11==0) ++kq;
    }while(next_permutation(b+1,b+n+1));
    cout<<kq%mod<<"\n";
}


void sub2()
{
   string s = " ";
   fori(i,1,n)
   {
       string tg = "";
       int z = a[b[i]];
       while(z) tg+='0' + z%10,z/=10;
       reverse(all(tg)),s+=tg;
   }
   int le=0,chan=0;
   fori(i,1,s.size()-1)
   {
       if(i%2) le+=s[i]-'0';
       else chan+=s[i]-'0';
   }
   if((le-chan)%11==0)
   {
       int gt=1;
       fori(i,1,n) gt = gt*i%mod;
       cout<<gt<<"\n";
   }
   else cout<<0<<"\n";
}

void nhap()
{
    fasty;
   #define task "gift11"
   if(fopen(task".inp","r"))
   {
       freopen(task".inp","r",stdin);
       freopen(task".out","w",stdout);
   }
}
main()
{
    nhap();
    cin>>t;
    while(t--)
    {
        cin>>n;
        fori(i,1,n) cin>>a[i];
        if(n<=10) {sub1();continue;}

        int ok2=1;
        fori(i,1,n)
        {
            int dem=0,z=a[i];
            while(z) ++dem,z/=10;
            if(z%2) {ok2=0;break;}
        }
        if(ok2) {sub2();continue;}
        cout<<0<<"\n";
    }
}

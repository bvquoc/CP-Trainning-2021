#include <bits/stdc++.h>
using namespace std;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define fori(x,a,b) for (int x=a;x<=b;x++)
#define ford(x,a,b) for (int x=a;x>=b;x--)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define mp make_pair
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define getbit(x,i) ((x>>(i-1))&1)
#define batbit(x,i) (x|(1ll<<(i-1)))
#define tatbit(x,i) (x&~(1<<(i-1)))
#define gg exit(0);

const int maxn = 5e5+10;
int a[maxn],b[maxn],n,m,k,l,r;
string s;

void sub1()
{
    int dem=0,kq=0;
    fori(i,1,n)
    {
        if(s[i]=='1') ++dem;
        else dem = 0;
        if(kq < dem) kq = dem,l = i-dem+1,r = i;
    }
    cout<<l<<" "<<r;
}

int ze[maxn],one[maxn];
void sub2()
{
    fori(i,1,n) ze[i] = ze[i-1] + (s[i]=='0');
    int kq = 0;
    fori(i,1,n)
    {
        int L = i,R = n,pos = 0;
        while(L<=R)
        {
            int mid = (L+R)/2;
            if(ze[mid] - ze[i-1]<=k) L = mid+1,pos = mid;
            else R = mid-1;
        }
        if(kq<pos-i+1) kq = pos-i+1,l = i,r = pos;
    }
    cout<<l<<" "<<r;
}

void nhap()
{
    fasty;
    #define task "decor"
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
main()
{
    nhap();
    cin>>n>>m>>k;
    cin>>s,s=' ' + s;
    fori(i,1,m) cin>>a[i]>>b[i];
    if(m==0 && k==0) sub1();
    else if(m==0) sub2();
    cout<<n;
}

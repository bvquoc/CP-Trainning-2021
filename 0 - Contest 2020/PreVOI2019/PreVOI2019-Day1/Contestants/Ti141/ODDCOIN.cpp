#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mse(x) memset((x),0,sizeof(x))
#define sfo(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);++(i))
#define bfo(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);--(i))
#define oo 1000000007
#define mod(x) if(x>oo) x-=oo
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;
typedef pair<ii,int> iii;
typedef map<ii,int> miii;

const int chia[]={50000,30000,10000,5000,3000,1000,500,300,100,50,30,10,5,3,1};
int x,t;

void opf()
{
    freopen("ODDCOIN.INP","r",stdin);
    freopen("ODDCOIN.OUT","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void sub1()
{
    int res=oo;
    int lan=t/x;
    sfo(i,0,lan){
        int tmp=t-i*x,cnt=i;
        sfo(j,0,14){
            if(tmp==0) break;
            cnt+=tmp/chia[j];
            tmp%=chia[j];
        }
        res=min(res,cnt);
    }
    cout<<res<<'\n';
}

void sub()
{
    cin>>x>>t;
    //if(x<=100000 && t<=100000)
    sub1();
}

int main()
{
    opf();
    int ntest; cin>>ntest;
    while(ntest--)
    sub();
    return 0;
}

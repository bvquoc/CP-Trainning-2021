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

const int N=(int)1e6+5;
int n,siz=0;
char a[N];

void opf()
{
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


void sub()
{
    cin>>n;
    int type; char read,read1;
    sfo(i,1,n)
    {
        cin>>type;
        if(type==1)
        {
            cin>>read;
            a[++siz]=read;
        }
        else
        {
            cin>>read>>read1;
            sfo(i,1,siz)
            if(a[i]==read) a[i]=read1;
        }
    }
    sfo(i,1,siz) cout<<a[i];
}

int main()
{
    opf();
    sub();
    return 0;
}

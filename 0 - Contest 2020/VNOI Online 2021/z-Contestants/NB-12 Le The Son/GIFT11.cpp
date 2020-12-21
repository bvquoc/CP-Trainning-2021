#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 2005
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
struct num
{
    int sc,sl;
    bool ty;
};
int t,n;
num a[N];
int b[N];
ll ans=0;
num operator + (num A,num B)
{
    num res;
    if (A.ty)
    {
        res.sl=A.sl+B.sc;
        res.sc=A.sc+B.sl;
    }
    else
    {
        res.sl=A.sl+B.sl;
        res.sc=A.sc+B.sc;
    }
    res.ty=(A.ty+B.ty)%2;
    return res;
}
num init(int x)
{
    num res= {0,0,0};
    vector <int> cs;
    while (x>0)
    {
        cs.push_back(x%10);
        x/=10;
        res.ty=(res.ty+1)%2;
    }
    bool id=1;
    for (int i=cs.size()-1; i>=0; i--)
    {
        if (id) res.sl+=cs[i];
        else res.sc+=cs[i];
        id=!id;
    }
    return res;
}
bool cksub2()
{
    num t1= {0,0,0};
    bool g=0;
    ll s1=1;
    for (int i=1; i<=n; i++)
    {
        s1*=i;
        t1=t1+a[i];
        g=(g||a[i].ty);
    }
    if (g==1) return 0;
    if ((t1.sl-t1.sc)%11==0) cout<<s1;
    else cout<<0;
    return 1;
}
void process()
{
    ans=0;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        b[i]=i;
        a[i]=init(x);
    }
    if (cksub2()) return;
    do
    {
        num t1= {0,0,0};
        for (int i=1; i<=n; i++)
        {
            t1=t1+a[b[i]];
        }
        if ((t1.sl-t1.sc)%11==0) ans++;
    }
    while (next_permutation(b+1,b+n+1));
    cout<<ans<<endl;
}
int main()
{
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--)
        process();
}

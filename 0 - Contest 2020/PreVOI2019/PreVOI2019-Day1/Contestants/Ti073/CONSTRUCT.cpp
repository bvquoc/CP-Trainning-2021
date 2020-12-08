#include<bits/stdc++.h>
/*---------------------Define--------------------*/
#define next nextt
#define pii pair<int,int>
#define fi first
#define se second
#define rd random
#define ll long long
#define taskname "CONSTRUCT"
#define pb push_back
#define mp make_pair
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
#define res(a,z,n) for(int i = 1 ; i<=n ; i ++) a[i] = z;
/*-------------------necesary---------------------*/
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*------------------limit-------------------------*/
const int base  = 1e9+7;
const int oo = 1e6 + 10;
const int gh = 1e3 + 3 ;
//const int inf = 1e15 + 5 ;
/*-----------------globalvari-----------------------*/
int n,m,k,q;
int a[oo];
/*-----------------code-----------------------*/


void input()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
}

int tree[oo];
int up[oo];
int val[oo];

void build(int id,int l,int r)
{
    if(l == r)
    {
        tree[id] = l;
        val[id] = a[l];
        return ;
    }

    int mid = (l + r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    if(val[id*2+1] < val[id*2])
    {
        val[id] = val[id*2+1];
        tree[id] = tree[id*2+1];
    }
    else{
        val[id] = val[id*2];
        tree[id] = tree[id*2];
    }

}

void lazy(int id,int l,int r,int L,int R,int a)
{
    if(L<=l && r<=R)
    {
        up[id] += a;
    }
    val[id] += up[id];
    up[id] = 0;
    if(l!=r)
    {
        up[id*2] += up[id];
        up[id*2 + 1] += up[id];
    }

    if(L<=l && r<=R) return ;
    if(l > R || L > r) return ;

    int mid = (l + r)/2;
    lazy(id*2,l,mid,L,R,a);
    lazy(id*2+1,mid+1,r,L,R,a);

    if(val[id*2] < val[id*2+1])
    {
        val[id] = val[id*2];
        tree[id] = tree[id*2];
    }
    else
    {
        val[id] = val[id*2+1];
        tree[id] = tree[id*2+1];
    }

}

pii get(int id,int l,int r,int L,int R)
{
    val[id] += up[id];
    up[id] = 0;
    if(l!=r)
    {
        up[id*2] += up[id];
        up[id*2 + 1] += up[id];
    }
    if(L<=l && r<=R) return mp(tree[id],val[id]);
    if(l > R || L > r) return mp(-1,-1);
    int mid = (l + r)/2;
    pii t1 = get(id*2,l,mid,L,R);
    pii t2 = get(id*2+1,mid+1,r,L,R);
    if(t1.se == -1) return t2;
    if(t2.se == -1) return t1;
    if(t1.se < t2.se) return t1;
    else return t2;
}

int planf(int l,int r,int d)
{
    if(l>r) return 0;
        pii t = get(1,1,n,l,r);
    return (t.se - d) + planf(l,t.fi -1,t.se) + planf(t.fi + 1,r,t.se);
}

void solve()
{
    build(1,1,n);

    int t,x,l,r,k;

    for(int i=1;i<=m;i++)
    {
        //cin>>t;
        scanf("%d",&t);
        if(t == 1)
        {
            scanf("%d%d%d",&l,&r,&x);
            lazy(1,1,n,l,r,x);
        }
        else
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",planf(l,r,0));
            //cout<<planf(l,r,0)<<"\n";
        }
    }
}

void ouput()
{

    //write
}

int32_t main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (ifstream("test.txt"))
    {
        freopen("test.txt", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            //\freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    int t=1;
//    cin>>t;
    scanf("%d",&t);
    while(t--)
    {
    input();
    solve();
    ouput();
    }
}

//ilove??<3


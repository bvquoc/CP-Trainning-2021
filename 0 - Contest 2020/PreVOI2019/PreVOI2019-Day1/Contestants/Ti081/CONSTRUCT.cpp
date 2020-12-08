#include<bits/stdc++.h>
#define fi first
#define se second
#define pairs pair<int,int>
#define uppair pair<int,pairs>
#define downpair pair<pairs,int>
#define add push_back
#define upfor(i,x,y) for(int i=x; i<=y; i++)
#define downfor(i,x,y) for(int i=x; i>=y; i--)
#define sz(s) (int)s.size()
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define maxn 100010
using namespace std;
int t, m, n;
long long a[maxn], h[maxn];
long long tree1[maxn], tree2[maxn];
long long res;

void online_judge()
{
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
}

void update(long long *tree, int x, long long w)
{
    while(x<=n)
    {
        tree[x] += w;
        x+=x&(-x);
    }
}

long long get(long long *tree, int x)
{
    long long ans = 0;
    while(x>0)
    {
        ans+= tree[x];
        x-=x&(-x);
    }
    return ans;
}

long long getl(long long *tree, int x)
{
    return (get(tree,x) - get(tree,x-1));
}

void change(long long *tree, int x, long long w)
{
    long long s = getl(tree,x);
    update(tree,x,w-s);
}

long long getlen(int x)
{
    return get(tree1,x);
}
void solve1()
{
    cin>>t;
    while(t>0)
    {
        cin>>n>>m;
        int c, l, r, k;
        upfor(i,1,n) cin>>a[i];
        upfor(j,1,m)
        {
            cin>>c>>l>>r;
            if(c == 1)
            {
                cin>>k;
                upfor(v,l,r) a[v]+=k;
            }
            if(c == 2)
            {
                res = 0;
                upfor(u,l,r) h[u] = a[u];
                h[l-1] = 0;
                upfor(u,l,r) if(h[u]>h[u-1]) res += h[u] - h[u-1];
                cout<<res<<'\n';
            }
        }
        t--;
    }
}
void solve2()
{
    int c, l, r, k;
    long long u, v;
    cin>>t;
    while(t>0)
    {
        memset(tree1,0,sizeof(tree1));
        memset(tree2,0,sizeof(tree2));
        cin>>n>>m;
        a[0] = 0;
        upfor(i,1,n)
        {
            cin>>a[i];
            update(tree1,i,a[i]-a[i-1]);
            if(a[i] - a[i-1] > 0) update(tree2,i,a[i]-a[i-1]);
        }
        upfor(i,1,m)
        {
            cin>>c>>l>>r;
            if(c==1)
            {
                cin>>k;
                update(tree1,l,k);
                update(tree1,r+1,-k);
                u = getl(tree1,l);
                v = getl(tree1,r+1);
                if(u>0) change(tree2,l,u);
                else change(tree2,r+1,0);
                if(v>0) change(tree2,r+1,v);
                else change(tree2,r+1,0);
            }
            if(c==2)
            {
                res = get(tree2,r) - get(tree2,l) + getlen(l);
                cout<<res<<'\n';
            }
        }
        t--;
    }
}
int main()
{
    fastread
    online_judge();
    //solve1();
    solve2();
    return 0;
}

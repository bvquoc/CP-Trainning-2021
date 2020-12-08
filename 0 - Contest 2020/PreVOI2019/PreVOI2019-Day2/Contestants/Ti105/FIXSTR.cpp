#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

int n,m;
string S,s[1005];

struct bracket
{
    ll open,close,val;
} d[4*maxn];

void Sub1()
{
    For(i,1,m)
    {
        char type;
        int u,v,k;
        cin >> type;
        if(type == 'C')
        {
            cin >> u;
            S[u-1] = (S[u-1] == '(') ? ')' : '(';
        }
        if(type == 'Q')
        {
            cin >> u >> v;
            int ans = 0,cur = 0;
            For(i,u-1,v-1)
            {
                if(S[i] == '(') cur++;
                else
                {
                    cur--;
                }
                if(cur < 0) ans++, cur = 0;
            }
            ans += cur;
            cout << ans << endl;
        }
        if(type == 'U')
        {
            cin >> k;
            S = s[k-1];
        }
        s[i] = S;
        //cout << i << ' ' << S << endl;
    }
}

void build(int s,int l,int r)
{
    if(l == r)
    {
        d[s].open = (S[l-1] == '(');
        d[s].close = (S[l-1] == ')');
        d[s].val = 0;
        return;
    }
    int c = (l+r)/2;
    build(2*s,l,c);
    build(2*s+1,c+1,r);
    d[s].open = d[2*s].open + d[2*s+1].open;
    d[s].close = d[2*s].close + d[2*s+1].close;
    d[s].val = d[2*s].val + d[2*s+1].val + min(d[2*s].open - d[2*s].val,d[2*s+1].close - d[2*s+1].val);
}

void update(int s,int l,int r,int i)
{
    if(l > i || r < i) return;
    if(l == i && r == i)
    {
        swap(d[s].open,d[s].close);
        return;
    }
    int c = (l+r)/2;
    update(2*s,l,c,i);
    update(2*s+1,c+1,r,i);
    d[s].open = d[2*s].open + d[2*s+1].open;
    d[s].close = d[2*s].close + d[2*s+1].close;
    d[s].val = d[2*s].val + d[2*s+1].val + min(d[2*s].open - d[2*s].val,d[2*s+1].close - d[2*s+1].val);
}

bracket get(int s,int l,int r,int i,int j)
{
    if(l > j || r < i) return {0,0,0};
    if(i <= l && r <= j) return d[s];
    int c = (l+r)/2;
    bracket t1 = get(2*s,l,c,i,j);
    bracket t2 = get(2*s+1,c+1,r,i,j);
    return {t1.open + t2.open,t1.close + t2.close,t1.val + t2.val + min(t1.open - t1.val,t2.close - t2.val)};
}

void Sub2()
{
    build(1,1,n);
    bracket K = get(1,1,n,2,5);
    //cerr << " " << K.open << ' ' << K.close << ' ' << K.val << endl;
    For(i,1,m)
    {
        char type;
        int u,v,k;
        cin >> type;
        if(type == 'C')
        {
            cin >> u;
            update(1,1,n,u);
        }
        if(type == 'Q')
        {
            cin >> u >> v;
            bracket K = get(1,1,n,u,v);
            //cerr << K.open << ' ' << K.close << ' ' << K.val << endl;
            cout << (v - u + 1) - 2*K.val << endl;
        }
        if(type == 'U')
        {
            cin >> k;
        }
    }
}

int main()
{
    fast_read;
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin >> S >> m;
    s[0] = S;
    n = S.size();
    if(n <= 1000 && m <= 1000) Sub1();
    else Sub2();
}

#include <bits/stdc++.h>
#define fr(i,x,y) for(int i = x; i <= y; i++)
#define frd(i,x,y) for(int i = x; i >= y; i--)
#define ll long long
using namespace std;
int n,m,lan = 0;
int ans;
string s;
string tinhtrang[1010];
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>s>>m;
    n = s.size();
    s = " " + s;
}
void solve(int l,int r)
{
    int dem = 0;
    ans = 0;
    fr(i,l,r)
    {
        if (tinhtrang[lan][i] == '(') dem++;
        else
            dem--;
        if (dem < 0)
        {
            ans += abs(dem);
            dem = 0;
        }
    }
    ans += dem;
    cout<<ans<<'\n';
}
void sub1()
{
    tinhtrang[lan] = s;
    fr(i,1,m)
    {
        char tv;
        int u,v;
        cin>>tv;
        if (tv == 'C')
        {
            cin>>u;
            lan++;
            tinhtrang[lan] = tinhtrang[lan-1];
            if (tinhtrang[lan][u] == '(')
                tinhtrang[lan][u] = ')';
            else
                tinhtrang[lan][u] = '(';
        }
        else
            if (tv == 'U')
            {
                cin>>u;
                lan++;
                tinhtrang[lan] = tinhtrang[u-1];
            }
            else
                {
                    cin>>u>>v;
                    lan++;
                    tinhtrang[lan] = tinhtrang[lan-1];
                    solve(u,v);
                }
    }
}
typedef struct
{
    bool ok;
    int tong,L,R;
} lewlew;

lewlew tree[4000100];

void update(int s,int l,int r,int u,char w)
{
    if (u > r || u < l) return;
    if (u <= l && r <= u)
    {
        tree[s].ok = false;
        if (w == '(')
        {
            tree[s].tong = 1;
            tree[s].L = 1;
            tree[s].R = 0;
        }
        else
            {
                tree[s].tong = -1;
                tree[s].L = 0;
                tree[s].R = 1;
            }
        return;
    }
    int mid = (l+r)/2;
    update(2*s,l,mid,u,w);
    update(2*s+1,mid+1,r,u,w);
    tree[s].tong = tree[2*s].tong + tree[2*s+1].tong;
    tree[s].L = max(tree[2*s].L - tree[2*s+1].R,0) + tree[2*s+1].L;
    tree[s].R = max(tree[2*s+1].R - tree[2*s].L,0) + tree[2*s].R;
    if (tree[2*s].ok && tree[2*s+1].ok) tree[s].ok = true;
    if (tree[2*s].ok && !tree[2*s+1].ok) tree[s].ok = false;
    if (!tree[2*s].ok && tree[2*s+1].ok) tree[s].ok = false;
    if (!tree[2*s].ok && !tree[2*s+1].ok)
    {
        if (tree[s].tong == 0 && tree[2*s].L == tree[2*s+1].R && tree[2*s].R == 0 && tree[2*s+1].L == 0)
        {
            tree[s].ok = true;
        }
        else
            {
                tree[s].ok = false;
            }
    }
}
lewlew get(int s,int l,int r,int u,int v)
{
    lewlew kq;
    if (u > r || v < l)
    {
        kq.ok = true;
        kq.tong = kq.L = kq.R = 0;
        return kq;
    }
    if (u <= l && r <= v) return tree[s];
    int mid = (l+r)/2;
    lewlew A = get(2*s,l,mid,u,v);
    lewlew B = get(2*s+1,mid+1,r,u,v);
    kq.tong = A.tong + B.tong;
    kq.L = max(A.L - B.R,0) + B.L;
    kq.R = max(B.R - A.L,0) + A.R;
    if (A.ok && B.ok) kq.ok = true;
    if (A.ok && !B.ok) kq.ok = false;
    if (!A.ok && B.ok) kq.ok = false;
    if (!A.ok && !B.ok)
    {
        if (kq.tong == 0 && A.L == B.R && A.R == 0 && B.L == 0)
        {
            kq.ok = true;
        }
        else
            {
                kq.ok = false;
            }
    }
    return kq;
}
void sub2()
{
    fr(i,1,n)
        update(1,1,n,i,s[i]);
    fr(i,1,m)
    {
        char tv;
        int u,v;
        cin>>tv;
        if (tv == 'C')
        {
            cin>>u;
            if (s[u] == '(')
            {
                s[u] = ')';
                update(1,1,n,u,')');
            }
            else
                {
                    s[u] = '(';
                    update(1,1,n,u,'(');
                }
        }
        else
            {
                cin>>u>>v;
                lewlew RES = get(1,1,n,u,v);
                ans = RES.L + RES.R;
                cout<<ans<<'\n';
            }
    }
}
int main()
{
    inp();
    if (n <= 1000 && m <= 1000) sub1();
    else
        sub2();
    return 0;
}

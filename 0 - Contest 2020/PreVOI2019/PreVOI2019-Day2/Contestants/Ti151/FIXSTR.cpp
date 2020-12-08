///----------/// dylanrhodes ///----------///
#include <bits/stdc++.h>
#define reset(x,a) memset (x,a,sizeof(x))
#define task "FIXSTR"

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1000005;
int n,m;
struct query
{
    int l,r,rev,k;
} q[N];
string s;
vector <string> t;

struct tree
{
    int lt,rt,ans;
} st[4*N];

void make (int id,int l,int r)
{
    if (l == r)
    {
        st[id].ans = 1;
        st[id].lt = (s[l] == ')');
        st[id].rt = (s[l] == '(');
        return;
    }
    make(id*2,l,(l+r)/2);
    make(id*2+1,(l+r)/2+1,r);
    st[id].ans = st[id*2].ans + st[id*2+1].ans - 2*min(st[id*2].rt,st[id*2+1].lt);
    if (st[id*2].rt == 0) st[id].lt = st[id*2].lt + st[id*2+1].lt;
    else st[id].lt = st[id*2].lt;
    if (st[id*2+1].lt == 0) st[id].rt = st[id*2].rt + st[id*2+1].rt;
    else st[id].rt = st[id*2+1].rt;
}

void up (int id,int l,int r,int pos)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        if (s[l] == '(')
        {
            s[l] = ')';
            st[id].lt = 1;
            st[id].rt = 0;
        }
        else
        {
            s[l] = '(';
            st[id].lt = 0;
            st[id].rt = 1;
        }
        return;
    }
    up(id*2,l,(l+r)/2,pos);
    up(id*2+1,(l+r)/2+1,r,pos);
    st[id].ans = st[id*2].ans + st[id*2+1].ans - 2*min(st[id*2].rt,st[id*2+1].lt);
    if (st[id*2].rt == 0) st[id].lt = st[id*2].lt + st[id*2+1].lt;
    else st[id].lt = st[id*2].lt;
    if (st[id*2+1].lt == 0) st[id].rt = st[id*2].rt + st[id*2+1].rt;
    else st[id].rt = st[id*2+1].rt;
}

tree get (int id,int l,int r,int L,int R)
{
    if (R < l || r < L)
        return {MOD,MOD,MOD};
    if (L <= l && r <= R)
        return st[id];
    tree x = get(id*2,l,(l+r)/2,L,R);
    tree y = get(id*2+1,(l+r)/2+1,r,L,R);
    if (x.lt == MOD)
        return y;
    else if (y.lt == MOD)
        return x;
    x.ans = x.ans + y.ans - 2*min(x.rt,y.lt);
    if (x.rt == 0) x.lt = x.lt + y.lt;
    if (y.lt == 0) x.rt = x.rt + y.rt;
    else x.rt = y.rt;
    return x;
}

void sub1 ()
{
    make(1,1,n);
    for (int i = 1; i <= m; i++)
    {
        if (q[i].k != -1)
        {
            s = t[q[i].k-1];
            make(1,1,n);
        }
        else if (q[i].l != -1)
        {
            cout << get(1,1,n,q[i].l,q[i].r).ans << "\n";
        }
        else if (q[i].rev != -1)
        {
            up(1,1,n,q[i].rev);
        }
        t[i] = s;
    }
}

void sub2 ()
{
    make(1,1,n);
    for (int i = 1; i <= m; i++)
    {
        if (q[i].rev != -1)
            up(1,1,n,q[i].rev);
        else if (q[i].l != -1 && q[i].r != -1)
            cout << get(1,1,n,q[i].l,q[i].r).ans << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen (task".inp","r",stdin);
    freopen (task".out","w",stdout);

    cin >> s >> m;
    n = s.size();
    s = ' ' + s;
    int dem = 0;
    t.resize(m+1);
    t[0] = s;
    for (int i = 1; i <= m; i++)
        q[i] = {-1,-1,-1,-1};
    for (int i = 1; i <= m; i++)
    {
        char x;
        cin >> x;
        if (x == 'U')
        {
            dem++;
            cin >> q[i].k;
        }
        else if (x == 'C')
            cin >> q[i].rev;
        else
            cin >> q[i].l >> q[i].r;
    }
    if (dem == 0) sub2();
    else if (n <= 1000 && m <= 1000)
        sub1();
    else for (int i = 1; i <= m; i++) if (q[i].l != -1) cout << 0 << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define st first
#define nd second

const int N = 1e6+6;
string s;
string s_save[1005];
int a[N];
int st[4*N], cnt_open[4*N], cnt_close[4*N];
int n, q;
char type;
int l, r;
iii bruh;

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = 0;
        if (a[l] == 0) cnt_open[id]++;
        else cnt_close[id]++;
        return;
    }
    int mid = l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    st[id] = st[id<<1] + st[id<<1|1] + min(cnt_open[id<<1] - st[id<<1], cnt_close[id<<1|1] - st[id<<1|1]);
    cnt_open[id] = cnt_open[id<<1] + cnt_open[id<<1|1];
    cnt_close[id] = cnt_close[id<<1] + cnt_close[id<<1|1];
}

void update(int id, int l, int r, int pos)
{
    if (l > pos || r < pos || l > r)
        return;
    if (l == r)
    {
        a[l] = !a[l];
        if (a[l] == 0) cnt_open[id] = 1, cnt_close[id] = 0;
        else cnt_open[id] = 0, cnt_close[id] = 1;
        return;
    }
    int mid = l+r>>1;
    update(id<<1,l,mid,pos);
    update(id<<1|1,mid+1,r,pos);
    st[id] = st[id<<1] + st[id<<1|1] + min(cnt_open[id<<1] - st[id<<1], cnt_close[id<<1|1] - st[id<<1|1]);
    cnt_open[id] = cnt_open[id<<1] + cnt_open[id<<1|1];
    cnt_close[id] = cnt_close[id<<1] + cnt_close[id<<1|1];
}

iii Push(iii lef, iii rig)
{
    iii ans;
    ans.st = lef.st + rig.st + min(lef.nd.st - lef.st, rig.nd.nd - rig.st);
    ans.nd.st = lef.nd.st + rig.nd.st;
    ans.nd.nd = lef.nd.nd + rig.nd.nd;
    return ans;
}

void get(int id, int l, int r, int L, int R)
{
    if (l > R || L > r || l > r)
        return;
    if (L <= l && r <= R)
    {
        bruh = Push(bruh,{st[id],{cnt_open[id],cnt_close[id]}});
        return;
    }
    int mid = l+r>>1;
    get(id<<1,l,mid,L,R);
    get(id<<1|1,mid+1,r,L,R);
}

iii solve(int l, int r)
{
    if (l == r)
    {
        if (s[l] == '(') return {0,{1,0}};
        else return {0,{0,1}};
    }
    int mid = l+r>>1;
    iii lef = solve(l,mid);
    iii rig = solve(mid+1,r);
    return Push(lef,rig);
}

int main()
{
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> q;
    n = s.size();
    for (int i = 1; i <= n; i++)
    {
        a[i] = (s[i-1] == ')');
    }
    s_save[0] = s;

    if (n <= 1000 && q <= 1000)
    {
        for (int i = 1; i <= q; i++)
        {
            cin >> type >> l;
            l--;
            if (type == 'C')
            {
                if (s[l] == '(') s[l] = ')';
                else s[l] = '(';
            }
            else if (type == 'Q')
            {
                cin >> r;
                r--;
                cout << (r-l+1) - solve(l,r).st * 2 << '\n';
            }
            else
            {
                s = s_save[l];
            }
            //cout << i << ": " << s << '\n';
            s_save[i] = s;
        }

        return 0;
    }

    build(1,1,n);
    while(q--)
    {
        cin >> type >> l;
        if (type == 'C')
            update(1,1,n,l);
        else if (type == 'Q')
        {
            cin >> r;
            bruh = {0,{0,0}};
            get(1,1,n,l,r);
            cout << (r-l+1) - bruh.st*2 << '\n';
        }
        else
        {

        }
    }

}
/*
((()))
11
C 1
Q 2 5
C 5
Q 1 6
C 5
C 4
Q 3 6
C 4
C 5
C 1
Q 1 5
*/

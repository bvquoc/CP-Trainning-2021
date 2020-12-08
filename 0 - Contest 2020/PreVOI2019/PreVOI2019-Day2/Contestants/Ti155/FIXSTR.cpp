#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Task "FIXSTR"

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;

struct node
{
    int bac, Min;
    node (int bac = 0, int Min = 0):
        bac(bac), Min(Min) {}
    node operator + (const node & other) const
    {
        node res;
        res.bac = bac + other.bac;
        res.Min = min(Min, bac + other.Min);
        return res;
    }
    int Get(void)
    {
        return bac - Min - Min;
    }
}ST[4*maxn];

#define lc id<<1
#define rc id<<1|1

void Update(int id, int l, int r, int i, int val)
{
    if (i > r || l > i) return;
    if (l == r){
        ST[id] = node(val, min(0, val));
        return;
    }
    int mid = (l + r) / 2;
    Update(lc, l, mid, i, val); Update(rc, mid+1, r, i, val);
    ST[id] = ST[lc] + ST[rc];
}

node GetSum(int id, int l, int r, int L, int R)
{
    if (l > R || L > r){
        return node(0, 0);
    }
    if (L <= l && r <= R){
        return ST[id];
    }
    int mid = (l + r) / 2;
    return GetSum(lc, l, mid, L, R) + GetSum(rc, mid+1, r, L, R);
}

#undef lc
#undef rc

int Get(char x)
{
    if (x == '(') return 1;
    return -1;
}

struct T
{
    char type;
    int l, r;
}Query[maxn];;

int N, Q;
string str;
string s[1005];

void sub2(void)
{
    for (int i=1; i<=Q; ++i){
        char type = Query[i].type;
        int l = Query[i].l;
        int r = Query[i].r;
        if (type == 'C'){
            if (str[l] == '(') str[l] = ')';
            else str[l] = '(';
            Update(1, 1, N, l, Get(str[l]));
        }
        else{
            cin >> r;
            node res = GetSum(1, 1, N, l, r);
            cout << res.Get() << '\n';
        }
    }
}

void sub1(void)
{
    s[0] = str;
    for (int i=1; i<=Q; ++i){
        char type = Query[i].type;
        int l = Query[i].l;
        int r = Query[i].r;
        if (type == 'C'){
            if (str[l] == '(') str[l] = ')';
            else str[l] = '(';
        }
        else if (type == 'Q'){
            cin >> r;
            node res;
            for (int i=l; i<=r; ++i){
                res.bac += Get(str[i]);
                res.Min = min(res.Min, res.bac);
            }
            cout << res.Get() << '\n';
        }
        else{
            str = s[l - 1];
        }
        s[i] = str;
        ///cout << str << '\n';
    }
}

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> str;
    N = str.size();
    str = " " + str;
    for (int i=1; i<=N; ++i){
        Update(1, 1, N, i, Get(str[i]));
    }
    cin >> Q;
    bool ok = 0;
    for (int i=1; i<=Q; ++i){
        cin >> Query[i].type >> Query[i].l;
        if (Query[i].type == 'Q'){
            cin >> Query[i].r;
        }
        if (Query[i].type == 'U'){
            ok = 1;
        }
    }
    if (ok) sub1();
    else sub2();
}

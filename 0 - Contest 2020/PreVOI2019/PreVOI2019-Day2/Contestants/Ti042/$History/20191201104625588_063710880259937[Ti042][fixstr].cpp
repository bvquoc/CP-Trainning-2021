#include<bits/stdc++.h>

using namespace std;

#define pb      push_back
#define sz(x)   x.size()

#define lch     tr[i].lef
#define rch     tr[i].rig

const int   N   = 1e6 + 1;

struct Bracket  {
    int Sum;
    int Min;
    Bracket(int _s = 0,int _m = 0) : Sum(_s), Min(_m)   {}
};
Bracket operator + (const Bracket &a,const Bracket &b)  {
    return  Bracket(a.Sum + b.Sum,min(a.Min,a.Sum + b.Min));
}
int calc(Bracket a) {
    return  a.Sum - a.Min - a.Min;
}

struct Node {
    Bracket LL;
    Bracket RR;

    Bracket TT;

    bool have;

    int ans;
    int lef, rig;

    Node() {
        ans = have = 0;
        LL.Sum = LL.Min = 0;
        RR.Sum = RR.Min = 0;
        TT.Sum = TT.Min = 0;
    }
};

ostream & operator << (ostream&out,Node &a) {
    out << "(" << a.LL.Sum << "-" << a.LL.Min << ") ";
    out << "(" << a.RR.Sum << "-" << a.RR.Min << ") ";
    out << "(" << a.TT.Sum << "-" << a.TT.Min << ") ";

    out << a.have << " ";
    out << a.ans << " ";
    out << a.lef << " ";
    out << a.rig << "\n";
    return  out;
}

Node operator + (const Node &a,const Node &b)   {
    Node c;

    if (a.have) c.LL = a.LL, c.have = 1;
    else        c.LL = a.LL + b.LL;

    if (b.have) c.RR = b.RR, c.have = 1;
    else        c.RR = a.RR + b.RR;

    c.TT = a.TT + b.TT;

    c.ans = a.ans + b.ans;

    c.ans -= calc(a.RR);
    c.ans -= calc(b.LL);

    c.ans -= calc(a.TT);
    c.ans -= calc(b.TT);

    c.ans += calc(a.RR + b.LL);
    c.ans += calc(a.TT + b.TT);

    return  c;
}

vector<Node> tr;
vector<int>  Rt;

string s;

void ini(int i,int l,int r) {
    if (l == r) {
        if (s[l] == '(')    tr[i].LL = tr[i].RR = Bracket( 1, 0);
        if (s[l] == ')')    tr[i].LL = tr[i].RR = Bracket(-1,-1);
        if (s[l] == '{')    tr[i].TT = Bracket( 1, 0),  tr[i].have = 1;
        if (s[l] == '}')    tr[i].TT = Bracket(-1,-1),  tr[i].have = 1;

        tr[i].ans = 1;

        return;
    }
    int m = (l + r) / 2;

    lch = sz(tr);   tr.pb(Node());  ini(lch,l,m);   ++m;
    rch = sz(tr);   tr.pb(Node());  ini(rch,m,r);

    tr[i] = tr[lch] + tr[rch];
}
void upd(int i,int l,int r,int p)   {
    if (l == r) {
        if (tr[i].LL.Sum > 0)   tr[i].LL = tr[i].RR = Bracket(-1,-1);
        else                    tr[i].LL = tr[i].RR = Bracket( 1, 0);
        return;
    }
    int m = (l + r) / 2;

    if (m >= p) {   tr.pb(tr[lch]); lch = sz(tr) - 1;   upd(lch,l,m,p);     }
    else        {   tr.pb(tr[rch]); rch = sz(tr) - 1;   upd(rch,m + 1,r,p); }

    tr[i] = tr[lch] + tr[rch];
}
Node get(int i,int l,int r,int L,int R) {
    if (l > R)  return  Node();
    if (L > r)  return  Node();

    if (L <= l && r <= R)
        return  tr[i];

    int m = (l + r) / 2;

    return  get(lch,l,m,L,R) + get(rch,m + 1,r,L,R);
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef combi
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    #endif // combi

    tr.pb(Node());
    Rt.pb(0);

    cin >> s;   s = "#" + s;

    int n = s.size() - 1;
    int q;  cin >> q;

    ini(0,1,n);

    for(int i = 1 ; i <= q ; ++i)   {
        char c; cin >> c;
        if (c == 'C')   {
            int p;  cin >> p;

            tr.pb(tr[Rt.back()]);
            Rt.pb(sz(tr) - 1);

            upd(Rt.back(),1,n,p);
        }
        if (c == 'U')   {
            int p;  cin >> p;

            Rt.pb(Rt[p - 1]);
        }
        if (c == 'Q')   {
            int l;  cin >> l;
            int r;  cin >> r;

            Rt.pb(Rt.back());

            cout << get(Rt.back(),1,n,l,r).ans << "\n";
        }
    }
}
/*
((()))
10
C 1
Q 2 5
C 5
Q 1 6
U 3
C 4
Q 3 6
U 5
C 1
Q 1 5
*/

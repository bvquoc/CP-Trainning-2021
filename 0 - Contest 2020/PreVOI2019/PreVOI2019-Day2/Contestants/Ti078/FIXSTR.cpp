///Thu Thaoo

#include <bits/stdc++.h>

#define ll long long
#define I freopen(Task".inp", "r", stdin)
#define O freopen(Task".out", "w", stdout)
#define vt vector <int>
#define rt(O) return O
#define pii pair <int, int>
#define st first
#define nd second
#define rd third
#define th fourth
#define pusf push_front
#define popf pop_front
#define popb pop_back
#define pusb push_back
#define Task "fixstr"
#define MOD 1000000007
#define uns unsigned
#define int ll
#define read_fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORU(i, l, n) for (int i=l; i<=n; i++)
#define FORD(i, n, l) for (int i=n; i>=l; i--)
#define reset(x) memset (x, 0, sizeof(x))
#define ignLine cout<<endl

using namespace std;

const int N = 1e6 + 3;

int m;
string S[1003];
string s;
int n;
bool F[N];
int upStr = 1;

struct sub1
{
    int check(int l, int r)
    {
        reset(F);
        FORU(i, l+1, r)
        {
            int loang = 0;
            while (S[upStr][i+loang] == ')' && S[upStr][i-1-loang] == '(' && !F[i+loang] && !F[i-1-loang])
            {
                F[i+loang] = true;
                F[i-1-loang] = true;
                loang++;
            }
        }
        int kount = 0;
        FORU(i, l, r)
        {
            if (!F[i]) kount++;;
        }
        return kount;
    }
    void swapp(int u)
    {
        if (S[upStr][u] == '(') S[upStr][u] = ')';
        else S[upStr][u] = '(';
    }
    void process(int l, int r)
    {
        int res = check(l, r);
        cout<<res<<endl;
    }
    void flipp (int u)
    {
        upStr = upStr + 1;
        S[upStr] = S[u-1];
    }
} sb1;

struct sub2
{
    int check(int l, int r)
    {
        reset(F);
        FORU(i, l+1, r)
        {
            int loang = 0;
            while (s[i+loang] == ')' && s[i-1-loang] == '(' && !F[i+loang] && !F[i-1-loang])
            {
                F[i+loang] = true;
                F[i-1-loang] = true;
                loang++;
            }
        }
        int kount = 0;
        FORU(i, l, r)
        {
            if (!F[i]) kount++;;
        }
        return kount;
    }
    void swapp(int u)
    {
        if (s[u] == '(') s[u] = ')';
        else s[u] = '(';
    }
    void process(int l, int r)
    {
        int res = check(l, r);
        cout<<res<<endl;
    }
} sb2;
void Input1()
{
    FORU(i, 1, m)
    {
        char ch;
        cin>>ch;
        if (ch == 'C')
        {
            int u;
            cin>>u;
            upStr = upStr + 1;
            S[upStr] = S[upStr-1];
            sb1.swapp(u);
//            cout<<S[upStr]<<endl;
        }
        else if (ch == 'Q')
        {
            int u, v;
            cin>>u>>v;
            sb1.process(u, v);
            upStr = upStr + 1;
            S[upStr] = S[upStr-1];
//            cout<<S[upStr]<<endl;
        }
        else
        {
            int u;
            cin>>u;
            sb1.flipp(u);
//            cout<<S[upStr]<<endl;
        }
    }
}
void Input2()
{
    s = S[1];
    FORU(i, 1, m)
    {
        char ch;
        cin>>ch;
        if (ch == 'C')
        {
            int u;
            cin>>u;
            sb2.swapp(u);
//            cout<<S[upStr]<<endl;
        }
        else if (ch == 'Q')
        {
            int u, v;
            cin>>u>>v;
            sb2.process(u, v);
//            cout<<S[upStr]<<endl;
        }
    }
}
main()
{
    read_fast
    I;
    O;
    cin>>S[1];
    n = S[1].size();
    S[1] = " " + S[1];
    cin>>m;
    if (n <= 1000 && m <= 1000) Input1();
    else
        Input2();
//    process();
    rt(0);
}

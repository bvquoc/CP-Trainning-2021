#include <bits/stdc++.h>
using namespace std;
struct query
{
    char t;
    int i, j;
}q[1000100];
string s;
int m, it[4000100], it1[4000100], leaf[1000100];
bool ok;
vector <pair <int, int> > v;
void sub1()
{
    vector <string> v;
    for (int i = 0; i < m; i++)
    {
        v.push_back(s);
        if (q[i].t == 'C')
        {
            if (s[q[i].i] == '(')
                s[q[i].i] = ')';
            else
                s[q[i].i] = '(';
        }
        else if (q[i].t == 'Q')
        {
            int res = 0, cnt = 0;
            for (int j = q[i].i; j <= q[i].j; j++)
            {
                //cout << s[j];
                if (s[j] == '(')
                    cnt++;
                else
                    cnt--;
                if (cnt < 0)
                {
                    res++;
                    cnt = 0;
                }
            }
            //cout << "\n";
            cout << res + cnt << "\n";
        }
        else
            s = v[q[i].i - 1];
    }
}
void build(int k, int l, int r)
{
    if (l == r)
    {
        if (s[l] == '(')
            it[k] = 1;
        else
            it[k] = -1;
        leaf[l] = k;
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    it[k] = it[k * 2] + it[k * 2 + 1];
    if (it[k] < 0)
        it1[k] = -it[k];
    //cout << k << " " << it[k] << "\n";
}
void update(int x)
{
    int k = leaf[x];
    it[k] = -it[k];
    for (k /= 2; k > 0; k /= 2)
    {
        it[k] = it[k * 2] + it[k * 2 + 1];
        if (it[k] < 0)
        {
            it1[k] = -it[k];
            it[k] = 0;
        }
    }
}
void get(int k, int l, int r, int L, int R)
{
    if (r < L || l > R)
        return;
    if (l >= L && r <= R)
    {
        pair <int, int> tmp;
        tmp.first = it[k];
        if (l != r)
            tmp.second = it1[k * 2] + it1[k * 2 + 1];
        else
            tmp.second = 0;
        v.push_back(tmp);
        return;
    }
    int mid = (l + r) / 2;
    get(k * 2, l, mid, L, R);
    get(k * 2 + 1, mid + 1, r, L, R);
}
void sub2()
{
    int n = s.length();
    build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        if (q[i].t == 'C')
            update(q[i].i);
        else
        {
            v.clear();
            get(1, 1, n, q[i].i, q[i].j);
            int res = 0;
            for (int i = 0; i < v.size() - 1; i++)
                res += max(v[i + 1].first - v[i].second, 0);
            cout << res + v[0].first + v[v.size() - 1].second << "\n";
        }
    }
}
void sub3()
{
    for (int i = 0; i < m; i++)
    {
        if (q[i].t == 'Q')
            cout << "0\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp", "r", stdin);
    freopen("FIXSTR.out", "w", stdout);
    cin >> s >> m;
    s = '.' + s;
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].t >> q[i].i;
        q[i].i;
        if (q[i].t == 'Q')
        {
            cin >> q[i].j;
            q[i].j;
        }
        if (q[i].t == 'U')
            ok = 1;
    }
    if (m <= 1000)
        sub1();
    else if (!ok)
        sub2();
    else
        sub3();
}

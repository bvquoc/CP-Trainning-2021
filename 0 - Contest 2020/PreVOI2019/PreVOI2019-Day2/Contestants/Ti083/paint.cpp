#include <bits/stdc++.h>

using namespace std;

const string TASK = "paint";

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()

using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
#define fi first
#define se second

const int MAXN = 1000007;
int col[MAXN], ptr = 1, num_col = 0;
int prv[MAXN];
int represent[MAXN];
int col_by_char[MAXN];
int N;

int get(int c)
{
    return (prv[c] != c ? prv[c] = get(prv[c]) : c);
}

void add_col(int x)
{
    ++num_col;
//    cerr << "add " << char(x + 'a') << ": " << num_col << endl;
    col_by_char[x] = num_col;
    represent[num_col] = x;
    prv[num_col] = num_col;
}

int main()
{
    freopen((TASK + ".inp").c_str(), "r", stdin);
    freopen((TASK + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    while (N--) {
        int type;
        cin >> type;
        if (type == 1) {
            char ch;
            cin >> ch;
            int x = int(ch - 'a');
            if (!col_by_char[x]) add_col(x);

            col[ptr++] = col_by_char[x];
//            cerr << "nxt " << col_by_char[x] << endl;
        } else {
            char ch_a, ch_b;
            cin >> ch_a >> ch_b;
            int a = int(ch_a - 'a'), b = int(ch_b - 'a');
            if (a == b) continue;
            if (!col_by_char[a]) continue;

            if (!col_by_char[b]) add_col(b);
//            cerr << "prv " << col_by_char[a] << " --> " << col_by_char[b] << endl;
            prv[col_by_char[a]] = col_by_char[b];
            col_by_char[a] = 0;
        }
    }


    for (int i = 1; i < ptr; ++i) {
        putchar(int('a') + represent[get(col[i])]);
    }
}

/*
10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d
*/

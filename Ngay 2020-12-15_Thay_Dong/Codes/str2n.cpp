#include <bits/stdc++.h>
using namespace std;

struct node {
    int nxt[26]; vector <int> id;

    node() {
        memset(nxt, 0, sizeof nxt);
    }
};

vector <node> tr;
vector <int> st;
vector <int> own;

void insert(const string &s, int i) {
    int pt = 0;
    for (char c : s) {
        int t = c - 'a';
        if (!tr[pt].nxt[t]) {
            tr[pt].nxt[t] = tr.size();
            tr.emplace_back();
        }
        pt = tr[pt].nxt[t];
    }
    tr[own[i] = pt].id.push_back(i);
}

void dfs(int pt) {
    while (tr[pt].id.size()) {
        st.push_back(tr[pt].id.back());
        tr[pt].id.pop_back();
    }
    for (int t = 0; t < 26; t++)
        if (tr[pt].nxt[t])
            dfs(tr[pt].nxt[t]);
    while (st.size() > 1 &&
    own[st.back()] == pt) {
        cout << st.back() << ' ';
        st.pop_back();
        cout << st.back() << '\n';
        st.pop_back();
    }
}

int main() {
    freopen("str2n.inp", "r", stdin);
    freopen("str2n.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    tr.emplace_back();
    own.resize(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        string s; cin >> s;
        insert(s, i);
    }
    dfs(0); return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

struct TNode{
    TNode *child[26];
    int best, end, cntEnd, cnt, cntLess;
    TNode() {
        for (int i = 0; i < 26; ++i)
            child[i] = NULL;
        best = end = -1;
        cntEnd = cnt = cntLess = 0;
    }
};
string s;
TNode *dict[maxn];
int ans[maxn], cur;
TNode *Insert(TNode *p, const string &s, int id) {
    for (char x : s) {
        int nxt = x - 'a';
        if (p->child[nxt] == NULL) p->child[nxt] = new TNode();
        p = p->child[nxt];
        if (p->best < id)
            p->best = id;
    }
    
    if (p->end == -1) p->end = id;
    ++p->cntEnd;
    return p;
}
void DFS(TNode *p) {
    for (int j = 1; j <= p->cntEnd; ++j)
        ans[++cur] = p->end;
    for (int i = 0; i < 26; ++i) if (p->child[i] != NULL) {
        DFS(p->child[i]);
        p->child[i]->cntLess = p->cnt;
        p->cnt += p->child[i]->cnt;
    }
    p->cnt += p->cntEnd;
}
int CntLess(TNode *p, int l, int r) {
    int sum = 0;
    for (; l <= r; ++l) {
        sum += p->cntEnd;
        int nxt = s[l] - 'a';
        if (p->child[nxt] != NULL) {
            p = p->child[nxt];
            sum += p->cntLess;
        }
        else {
            for (int j = 0; j < nxt; ++j) 
                if (p->child[j] != NULL)   
                    sum += p->child[j]->cnt;
            return sum;
        }
    }
    return sum + p->cntEnd;
}
int main() {
#if ONLINE_JUDGE || THEMIS
    freopen("anctext.inp", "r", stdin);
    freopen("anctext.out", "w", stdout);
#endif

#ifdef LDT
    freopen("input.txt", "r", stdin);
    freopen("sub2.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    int n, q;
    cin >> s;
    cin >> n;  
    dict[0] = new TNode();
    for (int i = 1; i <= n; ++i) {
        int x;
        string si;
        cin >> x >> si;
        dict[i] = Insert(dict[x], si, i);
    }
    DFS(dict[0]);
    assert(cur == n);
    ans[0] = -1;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << ans[CntLess(dict[0], l, r)] << '\n';
    }
    return 0;
}

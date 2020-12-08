#include <bits/stdc++.h>

using namespace std;

constexpr int radix  = 27;
constexpr char start = 'a';
constexpr int nmod   = 2;
constexpr int mod[]  = {(int)1e9 + 7, (int)1e9 + 9};

vector<int> power[nmod];

struct hash_str {
  int vals[nmod];

  static void init(int n) {
    for (int i = 0; i < nmod; ++i) {
      vector<int>& p = power[i];
      p.resize(n + 1);
      p[0] = 1;
      for (int j = 1; j <= n; ++j) {
        p[j] = (long long)p[j - 1] * radix % mod[i];
      }
    }
  }

  inline bool operator<(const hash_str& rhs) const {
    for (int i = 0; i < nmod; ++i) {
      if (vals[i] != rhs.vals[i]) {
        return vals[i] < rhs.vals[i];
      }
    }
    return false;
  }

  inline bool operator==(const hash_str& rhs) const {
    for (int i = 0; i < nmod; ++i) {
      if (vals[i] != rhs.vals[i]) {
        return false;
      }
    }
    return true;
  }

  inline hash_str operator+(char c) const {
    hash_str res;
    c -= start - 1;
    for (int i = 0; i < nmod; ++i) {
      res.vals[i] = ((long long)vals[i] * radix + c) % mod[i];
    }
    return res;
  }

  inline hash_str sub(const hash_str& rhs, int len) const {
    hash_str res;
    for (int i = 0; i < nmod; ++i) {
      res.vals[i] = (vals[i] - (long long)rhs.vals[i] * power[i][len] + (long long)mod[i] * mod[i]) % mod[i];
    }
    return res;
  }
};

constexpr int alpha   = 26;
constexpr int maxlenS = 5e5L + 5;
constexpr int maxn    = 3e5L + 5;

struct trie {
  int index;
  int prev;
  int last;
  hash_str hash;
  trie* children[alpha];

  static int last_word;
  static vector<pair<hash_str, trie*>> nodes;

  trie() : index(-1), children() { }

  trie* insert(const char s[]) {
    trie* ptr = this;
    for (int i = 1; s[i]; ++i) {
      int c = s[i] - 'a';
      if (!ptr->children[c]) {
        ptr->children[c] = new trie();
      }
      ptr = ptr->children[c];
    }
    return ptr;
  }

  void dfs() {
    if (index != -1) {
      last_word = index;
    }
    nodes.push_back({hash, this});
    prev = last_word;
    for (int c = 0; c < alpha; ++c) {
      if (children[c]) {
        children[c]->hash = hash + ('a' + c);
        children[c]->dfs();
      }
    }
    last = last_word;
  }
} root;

vector<pair<hash_str, trie*>> trie::nodes;
int trie::last_word = -1;

char S[maxlenS];
int n;
trie* word[maxn];
int q;

hash_str hs[maxlenS];

void build_hash() {
  sort(trie::nodes.begin(), trie::nodes.end());
  int lenS = strlen(S + 1);
  hash_str::init(lenS);
  for (int i = 1; i <= lenS; ++i) {
    hs[i] = hs[i - 1] + S[i];
  }
}

bool exist(const hash_str& v) {
  auto it = lower_bound(trie::nodes.begin(), trie::nodes.end(), make_pair(v, (trie*)nullptr));
  return it != trie::nodes.end() && it->first == v;
}

trie* get(const hash_str& v) {
  auto it = lower_bound(trie::nodes.begin(), trie::nodes.end(), make_pair(v, (trie*)nullptr));
  return it->second;
}

int query(int from, int to) {
  from--;
  int lef = from, rig = to + 1;
  while (lef + 1 < rig) {
    int mid = (lef + rig) / 2;
    if (exist(hs[mid].sub(hs[from], mid - from))) {
      lef = mid;
    } else {
      rig = mid;
    }
  }
  trie* v = get(hs[lef].sub(hs[from], lef - from));
  if (lef == to) {
    return v->prev;
  }
  int c = S[rig] - 'a';
  int lower = -1;
  for (int i = 0; i < c; ++i) {
    if (v->children[i]) {
      lower = i;
    }
  }
  if (lower != -1 && v->children[lower]->last != -1) {
    return v->children[lower]->last;
  }
  return v->prev;
}

int main() {
#if ONLINE_JUDGE || THEMIS
  freopen("anctext.inp", "r", stdin);
  freopen("anctext.out", "w", stdout);
#else
  freopen("local.in", "r", stdin);
  freopen("local.out", "w", stdout);
#endif
  scanf("%*d");
  scanf("%s", S + 1);
  scanf("%d", &n);
  word[0] = &root;
  for (int i = 1; i <= n; ++i) {
    int x;
    static char s[maxlenS];
    scanf("%d%s", &x, s + 1);
    word[i] = word[x]->insert(s);
    if (word[i]->index == -1) {
      word[i]->index = i;
    }
  }
  root.dfs();
  build_hash();
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", query(l, r));
  }
  return 0;
}

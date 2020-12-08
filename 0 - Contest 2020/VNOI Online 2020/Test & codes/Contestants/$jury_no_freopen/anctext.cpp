#include <iostream> 
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

#define For(i , a , b) for (int i = a , _b = b ; i <= _b ; ++i)
#define Rep(i , n) for (int i = 0 , _n = n ; i < _n ; ++i)
#define sz(A) ((int)A.size())
const int maxn = 300000 + 123;
const int alpha = 27;
int n; ///number of words
int at[maxn]; ///which node
string s;

struct node {
	int child[alpha], parent, level;
	char ch;
	node() {
		memset(child, -1, sizeof(child));
	}
};
std::vector<node> tree;
void initTrie() { 
	tree.push_back(*(new node()));
	tree[0].level = 0;
}
int insertString(int from, string s) {
	int current = from;
	Rep(i, sz(s)) {
		int k = s[i] - 'a';
		if (tree[current].child[k] == -1){ 
			tree.push_back(*(new node()));
			tree.back().parent = current;
			tree.back().ch = s[i];
			tree.back().level = tree[current].level + 1;
			tree[current].child[k] = sz(tree) - 1;
		}
		current = tree[current].child[k];
	}
	return current;
} 
void ReadData() {
	cin >> s;
	s = ' ' + s;
	initTrie();
	cin >> n;
	For(i, 1, n) {
		int parent; cin >> parent;
		string s; cin >> s;
		at[i] = insertString(at[parent], s);
	}
}

const int nMods = 2;
const int md[] = {(int)1e9 + 7, 69696969};
struct hsh {
	int value[nMods];

	hsh() {}
	hsh(int from) {
		Rep(i, nMods) value[i] = from;
	}
	hsh operator + (const hsh other) {
		hsh result;
		Rep(i, nMods) result.value[i] = (value[i] + other.value[i]) % md[i];
		return result;
	}
	hsh operator - (const hsh other) {
		hsh result;
		Rep(i, nMods) result.value[i] = (value[i] - other.value[i] + md[i]) % md[i];
		return result;
	}
	hsh operator * (const hsh other) {
		hsh result;
		Rep(i, nMods) result.value[i] = (1LL * value[i] * other.value[i]) % md[i];
		return result;
	}
	bool operator == (const hsh other) {
		Rep(i, nMods) if (other.value[i] != value[i]) return false;
		return true;
	}
};

const int base = 217;
hsh pwr[500000 + 123], s_hashed[500000 + 123];
hsh get(int lo, int hi) {
	return s_hashed[hi] - s_hashed[lo - 1] * pwr[hi - lo + 1];
}
void initHash() {
	pwr[0] = hsh(1);
	const hsh unit = hsh(base);
	For(i, 1, 500000) pwr[i] = pwr[i - 1] * unit;
	s_hashed[0] = hsh(0);
	For(i, 1, sz(s) - 1) {
		s_hashed[i] = s_hashed[i - 1] * unit + hsh(s[i] - 'a' + 1);
	}
}

int id[maxn], top = 0;
std::vector<std::vector<int> > contains;
inline void dfs(const int u) {
	///sort in decreasing order. 
	reverse(contains[u].begin(), contains[u].end());
	for (auto x: contains[u]) id[++top] = x;
	Rep(ch, alpha) if (tree[u].child[ch] != -1) dfs(tree[u].child[ch]);
}
void sortWords() {
	contains.resize(sz(tree));
	For(i, 1, n) contains[at[i]].push_back(i);
	dfs(0);
}

const int lg = 20;
std::vector<hsh> prefix;
std::vector<std::vector<int> > jump;

void finalizeTrie() {
	prefix.resize(sz(tree));
	prefix[0] = hsh(0);
	For(i, 1, sz(tree) - 1) {
		int p = tree[i].parent;
		prefix[i] = prefix[p] * hsh(base) + hsh(tree[i].ch - 'a' + 1);
	}

	jump.resize(sz(tree));
	for (auto& v: jump) v.assign(lg + 1, -1);
	For(i, 1, sz(tree) - 1) {
		jump[i][0] = tree[i].parent;
	}
	For(lv, 1, lg) Rep(i, sz(tree)) {
		if (jump[i][lv - 1] != -1) {
			jump[i][lv] = jump[jump[i][lv - 1]][lv - 1];
		}
	}
}
///If string from x to root <= s[lo..hi] return true else return false
bool compare(int x, int lo, int hi) {
	int lenx = tree[x].level, len = hi - lo + 1;
	if (tree[x].level <= len && prefix[x] == get(lo, lo + lenx - 1)) {
		///x is prefix of s[lo..hi]
		return true;
	}
	for (int i = lg; i >= 0; i--) {
		int y = jump[x][i];
		if (y != -1) {
			int leny = tree[y].level;
			if (leny > len) {
				x = y;
			} else 
			if (leny <= len && (!(prefix[y] == get(lo, lo + leny - 1))) ) {
				x = y;
			}
		}
	}
	lenx = tree[x].level;
	if (lo + lenx - 1 > hi) return false; ///s[lo..hi] is prefix of x
	return tree[x].ch < s[lo + lenx - 1];
}

void Process() {
	

	initHash();
	sortWords();
	finalizeTrie();

	int q; cin >> q;
	while (q--) {
		int L, R; cin >> L >> R;
		int lo = 1, hi = top, res = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (compare(at[id[mid]], L, R)) {
				res = id[mid]; lo = mid + 1;
			} else hi = mid - 1;
		}

		cout << res << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#if ONLINE_JUDGE || THEMIS
	#else
    //	freopen("input.txt", "r", stdin);
    //   freopen("local.out", "w", stdout);
	#endif

    int sub; cin >> sub;
	ReadData();
	Process();

	return 0;

}			

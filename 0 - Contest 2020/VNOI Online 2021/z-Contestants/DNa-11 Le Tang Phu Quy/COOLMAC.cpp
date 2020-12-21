#include<bits/stdc++.h>
using namespace std;

typedef long long Int;
const int MOD = 2004010501;//>2e9

#define task "COOLMAC"
struct Range {
	int left, right;
	Range(int left = 0, int right = 0) : left(left), right(right) {
	}
	void input() { cin >> left >> right; }
	bool operator < (const Range& other) const {
		return right > other.right;
	}
};

const int ubound = (int) 1e5;
int lbound = ubound;
int num_seqs; 
Range seqs[ubound + 5];

//namespace Subtask1 {
//	
//	int range;
//	int fenwick[ubound + 5];
//	void update(int x, int delta) {
//		for (; x <= range; x += x & -x) fenwick[x] += delta;	
//	}
//	
//	int query(int x) {
//		int res = 0; for (; x > 0; x &= x - 1) res += fenwick[x];
//		return res;
//	}
//	
//	int brute_ans = ubound, brute_run = 0;
//	void backtrack(int pos) {
//		if (pos > num_seqs) {
//			int cnt = query(range) - query(lbound - 1);
//			bool check = true;
//			if (cnt > 0) //WRONG CONDITION!!!	
//			brute_ans = min(brute_ans, brute_run);
//		}
//		else {
//			backtrack(pos + 1);
//			update(seqs[pos].left, +1);
//			++brute_run;
//			backtrack(pos + 1);
//			--brute_run;
//			update(seqs[pos].left, -1);
//		}
//	}
//	
//	void solve() {
//		memset(fenwick, 0, sizeof(fenwick));
//		range = ubound;
//		backtrack(1);
//	}
//}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	cin >> num_seqs;
	for (int i = 1; i <= num_seqs; i++) seqs[i].input();
	int num_days;
	cin >> num_days;
	for (int t, i = 1; i <= num_days; i++) cin >> t, lbound = min(lbound, t);
	
	sort(seqs + 1, seqs + 1 + num_seqs);
	int ans = 0;
	for (int pos = ubound + 1, it = 1; it <= num_seqs and pos > lbound; it++) {
		int pick = -1;
		for (; it <= num_seqs and seqs[it].right >= pos - 1; it++) 
			if (pick == -1) pick = it; else if (seqs[it].left < seqs[pick].left) pick = it;
		if (pick == -1) return cout << -1, 0;
		it = pick, ++ans;
		pos = seqs[pick].left;
	}  
	
	cout << ans;
}


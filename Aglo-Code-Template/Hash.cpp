const int BASE = 722;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
#define NMOD 2 // số modulo sẽ sử dụng

#define MAX   200200
int pw[NMOD][MAX]; // pw[j][i] = BASE^i % MOD[j];

struct Hash {
	int value[NMOD];

	Hash() {
		memset(value, 0, sizeof value);
	}

	Hash(char c) {
		for (int i = 0; i < NMOD; i++) value[i] = c;
	}

	Hash operator + (const Hash &h) const {
		Hash res;
		for (int i = 0; i < NMOD; i++) {
			res.value[i] = value[i] + h.value[i];
			if (res.value[i] >= MOD[i]) res.value[i] -= MOD[i];
		}
		return res;
	}

	Hash operator - (const Hash &h) const {
		Hash res;
		for (int i = 0; i < NMOD; i++) {
			res.value[i] = value[i] - h.value[i];
			if (res.value[i] < 0) res.value[i] += MOD[i];
		}
		return res;
	}

	Hash operator * (int k) const { // nhân mã hash với BASE^k
		Hash res;
		for (int i = 0; i < NMOD; i++) 
			res.value[i] = 1LL * value[i] * pw[i][k] % MOD[i];
		return res;
	}

	// vì bài này cần cho các mã hash vào map và gộp các mã hash cùng nhau lại,
	// ta phải viết hàm so sánh hai mã hash
	bool operator < (const Hash &h) const {
		for (int i = 0; i < NMOD; i++) if (value[i] != h.value[i]) 
			return value[i] < h.value[i];
		return false;
	}
};


char words[55][MAX];
Hash hashes[55][MAX];
// tính bảng mã Hash của xâu thứ i
int len = strlen(words[i]);
for (int j = 1; j <= len; j++) hashes[i][j] = hashes[i][j - 1] + Hash(words[i][j]) * j;
// lấy mã hash của xâu thứ i, đoạn từ l đến r
Hash getHash(int i, int l, int r) {
	return (hashes[i][r] - hashes[i][l - 1]) * (MAX - l);
}
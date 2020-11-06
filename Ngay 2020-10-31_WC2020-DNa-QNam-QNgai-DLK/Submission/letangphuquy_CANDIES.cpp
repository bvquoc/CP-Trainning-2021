#include<bits/stdc++.h>
using namespace std;

const int minN = 1e5 + 500;

typedef long long Int;
const Int INF = 1e15;

const int maxK = 100;
int numK = 0;
Int fibo[maxK];
void generate_fibo() {
	fibo[1] = fibo[2] = 1;
	for (int k = 3; k < maxK; k++) {
		fibo[k] = fibo[k - 1] + fibo[k - 2];
		if (fibo[k] > INF) break;
		numK = k;
	}	
	cerr << "the " << numK << "-th fibo = " << fibo[numK] << "\n";
}

int cnt[minN], sum[minN][maxK];
void subtask1() {
	cnt[0] = 0;
	int DEBUG = 0;
	for (int i = 1; i < minN; i++) {
		cnt[i] = i;
		for (int k = 1; k <= numK and fibo[k] <= i; k++)
			cnt[i] = min(cnt[i], cnt[i - fibo[k]] + 1);
		DEBUG = max(DEBUG, cnt[i]);
		sum[i][cnt[i]] += cnt[i];
	}
	for (int i = 1; i < minN; i++)
		for (int k = 0; k <= DEBUG; k++) sum[i][k] += sum[i - 1][k];
	cerr << "maximum number of candies used = " << DEBUG << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	generate_fibo();
	subtask1();
	int nTests;
	cin >> nTests;
	for (Int n, k; nTests --> 0; ) {
		cin >> n >> k;
		if (max(n, k) < minN) {
//			cout << subtask1(n, k) << "\n";
			int answer = 0;
			for (int _k = k; _k < maxK; _k++) answer += sum[n][_k];
			cout << answer << "\n";
		}
	}
}

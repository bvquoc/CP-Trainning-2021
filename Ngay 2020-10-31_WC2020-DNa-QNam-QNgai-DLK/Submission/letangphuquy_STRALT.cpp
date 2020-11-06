#include<bits/stdc++.h>
using namespace std;

int cntOperations = 0;
string desc;
string transform(int l, int r) {
	stack<int> round, box1, box2;
	vector<pair<int,int>> substrings;
//	vector<int> reps;
	for (int i = l; i <= r; i++) {
		if (desc[i] == '(') round.push(i);
		if (desc[i] == ')') {
			if (round.size() + box1.size() + box2.size() == 1) {
				int j = round.top();
				substrings.push_back(make_pair(j, i));
			}
			round.pop();
		}
		if (desc[i] == '[') {
			if (desc[i + 1] == '*') box1.push(i);
			else box2.push(i);
		}
		if (desc[i] == ']') {
			bool typ = (desc[i - 1] == '*');
			if (round.size() + box1.size() + box2.size() == 1) {
				int j = (typ) ? box2.top() : box1.top();
				substrings.push_back(make_pair(j, i));
			}
			if (typ) box2.pop();
			else box1.pop();
		}
	}
	cntOperations += substrings.size();
	string result = "";
	vector<bool> isFree(r - l + 1, true);
	for (auto str : substrings) {
		for (int i = str.first; i <= str.second; i++) isFree[i - l] = false;
	}
	for (int i = l, it = 0, cnt = 0; i <= r; i++) {
		if (isFree[i - l]) {
			if (isalpha(desc[i])) result += desc[i], cnt = 0;
			else cnt = 10 * cnt + (desc[i] - '0');
		}
		else {
			if (it < substrings.size() and i == substrings[it].first) {
				if (desc[i] == '(') {
					string get = transform(substrings[it].first + 1, substrings[it].second - 1);
//					cerr << cnt << " x [" << substrings[it].first << "," << substrings[it].second << "]\n"; 
					for (; cnt --> 0; ) 
						result += get;
				}
				else {
					if (desc[i + 1] == '*') {
						string get = transform(i + 2, substrings[it].second - 1);
						result += get;
						for (int i = get.size() - 1; i >= 0; i--) result += get[i];
					}
					else {
						string get = transform(i + 1, substrings[it].second - 2);
						result += get;
						for (int i = get.size() - 2; i >= 0; i--) result += get[i];
					}
				}
				it++;
			}
			cnt = 0;
		}
	}
//	cerr << "[" << l << "," << r << "] : " << result << "\n";
	return result;
}

int main()
{
	cin >> desc;
	string answer = transform(0, desc.size() - 1);
	cout << cntOperations << "\n";
	cout << answer;
}

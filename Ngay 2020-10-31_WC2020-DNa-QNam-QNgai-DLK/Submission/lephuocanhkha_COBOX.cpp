#include <bits/stdc++.h>
using namespace std;

struct Box {
    int a, b, id;
};

bool cmp(const Box &a, const Box &b) {
    if (a.a == b.a) return a.b > b.b;
    return a.a > b.a;
}

Box p[100005];
vector<int> group[100005];
map<long long, long long> cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    bool sub2 = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
        p[i].id = i;

        if (p[i].a != p[i].b) sub2 = 0;
    }

    sort(p + 1, p + n + 1, cmp);

    if (sub2 == 1) {
        int cntGroup = 0;
        for (int i = 1; i <= n; i++) {
            cnt[p[i].a]++;
            int count = cnt[p[i].a];
            group[count].push_back(p[i].id);
            cntGroup = max(cntGroup, count);
        }

        cout << cntGroup << "\n";
        for (int i = 1; i <= n; i++) {
            if (group[i].empty()) break;

            cout << group[i].size() << " ";
            for (auto j: group[i]) {
                cout << j << ' ';
            }
            cout << "\n";
        }
    }
    

    return 0;
}
#include<bits/stdc++.h>
#define task "PAINT"
#define nmax 1000006

using namespace std;

typedef pair<int, int> pii;

char Paint[] = "abcdefghijklmnopqrstuvwxyz";
int check[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
int n;
vector<int> vti;
vector<pii> vtp;
string s;

void Enter() {
    cin >> n;
}

void Solve() {
    for(int i = 1; i <= n; i++) {
        int t;
        char x, y;
        cin >> t >> x;
        if(t == 1)
            s = s + x;
        else {
            cin >> y;
            for(int j = 0; j < s.length(); j++)
                if(s[j] == x)
                    s[j] = y;
        }
    }
    cout << s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Enter();
    Solve();
}

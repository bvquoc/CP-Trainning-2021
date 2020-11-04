#include <bits/stdc++.h>
using namespace std;

string a, b, s;
int T, res;
vector <int> S;

int main() {
    scanf("%d", &T);
    while(T--) {
        cin >> a >> b;
        while(a[0] == '0') a.erase(0, 1);
        while(b[0] == '0') b.erase(0, 1);
        if (b.size() > a.size()) swap(a, b);
        for (int i = 1; i <= a.size() - b.size(); i++)
            s = s + '0';
        b = s + b;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] + b[i] - '0' - '0' + res >= 10) {
                S.push_back((a[i] + b[i] - '0' - '0' + res) % 10);
                res = 1;
            }
            else {
                S.push_back(a[i] + b[i] - '0' - '0' + res);
                res = 0;
            }
        }
        if (res == 1) printf("1");
        for (int i = S.size() - 1; i >= 0; i--)
            printf("%d", S[i]);
        printf("\n"), S.clear(), res = 0, s.clear();
    }
    return 0;
}

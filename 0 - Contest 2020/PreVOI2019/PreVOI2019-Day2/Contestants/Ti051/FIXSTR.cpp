#include<bits/stdc++.h>
#define task "FIXSTR"
#define mmax 1000006

using namespace std;

int n, m;
string A;
string B[mmax];
struct {
    char c;
    int x, y;
} e[mmax];

int check(int x, int y) {
    int res = 0;
    int cnt = 0;
    for(int i = x; i <= y; i++) {
        if(A[i] == ')') {
            if(cnt)
                cnt--;
            else
                res++;
        }
        else
            cnt++;
    }
    res += cnt;
    return res;
}

void Solve1() {
    B[0] = A;
    for(int i = 1; i <= m; i++) {
        if(e[i].c == 'C')
            A[e[i].x - 1] = (A[e[i].x - 1] == ')' ? '(' : ')');
        if(e[i].c == 'Q')
            cout << check(e[i].x - 1, e[i].y - 1) << '\n';
        if(e[i].c == 'U')
            A = B[e[i].x - 1];
        B[i] = A;
    }
}

void Solve2() {
    B[0] = A;
    for(int i = 1; i <= m; i++) {
        if(e[i].c == 'C')
            A[e[i].x - 1] = (A[e[i].x - 1] == ')' ? '(' : ')');
        if(e[i].c == 'Q')
            cout << check(e[i].x - 1, e[i].y - 1) << '\n';
    }
}

void Enter() {
    cin >> A;
    cin >> m;
    bool ok = 1;
    for(int i = 1; i <= m; i++) {
        cin >> e[i].c >> e[i].x;
        if(e[i].c == 'Q')
            cin >> e[i].y;
        if(e[i].c == 'U')
            ok = 0;
    }
    if(ok)
        Solve2();
    else
        Solve1();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Enter();
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }

int cal(int a, int b) { return (b - a + 1) >> 1; }
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a / c == b / c)
    {
        cout << cal(a, b);
        return 0;
    }

    int nc = a / c * c + c;
    int pc = b / c * c + 0;
    int mid = (pc - nc) / c;
    int move = cal(0, c);
    int step = cal(a, nc - 1) + cal(pc + 1, b) + 1 + mid * move;
    cout << step;
    return 0;
}
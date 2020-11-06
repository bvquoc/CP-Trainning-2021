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
typedef vector<int>    vi;
typedef pair<int, int> pi;
typedef vector<ll>     vll;
typedef pair<ll, int>  pli;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }

int main()
{
    int n, k;
    cin >> k >> n;

    deque<int> S;
    ll sum = 0;
    int res = 0;
    bool ok = false;
    while (n-->0)
    {
        int x;
        cin >> x;

        sum += x;
        S.push_back(x);
        if (sum >= k) ok = true;

        if (!ok) continue;
        while (S.size() && sum - S.front() >= k)
        {
            sum -= S.front();
            S.pop_front();
        }
        maximize(res, int(S.size()));
    }

    cout << res;
    return 0;
}
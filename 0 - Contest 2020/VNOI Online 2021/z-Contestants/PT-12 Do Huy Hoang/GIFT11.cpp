#include <bits/stdc++.h>

using namespace std;
#define task "GIFT11"
const int MAXN = 2007;
const int INF = 1e9 + 7;
const int mod = 998244353;
int T;
int N;
int A[MAXN];
void Input()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
}
int odd[MAXN], even[MAXN];
int num[MAXN];
stack <int> pq;
int calc(int x, int &y)
{
    while(x)
    {
        pq.push(x % 10);
        x /= 10;
        y++;
    }
    int ans = 0;
    bool ok = true;
    while(!pq.empty())
    {
        if(ok)
            ans += pq.top();
        else
            ans -= pq.top();
        pq.pop();
        ok ^= 1;
    }
    ans %= 11;
    if(ans < 0)
        ans += 11;
    return ans;
}
void Init()
{
//    calc(31, num[0]);
    for(int i = 1; i <= N; i++)
    {
        num[i] = 0;
        odd[i] = calc(A[i], num[i]);
        even[i] = 11 - odd[i];
    }
}
int ID[MAXN];
void Subtask1()
{
    for(int i = 1; i <= N; i++)
        ID[i] = i;
    int ans = 0;
    do
    {
        int pos = 1;
        int sum = 0;
        for(int i = 1; i <= N; i++)
        {
            int x = ID[i];
            if(pos % 2)
                sum += odd[x];
            else
                sum += even[x];
            if(sum >= 11)
                sum -= 11;
            pos += num[x];
        }
        ans += (sum == 0);
    }
    while(next_permutation(ID + 1, ID + 1 + N));
    cout << ans << '\n';
}
//void add(int &x, const int &y, const int &modulo)
//{
//    x += y;
//    if(x >= modulo)
//        x -= modulo;
//}
//int memo[MAXN][MAXN][12];
//int solve(int i, int j, int sum)
//{
//    if(i == N + 1)
//        return (sum == 0);
//    if(memo[i][j][sum] != -1)
//        return memo[i][j][sum];
//    int cur = 0;
//    int ns = sum;
//    add(ns, odd[i], 11);
//    add(cur, 1LL * solve(i + 1, j + 1, ns) * j % mod, mod);
//    ns = sum;
//    add(ns, even[i], 11);
//    add(cur, 1LL * solve(i + 1, j, ns) * (i - j + 1) % mod, mod);
//    return memo[i][j][sum] = cur;
//}
//int dp[MAXN][MAXN][12];
//void Subtask2()
//{
////    memset(memo, -1, sizeof memo);
////    cout << solve(1, 1, 0) << '\n';
//    memset(dp, 0, sizeof dp);
//    dp[0][0][0] = 1;
//    for(int i = 0; i < N; i++)
//        for(int j = 0; j < N; j++)
//            for(int k = 0; k < 11; k++)
//            {
//                if(dp[i][j][k] == 0)
//                    continue ;
//                int sum = k;
//                add(sum, odd[i + 1], 11);
//                add(dp[i + 1][j + 1][k], 1LL * dp[i][j][k] * j % mod, mod);
//                sum = k;
//                add(sum, even[i + 1], 11);
//                add(dp[i + 1][j][k], 1LL * dp[i][j][k] * (i + 1 - j) % mod, mod);
//            }
//    int ans = 0;
//    for(int i = 0; i <= N; i++)
//        add(ans, dp[N][i][0], mod);
//    cout << ans << '\n';
//}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> T;
    while(T--)
    {
        Input();
        Init();
        Subtask1();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100005;

int t, n, m;
long long a[MaxN];

struct SegmentTreeUpdate
{
    long long IT[4 * MaxN];
    int Low[4 * MaxN], High[4 * MaxN], Leaf[MaxN];
    void Build(int x, int Left, int Right)
    {
        Low[x] = Left;
        High[x] = Right;
        IT[x] = 0;
        if (Left == Right)
        {
            IT[x] = a[Left];
            Leaf[Left] = x;
            return;
        }
        int Mid = (Left + Right) / 2;
        Build(x * 2, Left, Mid);
        Build(x * 2 + 1, Mid + 1, Right);
    }
    void Update (int x, int Left, int Right, long long val)
    {
        if (Low[x] > Right || High[x] < Left)
        {
            return;
        }
        if (Low[x] >= Left && High[x] <= Right)
        {
            IT[x] += val;
            return;
        }
        Update(x * 2, Left, Right, val);
        Update(x * 2 + 1, Left, Right, val);
    }
    long long Get(int x)
    {
        x = Leaf[x];
        long long res = 0;
        while (x > 0)
        {
            res += IT[x];
            x /= 2;
        }
        return res;
    }
};

struct SegmentTreeSum
{
    long long Sum[4 * MaxN];
    int Low[4 * MaxN], High[4 * MaxN], Leaf[MaxN];
    void Build(int x, int Left, int Right)
    {
        Low[x] = Left;
        High[x] = Right;
        Sum[x] = 0;
        if (Left == Right)
        {
            Leaf[Left] = x;
            return;
        }
        int Mid = (Left + Right) / 2;
        Build(x * 2, Left, Mid);
        Build(x * 2 + 1, Mid + 1, Right);
    }
    void Update(int x, long long val)
    {
        x = Leaf[x];
        Sum[x] = val;
        while (x > 1)
        {
            x /= 2;
            Sum[x] = (Sum[x * 2] + Sum[x * 2 + 1]);
        }
        
    }
    long long Get(int x, int Left, int Right)
    {
        if (Low[x] > Right || High[x] < Left)
        {
            return 0;
        }
        if (Low[x] >= Left && High[x] <= Right)
        {
            return Sum[x];
        }
        return Get(x * 2, Left, Right) + Get(x * 2 + 1, Left, Right);
    }
};

SegmentTreeUpdate STU;
SegmentTreeSum STS;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CONSTRUCT.inp", "r", stdin);
    freopen("CONSTRUCT.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        STU.Build(1, 1, n);
        STS.Build(1, 2, n);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] - a[i-1] > 0)
            STS.Update(i, a[i] - a[i - 1]);
        }
        int type, left, right;
        long long k;
        while (m--)
        {
            cin >> type;
            if (type == 1)
            {
                cin >> left >> right >> k;
                STU.Update(1, left, right, k);
                if (left > 1)
                {
                    STS.Update(left, max(0LL, STU.Get(left) - STU.Get(left - 1)));
                }
                STS.Update(right + 1, max(0LL, STU.Get(right + 1) - STU.Get(right)));
            }
            else
            {
                cin >> left >> right;
                cout << STU.Get(left) + (left == right ? 0LL : STS.Get(1, left + 1, right)) << '\n';
            }
            
        }
        
    }
    
    return 0;
}
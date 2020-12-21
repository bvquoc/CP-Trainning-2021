#include <bits/stdc++.h>
#define ii pair <int, int>
#define X first
#define Y second

using namespace std;

const int N = 1e6+7;
const int OO = 1e9+7;

int n, m, res, Max = -OO, Min = OO;
int k[N], pos[N], check[N];
ii a[N];
ii tmp[N];
int cc = 0;
bool visit[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#define TASK "COOLMAC"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].X >> a[i].Y;
        Min = min(Min, a[i].X);
        Max = max(Max, a[i].Y);
    }

    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> k[i];
    sort(k + 1, k + m + 1);

    if(k[1] < Min || k[m] > Max)
    {
        cout << -1;
        return 0;
    }
    else
    {
        sort(a + 1, a + n + 1, greater <ii> ());

        stack <ii> q;
        q.push(a[1]);

        for(int i = 2; i <= n; i++)
        {
            while(q.size() && a[i].X <= q.top().X && a[i].Y >= q.top().Y)
            {
                q.pop();
            }
            if(a[i].X >= q.top().X && a[i].Y <= q.top().Y)
                continue;
            q.push(a[i]);
        }
        while(q.top().Y < k[1] && q.size())
            q.pop();


        res = q.size();

        while(q.size())
        {
            ii temp = q.top();
            tmp[++cc] = temp;
//            cout << temp.X << ' ' << temp.Y << endl;
            q.pop();
        }

//        cout << cc << endl;

        stack <ii> st;
        for(int i = cc; i >= 1; i--)
            st.push(tmp[i]);

        while(st.size() >= 2)
        {
            int L = st.top().X;
            int R = st.top().Y + 1;
//            cout << L << ' ' << R << ' ' << st.size() << endl ;
            pos[L]++;
            pos[R]--;
            visit[L] = true;
//            visit[R] = true;
            st.pop();

            int Tx = st.top().X;
            int Ty = st.top().Y + 1;
//            cout << Tx << ' ' << Ty << ' ' << st.size() << endl;
            pos[Tx]++;
            pos[Ty]--;
            visit[Tx] = true;
//            visit[Ty] = true;
            st.pop();

            if(st.size())
                if(Tx < R - 1 && Ty > st.top().X + 1)
                {
                    pos[Tx]--;
                    pos[Ty]++;
                    visit[Tx] = false;
//                    visit[Ty] = false;
                    res--;
                }
        }

        while(st.size())
        {
            int L = st.top().X;
            int R = st.top().Y + 1;
//            cout << L << ' ' << R << endl;
            pos[L]++;
            pos[R]--;
            visit[L] = true;
//            visit[R] = true;
            st.pop();
        }
//        cout << res << endl;
        for(int i = 1; i <= Max; i++)
            check[i] = check[i - 1] + pos[i];

        int KK = 1e5;
        for(int i = 1; i <= KK; i++)
            if(visit[i] && check[i] == 1)
            {
//                cout << i << ' ';
                check[i] = 0;
            }

        for(int i = k[1]; i <= KK; i++)
            if(check[i] <= 0)
            {
                cout << -1;
                return 0;
            }

        cout << res;
    }


    return 0;
}

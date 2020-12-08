#include<bits/stdc++.h>

using namespace std;

int n, type;
set<int> s;
vector<int> con[30];
char mau, mau1, mau2, dd[1000005];

int main()
{
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) s.insert(i);
    int A, B;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &type);
        if(type == 1)
        {
            scanf(" %c ", &mau);
            con[mau - 'a' + 1].push_back(*s.begin());
            s.erase(s.begin());
        }
        else{
            scanf(" %c %c ", &mau1, &mau2);
            if(mau1 == mau2) continue;
            A = mau1 - 'a' + 1;
            B = mau2 - 'a' + 1;
            for(int u : con[A]) con[B].push_back(u);
            con[A].clear();
        }
    }
    int umax = 0;
    for(char i = 'a'; i <= 'z'; ++i)
    {
        int j = i - 'a' + 1;
        for(int u : con[j]) dd[u] = i, umax = max(u, umax);
    }
    for(int i = 1; i <= umax; ++i) printf("%c", dd[i]);
}

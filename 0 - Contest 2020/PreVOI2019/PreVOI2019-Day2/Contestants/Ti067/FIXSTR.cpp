#include<bits/stdc++.h>

const int maxn = 1e6 + 5;

using namespace std;

int n, m;
char S[maxn], s[maxn], type[maxn];
int X[maxn], Y[maxn];

void Input()
{
    scanf("%s", S + 1);
    n = strlen(S + 1);
    scanf("%d", &m);
}

void sub1()
{
    for(int i = 1; i <= n; i++) s[i] = S[i];
    for(int i = 1; i <= m; i++)
    {
        scanf(" %c ", &type[i]);
        if(type[i] == 'C')
        {
            scanf("%d", &X[i]);
            if(S[X[i]] == '(') S[X[i]] = ')';
            else S[X[i]] = '(';
        }
        else if(type[i] == 'Q')
        {
            scanf("%d %d", &X[i], &Y[i]);
            int tmp = 0, ds = 0;
            for(int j = X[i]; j <= Y[i]; j++)
            {
                if(S[j] == '(') tmp++;
                else tmp--;
                if(tmp < 0) ds++, tmp = 0;
            }
            if(tmp > 0) ds += tmp;
            printf("%d\n", ds);
        }
        else
        {
            scanf("%d", &X[i]);
            int stop = X[i] - 1, j = i - 1;
            if(stop == 0) for(int j = 1; j <= n; j++) S[j] = s[j];
            else
            {
                while(j > stop)
                {
                    if(type[j] == 'C')
                    {
                        if(S[X[j]] == '(') S[X[j]] = ')';
                        else S[X[j]] = '(';
                    }
                    else if(type[j] == 'U')
                    {
                        stop = min(stop, X[j] - 1);
                        if(stop == 0)
                        {
                            for(int j = 1; j <= n; j++) S[j] = s[j];
                            break;
                        }
                    }
                    j--;
                }
            }
        }
    }
}

void Solve()
{
    if(n <= 1000 && m <= 1000) sub1();
    else sub1();
}

#define TASK "FIXSTR"
int main()
{
    #ifdef TASK
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    #else
    freopen("1.inp", "r", stdin);
    #endif // TASK
    Input();
    Solve();
}

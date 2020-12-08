#include <iostream>
#include <cstdio>
using namespace std;


int n;
char ans[10005];
int pos[200][10004];
int cnt[200];

void inp()
{
    cin >> n;
}


void proc()
{
    int k = 0;
    while (n--)
    {
        int c;
        char x,y;
        scanf("%d",&c);
        if (c == 1)
        {
            scanf(" %c",&x);
            k++;
            pos[x-0][++cnt[x-0]] = k;
        }
        else
        {
            scanf(" %c %c",&x,&y);
            if (x==y) continue;
            while (cnt[x-0])
            {
                pos[y-0][++cnt[y-0]] = pos[x-0][cnt[x-0]];
                cnt[x-0]--;
            }
        }
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        int id = c-0;
        for (int j = 1; j <= cnt[id]; j++)
        {
            ans[pos[id][j]] = c;
        }
    }
    for (int i = 1; i <= k; i++) cout << ans[i];
}


int main()
{
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);
    inp();
    proc();
    return 0;
}

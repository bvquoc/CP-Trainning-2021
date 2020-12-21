#include <bits/stdc++.h>
#define X first
#define Y second
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f0(i,n) for (int i = 0; i < n; i++)
#define N 500005

using namespace std;
typedef pair<int,pair<int,int>> ii;
int n, m, k;
char a[N];
ii len[N];
int main()
{
    ifstream fi("DECOR.INP"); ofstream fo("DECOR.OUT");
    int ct = 1;
    fi >> n >> m >> k;
    f1(i,n)
        fi >> a[i];
    f1(i,n) 
    {
        int cnt = 0;
        if (a[i] == '1') 
        for (int j = i; j <= n; j++) if (a[j] == '1') cnt++;
        else 
        {
            len[ct] = {cnt,{i, j-1}};
            ct++;
            i = j;
            break;
        }
    }
    ii ans = *max_element(len+1, len+ct);
    fo << ans.second.first << " " << ans.second.second;
    //system("pause");
    return 0;
}
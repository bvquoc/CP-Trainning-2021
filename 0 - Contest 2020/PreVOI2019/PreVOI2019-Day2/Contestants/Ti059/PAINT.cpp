#include <bits/stdc++.h>

using namespace std;
int n,dem=0;
vector <int> a[1000001];
char s[1000001];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char y,z;
        cin >> x;
        if(x==1)
        {
            cin >> y;
            dem++;
            a[(int)y].push_back(dem);
        }
        if(x==2)
        {
            cin >> y >> z;
            for(int j:a[(int)y])
                a[(int)z].push_back(j);
            a[(int)y].clear();
        }
    }
    for(int i=97;i<=122;i++)
        for(int j:a[i])
            s[j]=i;
    for (int i=1;i<=dem;i++)
        cout << s[i];
    return 0;
}

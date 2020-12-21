#include <bits/stdc++.h>
#define int long long
using namespace std;

map <int, int>::iterator it;

main()
{
    int t;
    cin >> t;
    while(t--)
    {
        map <int, int> same;
        int n, ans = 0, mul = 1;
        cin >> n;
        int a[n+1];
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            same[a[i]]++;
            mul *= same[a[i]];
        }
        sort(a, a + n);
        do{
            string s, s1 = "";
            int chan = 0, le = 0;
            for(int i = 0; i < n; ++i)
            {
                int number = a[i];
                ostringstream convert;
                convert << number;
                s = convert.str();
                s1 += s;
            }
            for(int i = 0; i < s1.length(); ++i)
            {
                if((i + 1) % 2 == 0)
                    chan += ((int)s1[i] - 48);
                else le += ((int)s1[i] - 48);
            }
            if(abs(le - chan) % 11 == 0)
                ans++;
        }while(next_permutation(a, a + n));
        cout << ans * mul << "\n";
    }
}

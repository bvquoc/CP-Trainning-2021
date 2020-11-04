#include <bits/stdc++.h>

using namespace std;

int m,n;
bool kt;
int a[100000];
long long s[100000];

int main()
{
    cin>>m>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
    for (int i=1; i<=n; i++)
        {
            kt=true;
            for (int j=i; j<=n; j++)
                if (s[j]-s[j-i]<m)
                    {
                        kt=false;
                        break;
                    }
            if (kt==true)
            {
                cout<<i;
                return 0;
            }
        }

}

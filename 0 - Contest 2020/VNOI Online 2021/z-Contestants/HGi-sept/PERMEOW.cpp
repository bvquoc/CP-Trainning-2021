#include <bits/stdc++.h>

using namespace std;
int i,j,n,x,y;
vector<int> a,b;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    int kt=0;
    for(i=1;i<=n;i++)
    {
        cin>>y;
        if(a[i-1]!=y) kt=1;
        b.push_back(y);
    }
    if(kt==0)
    {
        int dem=0,c;
        for(i=0;i<=n-1;i++)
        {
            if(a[i]!=i+1)
            {
                j=i+1;
                while(a[j]!=i+1)
                {
                    j++;
                }
                dem=dem+j-i;
                c=a[j];
                a.erase(a.begin()+j,a.begin()+j+1);
                a.insert(a.begin()+i,c);
            }
        }
        cout<<dem;
    }
    return 0;
}

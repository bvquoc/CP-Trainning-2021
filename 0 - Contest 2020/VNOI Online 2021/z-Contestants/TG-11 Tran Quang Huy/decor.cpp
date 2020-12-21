#include <bits/stdc++.h>

using namespace std;
int n,m,k;
string st;
void Tinh1()
{
    int t=0,d=0,t1,t2;
    for (int i=0;i<st.length();i++)
        if (st[i]=='0')
        {
            if (d<t)
            {
                d=t;
                t2=i;
                t1=i-t+1;
            }
            t=0;
        }
        else
            t++;
    if (d>t)cout<<t1<<" "<<t2;
    else cout<<n-t+1<<" "<<n;
}
int main()
{
    freopen("decor.inp","r",stdin);
    //freopen("decor.out","w",stdout);
    cin>>n>>m>>k;
    cin.ignore();
    cin>>st;
    if (m==0&&k==0)
        Tinh1();
    return 0;
}

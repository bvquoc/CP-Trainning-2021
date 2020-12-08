///Bankai: Getsuga Tenshou
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
ll n;
int kt;
string kq,x,y;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin>>n;
    kq=" ";
    for(int i=1;i<=n;i++)
    {
        cin>>kt;
        if(kt==1)
        {
            cin>>x;
            for(int j=0;j<kq.size();j++)
            {
                if(kq[j]==' ')
                    kq[j]=x[0];
            }
            kq=kq+" ";
        }
        else
        {
            cin>>x>>y;
            for(int j=0;j<kq.size();j++)
            {
                if(kq[j]==x[0]) kq[j]=y[0];
            }
        }
    }
    cout<<kq;
    return 0;
}

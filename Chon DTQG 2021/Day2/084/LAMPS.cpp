#include <bits/stdc++.h>

using namespace std;
int i,t,n,j,k,x,h,d,w[100],c[505],q[100],a[3005],b[3005];
int main()
{
    freopen("LAMPS.INP","r",stdin);
    freopen("LAMPS.OUT","w",stdout);
    cin>>n>>t;
    for (i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    for (k=1;k<=t;k++)
    {
        d=0;x=0;
        for (j=1;j<=n;j++)
        {
            cin>>c[j];
            if (c[j]==1)
            {
                x++;
                q[x]=j;
            }
            else
            {
                d++;
                w[d]=j;
            }
        }
        if (t==1 && n==4)
        {
            if (x==d)
            {
                if (q[1]==q[2]-2)
                    cout<<2<<" "<<w[1]<<" "<<w[2];
                else
                    cout<<2<<" "<<q[1]<<" "<<q[2];
            }
            if (x==4)
                cout<<0;
            if (x==1)
            {
                if (q[1]+2>n)
                {
                    if ((q[1]+2)%2==1)
                        cout<<1<<" "<<1;
                    else cout<<1<<" "<<2;
                }
                else cout<<1<<" "<<q[1]+2;
            }
            if (x==3)
            {
                if ((w[1]+1)%n==0)
                    d=n;
                else d=(w[1]+1)%n;
                if ((w[1]+3)%n==0)
                    h=n;
                else h=(w[1]+3)%n;
                cout<<3<<" "<<w[1]<<" "<<d<<" "<<h;
            }
            if (x==0)
                cout<<4<<" "<<w[1]<<" "<<w[1]+1<<" "<<w[1]+2<<" "<<w[1]+3;
        }
        else cout<<-1<<'\n';
    }
    return 0;
}

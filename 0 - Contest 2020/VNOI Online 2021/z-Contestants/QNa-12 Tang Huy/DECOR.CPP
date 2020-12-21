#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,k;
string s;
int a[N],u[N],v[N],l,r;
int res=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    for (int i=0;i<n;i++)
        a[i+1]=(s[i]-'0');
    for (int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i];
    }
    int tmp=1;
    if (m==0 && k==0)
    {
        int i=1,j,l,r,res=0,pos1=0,pos2=0;
        while (i<=n)
        {
            j=i+1;
            if (a[i]==1){
            l=i;
            j=i+1;
            while(a[i]==a[j]) j++;
            r=j;
            if (r-l>res)
            {
                res=r-l;
                pos1=l;
                pos2=r-1;
            }
            }
            i=j;
        }
        if (pos1==0 && pos2==0) cout<<-1;
        else
        cout<<pos1<<" "<<pos2;
    }
    else cout<<-1;
}
